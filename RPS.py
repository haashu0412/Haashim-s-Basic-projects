import random

rounds = int(input("How many rounds:"))

player_score = 0
computer_score = 0

for i in range (rounds):
    computer_guess = random.choice(['rock','paper','scissor'])

    player_guess = input(f"Round{i+1}, Enter Your Move : ").lower()

    print(f"Your move : {player_guess}")
    print(f"Computer move : {computer_guess}")

    if player_guess == computer_guess :
        print(f"Both same move, it's a tie")
    elif player_guess == "rock":
        if computer_guess == "scissors":
            print("You win")
            player_score += 1
        else:
            print("You lose")
            computer_score += 1

    elif player_guess == "paper":
        if computer_guess == "rock":
            print("You win")
            player_score += 1
        else:
            print("You lose")
            computer_score += 1
    
    elif player_guess == "scissors":
        if computer_guess == "paper":
            print("You win")
            player_score += 1
        else:
            print("You lose")
            computer_score += 1

    print(f"Score - Your's : {player_score} , Computer's : {computer_score}")

print(f"Final score - Your's : {player_score} , Computer's : {computer_score}")