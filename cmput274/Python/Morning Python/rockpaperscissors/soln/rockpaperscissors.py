num_matches = int(input())
Bob=0
Alice=0
for i in range(num_matches):
	rounds =  input().split()
	MAlice = 0
	MBob = 0
	for n in rounds:
		if n == "PR" or n == "RS" or n == "SP": 
			MAlice = MAlice + 1

		elif n == "RP" or n == "SR" or n == "PS":
			MBob = MBob + 1

	if MBob>MAlice:
		Bob=Bob+1
	elif MAlice>MBob:
		Alice=Alice+1

if Alice>=Bob:
		print("Alice " + str(Alice))
else:
		print("Bob " + str(Bob))

    # now you do the rest!
    # read in the rounds in this match
    # example: if the line of input was "RR RP SR" then
    # rounds == ["RR", "RP", "SR"]
    

# print here whoever is the overall winner of all the matches and
# how many matches the winner won
