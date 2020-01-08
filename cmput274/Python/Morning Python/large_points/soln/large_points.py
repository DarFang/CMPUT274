import math

n = int(input())

x, y, r = [], [], []
# x, y, r are empty lists

for i in range(n):
    x_in, y_in, r_in = map(float, input().split())
    x.append(x_in)
    y.append(y_in)
    r.append(r_in)

m = int(input())

x1, y1 = [], []

for i in range(m):
    x_in, y_in = map(float, input().split())
    x1.append(x_in)
    y1.append(y_in)

# Now read in the number of queries and then the
# queries themselves.
# You do not have to store all queries, you can
# output the answer for one query before reading
for p1 in range(m):
	within = False
	for p2 in range(n):

		if math.sqrt((x[p2]-x1[p1])**2+(y[p2]-y1[p1])**2)<=r[p2]:
			within=True
			

	if within == True:
		print("Large")

	else:
		print("Small")


# in the next query point.
