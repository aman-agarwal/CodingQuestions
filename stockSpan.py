
def stockSpan(arr):
  temp = [0]*len(arr)
  cum = [0]*len(arr)
  temp[0] = 1
  cum[0] = 1
  pind = None 
  for i in range(1,len(arr)):
    if arr[i] < arr[i-1]:
       pind = i-1
       temp[i] = 1
    else:
       s = 1
       if pind is None:
         temp[i] = temp[i-1]+1
       else:
         cind = pind
         temp[i] = 1+cum[i-1]-cum[cind]  
         while cind >= 0 and arr[cind] <= arr[i]:
           temp[i] += temp[cind]
           cind = cind-temp[cind]
    cum[i] = cum[i-1]+temp[i]
  print temp 
