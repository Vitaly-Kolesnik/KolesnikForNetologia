FROM ubuntu:22.04

ARG COMPILER=g++

RUN apt-get update \
    && apt-get install -y cmake make ${COMPILER} \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN cmake -S . -B build -DCMAKE_CXX_COMPILER=${COMPILER} \
    && cmake --build build

CMD ["./build/selection_sort"]
