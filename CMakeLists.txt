cmake_minimum_required(VERSION 3.8)
project(encrypt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES
        aux.h
        huffman.cc
        huffman.h
        huffman.txt
        LICENSE
        main.cc
        menus.cc
        menus.h
        msg.cc
        msg.h
        Node.cc
        Node.h
        README.md
        sis.h)

add_executable(encrypt ${SOURCE_FILES})