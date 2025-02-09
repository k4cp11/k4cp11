#include<ros/ros.h>
#include<cv_bridge/cv_bridge.h>
#include<sensor_msgs/image_encodings.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/objdetect/objdetect.hpp>
using namespace cv;
using namespace std;
static CascadeClassifier face_cascade;
static Mat frame_gray;
static vector<Rect> faces;
static vector<Rect>::const_iterator face_iter;
void callbackRGB(const sensor_msgs::Image msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
        cv_ptr=cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::BGR8);
    }
    catch(cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception:%s",e.what());
        return;
    }
    Mat imgOriginal=cv_ptr->image;
    cvtColor(imgOriginal,frame_gray,COLOR_BGR2GRAY);
    equalizeHist(frame_gray,frame_gray);
    face_cascade.detectMultiScale(frame_gray,faces,1.1,9,0|CASCADE_SCALE_IMAGE,Size(30,30));
    if(faces.size()>0)
    {
        for(face_iter=faces.begin();face_iter!=faces.end();++face_iter)
        {
            rectangle(
                imgOriginal,
                Point(face_iter->x,face_iter->y),
                Point(face_iter->x+face_iter->width,face_iter->y+face_iter->height),
                CV_RGB(255,0,255),
                2
            );
        }
    }
    imshow("faces",imgOriginal);
    cv::waitKey(1);
}
int main(int argc,char *argv[])
{
    ros::init(argc,argv,"cv_face_detect");
    namedWindow("faces");

    std::string strLoadFile ;
    char const*home=getenv("HOME");
    strLoadFile=home;
    strLoadFile+="/catkin_ws";
    strLoadFile+="/src/wpr_simulation/config/haarcascade_frontalface_alt.xml";
    bool res=face_cascade.load(strLoadFile);
    if(res==false)
    {
        ROS_ERROR("fail to load haarcascade_frontalface_alt.xml");
        return 0;
    }
    ros::NodeHandle nh;
    ros::Subscriber rgb_sub=nh.subscribe("kinect2/qhd/image_color_rect",1,callbackRGB);
    ros::spin();
    return 0;
}