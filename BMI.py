#!/usr/bin/env python
import rospy
from beginner_tutorials.msg import data
from beginner_tutorials.msg import info

def callback(data):
	rospy.loginfo("ID: %d" % (data.ID))
	rospy.loginfo("height: %f" % (data.height))
	rospy.loginfo("weight: %f" % (data.weight))
	msg = info()
	msg.ID = data.ID
	msg.BMI = (data.weight*10000)/(data.height*data.height)
	pub = rospy.Publisher('result', info, queue_size=10)
	pub.publish(msg)
	#rospy.loginfo("%d 's BMI is : %f" % (data.ID, data.BMI))

def listener():
    rospy.init_node('custom_listener', anonymous=True)
    rospy.Subscriber("data", data, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()