#include "NetworkServoMotor.hpp"



NetworkServoMotor::NetworkServoMotor(unsigned short servo, unsigned short startingPosition, unsigned short delta)
{
    publishpos = n_.advertise<MEXRemoteControl::servomsg>("servo"+to_string(servo), 10);
    subservangl = n_.subscribe("servorsp"+to_string(servo), 10, &NetworkServoMotor::callback,this);
}
NetworkServoMotor::~NetworkServoMotor(){}


bool NetworkServoMotor::setPositionInAbs(unsigned short newPosition){
    MEXRemoteControl::servomsg msg;
    
    msg.type="ABS";
    msg.value=newPosition;
    
    publishpos.publish(msg);
    ros::spinOnce();    

}

void NetworkServoMotor::callback(const MEXRemoteControl::servorsp& msg)
{
    absposition_=msg.abspos;
    degposition_=msg.degpos;
    radposition_=msg.radpos;
}

unsigned short NetworkServoMotor::getPositionInAbs()
{
    ros::spinOnce();
    return absposition_;
}

