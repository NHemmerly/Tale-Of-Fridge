cmake_minimum_required(VERSION 2.8)

project(taleOfFridge)

add_library(fridgeLibs
    src/player.h
    src/player.cpp
    src/fileLoader.h 
    src/fileLoader.cpp
    src/item.h 
    src/item.cpp   
    src/controller.h 
    src/controller.cpp 
)

add_executable(taleOfFridge src/main.cpp)

target_link_libraries(taleOfFridge fridgeLibs)