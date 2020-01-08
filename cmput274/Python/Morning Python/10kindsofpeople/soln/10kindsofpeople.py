# read the input
n,m = map(int, input().split()) #n is index, m is jouneys
sequence = input()
# solve the problem
for i in range(m):
	s,e = map(int, input().split())
	zero = False
	one = False
	for j in range(s-1,e):
		if sequence[j] == '1':
			one = True
		elif sequence[j] == '0':
			zero = True
	if zero == False and one == True:
		print('one')
	elif zero == True and one == False:
		print('zero')
	elif zero == True and one == True:
		print('both')
# output the answer
