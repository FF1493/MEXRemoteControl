//============================================================================
// Name        : NetworkServoMotor.hpp
// Author      : Henrik Wittemeier, Martin Huelse (martin.huelse@fh-bielefeld.de)
//
// Description : NetworkServoMotor header file. It contain the declaration
//               of the NetworkServoMotor class
//============================================================================

#include "ServoMotor.hpp"
#include "ros/ros.h"
#include "ros/time.h"
#include "MEXRemoteControl/servomsg.h"
#include "MEXRemoteControl/servorsp.h"

/**
 * 
 * \class NetworkServoMotor
 * 
 * \brief Class that allows to remotly control a
 * servo over ROS
 * 
 * The positions of the servo motor are defined
 * by positions values (given in units).
 */

class NetworkServoMotor
{
private:
    unsigned short servonum;
    unsigned short delta;
    short degposition;
    float radposition;
    unsigned short absposition;

    ros::Publisher publishpos;
    ros::Subscriber subservangl;
    ros::NodeHandle n;

    void callback(const MEXRemoteControl::servorsp &msg);

public:
    /**
	 *
	 * \brief constructor
	 *
	 *  \return void
	 *
	 */
    NetworkServoMotor(unsigned short servo, unsigned short startingPosition, unsigned short delta);
    /**
	 *
	 * \brief destructor
	 *
	 *  \return void
	 *
	 */
    ~NetworkServoMotor();

    unsigned short getServoNumber();

    unsigned short getMinPos();

    unsigned short getMidPos();

    unsigned short getMaxPos();

    bool setPositionInAbs(unsigned short newPosition);

    bool setPositionInDeg(short newPosition);

    bool setPositionInRad(float newPosition);

    bool setSpeed(unsigned short newSpeed);

    bool setAcceleration(unsigned short newAcceleration);

    unsigned short getPositionInAbs();

    short getPositioninDeg();

    float getPositioninRad();

    void showPololuValues(unsigned short &min, unsigned short &mid, unsigned short &max);
};