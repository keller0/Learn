#!/usr/bin/python
def fib(n):
    a,b = 0,1
    while a < n:
        print(a, ' ')
        a,b = b,a+b
    print()

fib(2000)

def fib2(n):
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result

f100 = fib2(100)
print(f100)

def ask_ok(prompt, retries=4, reminder='Please try again!'):
    while True:
        ok = input(prompt)
        if ok in ('y', 'ye', 'yes'):
            return True
        if ok in ('n', 'no', 'nop', 'nope'):
            return False
        retries = retries - 1
        if retries < 0:
            raise ValueError('invalid user response')
        print(reminder)

ask_ok('OK to overwrite the file?', 2, 'Come on, only yes or no!')

i = 5

def f(arg=i):
    print(arg)

i = 6
f()