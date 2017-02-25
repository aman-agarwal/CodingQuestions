import sys 
import numpy as np

arr = np.array(sys.argv[1:], dtype=float)
arr= np.sort(arr)
for i in xrange(len(arr)):
   x = arr[i]
   j = i+1
   k = len(arr) - 1
  # print x
   while j < k:
 #     print arr[j], arr[k]
      if arr[j]+arr[k] > x*-1:
         k=k-1
      elif arr[j] + arr[k] < x*-1:
         j=j+1
      else:
         print x, arr[j], arr[k]
         k=k-1
         j=j+1  
   #print 

