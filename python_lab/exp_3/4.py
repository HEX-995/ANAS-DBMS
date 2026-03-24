def digit_sum(number):
    sum=0
    for i in number:
        sum=sum+int(i)
    if(len(str(sum))!=1):
        return digit_sum(str(sum))
    else:
        return str(sum)
number=input("enter number: ")
print(digit_sum(number))