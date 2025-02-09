#!/usr/bin/env python3
#coding=utf-8
import rospy
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion
from geometry_msgs.msg import Twist
import math
def ImuCallback(msg):
    if msg.orientation_covariance[0]<0:
        return
    quaternion =[
        msg.orientation.x,
        msg.orientation.y,
        msg.orientation.z,
        msg.orientation.w
    ]
    (roll,pitch,yaw)=euler_from_quaternion(quaternion)
    roll=roll*180/math.pi
    pitch=pitch*180/math.pi
    yaw=yaw*180/math.pi
    target_yaw=90
    diff_angle= target_yaw-yaw
    vel_cmd=Twist()
    vel_cmd.angular.z=0.01*diff_angle
    vel_cmd.linear.x=0.1
    global vel_pub
    vel_pub.publish(vel_cmd)
    rospy.loginfo("滚转=%.0f 俯仰=%.0f 朝向=%.0f ",roll,pitch,yaw)
if __name__=="__main__":
    rospy.init_node("imu_node")
    imu_sub=rospy.Subscriber("/imu/data",Imu,ImuCallback,queue_size=10)
    vel_pub=rospy.Publisher("/cmd_vel",Twist,queue_size=10)
    rospy.spin()
