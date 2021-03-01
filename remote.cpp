#include "NetworkServoMotor.hpp"
#include <unistd.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "remote");
    NetworkServoMotor Servo0 = NetworkServoMotor(0, 1000, 2500);
    while (true)
    {
        std::cout<<2000<<std::endl;
        Servo0.setPositionInAbs(2000);
        usleep(1000000);
        std::cout<<2000<<std::endl;
        std::cout<<Servo0.getPositionInAbs()<<std::endl;

        Servo0.setPositionInAbs(1000);
        usleep(1000000);
        std::cout<<1000<<std::endl;
        std::cout<<Servo0.getPositionInAbs()<<std::endl;


    }
}