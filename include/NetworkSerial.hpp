#ifndef NetworkSerialH
#define NetworkSerialH

#include "ServoMotor.hpp"
#include "ros/ros.h"
#include "ros/time.h"
#include "MEXRemoteControl/servomsg.h"
#include "MEXRemoteControl/servorsp.h"

/**
 *
 * \class NetworkSerial
 *
 * \brief Class that connects between Ros
 * and the Polulu Serial interface
 * 
 *
 * This class is compatible with the NetworkServoMotor
 * class. ROS is needed.
 *
 *
 */
class NetworkSerial : public ServoMotor
{
private:
    /**
	 *
	 * \var publishpos_
	 *
	 * \brief Object of a ROS publisher
     * Publishes Position updates to ROS 
     *
	 */
    ros::Publisher publishpos_;

    /**
	 *
	 * \var subsservpos_
	 *
	 * \brief Object of a ROS subscriber
     * Subscribes Position updates from ROS 
     *
	 */
    ros::Subscriber subsservpos_;
    
    /**
	 *
	 * \var n_
	 *
	 * \brief Ros NodeHandle that is needed
     * for communication with ROS 
     *
	 */
    ros::NodeHandle n_;

  
public:

    /**
	 *
	 *
	 * \brief  Is called when subscriber gets a new Message object.
     * Is used to react on Messages.
     * Moves Robotarm based on Input.
	 *
	 *  \return void.
	 *
	 * \todo Function is implemented for absolut messages, but isnt working, due to a bug with the serial connection.
	 * It has to be clarified if this is a code bug, a permission error, or where the Problem comes from.
	 * Successfull tested was: The handing over to parent classes, using api without ros.
	 * To be clarified: Is the error depending on catkin_make? 
	 *
	 */
    void callback(const MEXRemoteControl::servomsg& msg);
    
    /**
	 *
	 *
	 * \brief  Should be called in a loop to continously poll for 
     * ROS Messages
	 *
	 *  \return void.
	 *
	 */
    void poll();

    /**
	 *
	 * \brief Parameterized constructor. In case of an error
	 * 			an exception is thrown.
	 *
	 *	\param servoID unsigned short. Index (>= 0) of the servo motor that
	 * 					identifies which slot / pin on the
	 * 					micro controller board the servo is
	 * 					connected with.
	 *
	 * 	\param neutralPos unsigned short. (neutralPos > 0) Neutral position of the servo,
	 * 					usually defined by an impulse of 1'500 micro seconds
	 * 					impulse length.
	 * 					The position value is usually given by impulse length per
	 * 					one micro seconds. Using the pololu micro-controller to
	 * 					control the servor motor the impulse length is given per
	 * 					units of 1/4 of a quarter of the micro-second.
	 * 					Therefore, position here is defined impulse length per
	 * 					one micro second per 1/4 micro second.
	 * 					Thus, position value = impulse lengths * 4 (units).
	 *					See Pololu manual for further explanations.
	 *
	 *	\param delta unsigned short. (delta < neutralPos) Defines the range of positions values,
	 * 					starting from the neutral positions +/- delta.
	 *
	 *
	 * 	\param *pololuController. Pointer to a pololu instance that controls the servo motors.
     *
     *  \param nodehandle Pointer to a nodehandle
	 */
    NetworkSerial(unsigned short servoID,
										   unsigned short neutralPos,
										   unsigned short delta,
										   IPololu  *pololuController,ros::NodeHandle* nodehandle);// Constructor
    ~NetworkSerial(){}; // Destructor
};
#endif 