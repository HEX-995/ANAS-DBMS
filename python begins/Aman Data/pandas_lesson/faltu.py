import csv
import pandas

FILE_PATH = "weather_data.csv"


#  Data in column

data = pandas.read_csv(FILE_PATH)
# print(type(data["temp"][0]))
# print(data.condition)


#  Data in row

# print(data[data.day == "Monday"])
# print(data[data.temp == data.temp.max()])
monday = data[data.day == "Monday"]
print(monday.condition)



# Creating a dataframe from scratch

data_dict = {
    "students": ["aman", "karan", "manoj"],
    "scores": [75,78,67]
}
data_frame = pandas.DataFrame(data_dict) # Way to create a dataframe from dictionary
# data.to_csv("new.csv")                 # Way to create a csv file from a dataframe
print(data_frame.to_dict())