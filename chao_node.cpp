#include<ros/ros.h>
#include<std_msgs/String.h>
#include<qq_msgs/Carry.h>
int main(int argc,char *argv[])
{
    ros::init(argc,argv,"chao_node");
    printf("我的枪去而复返，你的命有去无回");
    ros::NodeHandle nh;
    ros::Rate loop_rate(10);
    ros::Publisher pub=nh.advertise<qq_msgs::Carry>("ksckhq",10);
    while(ros::ok())
    {
        printf("我要开始刷屏了\n");
        qq_msgs::Carry msg;
        msg.grade="王者";
        msg.star=50;
        msg.data="果脯马超，带飞";
        pub.publish(msg);
        loop_rate.sleep();
    }
    
    return 0;
}