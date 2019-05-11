print(type(0))
print(type(true))
print(type(false))


function isBool(x)
   if x == true or x == false then
	  print(x, "is boolean")
   else
	  print(x, "is not boolean")
   end
end


isBool(false)
isBool(true)
isBool(nil)
isBool(1)

isBool(1.1)
isBool("asd")

