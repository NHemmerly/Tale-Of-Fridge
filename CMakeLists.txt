cmake_minimum_required(VERSION 3.1)

project(taleOfFridge)

include_directories(includes)
add_subdirectory(includes/yaml-cpp)
include_directories(${YAML_CPP_INCLUDE_DIRS})

add_library(fridgeLibs
    includes/player.h
    src/player.cpp
    includes/item.h 
    src/item.cpp   
    includes/controller.h 
    src/controller.cpp
    includes/entity.h 
    src/entity.cpp 
    includes/weapons.h 
    src/weapons.cpp 
    includes/room.h 
    src/room.cpp 
    includes/mapController.h 
    src/mapController.cpp 
)

add_executable(taleOfFridge src/main.cpp)

add_custom_target(CopyYAMLAssets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/yamlAssets ${CMAKE_BINARY_DIR}/yamlAssets
)
add_custom_command(
    TARGET taleOfFridge
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/yamlAssets ${CMAKE_BINARY_DIR}/yamlAssets
)

add_dependencies(taleOfFridge CopyYAMLAssets)
target_link_libraries(taleOfFridge fridgeLibs)
target_link_libraries(taleOfFridge yaml-cpp)
