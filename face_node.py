#!/usr/bin/env python3
#coding=utf-8
import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge,CvBridgeError
def Cam_RGB_Callback(msg):
    bridge=CvBridge() 
    cv_image=bridge.imgmsg_to_cv2(msg,"bgr8")
    gray_image=cv2.cvtColor(cv_image,cv2.COLOR_BGR2GRAY)
    face_casecade = cv2.CascadeClassifier('/home/ch/catkin_ws/src/wpb_home/wpb_home_python/config/haarcascade_frontalface_alt.xml')
    face=face_casecade.detectMultiScale(gray_image,1.3,5)
    for (x,y,w,h) in face:
        cv2.rectangle(cv_image,(x,y),(x+w,y+h),(0,0,255),3)
    cv2.imshow("face window",cv_image)
    cv2.waitKey(1)
if __name__=="__main__":
    rospy.init_node("face_node")
    rgb_sub=rospy.Subscriber("/kinect2/qhd/image_color_rect",Image,Cam_RGB_Callback,queue_size=1)
    rospy.spin()