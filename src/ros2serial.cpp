#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Pololu.hpp"
#include "ServoMotor.hpp"


Pololu conn("/dev/ttyACM0",9600);
ServoMotor Servo1(1,6000,3600,&conn);
ServoMotor Servo2(2,6000,3600,&conn);
ServoMotor Servo3(3,6000,3600,&conn);
ServoMotor Servo4(4,6000,3600,&conn);




ros::NodeHandle nh;
std::string com_port, baud_rate;
int servo1middle, servo1delta;

int main(int argc, char **argv)
{
    std::cout<<"Hallo Welt"<<std::endl;
}
