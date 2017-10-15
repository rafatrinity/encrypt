cmake_minimum_required(VERSION 3.8)
project(encrypt)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        aux.h
        huffman.cc
        huffman.h
        LICENSE
        main.cc
        menus.cc
        menus.h
        msg.cc
        msg.h
        sis.h Node.cc Node.h)

add_executable(encrypt ${SOURCE_FILES})