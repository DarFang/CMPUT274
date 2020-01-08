# read in the input
x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

# now solve the problem. good luck :D
try:
	Slope1 = (y2-y1)/(x2-x1)
except ZeroDivisionError:
	Slope1 = "0"
try:
	Slope2 = (y4-y3)/(x4-x3)
except ZeroDivisionError:
	Slope2 = "0"
if Slope1 == Slope2:
	print("parallel")
else:
	print("not parallel")