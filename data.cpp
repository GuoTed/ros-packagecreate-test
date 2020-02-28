#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/data.h"
#include "beginner_tutorials/info.h"

#include <sstream>

int main(int argc, char **argv){
	ros::init(argc, argv, "data");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<beginner_tutorials::data>("data", 1000);

  	ros::Rate loop_rate(10);
  	int count = 1;
	  while (ros::ok())
	  {
	    beginner_tutorials::data msg;

	    msg.ID = count;
	    msg.height = 180.0;
	    msg.weight = 50.0;

	    ROS_INFO("ID : [%d]", msg.ID);
	    ROS_INFO("height : [%f]", msg.height);
	    ROS_INFO("weight : [%f]", msg.weight);

	    pub.publish(msg);

	    ros::spinOnce();

	    loop_rate.sleep();
	    ++count;
	  }


  return 0;

}