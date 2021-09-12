import os

#Variables
s_list = []
c_list = []
e_list = []
e3_list = []
u_list = []
temp_list = []
temp1_list = []
fin_list=[]

period1 = 0
exec1 = 0

server = "server.txt"
ecu2 = "ecu2.txt"
ecu3 = "ecu3.txt"
client = "client.txt"
unit = "Unit.txt"

#Main
#First Subfolder
for z in range(0,5):
 for y in range(0,11):
  os.chdir(r"C:\Users\D-Flow\Desktop\BA\Analyzer Measurement")
  os.chdir("Measurment3")
  files = os.listdir()

#Second Subfolder (Percentage)
  print("z: ",files[z])
  os.chdir(files[z])
  percentage = os.listdir()

#Third Subfolder (Seed)
  print("y: ",percentage[y])
  os.chdir(percentage[y])
  seed = os.listdir()

#Read File Server
  with open(server) as s:
   for x in range(0,50):
    line = s.readline()
    if(line != ''):
     s_list.append(int(line))
   s.close()

#Read File ECU2
  with open(ecu2) as e:
   for x in range(0,50):
    line = e.readline()
    e_list.append(int(line))
   e.close()

#Read File ECU3
  with open(ecu3) as e2:
   for x in range(0,50):
    line = e2.readline()
    if(line != ''):
     e3_list.append(int(line))
   e2.close()

#Read File Client
  with open(client) as c:
   for x in range(0,50):
    line = c.readline()
    c_list.append(int(line))
   c.close()

#Read File Unit
  with open(unit) as u:
   u.readline()
   line = u.readline()
   line = u.readline()
   line = u.read(3)
   line = u.readline() 
   period1 = int(line)
   line = u.readline()
   line = u.readline()
   line = u.read(3)
   line = u.readline() 
   exec1 = int(line)
   #print(period1)
   #print(exec1)

  i = 1
  flag = 0
  for x in range(0,50):
   if(e_list[x] != 0):
    if(i==1):
     temp_list.append(2*period1+e_list[x]+c_list[flag])
     i = 0
    else:  
     temp_list.append(2*period1+e_list[x]+c_list[x])
   else:
    if(i ==0):
     flag = x
     i = 1 

  i = 1
  flag = 0
  for x in range(0,len(temp_list)):
   if(e3_list[x] != 0):
    if(i==1):
     temp1_list.append(period1+e3_list[x]+temp_list[flag])
     i = 0
    else:
     temp1_list.append(period1+e3_list[x]+temp_list[x])
   else:
    if(i ==0):
     flag = x
     i = 1

  if(z==0 and y ==3):
   print("temp")
   for x in temp_list:
    print(x)
   print("===") 
   print("temp1")
   for x in temp1_list:
    print(x)
   print("===")

  i = 1
  flag = 0
  for x in range(0,len(s_list)):
   if(s_list[x] != 0):
    if(i==1):
     fin_list.append(period1+s_list[x]+temp1_list[flag])
     i = 0
    else:
     fin_list.append(period1+s_list[x]+temp1_list[x])
   else:
    if(i ==0):
     flag = x
     i = 1 

  print("===")
  for f in fin_list:
   print(f)
  print("===")

  s_list = []
  c_list = []
  e_list = []
  e3_list = []
  u_list = []
  temp_list = []
  temp1_list = []

  fin_list.sort()

#Write File
  with open('Measurement.txt','w') as w1: 
   for f in fin_list:
    w1.write(str(f)+'\n')
   w1.close()
  fin_list = []   