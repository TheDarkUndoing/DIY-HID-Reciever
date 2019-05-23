
import serial
import time
port = serial.Serial("/dev/serial0", baudrate=115200,timeout=3.0)


i = input(": ")
c= []

while(True):
        rcv = 0
        print(i)
        for char in i:
                c.append(ord(char))
        c_size = len(c)
        if  c_size > 30:
                while len(c) > 0:
                        print(c)
                        port.write(c[:32])
                        c = c[31:]
                        print(c)
        else:
                port.write(c)
        port.write([10])
        rcv = port.read(c_size)
        print("recieved: ",rcv)
        c = []
        i = input(": ")


