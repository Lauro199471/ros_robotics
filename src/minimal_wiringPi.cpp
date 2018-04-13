
#include<ros/ros.h>   // Include ROS Library
#include <wiringPi.h> // Include wiringPi Library
#include <iostream>

using namespace std;

int main(int argc, char **argv) 
{ 
  ros::init(argc,argv,"minimal_wiringPi"); //name this node
  // when this compiled code is run, ROS will recognize it as a node called "minimal_wiringPi"

  ros::NodeHandle n; // need this to establish communications with our new node 

  cout << "Raspberry Pi wiringPi test program\n";
  wiringPiSetupGpio(); // Initalize Pi

  pinMode(18,PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);
  pwmSetRange(2000);
  pwmSetClock(192);

  pwmWrite(18,150);
  delay(10000);
  pwmWrite(18,200);

  return 0; // should never get here, unless roscore dies 
} 
