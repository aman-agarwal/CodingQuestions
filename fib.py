def fib(n):
   a = 1
   b = 1
   for i in xrange(n):
      c = b
      b = a + b
      a = c
   return b

for n in xrange(10):
   print fib(n)
