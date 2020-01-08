# Read the input
a, b, c = map(int, input().split())


# Solve the problem
avg=(a+b+c)/3
result = str(int(abs(a-avg)))+" "+str(int(abs(b-avg)))+" "+str(int(abs(c-avg)))
# Output the result
print(result)