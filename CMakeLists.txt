cmake_minimum_required(VERSION 3.27)
project(ChewingCpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(ChewingCpp main.cpp
        CustomString.h
        CustomString.cpp
        CNode.h
        CNode.cpp
        LinkedList.h
        LinkedList.cpp)
