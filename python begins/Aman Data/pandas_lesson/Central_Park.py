import pandas

FILE_PATH = "2018_Central_Park_Squirrel_Census_-_Squirrel_Data.csv"

data = pandas.read_csv(FILE_PATH)
fur_colours = list(data["Primary Fur Color"].unique()[1:])
dic = {}
dic["fur counts"] = fur_colours
dic["Count"] = list(data["Primary Fur Color"].value_counts())
data_frame = pandas.DataFrame(dic)
data_frame.to_csv("fur_count.csv")