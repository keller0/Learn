a = {}
for i = 1, 10 do
	a[i] = io.read()
end

a[#a + 1] = v

for i = 1, #a do
	print(a[i] * 2)
end
