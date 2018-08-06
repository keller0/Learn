#!/usr/bin/python

# List
matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
]

m = [[row[i] for row in matrix] for i in range(4)]

print(m)

t = []
for i in range(4):
    t.append([row[i] for row in matrix])

print(t)

t_all = []
for i in range(4):
    t_row = []
    for row in matrix:
        t_row.append(row[i])
    t_all.append(t_row)

print(t_all)

print(list(zip(*matrix)))

a = [1, 2, 3]
del a[0]

print(a)

# Tuples
t = 123, 321, 'hi'
print(t[0])

u = t, (1, 2, 3, 4)
print(u)

v= ([1, 2, 3], [3, 2, 1])
print(v)

x, y, z = t
print(x, y, z)

# Sets
basket = {'apple', 'orange'}
f1 = 'apple' in basket
f2 = 'banana' in basket
print(f1, f2)

a = set('abcdabc')
b = set('bcdef')
print(a, b)
print(a - b)
print(a | b)
print(a & b)
print(a ^ b)

# Dictionaries
tel = {'jack': 12, 'sape': 23}
tel['guido'] = 45
print(tel)
print(tel['jack'])
del tel['jack']
print(tel)
tel['irv'] = 53
print(list(tel))
print(sorted(tel))
b1 = 'guido' in tel
b2 = 'jack' not in tel
print(b1, b2)

for k, v in tel.items():
    print(k, v)