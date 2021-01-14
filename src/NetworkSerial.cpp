#include "NetworkSerial.hpp"

/*NetworkSerial::NetworkSerial(unsigned short servoID,
										   unsigned short neutralPos,
										   unsigned short delta,
										   IPololu  *pololuController):ServoMotor(servoID,neutralPos,delta,pololuController){

    //n=new ros::NodeHandle
    publishpos = n.advertise<MEXRemoteControl::servorsp>("servo"+to_string(servoNmb_), 10);
    subservangl = n.subscribe("servorsp"+to_string(servoNmb_), 5, &NetworkSerial::callback,this);
}*/

void NetworkSerial::callback(const MEXRemoteControl::servomsg& msg)
{
    std::cout<<msg.value<<std::endl;
}