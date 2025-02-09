#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>
ros::Publisher vel_pub;
int cnt;
void LidarCallBack(const sensor_msgs::LaserScan msg)
{
    float fMidDist=msg.ranges[180];
    ROS_INFO("前方测距range[180]=%f米",fMidDist);
    geometry_msgs::Twist vel_cmd;
    if(cnt>0)
    {
        cnt--;
        return;
    }
    if(fMidDist<1.5)
        vel_cmd.angular.z=0.3,cnt=50;
    else
        vel_cmd.linear.x=0.1;
    vel_pub.publish(vel_cmd);
}
int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"lidar_node");
    ros::NodeHandle n;
    ros::Subscriber lidar_sub=n.subscribe("/scan",10,&LidarCallBack);
    
    vel_pub=n.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    ros::spin();
    return 0;
}