#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Pololu.hpp"
#include "ServoMotor.hpp"
#include "NetworkSerial.hpp"
#include "SerialCom.hpp"

Pololu conn();


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
    NetworkSerial Servo1 = NetworkSerial(1,5680,3600,&conn);
    NetworkSerial Servo2 =  NetworkSerial(2,6000,3600,&conn);
    NetworkSerial Servo3 =  NetworkSerial(3,6000,3600,&conn);
    NetworkSerial Servo4 =  NetworkSerial(4,6000,3600,&conn);
     
    conn.openConnection();
    
    Servo1.setSpeed(speed);
    Servo1.setAcceleration(acceleration);
    Servo1.setPositionInAbs(5680);
    Servo1.setPositionInAbs(1000);
    
    
    
    ros::spin();
}
