import sys
import numpy as np

def mergeSort(arr):
   _mergeSort(arr, 0, arr.size-1)

def _mergeSort(arr, start, end):
   if start < end:
      #print start, end
      _mergeSort(arr, start, (end+start)/2)
      _mergeSort(arr, (end+start)/2 + 1, end)
      merge(arr, start, end)

def merge(arr, start, end):
   aux = np.zeros(end-start+1)
   i = start
   j = (end+start)/2 + 1
   k = 0
   while i <= (end+start)/2 and j <= end:
      if arr[i] <= arr[j]:
         aux[k] = arr[i]
         i=i+1
      else:
         aux[k] = arr[j]
         j=j+1
      k=k+1
   aux[k:] = np.append(arr[i:(end+start)/2+1], arr[j:end+1])
   arr[start:end+1]=aux

arr = np.array(sys.argv[1:], dtype=float)
arr2 = np.copy(arr)

mergeSort(arr)
print arr
print arr2

#quickSort(arr2)
#print arr2

