#include "ros/ros.h"
#include "beginner_tutorials/data.h"
#include "beginner_tutorials/info.h"

void chatterCallback(const beginner_tutorials::info::ConstPtr& msg)
{
  ROS_INFO("BMI_ID : [%d]", msg->ID);
  ROS_INFO("BMI : [%f]", msg->BMI);
  //pub->publish(ID); 
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "result");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("BMI_ID", 1000, chatterCallback); /*chatter->*/
	ros::spin();

	return 0;
}