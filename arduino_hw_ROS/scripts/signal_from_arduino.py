#!/usr/bin/env python
import rospy
import rosbag
import time
from std_msgs.msg import Int16


bag = rosbag.Bag('/home/zuzyk-u16/catkin_ws/src/arduino_hw_ROS/bag/test.bag', 'w')


class SFA:


   def __init__(self):
      pass


   def callback_f(self, data):
      bag.write("fire", data)
      print("fier sensor data [{}]\n".format(data.data))
         
   def callback_l(self, data):
      bag.write("light", data)
      print("light sensor data [{}]\n".format(data.data))

   def callback_m(self, data):
      bag.write("magnet", data)
      print("magnet sensor data [{}]\n".format(data.data))

   def listener(self):
      rospy.init_node('listener', anonymous=True)
      rospy.Subscriber("fire", Int16, self.callback_f)
      rospy.Subscriber("light", Int16, self.callback_l)
      rospy.Subscriber("magnet", Int16, self.callback_m)
     
      rospy.spin()

if __name__ == '__main__':
    s = SFA()
    s.listener()
    bag.close()


    

