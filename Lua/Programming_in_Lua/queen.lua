N = 8 -- board size
T = 1
-- check whether position (n, c) is free from attacks
function isplaceok (a, n, c)
   T = T + 1
   for i = 1, n-1 do --for eache queen already palced
	  if (a[i] == c) or
		 (a[i] - i == c - n) or
	  (a[i] + i == c + n) then
		 return false
	  end
   end
   return true
end

-- print a board
function printsolution (a)
   for i = 1, N do
	  for j =1, N do
		 -- write "x" or "-" plus a space
		 io.write(a[i] == j and "X" or "-", " ")
	  end
	  io.write("\n")
   end
   io.write("\n")
end

-- add to board 'a' all queens from 'n' to 'N'
function addqueen (a, n)
   if n > N then -- all queens have been placed?
	  printsolution(a)
	  return true
   else -- try to place n-th queen
	  for c = 1, N do
		 if isplaceok(a, n, c) then
			a[n] = c -- place n-th queen at column 'c'
			local res = addqueen(a, n + 1)
			if res == true then
			   return true
			end
		 end
	  end
   end
end

-- run the program
addqueen({}, 1)
print(T)


