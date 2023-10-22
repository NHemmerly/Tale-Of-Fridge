cmake_minimum_required(VERSION 2.8)

project(taleOfFridge)

include_directories(includes)

add_library(fridgeLibs
    includes/player.h
    src/player.cpp
    includes/fileLoader.h 
    src/fileLoader.cpp
    includes/item.h 
    src/item.cpp   
    includes/controller.h 
    src/controller.cpp
    includes/entity.h 
    src/entity.cpp 
    includes/weapons.h 
    src/weapons.cpp 
    includes/map.h 
    src/map.cpp 
    includes/yamlParser.h 
    src/yamlParser.cpp 
    includes/yaml.h
)

add_executable(taleOfFridge src/main.cpp)

target_link_libraries(taleOfFridge fridgeLibs)