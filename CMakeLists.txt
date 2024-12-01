cmake_minimum_required(VERSION 3.29)
project(cities_of_the_world)

set(CMAKE_CXX_STANDARD 14)

add_executable(cities_of_the_world
    main.cpp
        Mayor.cpp
        MenuManager.cpp
        OperationsController.cpp)
