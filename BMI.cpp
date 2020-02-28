#include "ros/ros.h"
#include "beginner_tutorials/data.h"
#include "beginner_tutorials/info.h"


ros::Publisher *pub;

void chatterCallback(const beginner_tutorials::data::ConstPtr& msg)
{
  beginner_tutorials::info INFO;
  INFO.ID = msg->ID;
  INFO.BMI = (msg->weight)*10000/(msg->height*msg->height);

  ROS_INFO("ID : [%d]", INFO.ID);
  ROS_INFO("BMI : [%f]", INFO.BMI);
  pub->publish(INFO);
  
  
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "BMI");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("data", 1000, chatterCallback);

	pub = new ros::Publisher(n.advertise<beginner_tutorials::info>("BMI_ID", 1000));

	//std_msgs::Float64 BMI;
	//BMI.data = Weight.data/(Height.data);


	
	//ros::Publisher BMI_pub = n.advertise<std_msgs::Float64>("BMI", 1000);
	//BMI_pub.publish(BMI);

	ros::spin();

	return 0;
}