base=int(input("enter a: "))
exponent=int(input("enter b: "))
power=1
for i in range(1,exponent+1):
    power=power*base
print(power)