import string 

def caesar(text,shift,alphabets):

    def shift_alphabet(alphabet):
        return alphabet[shift:] + alphabet[:shift]
    
    shifted_alphabets = tuple(map(shift_alphabet, alphabets))
    final_alphabet = ''.join(alphabets)
    final_shifted = ''.join(shifted_alphabets)
    table = str.maketrans(final_alphabet , final_shifted)
    return text.transalate(table)

plain_text = "This is a new test. Hello World!"
print(caesar(plain_text , 7 , [string.ascii_lowercase , string.ascii_uppercase , string.punctuation]))