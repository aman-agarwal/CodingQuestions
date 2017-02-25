arr = [1, 2, 3, 4, 5, 6]
x = 1

i = 0
j = len(arr) -1
while i <= j:
   if arr[int((i+j) * 0.5)] == x:
       print int((i+j) * 0.5)
       break
   elif arr[int(i+j) * 0.5)] > x:
       j = j-1
   else:
      i = i + 1
