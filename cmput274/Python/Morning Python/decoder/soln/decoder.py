# Read in the input
lines = int(input())
dictionary = {}

# Construct a dictionary mapping binary strings to English words
for i in range(lines):

	bit, word = input().split()
	dictionary[bit] = word
# Use the dictionary to decode the binary string
inp = input()

string =[]
check=""
for i in inp:
	check=check+i
	if  check  in dictionary.keys():
		string.append(dictionary[check])
		check = ""


print(" ".join(string))