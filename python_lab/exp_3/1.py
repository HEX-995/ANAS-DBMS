def factorial(number):
    answer=1
    for i in range(number,0,-1):
        answer=answer*i
    return answer

sum=0
number=input("enter the number:")
for i in number:
    n=int(i)
    sum=sum+factorial(n)

print(sum)
if(sum==int(number)):
    print("yes")
else:
    print("no")
