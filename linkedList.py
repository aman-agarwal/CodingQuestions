
class Node:
  def __init__(self, val):
    self.val = val
    self.next = None

def reverse(node):
  prev = None 
  while node is not None:
    temp = node.next
    node.next = prev
    prev = node
    node = temp
  return prev 
    
def reverseK(node, k):
  i = 0
  while node is not None:
    count = 0
    start = node
    prev = None
    while node is not None and count < k:
      temp = node.next
      node.next = prev
      prev = node
      node = temp 
      count += 1
    if i == 0:
      first = prev
    else:
      startLast.next = prev
    startLast = start 
    i += 1
  return first   

def printList(node):
  while node is not None:
    print node.val
    node = node.next 

def addLeft(node, val):
  n = Node(val)
  n.next = node
  return n 

def create(lst):
  start = None
  for val in lst:
    if start is None: 
       start = Node(val)
       node = start
    else:
       node.next = Node(val)
       node = node.next 
  return start  

n = Node(1)
printList(n)
n=reverse(n)
#printList(n)
#n.next = Node(2)
#printList(n)
#reverse(n)
#printList(n)

