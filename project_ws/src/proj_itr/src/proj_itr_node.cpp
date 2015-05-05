#include "ros/ros.h"
#include "ar_pose/ARMarker.h"
#include "std_msgs/Empty.h"
#include "geometry_msgs/Twist.h"
#include <dynamic_reconfigure/server.h>
#include <proj_itr/dynparamConfig.h>
#include <time.h>

bool bTakeOff=false,bLand=false;

float e,ex,ey,ez,x,y,z,xd,yd,zd;
int i=0;

void callback(proj_itr::dynparamConfig &config, uint32_t level) {

bTakeOff=config.takeOff;

config.takeOff=false;
bLand=config.landing;

config.landing=false;
}


void chatterCallback(const ar_pose::ARMarker ar_pose_marker)
{
 //ar_pose::ARMarker ar_pose_marker;


 
      x=ar_pose_marker.pose.pose.position.x;
	 y=ar_pose_marker.pose.pose.position.y;
 z=ar_pose_marker.pose.pose.position.z;
//printf("%f %f %f \n", x,y,z);



}

int main(int argc, char **argv)
{
 //usleep(5000000);
  ros::init(argc, argv, "proj_itr_node");
  ros::NodeHandle n;
std_msgs::Empty launch;
std_msgs::Empty landing;

  ros::Subscriber pose_sub_ = n.subscribe("ar_pose_marker", 1, chatterCallback); 

 ros::Publisher vel = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);




  ros::Rate loop_rate(20);
dynamic_reconfigure::Server<proj_itr::dynparamConfig> server;
dynamic_reconfigure::Server<proj_itr::dynparamConfig>::CallbackType f;
f = boost::bind(&callback, _1, _2);
server.setCallback(f);
    
     
     
              
while (ros::ok())
{

   ros::Publisher takeOff_pub = n.advertise<std_msgs::Empty>("ardrone/takeoff", 100,true);
ros::Publisher land_pub = n.advertise<std_msgs::Empty>("ardrone/land", 100,true);


if(bLand==true)
{
ROS_INFO("Reconfigure Request Land"); 
land_pub.publish(landing);
usleep(500000);
ROS_INFO("Reconfigure Request LandOk");
bLand=false;
}
else if(bTakeOff==true)
{
ROS_INFO("Reconfigure Request TakeOff");
takeOff_pub.publish(launch); 
 usleep(500000);
ROS_INFO("Reconfigure Request TakeOffOk");
bTakeOff=false;
}

geometry_msgs::Twist veloc;
/*
   if (z<1){
	veloc.linear.z=.01;
   }
   else{
   if (z>1){
	veloc.linear.z=-.01;
	}
    else{
	veloc.linear.z=0;
}   
}
   if (x<0){
	veloc.linear.x=-.01;
   }
   else{
   if (x>0){
	veloc.linear.x=.01;
	}
    else{
	veloc.linear.x=0;
}   
}
   if (y<0){
	veloc.linear.y=-.01;
   }
   else{
   if (y>0){
	veloc.linear.y=.01;
	}
    else{
	veloc.linear.y=0;
}   
}*/

vel.publish(veloc);
   ros::spinOnce();
      loop_rate.sleep();
}  
  return 0;

}
