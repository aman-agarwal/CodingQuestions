from collections import deque

def bfs(graph, start):
    queue = deque([start])
    visited = set([start])
    dist = {start:0}
    
    while len(queue) > 0:
        node = queue.popleft()
        for x in graph[node]:
            if x not in visited:
                visited.add(x)
                dist[x] = dist[node] + 1
                queue.append(x)
    print dist

def dfs(graph, start):
   lst = []
   visited = set([])
   _dfs(graph, start, lst, visited)
   print lst

def _dfs(graph, node,lst, visited):
   lst.append(node)
   visited.add(node)
   for x in graph[node]:
      if x not in visited:
         _dfs(graph, x, lst, visited)   

graph = {'A': set(['B', 'C', 'H']),
         'B': set(['A', 'D', 'E', 'G']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E']),
         'G': set(['B']),
         'H': set(['A'])}
bfs(graph, 'A')
dfs(graph, 'A')
