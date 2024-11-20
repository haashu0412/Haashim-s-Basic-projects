word = "Secret"

allowed_error = 7
guesses = []
done = False

while not done:
    for letter in word:
        if letter.lower() in guesses:
            print(letter,end=" ")
        else:
            print("_",end=" ")
    print("")

    guess = input(f"Allowed errors left{allowed_error},Next guess:")
    guesses.append(guess.lower())
    if guess.lower() not in word.lower():
        allowed_error -= 1
        if allowed_error == 0:
            break

    done = True 
    for letter in word:
        if letter.lower() not in guesses:
            done = False

if done:
    print(f"You found the word! it was {word}!")
else:
    print(f"Game over , the word was {word}!")