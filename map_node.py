#!/usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String
from qq_msgs.msg import Carry
def chaop_callback(msg):
    rospy.logwarn(msg.grade)
    rospy.logwarn(str(msg.star)+"星")
    rospy.loginfo(msg.data)
def yaop_callback(msg):
    rospy.logwarn(msg.data)
if __name__=="__main__":
    rospy.init_node("map_node")
    sub=rospy.Subscriber("pksckhq",Carry,chaop_callback,queue_size=10)
    sub_2=rospy.Subscriber("pgie_gie_dai_fei",String,yaop_callback,queue_size=10)
    rospy.spin()