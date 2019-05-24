import serial
from datetime import datetime

device = ''
distance = ''
filename = ''

def write_to_file(self):
    with open(filename, 'a') as opened_file:
        opened_file.write(msg)

#
# collect device and distance information for the filename
#
print('Enter the name of the test device')
device = input()
device = device.strip()
device = device.replace(' ', '-')

# comment the next four lines, if you do not want to embed the distance
# information in the filename
print('Enter the distance you will be testing (example 50cm)')
distance = input()
distance = distance.strip()
distance = distance.replace(' ', '')

datestr = datetime.now().strftime('%Y-%m-%d-%H:%M')

filename = device
if distance != '':
  filename += '_' + distance
filename += '_' + datestr
filename += '.txt'

# print out the filename
print('Filename: ' + filename)

ser = serial.Serial('COM5', 9600)
while True:
    response = ser.readline()
    response = response.decode('utf-8').replace('\r\n', '')
    msg = datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3] + ', ' +response + '\n'
    if response != '':
        write_to_file(msg)
