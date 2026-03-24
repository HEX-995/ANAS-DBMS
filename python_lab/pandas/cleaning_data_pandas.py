import pandas as pd
# *******************CLEANING THE DATA**************************
# remove the rows with NaN
df=pd.read_csv('data_2.csv')
# print(df.head(20))
new_df=df.dropna()
# dropna() return a new dataframe
# print(new_df.head(20))

# new_df_2=df.dropna(inplace=True)
# print(df.head(20))
# dropna(inplace=True) removes the NaN rows from origional dataframe

# replace empty values
# print(df.fillna(00).head(20))
#df.fillna(666,inplace=True)
#print(df.head(20))

# replace for specified columns
df.fillna({"Calories":133},inplace=True)
#print(df)

# calculation of mean, median, mode
x=df["Calories"].mean()

#cleaning wrong format
#print(df)
df['Date']=pd.to_datetime(df['Date'],format='mixed')
#print(df)

#cleaning wrong format
#small data set
df.loc[7,'Duration']=45
# print(df)

# big data set
for x in df.index:
    if df.loc[x,'Duration']>120:
        df.loc[x,'Duration']=120
        
# OR just delete the row
for x in df.index:
    if df.loc[x,"Duration"]>120:
        df.drop(x,inplace=True)
        
# remove duplicates
print(df.duplicated())
df.drop_duplicates(inplace=True)
print(df.duplicated())