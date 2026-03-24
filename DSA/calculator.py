
def add(a,b):
    return a+b
def sub(a,b):
    return a-b
def mul(a,b):
    return a*b
def div(a,b):
    return a/b

dictionary={
    "+":add,
    "-":sub,
    "*":mul,
    "/":div
}

def calculator():
    c="y"
    a=int(input("First: "))
    while (c == "y"):
        print(f"{dictionary}\n")
        op=input("select operation: ")
        b=int(input("second: "))
        result= dictionary[op](a,b)
        print(result)
        c=input("y or n")
        if(c=="y"):
            a=result
        else:
            calculator()
calculator()
