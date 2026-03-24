def is_leap_year(year):
    if year%400==0:
        return True
    else:
        return False
b=int(input("Enter year: "))

while(is_leap_year(b)):
    print("yes")
    break

    # Don't change the function name.