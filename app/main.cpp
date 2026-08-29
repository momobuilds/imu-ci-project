#include <iostream>

#include "imu/imu.hpp"

int main()
{
    imu::ImuSensor sensor;

    const imu::ImuData data = sensor.read();

    std::cout << "Acceleration:\n";
    std::cout << "ax = " << data.ax << '\n';
    std::cout << "ay = " << data.ay << '\n';
    std::cout << "az = " << data.az << '\n';

    std::cout << "\nGyroscope:\n";
    std::cout << "gx = " << data.gx << '\n';
    std::cout << "gy = " << data.gy << '\n';
    std::cout << "gz = " << data.gz << '\n';
    std::cout << "\nTemperature:\n";
    std::cout << data.temperature << " C\n";
    return 0;
}