cmake_minimum_required(VERSION 3.15)

project(argon)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/lexer.cpp
)
