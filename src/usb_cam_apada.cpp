// This gets data from Camera and sends data
// via ROS Topics

// @topic : /image_raw_apada

#include <ros/ros.h>

#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>

#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

#include <image_transport/image_transport.h>

#define usb_cam 0

void usbCameraDriver_apada(void)
{
  //cv::VideoCapture input_video;
  cv::Mat frame;

  // ROS <-> OpenCV
  cv_bridge::CvImage cvi;
  image_transport::ImageTransport *it;
  image_transport::Publisher pub;
  ros::NodeHandle n("~");

  // Setup ROS Message
  cvi.header.frame_id = "image"; // FrameID for OpenCV
  cvi.encoding = sensor_msgs::image_encodings::BGR8; // Type

  it = new image_transport::ImageTransport(n); // setup publisher
  pub = it->advertise("/image_raw_apada" , 2); // name of topic and queue size (change according to data bandwidth)

  // OpenCV Init
  cv::VideoCapture input_video(usb_cam); // Open Camera

  if(input_video.isOpened() == false)
  {
    ROS_ERROR("Couldnt open camera");
    ros::shutdown();
  }

  ros::Rate looprate = 30;

  while(ros::ok())
  {
    input_video.read(frame); // Read Frame
    cvi.image = frame; // pack image for ROS MSG
    cvi.header.stamp = ros::Time::now(); // pack Timestamp for ROS MSG
    pub.publish(cvi.toImageMsg()); // Publish ROS MSG
    looprate.sleep();
  }

  input_video.release();
}


int main(int argc, char **argv)
{
   ros::init(argc, argv, "usb_cam_apada");


  std::cout << "Hello World" << std::endl;
  usbCameraDriver_apada();


  return EXIT_SUCCESS;
}
