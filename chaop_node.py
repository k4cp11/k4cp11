#!/usr/bin/env python3
#coding=utf-8
import rospy
from std_msgs.msg import String
from qq_msgs.msg import Carry
if __name__=="__main__":
    rospy.init_node("chaop_node")
    rospy.logwarn("p我的枪去而复返，你的生命有去无回")
    pub=rospy.Publisher("pksckhq",Carry,queue_size=10)

    rate=rospy.Rate(10)
    
    while not rospy.is_shutdown():
        rospy.loginfo("p我要开始刷屏了")
        msg=Carry()
        msg.grade="王者"
        msg.star=50
        msg.data="p果脯马超，带飞"
        pub.publish(msg)
        rate.sleep()

