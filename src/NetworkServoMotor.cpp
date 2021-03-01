#include "NetworkServoMotor.hpp"



NetworkServoMotor::NetworkServoMotor(unsigned short servo, unsigned short startingPosition, unsigned short delta)
{
    publishpos = n.advertise<MEXRemoteControl::servomsg>("servo"+to_string(servo), 10);
    subservangl = n.subscribe("servorsp"+to_string(servo), 10, &NetworkServoMotor::callback,this);
}
NetworkServoMotor::~NetworkServoMotor(){}


bool NetworkServoMotor::setPositionInAbs(unsigned short newPosition){
    MEXRemoteControl::servomsg msg;
    msg.type="ABS";
    msg.value=newPosition;
    publishpos.publish(msg);
    while(ros :: ok)
    {
        ros::spinOnce();
        if(absposition==newPosition)
            break;
        std::cout<< "Waiting for Response "<< absposition<<" "<<newPosition << std::endl;
        publishpos.publish(msg);
        usleep(500000);

    }

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
