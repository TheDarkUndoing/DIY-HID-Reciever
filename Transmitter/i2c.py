from smbus import SMBus
import time


addr = 0x8 # bus address
bus = SMBus(1) # indicates /dev/ic2-1
x = input(": ")
c = list()
while(True):
	print(x)
	for char in x:
		c.append(ord(char))

	if  len(c) > 32:
		while len(c) > 0:
			print(c)
			bus.write_i2c_block_data(addr,0,c[:32])
			c = c[31:]
			print(c)
			time.sleep(1)
	else:
		print(c)
		bus.write_i2c_block_data(addr,0,c)
		c =[]
	x = input(": ")
