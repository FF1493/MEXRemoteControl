#include "NetworkServoMotor.hpp"
#include "geometry_msgs/Point.h"

NetworkServoMotor::NetworkServoMotor(int argc, char **argv,unsigned short servo, unsigned short startingPosition, unsigned short delta){
   
    //n=new ros::NodeHandle
    publisher = n.advertise<geometry_msgs::Point>("servo1", 10);
}
NetworkServoMotor::~NetworkServoMotor(){}
void NetworkServoMotor::publishServostate(int targetposition){
    geometry_msgs::Point point;
    point.x=targetposition;
    publisher.publish(point);
}
