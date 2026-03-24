list_1=[1,2,3,4,5]
k=9
sublists=[]
for i in range(len(list_1)):
    for j in range(i+1,len(list_1)+1):
        if (sum(list_1[i:j])==k):
            sublists.append(list_1[i:j])
print(sublists)