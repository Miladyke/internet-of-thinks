#script python
import serial
import time
import os

arduino_port = 'comx'
band_rate = 9600
ser = serial.Serial(arduino_port,band_rate, timeout)