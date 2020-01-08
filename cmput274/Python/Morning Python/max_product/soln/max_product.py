length = int(input())
table1 = list(map(int, input().split()))
table2 = list(map(int, input().split()))
total = 0
table1.sort()
table2.sort()

for i in range(length):

	total = total+int(table1[i])*int(table2[i])


print(total)