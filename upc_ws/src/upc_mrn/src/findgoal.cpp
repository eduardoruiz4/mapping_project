#include <termios.h>
#include <stdio.h>
#include <iostream>
#include <ros/ros.h>
#include <time.h>
#include "sensor_msgs/LaserScan.h"
#include <math.h>
#include <visualization_msgs/Marker.h>

#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <tf/transform_datatypes.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

sensor_msgs::LaserScan current_scan;
bool new_scan;
float xcorner[4]={};   
  float ycorner[4]={};
int j=0;
float xgoal,ygoal;
float dist=0;

int moveRobot(float x, float y, float yaw);

void publishMarker(uint i, const float & x, const float & y,int color=0,int type=0,const float & yaw=0.0);

void getXY(int i,float range,float angle_min,float angle_increment,float & x, float & y)
{
x=range*cos(angle_min+angle_increment*i);
y=range*sin(angle_min+angle_increment*i);
printf("%f %f \n",x,y);
}

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  //ROS_INFO("New LaserScan msg received");
  //Scan msg structure: http://www.ros.org/doc/api/sensor_msgs/html/msg/LaserScan.html
  //ROS_INFO("Scan: number=%d,  angle min=%f rad, angle_max=%f rad, angle_increment=%f rad, ranges.size()=%zu", msg->header.seq, msg->angle_min, msg->angle_max, msg->angle_increment, msg->ranges.size());
  current_scan = *msg;
  new_scan=true;
}

int main(int argc, char** argv)
{
  ROS_INFO("----");
  ROS_INFO("Find Goal Node");
  ros::init(argc, argv, "findgoal");

  // init a node handler
  ros::NodeHandle n;

  // subscribe to laserscan topic
  ros::Subscriber sub = n.subscribe("scan", 1, scanCallback);
  ros::Publisher  pub = n.advertise<visualization_msgs::Marker>("candidate_marker", 50);

  ROS_INFO("----");
  ROS_INFO("Press Ctrl+C to exit the program");
  ROS_INFO("----");
 bool bgoalfind=false; 
  float x[639]={};   // [m]
  float y[639]={};
    // [m]
  float yaw=0.0; // [rad]
  new_scan=false;

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
if(bgoalfind==false){
yaw=0.4; 
moveRobot(0,0,yaw);

}
    if(new_scan)
    {
      new_scan=false;

      //x=0;
      //y=0;
      //yaw=0;

      // \TODO: Decide a goal (x,y,yaw) using scan (current_scan)
      // ...
      // \TODO_END

      //publishMarker(0,x,y,0,1,yaw);
      
    
      ///////////////////////////////////////////
      // Some code usage EXAMPLES
      
       //\EXAMPLE: debugging outputs
   //    ROS_INFO("Information text, showing my yaw value=%f",yaw);
   //    ROS_WARN("Warning text");
   //    ROS_ERROR("Error text");


       // \EXAMPLE: Set goal to 1m forward, after publishing arrow marker
     /*  x=1.0;
       y=0.0;
       yaw=0.0;
       publishMarker(1,x,y,1,1,yaw);
       moveRobot(x,y,yaw);
*/
       // \EXAMPLE: Go through the laser points and, for example, print its ranges
      j=0;
       for(unsigned int i=0;i<current_scan.ranges.size();i++)
       {
     
            if(std::isnan(current_scan.ranges[i])&&(i>1))
		current_scan.ranges[i]=current_scan.ranges[i-1];
            getXY(i,current_scan.ranges[i],current_scan.angle_min,current_scan.angle_increment,x[i],y[i]);
             if(i>1){
              dist=pow((pow((x[i]-x[i-1]),2)+pow((y[i]-y[i-1]),2)),0.5);
		if(dist>0.4){
		       
			xcorner[j]=x[i-1];
			ycorner[j]=y[i-1];
			xcorner[j+1]=x[i];
			ycorner[j+1]=y[i];
			
			  ROS_INFO("j=%d ",j);
		if(j<2){
        	j=j+2;
		}
		else{        
			yaw=0;
xgoal=(xcorner[0]+xcorner[3])/2;
ygoal=(ycorner[0]+ycorner[3])/2; 

ROS_INFO("xc1:%f xc2:%f xc3:%f xc4:%f xgoal:%f",xcorner[0],xcorner[1],xcorner[2],xcorner[3],xgoal);

//moveRobot(xgoal,ygoal,yaw);
float prx,plx,pry,ply,vx,vy,nx,ny,L=0.4;
prx=xcorner[0];
plx=xcorner[3];
pry=ycorner[0];
ply=ycorner[3];
vx=prx-plx;
vy=pry-ply;
nx=-vy/(pow((pow(vx,2)+pow(vy,2)),0.5));
ny=vx/(pow((pow(vx,2)+pow(vy,2)),0.5));
xgoal=xgoal+nx*L;
ygoal=ygoal+ny*L;
publishMarker(1,xgoal,ygoal,1,1,yaw);
moveRobot(xgoal,ygoal,yaw);


bgoalfind=true;

break;
		}	
		}
		}

//
       }

    
      //EXAMPLE: returns true if value is a NaN (not a number)
      // if(std::isnan(current_scan.ranges[0]))
      //   ROS_INFO("value is a NaN");
      // else
       //  ROS_INFO("value is not a NaN");

      // \EXAMPLE: Publish a cylinder marker in the midpoint of the laser scan msg. Needs the getXY function to be filled up and working
       //int midpoint_i = current_scan.ranges.size()/2; %
 
      //moveRobot(x,y,yaw);
      ///////////////////////////////////////////

    }    

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

int moveRobot(float x, float y, float yaw)
{
  ROS_INFO("moveRobot(x=%4.2f,y=%4.2f,yaw=%4.2f)", x,y,yaw);
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

 // ROS_INFO("moveRobot: Do you want to move the robot? (y/n) or (E)xit");
  std::string ss;
  ss='y';
usleep(500000);
 // std::cin >> ss;
  if(ss=="E")
  {
    ROS_INFO("Shutting down.");
    ros::shutdown(); //exit(0);
  }
  else if(ss=="y")
  {
    //wait for the action server to come up
    if(!ac.waitForServer(ros::Duration(5.0)))
    {
      ROS_ERROR("moveRobot: Move base server not connected");
      ros::shutdown();
      return 0;
    }

    //we'll send a goal to the robot
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "camera_depth_frame";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose.position.x = x+0.1; //offset from camera_depth_frame to base_footprint (tf transformation could be used instead)
    goal.target_pose.pose.position.y = y;
    goal.target_pose.pose.position.z = -0.28; //offset from camera_depth_frame to base_footprint (tf transformation could be used instead)

    //Conversion from roll,pitch,yaw to Quaternion, which is how orientations are represented
    tf::quaternionTFToMsg (tf::createQuaternionFromRPY(0.0,0.0,yaw),  goal.target_pose.pose.orientation);

    ROS_INFO("moveRobot: Sending Goal");
    ac.sendGoal(goal);

    int timeout=15;
    if(!ac.waitForResult(ros::Duration(timeout))) //wait timeout seconds
      ROS_WARN("moveRobot: timeout %dsec reached",timeout);
    
    //ROS_INFO("Current State: %s\n", ac.getState().toString().c_str());
    
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
      ROS_INFO("moveRobot: Hooray, the base reached the goal!");
      return 1;
    }
    else
    {
      ROS_WARN("moveRobot: Oops, the base failed to reach the goal for some reason!");
      return 2;
    }
  }
  else
  {
    ROS_INFO("moveRobot: Not sending goal.");
    return 0;
  }
}

