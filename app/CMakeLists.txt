cmake_minimum_required(VERSION 3.7)
project(test1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions ("-Wall -Wextra -Wpedantic -Weffc++ -Wconversion -Wunreachable-code -Wold-style-cast")

set(SOURCES
        main.c
        func.c
        )

set(HEADERS
        main.h
        )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} m)