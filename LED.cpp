#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;

void messageCb(const std_msgs::Empty &toggle_msg)
{
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb);

void setup()
{
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}