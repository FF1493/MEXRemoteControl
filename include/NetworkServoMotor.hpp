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
    /**
	 *
	 * \var servonum_
	 *
	 * \brief Servo port number 
     *
	 */
    unsigned short servonum_;

    /**
	 *
	 * \var delta_
	 *
	 * \brief Defines the range of positions values.
	 * Starting from the neutral positions +/- delta.
	 *
	 */
    unsigned short delta;

    /**
	 *
	 * \var degposition_
	 *
	 * \brief Defines the positiom in degree.
	 * 
	 *
	 */
    short degposition_;

	/**
	 *
	 * \var degposition_
	 *
	 * \brief Defines the positiom in rad.
	 * 
	 *
	 */
    float radposition_;

	/**
	 *
	 * \var degposition_
	 *
	 * \brief Defines the positiom as absolut value.
	 * 
	 *
	 */
	unsigned short absposition_;


    /**
	 *
	 * \var publishpos_
	 *
	 * \brief Object of a ROS publisher
     * Publishes Position updates to ROS 
     *
	 */
    ros::Publisher publishpos;

     /**
	 *
	 * \var subsservpos_
	 *
	 * \brief Object of a ROS subscriber
     * Subscribes Position updates from ROS 
     *
	 */
    ros::Subscriber subservangl;
    
    /**
	 *
	 * \var n_
	 *
	 * \brief Ros NodeHandle that is needed
     * for communication with ROS 
     *
	 */
    ros::NodeHandle n_;

    /**
	 *
	 *
	 * \brief  Is called when subscriber gets a new Message object.
     * Is used to react on Messages.
     * Moves Robotarm based on Input.
	 *
	 *  \return void.
	 *
	 */
    void callback(const MEXRemoteControl::servorsp &msg);

public:
    /**
	 *
	 * \brief constructor
	 *
     *
     * \param servo unsigned short servo (pin on polulu board)
     *
     * \param startingPosition unsigned short startingPosition value given
	 *                     as absolut value.
     * \param delta unsigned short delta value given
	 *                     as absolut value.
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


    /**
	 *
	 * \brief Delivers the minimal position value the servo
	 * motor can / shall move to.
	 *
	 *  \return unsigned short
	 *
     * \todo To be implemented
     *
	 */
    unsigned short getMinPosInAbs();

    /**
	 *
	 * \brief Delivers the middle position value of the servo
	 *
	 *  \return unsigned short
	 *
     * \todo To be implemented
     *
	 */
    unsigned short getMidPosInAbs();

    /**
	 *
	 * \brief Delivers the maximal position value the servo
	 * motor can / shall move to.
	 *
	 *  \return unsigned short
	 *
     * \todo To be implemented
     *
	 */
    unsigned short getMaxPosInAbs();

    /**
	 *
	 *
	 * \brief Moves the servo motor to the given position.
	 *
	 *  \param newPosition unsigned short position value given
	 *                     in units.
	 *
	 *  \return unsigned short actual position set given in units.
	 */
    bool setPositionInAbs(unsigned short newPosition);

    /**
	 *
	 *
	 * \brief Delivers the position value (in units) the servo trageted at.
	 *
	 * \return unsigned short.
     *
     * \todo To be implemented
	 *
	 */
	unsigned short getPositionInAbs();

    /**
	 *
	 *
	 * \brief Moves the servo motor to the given position.
	 *
	 *  \param newPosition unsigned short position value given
	 *                     in degree.
	 *
	 *  \return unsigned short actual position set in degree.
     *
     * \todo To be implemented
	 */
    bool setPositionInDeg(short newPosition);
    
	/**
	 *
	 *
	 * \brief Moves the servo motor to the given position.
	 *
	 *  \param newPosition unsigned short position value given
	 *                     in radian.
	 *
	 *  \return unsigned short actual position set in radian
     *
     * \todo To be implemented
	 */
    bool setPositionInRad(float newPosition);

    /**
	 *
	 *  \brief Sets the maximal speed the servo shall move.
	 *
	 *  \param unsigned short newSpeed (the meaning of the values
	 *      has to be specified in the derived class.)
	 *
	 *  \return unsigned short actual speed value set.
     *
     * \todo To be implemented
     *
	 */
    bool setSpeed(unsigned short newSpeed);

    /**
	 *
	 *  \brief Sets the maximal acceleration the servo shall move.
	 *
	 *  \param unsigned short newAcceleration (the meaning of the values
	 *      has to be specified in the derived class.)
	 *
	 *  \return unsigned short actual accelaration value set.
     *
     * \todo To be implemented
	 */
    bool setAcceleration(unsigned short newAcceleration);


    /**
	 *
	 *
	 * \brief  Delivers the position value (in degree) the servo trageted at.
	 *
	 *  \return unsigned short.
     *
     *
     * \todo To be implemented
	 *
	 */
    short getPositioninDeg();

    /**
	 *
	 *
	 * \brief Delivers the position value (in radian) the servo trageted at.
	 *
	 *  \return unsigned short.
     *
    *
     * \todo To be implemented
	 *
	 */
    float getPositioninRad();

    /**
	 *
	 *
	 * \brief
	 *
	 *  Shows which settings have to be made in the Pololu Maestro Control Center for the servo,
	 *  based on the starting position and the delta for the specific servo.
	 *  See Pololu manual for further explainations.
     *
     * 
     * \todo To be implemented
     *
	 */
    void showPololuValues(unsigned short &min, unsigned short &mid, unsigned short &max);
};