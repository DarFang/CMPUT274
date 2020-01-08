value = int(input())
slime = []
for i in range(value):
	slime.append(1)
	if len(slime)>1:
		while slime[-1]==slime[-2]:
			slime[-2]=slime[-2]+1
			slime.pop()
			if len(slime)<2:
				break
print(" ".join(list(map(str, slime))))
