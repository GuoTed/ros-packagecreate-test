#!/usr/bin/env python
import rospy
from beginner_tutorials.msg import data
from beginner_tutorials.msg import info

def callback(data):
	rospy.loginfo("ID: %d" % (data.ID))
	rospy.loginfo("BMI: %f" % (data.BMI))
	
def listener():
    rospy.init_node('result_listener', anonymous=True)
    rospy.Subscriber("result", info, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()