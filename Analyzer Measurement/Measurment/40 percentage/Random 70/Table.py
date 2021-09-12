import os

c_list = []
s_list = [] 
m_list =[]
time = 813

with open("client.txt") as c:
 line = c.readline()
 while line != "":
  c_list.append(int(line))
  line = c.readline()

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
  print("    ",i+1," & ",str(c_list[i])," & ",str(s_list[i])," & ",str(c_list[i]+s_list[i])," & ",str(c_list[i]+s_list[i]+2*time)," &", str(m_list[i]),"  \\\\")

for i in range(len(m_list),50):
  print("    ",i+1," & ",str(c_list[i])," & ",str(s_list[i])," & ",str(c_list[i]+s_list[i])," & ",str(c_list[i]+s_list[i]+2*time)," &  \\\\")

