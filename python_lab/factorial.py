def factorial(number):
    answer=1
    for i in range(number,0,-1):
        answer=answer*i
    return answer
        
number=int(input("enter the number: "))
print(factorial(number))
