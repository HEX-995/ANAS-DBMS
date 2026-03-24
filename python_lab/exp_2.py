def count_vowels(s):
    if s == "":
        return 0
    if s[0].lower() in "aeiou":
        return 1 + count_vowels(s[1:])
    return count_vowels(s[1:])

s = input("Enter string: ")
print("Vowel count:", count_vowels(s))
