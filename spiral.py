import numpy as np

def spiral_rec(arr, n, val, ind):
    if n == 1:
        arr[ind, ind] = val
    elif n >= 2:
        for i in range(ind,ind+n):
            arr[ind, i] = val 
            val += 1
        for i in range(ind+1,ind+n):
            arr[i, ind+n-1]= val
            val += 1
        for i in range(ind+n-2,ind-1,-1):
            arr[ind+n-1, i] = val
            val += 1
        for i in range(ind+n-2, ind,-1):
            arr[i, ind] = val
            val += 1
        spiral_rec(arr, n-2, val, ind+1)

def spiral(n):
    arr = np.zeros((n,n))
    spiral_rec(arr, n, 1, 0)
    print arr

spiral(2)
spiral(6)
