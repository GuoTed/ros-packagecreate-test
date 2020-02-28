#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

void OdomCallBack(const nav_msgs::Odometry::ConstPtr& msg){
	double x = msg->pose.pose.position.x;
	double y = msg->pose.pose.position.y;
	ROS_INFO("hello");
	ROS_INFO("x: %f, y: %f",x,y);
	ROS_INFO("hi");
}

int main(int argc, char** argv){
	ros::init(argc,argv,"beginner_tutorials");
	ros::NodeHandle nh;
	ROS_INFO("1");
	ros::Subscriber sub = nh.subscribe("odom",10,OdomCallBack);
	ROS_INFO("2");
	ros::spin();
	return 0;
}
