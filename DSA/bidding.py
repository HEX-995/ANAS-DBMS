import os
dictionary={}
another_bidder=True
while(another_bidder==True):
    name=input("Type your name: ")
    bid=int(input("Your bid: "))
   
    dictionary[name]= bid
    question=input("Is there another bidder: ").lower()
    if (question=="no"):
        another_bidder=False
    else:
        os.system('clear')

def highest_bidder():
    max=0
    for i in dictionary:
        if (dictionary[i]>max):
            max=dictionary[i] 
    print(f"{i} is the highest bidder with ${max}")
highest_bidder()
