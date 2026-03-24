# 1. Write a Python program to find the longest substring without repeating characters.
# 2. Write a program to sort a dictionary based on keys and values simultaneously.
# 3. Write a program to remove all duplicate elements from a tuple without converting
# it to a set.
# 4. Write a program to find the minimum number of swaps required to sort a list.
# 5. Write a program to find all sublists whose sum equals a given number k.
string=input("enter a string:")
longest=""
for a in string:
    if a not in longest:
        longest=longest+a
print(longest)