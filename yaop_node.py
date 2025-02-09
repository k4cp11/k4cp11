#!/usr/bin/env python3
#coding=utf-8
import rospy
from std_msgs.msg import String

if __name__=="__main__":
    rospy.init_node("yaop_node")
    rospy.logwarn("p未来生于过去")
    pub=rospy.Publisher("pgie_gie_dai_fei",String,queue_size=10)

    rate=rospy.Rate(10)
    
    while not rospy.is_shutdown():
        rospy.loginfo("p我要开始刷屏了")
        msg=String()
        msg.data="p大哥带我飞"
        pub.publish(msg)
        rate.sleep()

