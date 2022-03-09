#!/bin/bash

build_number(){
    echo "BUIDLING NUMBER"
    g++ -c Number/number.cpp -o build/number.o
    ar rvs build/number.a build/number.o
    echo "BUIDLING NUMBER DONE"
}

build_vector(){
    echo "BUIDLING VECTOR"
    g++ -c -INumber Vector/vector.cpp -o build/vector.o
    g++ -shared -o build/libVector.so build/vector.o build/number.a
    echo "BUIDLING VECTOR DONE"
}
build_app(){
    echo "BUIDLING TEST"
    g++ -o build/main Test/main.cpp -INumber -IVector build/libVector.so build/number.a
    echo "BUIDLING TEST DONE"
}

build(){
    [ -d build ] || mkdir build
    build_number
    build_vector
    build_app
}

clean(){
    echo "CLEANING BUILD FILES"
    rm -rf build
    echo "CLEANING BUILD FILES DONE"
}

run(){
    echo "RUNNING APP..."
    [ -f build/main ] && ./build/main || echo "ERROR: executable main not found!"
}

build
run