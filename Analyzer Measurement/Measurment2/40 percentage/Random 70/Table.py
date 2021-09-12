import os

c_list = []
e_list = []
s_list = [] 
m_list =[]
test = 0
counter = 0
time = 813

with open("client.txt") as c:
 line = c.readline()
 while line != "":
  c_list.append(int(line))
  line = c.readline()

with open("ecu2.txt") as e:
 line = e.readline()
 while line != "":
  e_list.append(int(line))
  line = e.readline()

with open("server.txt") as s:
 line = s.readline()
 while line != "":
  s_list.append(int(line))
  line = s.readline()

with open("Measurement.txt") as m:
 line = m.readline()
 while line != "":
  m_list.append(int(line))
  line = m.readline()

for i in range(0,len(m_list)):
 if(e_list[i] == 0):
  print("    ",i+1," & ",str(c_list[i])," & ",str(e_list[i+1])," & ",str(s_list[i-counter])," & ",str(c_list[i]+e_list[i+1]+s_list[i-counter])," & ",str(c_list[i]+e_list[i+1]+s_list[i-counter]+3*time)," &", str(m_list[i]),"  \\\\")
  test = 1
 else:
  if(test == 0):
   print("    ",i+1," & ",str(c_list[i])," & ",str(e_list[i])," & ",str(s_list[i-counter])," & ",str(c_list[i]+e_list[i]+s_list[i-counter])," & ",str(c_list[i]+e_list[i]+s_list[i-counter]+3*time)," &", str(m_list[i]),"   \\\\")
  else:
   print("    ",i+1," & ",str(c_list[i])," & 0 & - & - & - &", str(m_list[i]),"   \\\\")
   test = 0
   counter = counter +1

for i in range(len(m_list),50):
 if(e_list[i] == 0):
  print("    ",i+1," & ",str(c_list[i])," & ",str(e_list[i+1])," & ",str(s_list[i-counter])," & ",str(c_list[i]+e_list[i+1]+s_list[i-counter])," & ",str(c_list[i]+e_list[i+1]+s_list[i-counter]+3*time)," &  \\\\")
  test = 1
 else:
  if(test == 0):
   print("    ",i+1," & ",str(c_list[i])," & ",str(e_list[i])," & ",str(s_list[i-counter])," & ",str(c_list[i]+e_list[i]+s_list[i-counter])," & ",str(c_list[i]+e_list[i]+s_list[i-counter]+3*time)," &   \\\\")
  else:
   print("    ",i+1," & ",str(c_list[i])," & 0 & - & - & - &   \\\\")
   test = 0
   counter = counter +1
   

