/*
zuzyk arduino + ros
*/
#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Int16.h>



std_msgs::Int16 data1;
std_msgs::Int16 data2;
std_msgs::Int16 data3;


ros::NodeHandle nh;

ros::Publisher fire_p("fire", &data1);
ros::Publisher light_p("light", &data2);
ros::Publisher magnet_p("magnet", &data3);

void setup() {
  
  
  nh.initNode();
  nh.advertise(fire_p);
  nh.advertise(light_p);
  nh.advertise(magnet_p);

}


void loop() {
  int f = analogRead(A2);
  int l = analogRead(A2);
  int m = analogRead(A0);

  data1.data = f;
  data2.data = l;
  data3.data = m;

  fire_p.publish( &data1);
  light_p.publish( &data2);
  magnet_p.publish( &data3);

  nh.spinOnce();
  delay(2000);

}


