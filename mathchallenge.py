import random
import time

operators =["+","-","*"]

min_operator = 3
max_operator = 12
total = 10

def generate_problem():
    left = random.randint(min_operator, max_operator)
    right = random.randint(min_operator, max_operator)
    operator = random.choice(operators)

    exp = str(left) + " " + operator + " " + str(right)
    answer = eval(exp)
    return exp, answer


wrong = 0
input("PRESS ENTER TO START!")
print("------------------")

start_time = time.time()

for i in range (total):
    exp, answer = generate_problem()
    while True:
        guess = input("Problem #" + str(i+1) + ":" + exp + "=")
        if guess == str(answer):
            break
        wrong += 1

end_time = time.time()
total_time = end_time - start_time

print("----------------------")
print("Nice work! You finished in:", total_time,"seconds!")






