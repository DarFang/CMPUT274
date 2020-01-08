# ---------------------------------------------------
#    Name: Darius Fang
#    ID: 1570975
#    CMPUT 274, Fall  2019
#
#    Weekly Assignment 1: Password Validator
#    Citation: docs.python.org string and random module libraries
# ---------------------------------------------------
import random
import string


def validate(password):
    """ Analyzes an input password to determine if it is "Secure", "Insecure", or "Invalid" based on the assignment description criteria.

    Arguments:
        password (string): a string of characters

    Returns:
        result (string): either "Secure", "Insecure", or "Invalid".
    """
    #  Check of the password is 8 or more chracters

    if len(password) >= 8:
        #  Adding all possible outcomes for the line. Default is false until it runs the for loop.
        SpecialChar = "!#$%&'()*+,./:;<=>?@[]^`{|}~"  # List of all special characters
        upper = False
        lower = False
        num = False
        special = False
        forbidden = False
        checkspecial = False

        for char in password:  # Validate each character
            if char >= "a" and char <= "z":  # Is the character lowercase?
                lower = True

            elif char >= "A" and char <= "Z":  # Is the character uppercase?
                upper = True  # Yes

            elif char >= "0" and char <= "9":  # Is the character a number?
                num = True  # Yes

            else:
                for SChar in SpecialChar:  # Checking each special character listed

                    if SChar == char:  # Does this value equal each other?
                        checkspecial = True

                if checkspecial == True:  # Was one value equall to the character?
                    special = True  # Yes. It is a sepcial character

                else:
                    forbidden = True  # No. It is a forbidden character


        if forbidden == False:
            if upper == True and lower == True and num == True and special == True:  # Did it check all of the requirements?
                return("Secure")  # Yes

            else:
                return("Insecure")  # No

        else:
            return("Invalid")  # There is a forbidden value

    else:
        return("Invalid")  # The password is not long enough


def generate(n=8):  # Input
    """ Generates a password of length n which is guaranteed to be Secure according to the given criteria.

    Arguments:
        n (integer): the length of the password to generate, n >= 8.

    Returns:
        secure_password (string): a Secure password of length n.
    """

    SpecialChar = "!#$%&'()*+,./:;<=>?@[]^`{|}~"  # Special characters

    password = [string.ascii_uppercase[random.randint(0, 25)],  # Creates an uppercase character
                   string.ascii_lowercase[random.randint(0, 25)],  # Creates a lowercase character
                   str(random.randrange(10)),  # Creates an interger and converts it to a string
                   SpecialChar[random.randrange(len(SpecialChar))]]  # Creates a special character

    for num in range(n-4):
        password.append(string.ascii_lowercase[random.randint(0, 25)])  # Produce the remaining characters to lowercase

    random.shuffle(password)  # Shuffle the list
    password = "".join(password)  # Convert the list to a string
    return (password)  # Return the string


if __name__ == "__main__":
    print(validate('HACKING'))
    print(validate('Passw0rd!'))
    print(validate('helloworld!'))
    print(generate(999))
    print(generate(999))