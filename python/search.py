list=[11,12,13,14,15,16,17]
print(list)
b=int(input("Enter the element you want to find:"))
low=0 
high=int(len(list)-1)
while low<=high:
    mid=int((low+high)/2)
    if list[mid]==b:
       f=1
       break
    elif list[mid]>b:
        high=mid-1
    else:
        low=mid+1
if f==1 :
    print("Element is present at index",mid)