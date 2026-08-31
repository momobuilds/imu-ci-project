#include "imu/imu.hpp"

namespace imu {

ImuSensor::ImuSensor() = default;

ImuData ImuSensor::read() const
{
    ImuData data{};

    data.ax = 0.0;
    data.ay = 0.0;
    data.az = 6.0;

    data.gx = 0.0;
    data.gy = 0.0;
    data.gz = 0.0;
    data.temperature = 25.0;
    return data;
}

}