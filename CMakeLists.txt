cmake_minimum_required(VERSION 3.22)

project(infra-lib)
project(cmake-project-template)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

add_subdirectory(src)
