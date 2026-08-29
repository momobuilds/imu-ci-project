#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "imu/imu.hpp"

TEST_CASE("Stationary IMU returns expected acceleration")
{
    imu::ImuSensor sensor;

    const imu::ImuData data = sensor.read();

    CHECK(data.ax == Catch::Approx(0.0));
    CHECK(data.ay == Catch::Approx(0.0));
    CHECK(data.az == Catch::Approx(9.81));
}


TEST_CASE("Stationary IMU has zero angular velocity")
{
    imu::ImuSensor sensor;

    const imu::ImuData data = sensor.read();

    CHECK(data.gx == Catch::Approx(0.0));
    CHECK(data.gy == Catch::Approx(0.0));
    CHECK(data.gz == Catch::Approx(0.0));
}