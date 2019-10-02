import sys
import numpy as np

class Node:
   def __init__(self, val):
      self.val = val
      self.l = None
      self.r = None

class Tree:
   def __init__(self):
      self.root = None
   
   def insert(self, val):
      if self.root is not None:
         self._insert(val, self.root)
      else:
         self.root = Node(val)
    
   def _insert(self, val, node):
      if node.val >= val:
         if node.l is None:
            node.l = Node(val)
         else:
            self._insert(val, node.l)
      else:
         if node.r is None:
            node.r = Node(val)
         else:
            self._insert(val, node.r)

   def inorder(self,lst):
      self._inorder(self.root,lst)
 
   def _inorder(self, node, lst):
      if node is not None:
         self._inorder(node.l, lst)
         lst.append(node.val)
         self._inorder(node.r, lst)

   def find(self, val):
      return self._find(val, self.root)

   def _find(self,val, node):
      if node is None: 
         return 0
      elif node.val == val:
         return 1
      elif node.val < val:
         return self._find(val, node.r)
      else:
         return self._find(val, node.l)
 
   def balanced(self):
      min_dist = [None]
      max_dist = [None]
      self._balanced(self.root, min_dist, max_dist, 0)
      if max_dist[0] - min_dist[0]  > 1:
         return 0
      else:
         return 1
   
   def _balanced(self, node, min_dist, max_dist, dist):
      if (node.l == None and node.r == None):
         if min_dist[0] == None:
            min_dist[0] = dist
            max_dist[0] = dist
         else: 
            if dist < min_dist[0]:
               min_dist[0] = dist
            if dist > max_dist[0]:
               max_dist[0] = dist
      else:
         if node.l is not None:
            self._balanced(node.l, min_dist, max_dist, dist+1)
         if node.r is not None:
            self._balanced(node.r, min_dist, max_dist, dist+1)
   
   def levelorder(self):
      lst = [(self.root,0)]
      for x,d in lst:
         if x.l is not None:
            lst.append((x.l,d+1))
         if x.r is not None:
            lst.append((x.r,d+1))
      d_prev = 0
      for x,d in lst:
         if d > d_prev:
            d_prev = d
            print
         sys.stdout.write(str(x.val) + " ")
      print
 
   def min_height(self, sortedArr):
      mid = len(sortedArr)/2
      self.root = Node(sortedArr[mid])
      self._min_height(self.root, sortedArr[0: mid], sortedArr[mid+1:])

   def _min_height(self, node, arr1, arr2):
      mid1 = len(arr1)/2 
      mid2 = len(arr2)/2 
      if len(arr1) > 0: 
         node.l = Node(arr1[mid1])
         self._min_height(node.l, arr1[0: mid1], arr1[mid1+1:])  
      if len(arr2) > 0:  
         node.r = Node(arr2[mid2])
         self._min_height(node.r, arr2[0: mid2], arr2[mid2+1:])
       
   def commonAnc(self, v1, v2):
      return self. _commonAnc(self.root, v1, v2)[2]

   def _commonAnc(self, node, v1, v2):
      if node is None:
         return (False, False, None)
 
      t1 = self._commonAnc(node.l, v1, v2)
      t2 = self._commonAnc(node.r, v1, v2)
    
      if t1[2] is not None:
         return (True, True, t1[2])
      if t2[2] is not None:
         return (True, True, t2[2])
      f1 = (node.val==v1) or t1[0] or t2[0]
      f2 = (node.val==v2) or t1[1] or t2[1]
      if f1 and f2:
         return (True, True, node.val)
      return (f1, f2, None)

  def _pair(self, node1, node2):
       node1.r = node2
       node2.l = node1 

  def _dll(self, node):
      left = None
      right = None 
      if node.l is not None:
           left = _dll(node.l)
      if node.r is not None:
           right = _dll(node.r)
      if left is None and right is None:
           return (node, node)
      if left is None:
           _pair(node, right[0])
           return (node, right[1])
      if right is None:
          _pair(node, left[0])
          return (node, left[1])
      _pair(node, left[0])
      _pair(left[1], right[0])
      return (node, right[1])     

  def dll(self):
      return _dll(self.root)[0]

x = int(sys.argv[1])
y = int(sys.argv[2])
lst = np.array(sys.argv[3:], dtype=int)
tree = Tree()
#tree.min_height(np.sort(lst))
for z in lst: 
   tree.insert(z)

lst = []
tree.inorder(lst)
print lst

tree.levelorder()

#print tree.find(x)
#print tree.balanced()
print tree.commonAnc(x,y)


