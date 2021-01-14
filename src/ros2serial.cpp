#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Pololu.hpp"
#include "ServoMotor.hpp"
#include "SerialCom.hpp"

Pololu conn();
ServoMotor Servo1();
ServoMotor Servo2();
ServoMotor Servo3();
ServoMotor Servo4();

struct Servo{
    int Middle, Delta;
}servo1, servo2, servo3, servo4;



int main(int argc, char **argv)
{
    unsigned short acceleration = 10;
    unsigned short speed = 100;

    ros::init(argc,argv,"MEXlistener");
    //ros::NodeHandle nh;

    Pololu conn=  Pololu("/dev/ttyACM0",9600);
    ServoMotor Servo1 = ServoMotor(1,5680,3600,&conn);
    ServoMotor Servo2 =  ServoMotor(2,6000,3600,&conn);
    ServoMotor Servo3 =  ServoMotor(3,6000,3600,&conn);
    ServoMotor Servo4 =  ServoMotor(4,6000,3600,&conn);
     
    conn.openConnection();
    
    Servo1.setSpeed(speed);
    Servo1.setAcceleration(acceleration);
    Servo1.setPositionInAbs(5680);
    Servo1.setPositionInAbs(1000);
    
    
    
    ros::spin();
}
