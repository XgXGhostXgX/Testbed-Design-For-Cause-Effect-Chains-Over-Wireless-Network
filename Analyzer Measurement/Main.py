import os

#Variables
s_list = []
c_list = []
u_list = []
fin_list=[]

period1 = 0
exec1 = 0

server = "server.txt"
client = "client.txt"
unit = "Unit.txt"

#Main
#First Subfolder
for z in range(0,5):
 for y in range(0,11):
  os.chdir(r"C:\Users\D-Flow\Desktop\BA\Analyzer Measurement")
  os.chdir("Measurment")
  files = os.listdir()

#Second Subfolder (Percentage)
  print("z: ",z)
  os.chdir(files[z])
  percentage = os.listdir()

#Third Subfolder (Seed)
  print("y: ",y)
  os.chdir(percentage[y])
  seed = os.listdir()

#Read File Server
  with open(server) as s:
   for x in range(0,50):
    line = s.readline()
    s_list.append(int(line))
   s.close()

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
   if(s_list[x] != 0):
    if(i==1):
     fin_list.append(2*period1+s_list[x]+c_list[flag])
     i = 0
    else:  
     fin_list.append(2*period1+s_list[x]+c_list[x])
   else:
    if(i ==0):
     flag = x
     i = 1 

  print("===")
  for f in c_list:
   print(f)
  print("===")

  s_list = []
  c_list = []
  u_list = []

#Write File
  #with open('Measurement.txt','w') as w1: 
   #for f in fin_list:
   # w1.write(str(f)+'\n')
  #w1.close()
  fin_list = []   