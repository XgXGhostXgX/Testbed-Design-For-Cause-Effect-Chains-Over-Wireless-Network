import os

fin_list = []
m_list = []
a_list = ["1","10","100","20","30","40","50","60","70","80","90"]

def boxplot(n,p):
 if(n*p == int(n*p)):
  return 1/2*(m_list[int(length*p)-1]+m_list[int(length*p)])
 else:
  return m_list[int(n*p)] 

#Folder open
print()
for x in range(0,11):
 os.chdir(r"C:\Users\D-Flow\Desktop\BA\Analyzer Measurement\Measurment3\70 percentage")
 folder = os.listdir()
 os.chdir(folder[x])
 #print("SEED: ",a_list[x-1])

 with open("Measurement.txt") as m:
  line = m.readline()
  while line != "":
   m_list.append(int(line))
   line = m.readline()
  m.close() 

 length = len(m_list)
 
 print(folder[x])
#Median
 median =boxplot(length,0.5)
 fin_list.append(median)
 print("Median: ",median)

#upper Quantil
 upperQ =boxplot(length,0.75)
 fin_list.append(upperQ)
 print("Upper Quantil: ",upperQ)

#lower Quantil
 lowerQ =boxplot(length,0.25)
 fin_list.append(lowerQ)
 print("Lower Quantil: ",lowerQ)

#Highest/Lowest
 high = m_list[length-1]
 low = m_list[0]
 fin_list.append(high)
 fin_list.append(low)
 print("highest: ",high)
 print("lowest: ",low)
 
 with open("Unit.txt") as m:
  line = m.readline()
  while line != "":
   temp = line
   line = m.readline()
  print("Theory: ",temp)
  print(" \n")
  fin_list.append(temp)
 m_list = []

#PRINTING

print("%70 Utilization")
print("\\subfigure[Measurement with 70\\% Utilization]{")
print("\\resizebox{0.4\\textwidth}{!}{")
print("\\begin{tikzpicture}")
print(" \\begin{axis} ")
print("  [")
print("  boxplot/draw direction=y,")
print("  xtick={1,2,3,4,5,6,7,8,9,10,11},")
print("  xticklabels={1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100},")
print("  xlabel={Seed},")
print("  ylabel={Execution Time in Ticks},")
print("  height=9cm,")
print("  width=12cm,")
print("  legend style={cells={anchor=east},legend pos=outer north east,}")
print("  ]")
print("%Seed 1 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[1], ",")
print("  lower quartile=",fin_list[2],",")
print("  upper whisker=",fin_list[3],",")
print("  lower whisker=",fin_list[4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=0.5:1.5]") 
print("		{",fin_list[5],"};")
print("\\addplot[green,domain=0.6:1.4]") 
print("    	{",fin_list[0],"};")
print("%Seed 10 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*1+1], ",")
print("  lower quartile=",fin_list[6*1+2],",")
print("  upper whisker=",fin_list[6*1+3],",")
print("  lower whisker=",fin_list[6*1+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=1.5:2.5]") 
print("		{",fin_list[6*1+5],"};")
print("\\addplot[green,domain=1.6:2.4]") 
print("    	{",fin_list[6*1],"};")
print("%Seed 20 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*3+1], ",")
print("  lower quartile=",fin_list[6*3+2],",")
print("  upper whisker=",fin_list[6*3+3],",")
print("  lower whisker=",fin_list[6*3+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=2.5:3.5]") 
print("		{",fin_list[6*3+5],"};")
print("\\addplot[green,domain=2.6:3.4]") 
print("    	{",fin_list[6*3],"};")
print("%Seed 30 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*4+1], ",")
print("  lower quartile=",fin_list[6*4+2],",")
print("  upper whisker=",fin_list[6*4+3],",")
print("  lower whisker=",fin_list[6*4+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=3.5:4.5]") 
print("		{",fin_list[6*4+5],"};")
print("\\addplot[green,domain=3.6:4.4]") 
print("    	{",fin_list[6*4],"};")
print("%Seed 40 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*5+1], ",")
print("  lower quartile=",fin_list[6*5+2],",")
print("  upper whisker=",fin_list[6*5+3],",")
print("  lower whisker=",fin_list[6*5+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=4.5:5.5]") 
print("		{",fin_list[6*5+5],"};")
print("\\addplot[green,domain=4.6:5.4]") 
print("    	{",fin_list[6*5],"};")
print("%Seed 50 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*6+1], ",")
print("  lower quartile=",fin_list[6*6+2],",")
print("  upper whisker=",fin_list[6*6+3],",")
print("  lower whisker=",fin_list[6*6+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=5.5:6.5]") 
print("		{",fin_list[6*6+5],"};")
print("\\addplot[green,domain=5.6:6.4]") 
print("    	{",fin_list[6*6],"};")
print("%Seed 60 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*7+1], ",")
print("  lower quartile=",fin_list[6*7+2],",")
print("  upper whisker=",fin_list[6*7+3],",")
print("  lower whisker=",fin_list[6*7+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=6.5:7.5]") 
print("		{",fin_list[6*7+5],"};")
print("\\addplot[green,domain=6.6:7.4]") 
print("    	{",fin_list[6*7],"};")
print("%Seed 70 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*8+1], ",")
print("  lower quartile=",fin_list[6*8+2],",")
print("  upper whisker=",fin_list[6*8+3],",")
print("  lower whisker=",fin_list[6*8+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=7.5:8.5]") 
print("		{",fin_list[6*8+5],"};")
print("\\addplot[green,domain=7.6:8.4]") 
print("    	{",fin_list[6*8],"};")
print("%Seed 80 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*9+1], ",")
print("  lower quartile=",fin_list[6*9+2],",")
print("  upper whisker=",fin_list[6*9+3],",")
print("  lower whisker=",fin_list[6*9+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=8.5:9.5]") 
print("		{",fin_list[6*9+5],"};")
print("\\addplot[green,domain=8.6:9.4]") 
print("    	{",fin_list[6*9],"};")
print("%Seed 90 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*10+1], ",")
print("  lower quartile=",fin_list[6*10+2],",")
print("  upper whisker=",fin_list[6*10+3],",")
print("  lower whisker=",fin_list[6*10+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=9.5:10.5]") 
print("		{",fin_list[6*10+5],"};")
print("\\addplot[green,domain=9.6:10.4]") 
print("    	{",fin_list[6*10],"};")
print("%Seed 100 ")
print(" \\addplot+[")
print(" blue,")
print(" solid,")
print(" boxplot prepared={")
print("  median=,")
print("  upper quartile=", fin_list[6*2+1], ",")
print("  lower quartile=",fin_list[6*2+2],",")
print("  upper whisker=",fin_list[6*2+3],",")
print("  lower whisker=",fin_list[6*2+4],",")
print(" } ] coordinates {};")
print(" \\addplot[red,domain=10.5:11.5]") 
print("		{",fin_list[6*2+5],"};")
print("\\addplot[green,domain=10.6:11.4]") 
print("    	{",fin_list[6*2],"};")
print("\\end{axis}")
print("\\end{tikzpicture}")
print("}")
print("}&")
print("\\end{tabular}")
print("\\end{figure}")