# read the input
line=input().lower()

# solve the problem
num=0
for char in line:
	if char == "a" or char == "e" or char == "i" or char == "o" or char == "u":
		num = num+1 

# output the result
print(num)