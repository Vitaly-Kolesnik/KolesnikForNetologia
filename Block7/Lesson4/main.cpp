#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <pqxx/pqxx>

struct Phone {
    int id;
    std::string number;
};

struct Client {
    int id;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::vector<Phone> phones;
};

class ClientManager {
private:
    std::string connectionString;

public:
    explicit ClientManager(std::string connStr)
        : connectionString(std::move(connStr)) {}

    void createDbStructure() {
        pqxx::connection c(connectionString);
        pqxx::work w(c);

        w.exec(R"(
            CREATE TABLE IF NOT EXISTS clients (
                id SERIAL PRIMARY KEY,
                first_name VARCHAR(50) NOT NULL,
                last_name VARCHAR(50) NOT NULL,
                email VARCHAR(100) UNIQUE NOT NULL
            );
        )");

        w.exec(R"(
            CREATE TABLE IF NOT EXISTS phones (
                id SERIAL PRIMARY KEY,
                client_id INT REFERENCES clients(id) ON DELETE CASCADE,
                phone_number VARCHAR(30) UNIQUE NOT NULL
            );
        )");

        w.commit();
        std::cout << "Структура БД создана.\n";
    }

    // 2. Добавление клиента (INSERT)
    int addClient(const std::string& firstName, const std::string& lastName, const std::string& email) {
        pqxx::connection c(connectionString);
        pqxx::work w(c);

        pqxx::result r = w.exec_params(
            "INSERT INTO clients (first_name, last_name, email) VALUES ($1, $2, $3) RETURNING id;",
            firstName, lastName, email
        );

        int clientId = r[0][0].as<int>();
        w.commit();
        return clientId;
    }

    void addPhone(int clientId, const std::string& phone) {
        pqxx::connection c(connectionString);
        pqxx::work w(c);

        w.exec_params(
            "INSERT INTO phones (client_id, phone_number) VALUES ($1, $2);",
            clientId, phone
        );

        w.commit();
    }

    void updateClient(int clientId, 
                      const std::optional<std::string>& firstName = std::nullopt,
                      const std::optional<std::string>& lastName = std::nullopt,
                      const std::optional<std::string>& email = std::nullopt) {
        pqxx::connection c(connectionString);
        pqxx::work w(c);

        if (firstName.has_value()) {
            w.exec_params("UPDATE clients SET first_name = $1 WHERE id = $2;", *firstName, clientId);
        }
        if (lastName.has_value()) {
            w.exec_params("UPDATE clients SET last_name = $1 WHERE id = $2;", *lastName, clientId);
        }
        if (email.has_value()) {
            w.exec_params("UPDATE clients SET email = $1 WHERE id = $2;", *email, clientId);
        }

        w.commit();
    }

    void deletePhone(const std::string& phone) {
        pqxx::connection c(connectionString);
        pqxx::work w(c);

        w.exec_params("DELETE FROM phones WHERE phone_number = $1;", phone);
        w.commit();
    }

    void deleteClient(int clientId) {
        pqxx::connection c(connectionString);
        pqxx::work w(c);

        w.exec_params("DELETE FROM clients WHERE id = $1;", clientId);
        w.commit();
    }

    std::vector<Client> findClient(const std::string& query) {
        pqxx::connection c(connectionString);
        pqxx::read_transaction r(c);

        pqxx::result clientRes = r.exec_params(R"(
            SELECT DISTINCT c.id, c.first_name, c.last_name, c.email
            FROM clients c
            LEFT JOIN phones p ON c.id = p.client_id
            WHERE c.first_name = $1 
               OR c.last_name = $1 
               OR c.email = $1 
               OR p.phone_number = $1;
        )", query);

        std::vector<Client> clients;

        for (const auto& row : clientRes) {
            Client client;
            client.id = row["id"].as<int>();
            client.firstName = row["first_name"].as<std::string>();
            client.lastName = row["last_name"].as<std::string>();
            client.email = row["email"].as<std::string>();

            pqxx::result phoneRes = r.exec_params(
                "SELECT id, phone_number FROM phones WHERE client_id = $1;", client.id
            );

            for (const auto& pRow : phoneRes) {
                client.phones.push_back({
                    pRow["id"].as<int>(),
                    pRow["phone_number"].as<std::string>()
                });
            }

            clients.push_back(client);
        }

        return clients;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    try {
        std::string connStr = "host=127.0.0.1 port=5432 dbname=clients_db user=postgres password=secret";
        ClientManager manager(connStr);

        manager.createDbStructure();

        int id1 = manager.addClient("Иван", "Иванов", "ivan@example.com");
        manager.addPhone(id1, "+79991112233");

        auto found = manager.findClient("Иван");
        for (const auto& client : found) {
            std::cout << "Найден: " << client.firstName << " " << client.lastName << " (" << client.email << ")\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
