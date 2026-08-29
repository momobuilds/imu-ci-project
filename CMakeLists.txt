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

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

enable_testing()

add_executable(
    imu_tests
    tests/test_imu.cpp
)

target_link_libraries(
    imu_tests
    PRIVATE
    imu
    Catch2::Catch2WithMain
)

add_test(
    NAME imu_tests
    COMMAND imu_tests
)