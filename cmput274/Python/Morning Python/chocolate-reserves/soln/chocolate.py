piece, jars= map(int, input().split())
room=0

for j in range(jars):
	choc, maxi = map(int, input().split())
	if (maxi-choc-piece)>=0:
		room += 1

print(room)