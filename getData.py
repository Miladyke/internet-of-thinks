#script python
import serial
import time
import os

arduino_port = 'comx'
band_rate = 9600
ser = serial.Serial(arduino_port,band_rate, timeout=1)
time.sleep(2)
while True
  data=ser.readline().decode('utf-8').rstrip()
  if data:
      humidity,temperature=data.split(",")
      print(f"humedad:{humidity}%, Tempertura: {temperature}°C")
  time.sleep(1)
  #rstrip: elimina espacios en blanco
  #Timeout

  