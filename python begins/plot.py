# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt 
a=[12,15,18,19,25]
b=[1,2,3,4,5]
plt.plot(b,a,color='m',linestyle='-.')
plt.xlabel("DAYS",rotation=30,size=15,color='r')
plt.ylabel("TEMP/C",rotation=45,size=15,color='b')
plt.legend("WEEKLY ANALYSIS")

plt.show()