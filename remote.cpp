#include "NetworkServoMotor.hpp"
#include <unistd.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "remote");
    NetworkServoMotor Servo0 = NetworkServoMotor(0, 2500, 5000);
    while (ros::ok)
    {
        std::cout<<"setPositionInAbs(1000)"<<std::endl;
        Servo0.setPositionInAbs(4000);
        usleep(5000000);
        std::cout<<"getPositionInAbs("<<Servo0.getPositionInAbs()<<")"<<std::endl;

        std::cout<<"setPositionInAbs(4000)"<<std::endl;
        Servo0.setPositionInAbs(1000);
        usleep(5000000);
        std::cout<<"getPositionInAbs()"<<Servo0.getPositionInAbs()<<")"<<std::endl;
        std::cout<<std::endl;

    }
}