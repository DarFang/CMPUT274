# Get the input
leftlane = input().split()

# now do something similar to get the list of vehicles in the right lane
rightlane = input().split()


# Solve the problem
length=[len(leftlane),len(rightlane)]
maxL=max(length)
out=''
for i in range(maxL):
	if length[0]>i:
		out=out+leftlane[i]+' '
	if length[1]>i:
		out=out+rightlane[i]+' '

# Print the result
print(out)