import serial
import mouse, sys
import time 

mouse.FAILSAFE=False
ArduinoSerial = serial.Serial('com6',115200)
time.sleep(1)
button_was_pressed = False
while 1:
    data=str(ArduinoSerial.readline().decode('ascii'))
    (x,y,z)=data.split(":")
    (X,Y)=mouse.get_position()  
    (x,y)=(int(x),int(y))
    mouse.move(X+x,Y+y)
    button_is_pressed = z.strip() == "1"
    if button_is_pressed and not button_was_pressed:
        mouse.click(button="middle")
    button_was_pressed = button_is_pressed