import serial
import time
port = serial.Serial("/dev/serial0", baudrate=115200,timeout=3.0)
file =  open("text.txt","r+")

i = input(": ")
while True:
    if i == "send":
        for line in  file:
             if len(line) > 63:
                 elem = 60
                 line = [line[i * elem:(i + 1)* elem] for i in range((len(line)+ elem - 1) // elem)]
                 for sl in line:
                     sl = ''.join(sl)
                     port.write(sl.encode('UTF-8'))
                     time.sleep(.5)
             else:
                 port.write(line.encode('UTF-8'))
            # time.sleep(.2)
             rcv = port.read(len(line))
             print("Digispark: ","SIZE: ",len(rcv),rcv)
             print("Line: SIZE: ",len(line),line)
    if len(i) > 300:
        block = i
        while len(block) > 0:
             port.write(block[:32].encode('ascii'))
            # rcv = port.read(len(block))
            # print("Digispark: ","SIZE: ",len(rcv),rcv)
             time.sleep(1/2)
             block = block[32:]

    else:
       msg = i.encode('ascii')+"\n".encode('ascii')
       port.write(msg)
       rcv = port.read(len(msg))
       print("Digispark: ","SIZE: ",len(rcv),rcv)
       chk = "b'%s\\n'"%(i)
       print(chk)
       print(rcv)
      # time.sleep(1)
       if chk  == str(rcv):
            port.write([6])
            print("Sent ACK")

       else:
            print("ERROR")
   # time.sleep(.1)

    i = input(": ")
