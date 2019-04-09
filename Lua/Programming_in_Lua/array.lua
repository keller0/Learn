a = {}
a[1] = 1
a[2] = nil
a[3] = 1
a[4] = 1
a[1000] = 10

for i = 1, #a do
	print(a[i])
end

print(#a)
