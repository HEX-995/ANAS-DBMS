    
list_1=[3,6,4,2,8,3]
list_2=list_1
swap=0
for i in range(len(list_2)-1):
    for a in range(len(list_2)-1):
        if (list_2[a]>list_2[a+1]):
            temp=list_1[a]
            list_2[a]=list_2[a+1]
            list_2[a+1]=temp
            swap=swap+1
print(swap)
            