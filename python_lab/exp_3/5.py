def is_armstrong(number):
    size=len(number)
    sum=0
    for i in number:
        sum+=pow(int(i),size)
    if(str(sum)==number):
        print("yes")
    
number=input("enter the number: ")
is_armstrong(number)