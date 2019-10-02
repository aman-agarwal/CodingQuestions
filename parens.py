import sys

def f(n):
   _f("", 0, 0, n)

def _f(s, cL, cR, n):
   if cR == n:
      print s
   else:
      if cR < cL:
         _f(s + ")", cL, cR+1, n)
      if cL < n:
         _f(s + "(", cL+1, cR, n)  

n = int(sys.argv[1])
f(n)
