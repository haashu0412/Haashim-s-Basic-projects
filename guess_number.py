import random

user_score = 0
computer_score = 0

rounds = int(input("How many Rounds: "))

for i in range(rounds):
    computer_guess = random.randint(0,5)

    user_guess = int(input(f"Round{i+1}: Guess number between 0 and 5: "))

    if user_guess == computer_guess:
        print(f"Correct")
        user_score += 1
    else:
        print("wrong!!")
        computer_score += 1
    
    print(f"Your score :{user_score},computer score:{computer_score}\n")

print(f"Final Score - your's : {user_score} , Computer : {computer_score}")