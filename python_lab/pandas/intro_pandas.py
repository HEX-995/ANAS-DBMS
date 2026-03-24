# *******************INTRODUCTION TO PANDAS**************************
import pandas as pd

#Series
arr1=[1,2,3,4]
var2=pd.Series(arr1)
#print(var2)

#indexing
var3=pd.Series(arr1,index=["w","x","y","z"])
# print(var3)

#pandas series from dictionary
student={"24140":"dilshad","24141":"anas","24142":"neeraj"}
var4=pd.Series(student,index=["24140","24141","24142"])
# print(var4["24140"])

# dataframes
# load dict into dataframe
data={
    'employees':["dilshad","anas","yuva"],
    'work':["web developer","ML engineer","android developer"]
}
var=pd.DataFrame(data,index=["emp1","emp2","emp3"])
# print(var)
# print(var.loc[0])
# print(var.loc[["emp1","emp2"]])

# load csv in dataframe
var5=pd.read_csv('currency.csv')
# print(var5.loc[[56,57]])
# print(var5.to_string())
# print(var5)

# max rows
# pd.options.display.max_rows=100
# print(pd.options.display.max_rows)

# load json in dataframe
var6=pd.read_json('data.json')
# print(var6)
# print(var6.to_string())

# viewing data csv by head and tail method and use of info()
# print(var5.head(10))
# print(var5.tail(10))
# print(var5.tail(10).dtypes), type check
# print(var5.info())
