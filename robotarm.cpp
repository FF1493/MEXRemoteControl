#include "NetworkSerial.hpp"
#include "SerialCom.hpp"
#include "ros/ros.h"
#include <unistd.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "robotarm");
    ros::NodeHandle  n;
    Pololu conn("/dev/ttyACM0",9600);
    std::cout<<"1"<<std::endl;
    conn.openConnection();
    std::cout<<"2"<<std::endl;

   // conn.getErrors();
    std::cout<<"3"<<std::endl;
    try
    {
        NetworkSerial Servo0 = NetworkSerial(0, 2500, 1000, &conn, &n);
        std::cout <<"4good"<<std::endl;

    }
    catch(ExceptionServoMotorBase* ex){
        std::cout<< ex->getMsg()<<"4bad"<<std::endl;
    }catch(ExceptionPololu* ex){
        std::cout<< ex->getMsg()<<"4bad"<<std::endl;
    }
    std::cout<<"5"<<std::endl;
    ros::spin();
        

  
}