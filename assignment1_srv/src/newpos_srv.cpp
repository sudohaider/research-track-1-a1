#include "ros/ros.h"
#include "assignment1_srv/NewPosition.h"

/**
 * random number generation with the specified range as arguments
 */
double randMToN(double M, double N)
{     return M + (rand() / ( RAND_MAX / (N-M) ) ) ; }

/**
 * passing random x and y values to Response pointer 
 */
bool myrandom (assignment1_srv::NewPosition::Request &req, assignment1_srv::NewPosition::Response &res){
    res.x = randMToN(req.min, req.max);
    res.y = randMToN(req.min, req.max);
    return true;
}

/**
 * main function to initialize service and node, and advertising data on topic /newpos.
 */
int main(int argc, char **argv)
{
   ros::init(argc, argv, "newpos_srv");
   ros::NodeHandle n;
   ros::ServiceServer service= n.advertiseService("/newpos", myrandom);
   ros::spin();

   return 0;
}
