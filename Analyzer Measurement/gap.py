import os

t_list = []
m_list = []
g_list = []
test = 0

#Folder open 4chain
print()
for x in range(0,11):
 os.chdir(r"C:\Users\D-Flow\Desktop\BA\Analyzer Measurement\Measurment\70 percentage")
 folder = os.listdir()
 os.chdir(folder[x])
 

 with open("Measurement.txt") as m1:
  line = m1.readline()
  while line != "":
   test = line
   line = m1.readline()
  m_list.append(test)
  print("M: ",m_list[x])
 
 with open("Unit.txt") as m2:
  line = m2.readline()
  while line != "":
   test = line
   line = m2.readline()
  t_list.append(test)
  print("T: ",t_list[x])

 g_list.append(int(t_list[x])-int(m_list[x]))
 test=0

#Folder open 6chain
print()
for x in range(0,11):
 os.chdir(r"C:\Users\D-Flow\Desktop\BA\Analyzer Measurement\Measurment2\70 percentage")
 folder = os.listdir()
 os.chdir(folder[x])
 

 with open("Measurement.txt") as m1:
  line = m1.readline()
  while line != "":
   test = line
   line = m1.readline()
  m_list.append(test)
  print("M: ",m_list[x+11])
 
 with open("Unit.txt") as m2:
  line = m2.readline()
  while line != "":
   test = line
   line = m2.readline()
  t_list.append(test)
  print("T: ",t_list[x+11])

 g_list.append(int(t_list[x+11])-int(m_list[x+11]))
 test=0

 #Folder open 8chain
print()
for x in range(0,11):
 os.chdir(r"C:\Users\D-Flow\Desktop\BA\Analyzer Measurement\Measurment3\70 percentage")
 folder = os.listdir()
 os.chdir(folder[x])
 

 with open("Measurement.txt") as m1:
  line = m1.readline()
  while line != "":
   test = line
   line = m1.readline()
  m_list.append(test)
  print("M: ",m_list[x+22])
 
 with open("Unit.txt") as m2:
  line = m2.readline()
  while line != "":
   test = line
   line = m2.readline()
  t_list.append(test)
  print("T: ",t_list[x+22])

 g_list.append(int(t_list[x+22])-int(m_list[x+22]))
 test=0


print("\\begin{tabular}{|c | c c c |}")
print("\\hline")
print("Seed & Length 4 & Length 6 & Length 8 \\\\")
print("\\hline")
print("     1 &",g_list[0]," & ",g_list[11]," & ",g_list[22]," \\\\")
print("     10 &",g_list[1],"  & ",g_list[12]," & ",g_list[23]," \\\\")
print("     20 & ",g_list[3]," & ",g_list[14]," & ",g_list[25]," \\\\")
print("     30 & ",g_list[4]," & ",g_list[15]," & ",g_list[26]," \\\\")
print("     40 & ",g_list[5]," & ",g_list[16]," & ",g_list[27]," \\\\")
print("     50 & ",g_list[6]," & ",g_list[17]," & ",g_list[28]," \\\\")
print("     60 & ",g_list[7]," & ",g_list[18]," & ",g_list[29]," \\\\")
print("     70 & ",g_list[8]," & ",g_list[19]," & ",g_list[30]," \\\\")
print("     80 & ",g_list[9]," & ",g_list[20]," & ",g_list[31]," \\\\")
print("     90 & ",g_list[10]," & ",g_list[21]," & ",g_list[32]," \\\\")
print("     100 & ",g_list[2]," & ",g_list[13]," & ",g_list[24]," \\\\")
print("\\hline")
print("\\end{tabular}")



