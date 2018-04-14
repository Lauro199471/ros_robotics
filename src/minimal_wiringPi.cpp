
#include<ros/ros.h>   // Include ROS Library
#include <wiringPi.h> // Include wiringPi Library
#include <iostream>

using namespace std;

int main(int argc, char **argv) 
{ 
  int i = 0;
  
  ros::init(argc,argv,"minimal_wiringPi"); //name this node
  // when this compiled code is run, ROS will recognize it as a node called "minimal_wiringPi"

  ros::NodeHandle n; // need this to establish communications with our new node 

  cout << "Raspberry Pi wiringPi test program\n";
  wiringPiSetupGpio(); // Initalize Pi

  pinMode(18,PWM_OUTPUT);
  pwmSetMode(PWM_MODE_BAL);
  pwmSetRange(1024);
  pwmSetClock(32);

  while(ros::ok())
  {
	pwmWrite(18,i);
	delay(2);
	i = (i + 1) % 1024;
  }

 
  cout << "Finished" << endl;
  return 0; // should never get here, unless roscore dies 
} 
