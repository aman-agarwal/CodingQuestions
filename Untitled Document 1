from collections import deque

def bfs(graph, start):
    queue = deque([start])
    visited = set([start])
    dist = {start:0}
    
    while len(queue) > 0:
        node = queue.popLeft()
        for x in graph[node]:
            if x not in visited:
                visited.insert(x)
                dist[x] = dist[node] + 1
                queue.insert(x)
    print dist

graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}
bfs(graph, 'A')
