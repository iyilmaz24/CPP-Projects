cmake_minimum_required(VERSION 3.27)
project(hash_table_password_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(hash_table_password_server main.cpp
        hashtable.h
        hashtable.hpp
        passserver.cpp
        passserver.h
        proj5.cpp
        sproj5.cpp)
