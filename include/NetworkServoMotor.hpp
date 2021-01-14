#include "ServoMotor.hpp"
#include "ros/ros.h"
#include "ros/time.h"

class NetworkServoMotor
{
private:
    unsigned short servo;
    unsigned short delta;
    ros::Publisher publisher;
    ros::NodeHandle n;
public:
    NetworkServoMotor(int argc, char **argv,unsigned short servo, unsigned short startingPosition, unsigned short delta);
    ~NetworkServoMotor();
    void publishServostate(int targetposition);
    
};