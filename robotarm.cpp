#include "NetworkSerial.hpp"
#include "SerialCom.hpp"
#include <unistd.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "servomanipulator");
    Pololu conn("/dev/ttyACM0",9600);
    conn.openConnection();
    conn.getErrors();
    NetworkSerial Servo1 = NetworkSerial(0, 7500, 1500, &conn);

    while (ros :: ok)
    {
        ros::spinOnce();
    }
}