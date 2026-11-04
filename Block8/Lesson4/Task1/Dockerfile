FROM ubuntu:16.04

RUN sed -i 's|http://archive.ubuntu.com/ubuntu|http://old-releases.ubuntu.com/ubuntu|g; s|http://security.ubuntu.com/ubuntu|http://old-releases.ubuntu.com/ubuntu|g' /etc/apt/sources.list \
    && apt-get update \
    && apt-get install -y g++ nano \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY main.cpp /app/

RUN g++ main.cpp -o hello

CMD ["./hello"]
