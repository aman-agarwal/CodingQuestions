import sys
import numpy as np

amt = int(sys.argv[1])
denom = np.array(sys.argv[2:], dtype=int)

def f(amt, curr, ind):
   x = denom[ind]
   if amt == x:
      print np.append(curr, [x])
   elif amt > x:
      for ind2 in xrange(ind, denom.size):
             y = denom[ind]     
             if curr.size == 0 and x > 0:
                f(amt-x, np.array([x]), ind2)
             elif x == 0:
                f(amt, curr, y)
             else:
                f(amt-x, np.append(curr, [x]), ind2)

f(amt, np.array([]), 0)

