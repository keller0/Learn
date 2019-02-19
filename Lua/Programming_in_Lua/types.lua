print("\
    Lua is a dynamically typed language.\
    There are eight basic types in Lua: \
      nil, boolean, number, string, userdata,\
      function, thread, and table.\
    The type function gives the type name of a given value:\
")

print(type("Hello world"))  --> string
print(type(10.4*3))  --> number
print(type(print))  --> function
print(type(type))  --> function
print(type(true))  --> boolean
print(type(nil))  --> nil
print(type(type(X))) --> string

print("\
    Variables have no predefined types; any variable may\
    contain values of any type:\
")

print(a) --> nil

a = 10
print(type(a))

a = "now its string"
print(type(a))

a = print -- valid
print(type(a))

a("haosjdopajsopd") -- good