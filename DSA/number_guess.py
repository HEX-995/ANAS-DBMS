import random
var=random.randint(1,100)
print(var)
def guess(lives):
    while lives>0:
        print(f"You have {lives} lives.")
        num=int(input("Guess a number: "))
        if num==var:
            print(f"You win ans was {num}")
            return
        elif num>var:
            print("high")
        elif num<var:
            print("low")
        lives-=1
    print("You lose")
        
level=input("Type 'easy' or 'hard': ")
if level=="easy":
    lives=10
else:
    lives=5
guess(lives)