#include "NetworkServoMotor.hpp"
#include <unistd.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "servomanipulator");
    NetworkServoMotor Servo1 = NetworkServoMotor(argc, argv,1, 2000, 200);
    while (true)
    {
        Servo1.publishServostate(2100);
        usleep(1000000);
        Servo1.publishServostate(1900);
        usleep(1000000);

    }
}