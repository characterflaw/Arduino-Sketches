import os, serial
from time import sleep

port = '/dev/cu.usbmodem145401'  # Mega 2560 & UNO
# port = '/dev/cu.usbserial-14530'  # Nano
baudrate = 9600
timeout = 3
payload = 'dispense'

# WAIT to give Serial interface a moment to start
# 1 for Mega
# 2 for Uno or Nano 
sleep(1)

def send_string(msg):
	with serial.Serial(port, baudrate, timeout=timeout) as ser:
		os.system('clear') # clears the screen
		sleep(2)
		ser.write(msg.encode())

		sleep(2)

		# await_ack
		response = ser.readline()
		response = response.decode('utf-8').replace('\r\n', '')

		if response == 'ACK':
			return True;
		else:
			return False


if send_string(payload):
	print('Message Received!')
else:
	print('no response')
