#!/usr/bin/env python
import time
import rospy
from std_msgs.msg import String
import sys, select, termios, tty

def talker():
    pub = rospy.Publisher('signal', String, queue_size=1)
    rospy.init_node('arduino_ros', anonymous=True)
    rate = rospy.Rate(1) 
    ol = termios.tcgetattr(sys.stdin)
    tty.setcbreak(sys.stdin.fileno())
    while not rospy.is_shutdown():
	
	if select.select([sys.stdin], [],[],0)[0] == [sys.stdin]:
           s = sys.stdin.read(1)
           
           pub.publish(s)
           
        rate.sleep()
        pub.publish('1')

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        passw
