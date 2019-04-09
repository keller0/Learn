b = [[ Multi-line string
    As soon as the light in the bedroom went out there was a stirring and
    a fluttering all through the farm buildings. Word had gone round during
    the day that old Major, the prize Middle White boar...
]]

print(b)

s1 = "Hello "
s2 = 'World'
print(s1 .. s2)

myNumber = 42
myStringNumber = tostring(myNumber)
print(myStringNumber)

n1, n2 = 10, 90
print(n1, n2)

print("this is a string with \n\tnew line")

print([[

Lua provides automatic conversions between numbers and strings
at run time. Any numeric operation applied to a string tries to
convert the string to a number:
]])

print("10" + 1)
print("10 + 1")
print("10" + "1")
-- print("hello" + 1) -- attempt to perform arithmetic on a string value
print(10 .. 20) --> 1020

-- print length of a string use #
print(#"12345\n\t")
print(#tostring(10))


print(string.upper( "this is an uppercase string" ))
print(string.format( "pi = %.4f", math.pi ))

local s1 = "hello world"
local sBegin, sEnd = string.find( s1, "world")
print(sBegin, sEnd)

local found = string.match( s1, "world" )
print(found)

local date = "today is 20/2/2019"
local d = string.match( date, "%d+/%d+/%d+" )
print(d)

local temp = "hell0"
local temp2 = string.gsub( temp, "0", "o")
print(temp2)