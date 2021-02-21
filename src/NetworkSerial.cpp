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
    if(msg.type=="ABS")
    {
        setPositionInAbs(msg.value);
        std::cout<< "Received message:"<< msg.value<<std::endl;
        while(true)
        {
            if(getPositionInAbs()==msg.value)
                break;
            std::cout<< "Waiting for good value"<<std::endl;
            usleep(500000);
        }
    }
    else if(msg.type=="DEG")
    {
        std::cout<<"Not implemented YET"<<std::endl;
    }
    MEXRemoteControl::servorsp resp;
    resp.abspos = getPositionInAbs();
    resp.degpos = getPositionInDeg();
    publishpos.publish(resp);

    std::cout<<msg.value<<std::endl;
}