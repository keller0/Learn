ans1 = 2+5*8
ans2 = (2+5)*8
print(ans1, ans2)

m1 = 5%2
print(m1)

myPi = math.pi
print(myPi)

-- pseudo random
print(math.random())
print(math.random(1, 100))
-- reseed
math.randomseed(os.time())
print(math.random())
print(math.random(1, 100))