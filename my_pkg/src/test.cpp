#include <ros/ros.h>
#include "std_msgs/String.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){

    ros::init(argc,argv,"test_node");
    ros::NodeHandle nh;

    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);
    int count = 0;

    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "Hello Listener " + std::to_string(count);
        
        chatter_pub.publish(msg);

        count++;

        ros::spinOnce();
        loop_rate.sleep();
    }
    

    //cout<<"Hello ROS!" << endl;

    return 0;
}