void publishMarker(uint i, const float & x, const float & y,int color,int type,const float & yaw)
{
    //ROS_INFO("publishMarker: publishing marker with id = %i, and pose: %f, %f, %f", i, x, y, yaw);
    ros::NodeHandle n;
    ros::Publisher  pub = n.advertise<visualization_msgs::Marker>("candidate_marker", 1);

    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "camera_depth_frame";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "candidates";
    marker.id = i;

    // Set the marker type.
    // Set the scale of the marker
    switch(type)
    {
      default:
      case 0:
        marker.type = visualization_msgs::Marker::CYLINDER;
        marker.scale.x = marker.scale.y = 0.10; marker.scale.z = 0.56;
        marker.pose.position.z = 0.0;
        break;
      case 1:
        marker.type = visualization_msgs::Marker::ARROW;
        marker.scale.x = 0.5; marker.scale.y = marker.scale.z = 0.1;
        marker.pose.position.z = -0.28;
        break;
    }   

    // Set the marker action.  Options are ADD and DELETE
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    //marker.pose.position.z = -0.28; //depending on marker type, set above
    tf::quaternionTFToMsg (tf::createQuaternionFromRPY(0.0,0.0,yaw), marker.pose.orientation);

    // Set the lifetime of the marker
    marker.lifetime = ros::Duration(15);
    
    // Set the color -- be sure to set alpha to something non-zero!
    float r,g,b;
    color=color%7;
    switch(color)
    {
      default:
      case 0: r=0; g=0; b=1; break;
      case 1: r=0; g=1; b=0; break;
      case 2: r=1; g=0; b=0; break;
      case 3: r=1; g=0; b=1; break;
      case 4: r=0; g=1; b=1; break;
      case 5: r=1; g=1; b=0; break;
      case 6: r=0; g=0.5; b=1; break;
    }
    marker.color.r = r;
    marker.color.g = g;
    marker.color.b = b;
    marker.color.a = 1;

    // Publish the marker
    pub.publish(marker);
}
