percentile={
    "dilshad":95,
    "aman":98,
    "anas":99}
rank={}
for i in percentile:
    score=percentile[i]
    if score>95:
        rank[i]="good rank"
    else:
        rank[i]="can do better"
print(rank["aman"])