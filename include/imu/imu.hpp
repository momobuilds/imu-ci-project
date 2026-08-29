#pragma once

namespace imu {

struct ImuData {
    double ax;
    double ay;
    double az;

    double gx;
    double gy;
    double gz;
    double temperature;
};

class ImuSensor {
public:
    ImuSensor();

    ImuData read() const;
};

}

