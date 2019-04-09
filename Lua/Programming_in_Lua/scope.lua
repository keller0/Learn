a = 10

-- use local !
function ala()
    local a = 90
    print(a)
end

ala()

print(a)

local function lala()
    print("this function can be only used in this file")
end
lala()