#include "NetworkSerial.hpp"

NetworkSerial::NetworkSerial(unsigned short servoID,
										   unsigned short neutralPos,
										   unsigned short delta,
										   IPololu  *pololuController,ros::NodeHandle* nodehandle):n(*nodehandle),ServoMotor(servoID,neutralPos,delta,pololuController){
    
    std::cout<<"4.5"<<"servorsp"+to_string(servoID)+"!"<<std::endl;                                      
    publishpos = n.advertise<MEXRemoteControl::servorsp>("servorsp"+to_string(servoID), 10,true);
    subservangl = n.subscribe("servo"+to_string(servoID), 10, &NetworkSerial::callback,this);
    //ros::spin();

    };

void NetworkSerial::callback(const MEXRemoteControl::servomsg& msg)
{
    std::cout<<"GOT MESSAGE"<<std::endl;
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