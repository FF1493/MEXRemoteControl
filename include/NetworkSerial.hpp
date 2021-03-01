#ifndef NetworkSerialH
#define NetworkSerialH

#include "ServoMotor.hpp"
#include "ros/ros.h"
#include "ros/time.h"
#include "MEXRemoteControl/servomsg.h"
#include "MEXRemoteControl/servorsp.h"


class NetworkSerial : public ServoMotor
{
private:
    ros::Publisher publishpos;
    ros::Subscriber subservangl;
    ros::NodeHandle n;

  

    void callback(const MEXRemoteControl::servomsg& msg);

public:
    NetworkSerial(unsigned short servoID,
										   unsigned short neutralPos,
										   unsigned short delta,
										   IPololu  *pololuController,ros::NodeHandle* nodehandle);
    ~NetworkSerial(){};
};
#endif 