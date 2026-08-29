cmake_minimum_required(VERSION 3.16)

project(imu_ci_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    imu
    src/imu.cpp
)

target_include_directories(
    imu
    PUBLIC
    include
)

add_executable(
    imu_app
    app/main.cpp
)

target_link_libraries(
    imu_app
    PRIVATE
    imu
)