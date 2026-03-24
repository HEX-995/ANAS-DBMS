def power(a, b):
    result = 1
    for _ in range(b):
        result *= a
    return result
print("POWER= ",power(3, 5))
