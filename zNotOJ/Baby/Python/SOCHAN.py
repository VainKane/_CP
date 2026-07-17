n = int(input())

count = 0

for i in range (1, n + 1):
    if (i % 6 == 0):
        count += 1

print(count)


for i in range (1, n + 1):
    if (i % 6 == 0):
        print(i, end = ' ')