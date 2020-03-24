t = {hello = 100, 200, 300}

print("k, v in pairs:")
for k, v in pairs(t) do
    print(k, v)
end

print("k, v in ipairs:")
for k, v in ipairs(t) do
    print(k, v)
end
