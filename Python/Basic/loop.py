#!/usr/bin/python

words = ['apple', 'banana', 'cat']

for w in words:
    print(w, len(w))

for i in range(5):
    print(i)

a = ['Mary', 'had', 'a', 'little', 'cat']

for i in range(len(a)):
    print(i, a[i])

for n in range(2, 10):
    for x in range(2, n):
        if n % x == 0:
            print(n, 'equals', x, '*', n//x)
            break
    else:
        print(n, 'is a prime number')

for num in range(2, 10):
    if num % 2 == 0:
        print("Found an even number", num)
        continue
    print("Found a number", num)
