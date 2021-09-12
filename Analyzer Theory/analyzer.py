import os
import math

period = []
execution = []
reaction = []
mreaction = 0
mreaction2 = 0

#worstcase respond time
def wcrt():
 reaction.append(execution[0])
  
 c = execution[1] 
 r = c
 while True:
  i =0
  i = i+execution[0]*math.ceil(reaction[0]/period[0])
  print("i",i)
  if r < i+c:
   r = i+c 
   print("r",r)
  else: 
   reaction.append(r)
   break

 reaction.append(execution[0])

 c = execution[1] 
 r = c
 while True:
  i =0
  i = i+execution[0]*math.ceil(reaction[0]/period[0])
  if r < i+c:
   r = i+c 
  else: 
   reaction.append(r)
   break 

 print(reaction[0])
 print(reaction[1])
# print(reaction[2])
# print(reaction[3])

#maximum reaction time
def mrt(case):
 value = period[0]+reaction[1]
 value += max(reaction[0],period[1]+reaction[0]*0)+max(reaction[1],period[0]+reaction[1]*1)+max(reaction[0],period[1]+reaction[0]*0)
 if case >= 2:
  value += max(reaction[1],period[0]+reaction[1]*1)+max(reaction[0],period[1]+reaction[0]*0)
 if case >= 3:
  value += max(reaction[1],period[0]+reaction[1]*1)+max(reaction[0],period[1]+reaction[0]*0)
 return value


for z in range (0,5):
 for y in range (0,11):
  os.chdir(r"C:\Users\D-Flow\Desktop\BA\Analyzer Theory")
  files = os.listdir()
  os.chdir(files[z])
  files2 = os.listdir()
  os.chdir(files2[y])
  print(os.listdir())
 
  with open('Unit.txt','r') as reader1:
   line = reader1.readline()
   #print(line,end='')
   period.append(int(line))
   line = reader1.readline()
   execution.append(int(line))
   line = reader1.readline()
   period.append(int(line))
   line = reader1.readline()
   execution.append(int(line))
   line = reader1.readline()

  wcrt()
  
  #with open ('theory.txt','w') as reader:
   #reader.write("4 Chains: " + str(mrt(1)) + "\n")
   #reader.write("6 Chains: " + str(mrt(2)) + "\n")
   #reader.write("8 Chains: " + str(mrt(3)) + "\n")

  period = []
  execution = []
  reaction = []