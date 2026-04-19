#include <iostream>
#include <fstream>
#include <string>

class Address 
{
    private:
        std::string city;
        std::string street;
        int house_number;
        int apartment_number;

    public:
        Address(std::string city, std::string street, int house, int apartment)
            : city(city), street(street), house_number(house), apartment_number(apartment) 
        {
        }
    
        std::string get_city() const 
        {
            return city;
        }
    
        std::string get_output_address() const 
        {
            return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
        }
};

void sort_addresses(Address** addresses, int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (addresses[j]->get_city() > addresses[j + 1]->get_city()) 
            {
                Address* temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    std::ifstream fin("in.txt");
    if (!fin.is_open()) 
    {
        std::cout << "Ошибка: не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    int n;
    fin >> n;
    fin >> std::ws;
    Address** addresses = new Address * [n];
    for (int i = 0; i < n; ++i) 
    {
        std::string city, street;
        int house, apartment;
        std::getline(fin, city);
        std::getline(fin, street);
        fin >> house >> apartment;
        fin >> std::ws;
        addresses[i] = new Address(city, street, house, apartment);
    }
    
    fin.close();
    sort_addresses(addresses, n);
    std::ofstream fout("out.txt");
    if (!fout.is_open()) 
    {
        std::cout << "Ошибка: не удалось создать файл out.txt" << std::endl;
        for (int i = 0; i < n; ++i) delete addresses[i];
        delete[] addresses;
        return 1;
    }

    fout << n << std::endl;
    for (int i = 0; i < n; ++i) {
        fout << addresses[i]->get_output_address() << std::endl;
    }
    
    fout.close();
    for (int i = 0; i < n; ++i) 
    {
        delete addresses[i];
    }
    
    delete[] addresses;
    std::cout << "Адреса отсортированы и записаны в out.txt" << std::endl;
    return 0;
}
