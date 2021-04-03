# MEXRemoteControl

Ros Package that implements the MEX Api to Ros. 
The Goal is, to get the ability to control the MEX over Networks and Distance.



## Getting Started

 1. Install Ros Melodic on Ubuntu 18.04 LTS [Installation Guide](http://wiki.ros.org/melodic/Installation/Ubuntu)
 2. Compile sourcecode: `cd catkin_ws && catkin_make`
 3. Start Ros master `roscore`
 4. Open new Terminal and start robotarm service `rosrun MEXRemoteControl robotarm.cpp`
 5. Open new Terminal and start robotarm service `rosrun MEXRemoteControl remote.cpp`
## Open Issues

### 1 Serial Connection
The Serial connection is not working. After sending one command successfull, the Polulu doesn't react on following commands.
