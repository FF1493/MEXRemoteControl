#include "NetworkServoMotor.hpp"



NetworkServoMotor::NetworkServoMotor(unsigned short servo, unsigned short startingPosition, unsigned short delta){
   
    //n=new ros::NodeHandle
    publishpos = n.advertise<geometry_msgs::Point>("servo1", 10);
    subservangl = n.subscribe("servo1", 5, &NetworkServoMotor::callback,this);
  
}
NetworkServoMotor::~NetworkServoMotor(){}
void NetworkServoMotor::publishServostate(int targetposition){
    geometry_msgs::Point point;
    point.x=targetposition;
    publishpos.publish(point);

}
void NetworkServoMotor::callback(const geometry_msgs::Point& msg)
{
    position=msg.x;
}
int NetworkServoMotor::getPositionInAbs()
{
    ros::spinOnce();
    return position;
}
