#include "ServoMotor.hpp"
#include "ros/ros.h"
#include "ros/time.h"
#include "geometry_msgs/Point.h"


class NetworkServoMotor
{
private:
    unsigned short servonum;
    unsigned short delta;
    int position;
    ros::Publisher publishpos;
    ros::Subscriber subservangl;
    ros::NodeHandle n;
    void callback(const geometry_msgs::Point& msg);

public:

    NetworkServoMotor(unsigned short servo, unsigned short startingPosition, unsigned short delta);

    ~NetworkServoMotor();

    void publishServostate(int targetposition);

    int getPositionInAbs();
};