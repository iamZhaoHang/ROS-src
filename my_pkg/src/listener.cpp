#include <ros/ros.h>
#include "std_msgs/String.h"
#include <iostream>

using namespace std;

void chatterCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv){

    ros::init(argc,argv,"lis_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);

    ros::spin();

    //cout<<"Hello ROS!" << endl;

    return 0;
}