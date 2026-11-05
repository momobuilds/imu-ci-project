# IMU CI Project

[![C++ CI](https://github.com/momobuilds/imu-ci-project/actions/workflows/ci.yml/badge.svg)](https://github.com/momobuilds/imu-ci-project/actions/workflows/ci.yml)

A small C++17 IMU driver skeleton used to practise a professional embedded-software workflow: a clean library/app split, unit tests, and continuous integration on every push. `main` is branch-protected, so changes go through pull requests and CI must pass first.

The sensor is currently **simulated** (stationary device: gravity on the z-axis, zero angular velocity), which lets the API and tests be developed before real hardware is attached.

## Structure

```text
include/imu/imu.hpp    public API: ImuSensor, ImuData (accel, gyro, temperature)
src/imu.cpp            simulated sensor implementation
app/main.cpp           demo executable that prints one reading
tests/test_imu.cpp     Catch2 unit tests
.github/workflows/     GitHub Actions: configure → build → ctest
```

## Build and test

```sh
cmake -S . -B build
cmake --build build
./build/imu_app                                  # print a sample reading
ctest --test-dir build --output-on-failure       # run unit tests
```

Catch2 v3 is fetched automatically by CMake (`FetchContent`).

## Roadmap

- Replace the simulator with a real I²C/SPI driver (e.g. MPU-6050 / ICM-42688) behind the same interface
- Add calibration (bias removal) and orientation estimation (complementary filter), with tests
- Cross-compile for an MCU target in CI

**Stack:** C++17 · CMake · Catch2 · GitHub Actions
