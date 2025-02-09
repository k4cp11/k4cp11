#include<ros/ros.h>
#include<std_msgs/String.h>
int main(int argc,char *argv[])
{
    ros::init(argc,argv,"yao_node");
    printf("我不管，我最帅");
    ros::NodeHandle nh;
    ros::Rate loop_rate(10);
    ros::Publisher pub=nh.advertise<std_msgs::String>("gie_gie_dai_fei",10);
    while(ros::ok())
    {
        printf("我要开始刷屏了\n");
        std_msgs::String msg;
        msg.data="gg带我飞";
        pub.publish(msg);
        loop_rate.sleep();
    }
    
    return 0;
}