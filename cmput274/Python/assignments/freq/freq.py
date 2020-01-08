# ---------------------------------------------------
#    Name: Darius Fang
#    ID: 1570975
#    CMPUT 274, Fall  2019
#
#    Weekly Assignment 3: Frequency
#    Citation: docs.python.org system module
# ---------------------------------------------------
import sys


def read_words(fileName):
    """ Reads a file input

    Arguments:
        filename (string): a string consisting the file reaquested

    Returns: sentence (string): string of the read file
    """

    fread = open(fileName, "r")  # opens file to read
    sentence = fread.read()  # reads the file
    fread.close()  # closes file
    return sentence


def sort_words(sentence):
    """ Sorts the words by lexicopgrahic order into a tuple with the first value 
        being the word and the sencond being the count

    Arguments:
        sentence (string): the read file

    Returns:  words (tuple): the first value word, and the second count
    """

    sentence = sentence.split()  # splits the string into a list
    sentence = sorted(sentence)  # sorts by lexicographic order
    words = {}
    for i in sentence:
        words[i] = sentence.count(i)  # sorts it to count and words

    return(words)


def output(WordList, fname):
    """ outputs the sorted list into a file

    Arguments:
        WordList (tuple): the sorted words and the count

    Returns:
        none, but it outputs to the file name called file_input.out
    """

    name = fname + ".out"  # output file name
    fout = open(name, "w")  # open write file
    total = sum(WordList.values())
    for word, num in WordList.items():
        string = str(word) + " " + str(num) + " " + str(round(num/total, 3)) + "\n"
        fout.write(string)  # format word count freq

    fout.close()


if __name__ == "__main__":
    arg = len(sys.argv)  # length of arguments
    if arg == 2:
        WordList = read_words(sys.argv[1])  # uses the 2nd argument as the file input
        WordList = sort_words(WordList)  # sorts the string
        output(WordList, sys.argv[1])  # output to the a new file
    else:  # if arguments do not match
        adj = ""
        if arg < 2:
            adj = "few"

        else:
            adj = "many"

        print("There are too " + adj + " arguments.\nThe corret way to use the program is: \npython3 freq.py <input_file_name>")