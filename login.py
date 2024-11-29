import pwinput

def login(username, password):
    correct_username = "python"
    correct_password = "java"

    return username == correct_username and password == correct_password

def main():
    max_attempts = 3

    for attempts in range(1, max_attempts + 1):
        input_username = input("Enter username: ")
        input_password = pwinput.pwinput("Enter password: ")

        if login(input_username, input_password):
            print("Login successful")
            break
        else:
            if attempts != max_attempts:
                print(f"Try again. You have {max_attempts - attempts} attempts left.")
            else:
                print("Account locked")

if __name__ == "__main__":
    main()
