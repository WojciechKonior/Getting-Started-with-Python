def someFunction(*args, **kwargs):
  print(args)
  print(kwargs)
  print(locals())

someFunction(1,2,3, operation='sum')
print(globals())

def x():
  return 5

print(x.__code__.co_varnames)
print(x.__code__.co_code)

y = [x]
print(y[0]())

print((lambda x: x+3)(5))
print((lambda x,y: x+y)(5,5))

myList = [5, 3, 2, 1]
myList2 = sorted(myList)
