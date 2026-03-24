import pandas as pd
import matplotlib.pyplot as plt
df=pd.read_csv('data.csv')

#simple plotting
# df.plot()
# plt.show()

#scatter plot
#good relation
# df.plot(kind='scatter',x='Duration',y='Calories')
# plt.show()

#bad relation
# df.plot(kind='scatter',x='Duration',y='Maxpulse')
# plt.show()

#histogram
df["Duration"].plot(kind='hist')
plt.show()