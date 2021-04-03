#include "NetworkSerial.hpp"

NetworkSerial::NetworkSerial(unsigned short servoID,
										   unsigned short neutralPos,
										   unsigned short delta,
										   IPololu  *pololuController,ros::NodeHandle* nodehandle):n_(*nodehandle),ServoMotor(servoID,neutralPos,delta,pololuController){
                                         
    publishpos_ = n_.advertise<MEXRemoteControl::servorsp>("servorsp"+to_string(servoID), 10,true); // Initialize a new publisher that publishes the Topic (servorsp<servoid>)
    subsservpos_ = n_.subscribe("servo"+to_string(servoID), 10, &NetworkSerial::callback,this); // Initialize a new subscriber that subscribes the Topic (servo<servoid>)
    };

void NetworkSerial::callback(const MEXRemoteControl::servomsg& msg)
{
    if(msg.type=="ABS")
    {
        this->setPositionInAbs(msg.value); // send received Position to Polulu
        sleep(1);    
    }
    else if(msg.type=="DEG")
    {
        std::cout<<"Not implemented YET"<<std::endl; // same as above for DEG values
    }
}
void NetworkSerial::poll()
{
    ros::spinOnce(); // Listen for new Messages, if available "callback" is called
    MEXRemoteControl::servorsp resp; // Create a new servoresponse object
    resp.abspos = this->getPositionInAbs(); //get new Position update write to servoresponse
    publishpos_.publish(resp);// Publish position updates
}