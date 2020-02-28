#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
from beginner_tutorials.msg import data

def talker():
    pub = rospy.Publisher('data', data, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz

    msg = data()

    count = 1

    while not rospy.is_shutdown():
        #hello_str = "hello world %s" % rospy.get_time()
        msg.ID = count
        msg.height = 180.0
        msg.weight = 50.0
        rospy.loginfo(msg.ID)
        pub.publish(msg)
        rate.sleep()
        count = count +1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass