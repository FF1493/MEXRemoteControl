#include "NetworkServoMotor.hpp"
#include <unistd.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "servomanipulator");
    NetworkServoMotor Servo1 = NetworkServoMotor(1, 2000, 200);
    while (true)
    {
        Servo1.publishServostate(2100);
        usleep(1000000);
        std::cout<<2100<<std::endl;
        std::cout<<Servo1.getPositionInAbs()<<std::endl;

        Servo1.publishServostate(1900);
        usleep(1000000);
        std::cout<<1900<<std::endl;
        std::cout<<Servo1.getPositionInAbs()<<std::endl;


    }
}