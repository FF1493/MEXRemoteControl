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

  

    void callback(const MEXRemoteControl::servomsg &msg);

public:
    NetworkSerial(unsigned short servoID,
										   unsigned short neutralPos,
										   unsigned short delta,
										   IPololu  *pololuController):ServoMotor(servoID,neutralPos,delta,pololuController){
    publishpos = n.advertise<MEXRemoteControl::servorsp>("servo"+to_string(servoNmb_), 10);
    subservangl = n.subscribe("servorsp"+to_string(servoNmb_), 5, &NetworkSerial::callback,this);
    };
    ~NetworkSerial(){};
};