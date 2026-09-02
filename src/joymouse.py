import serial
import pyautogui
import time 

pyautogui.FAILSAFE=False
ArduinoSerial = serial.Serial('com6',115200)
time.sleep(1)
button_was_pressed = False
while 1:
    data=str(ArduinoSerial.readline().decode('ascii'))
    (x,y,z)=data.split(":")
    (X,Y)=pyautogui.position()  
    (x,y)=(int(x),int(y))
    pyautogui.moveTo(X+x,Y+y)
    button_is_pressed = z.strip() == "1"
    if button_is_pressed and not button_was_pressed:
        pyautogui.click(button="middle")
    button_was_pressed = button_is_pressed