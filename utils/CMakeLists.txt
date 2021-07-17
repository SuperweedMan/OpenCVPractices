cmake_minimum_required(VERSION 3.0.0)
project(Utils VERSION 0.1.0)

MESSAGE("${PROJECT_NAME} CMakeLists:  ${CMAKE_CURRENT_SOURCE_DIR}")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src ${PROJECT_NAME}_SOURCES)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)