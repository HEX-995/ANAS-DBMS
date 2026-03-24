# capitals={
#     "France":["Paris","Lille","Dijon"]
# }
# print(capitals["France"][1])

# #nested list
# list=["a","b",["c","d"]]
# print(list[2][0])

#nested dictionary
cities={
    "France":{"cities_visited":["paris","lille","dijon"],
              "no_of_times_visited":10}
}

print(cities["France"]["cities_visited"][1])
for i in cities:
    print(f"{i}:")
    for k in cities[i]:
        print(f"{k}:")
        print(f"{cities[i][k]}\n")