#include "NetworkServoMotor.hpp"



NetworkServoMotor::NetworkServoMotor(unsigned short servo, unsigned short startingPosition, unsigned short delta)
{
    servonum=servo;
     //n=new ros::NodeHandle
    publishpos = n.advertise<MEXRemoteControl::servomsg>("servo"+to_string(servonum), 10);
    subservangl = n.subscribe("servorsp"+to_string(servonum), 5, &NetworkServoMotor::callback,this);
}
NetworkServoMotor::~NetworkServoMotor(){}


bool NetworkServoMotor::setPositionInAbs(unsigned short newPosition){
    MEXRemoteControl::servomsg msg;
    msg.value=newPosition;
    publishpos.publish(msg);

}

void NetworkServoMotor::callback(const MEXRemoteControl::servorsp& msg)
{
    absposition=msg.abspos;
    degposition=msg.degpos;
    radposition=msg.radpos;
}

unsigned short NetworkServoMotor::getPositionInAbs()
{
    ros::spinOnce();
    return absposition;
}

unsigned short NetworkServoMotor::getServoNumber(){return servonum;}
