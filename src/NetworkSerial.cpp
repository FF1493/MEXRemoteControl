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
    //std::cout<<"Not implemented YET"<<std::endl;
    if(msg.type=="ABS")
    {
        std::cout<<"Set Position to: "<< msg.value <<std::endl;
        std::cout<<"SetPositioninAbs"<<this->setPositionInAbs(msg.value)<< std::endl; 
        sleep(1);    
    }
    else if(msg.type=="DEG")
    {
        std::cout<<"Not implemented YET"<<std::endl;
    }
    

}
void NetworkSerial::poll()
{
    ros::spinOnce();
    MEXRemoteControl::servorsp resp;
    resp.abspos = this->getPositionInAbs();
    std::cout<<"Response of get Position in ABS: "<<resp.abspos<<std::endl;

    //resp.degpos = getPositionInDeg();
    publishpos.publish(resp);
    std::cout<<std::endl;
}