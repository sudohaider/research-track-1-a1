#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "assignment1_pkg/Position.h"
#include "assignment1_srv/NewPosition.h"

ros::Publisher pub; 	///< Initializing publisher for linear x and y velocities
ros::Publisher pub2; 	///< Initializing publisher for current and new positions of x and y

ros::ServiceClient client; 	///< initializing service client

float newpos_x; 	///< Initializing float variable for storing new values of position x
float newpos_y; 	///< Initializing float variable for storing new values of position y

/**
 * Determining distance from current position (x,y) to new position (new_x,new_y)
 */
float distanceFormula(float x, float y, float new_x, float new_y)
{
  return sqrt(pow(new_x - x, 2) + pow(new_y - y, 2));
}

/**
 * Callback function for subscribing to topic /odom. 
 * Initializes and calls service to acquire values of new position within specified range,
 * requests for new positions when robot reaches the destination,
 * or sets the values of linear x and y velocities, and
 * publishes message with values of x, y, new_x, new_y.
 */
void positionCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  ROS_INFO("Robot position [%f, %f]", msg->pose.pose.position.x, msg->pose.pose.position.y);

  assignment1_srv::NewPosition newpos;	

  newpos.request.min=-6.0; 
  newpos.request.max=6.0;

  client.call(newpos);

  if (distanceFormula(msg->pose.pose.position.x, msg->pose.pose.position.y, newpos_x, newpos_y) < 0.1)
  {
    newpos.request.min = -6.0;
    newpos.request.max = 6.0;
    client.call(newpos);
    newpos_x = newpos.response.x;
    newpos_y = newpos.response.y;
  }  

  else
  {

    geometry_msgs::Twist vel;

    int k = 1;
    vel.linear.x = k * (newpos_x - msg->pose.pose.position.x);
    vel.linear.y = k * (newpos_y - msg->pose.pose.position.y);
    pub.publish(vel);
  }

  assignment1_pkg::Position mymsg;
  mymsg.name = "position";
  mymsg.x = msg->pose.pose.position.x;
  mymsg.y = msg->pose.pose.position.y;
  mymsg.new_x = newpos_x;
  mymsg.new_y = newpos_y;
  pub2.publish(mymsg);
}


/**
 * main function to initialize service and node, and advertise on topics.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "assignment1_node");
  ros::NodeHandle n;
  
  client = n.serviceClient<assignment1_srv::NewPosition>("/newpos");

  pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  pub2 = n.advertise<assignment1_pkg::Position>("/assignment1/position", 1000);

  ros::Subscriber sub = n.subscribe("/odom", 1000, positionCallback);

  ros::spin();

  return 0;
}
