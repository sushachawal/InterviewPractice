# Probably can do this with a bi-directional search too! dijkstras
# is only useful when there are different costs associated with traversing
# certain paths in the graph!

import heapq
from sys import argv

def getPath(visited, s, e):
    path = []
    path.append(e)
    cur = e
    while cur != s:
        path.append(visited[cur][0])
        cur = visited[cur][0]
    return path[::-1]

def shortestPath(graph, s, e):
    pq = []
    visited = dict([])
    visited[s] = (0,0)
    heapq.heappush(pq, (0, s))
    while pq:
        node = heapq.heappop(pq)
        path = node[0]
        name = node[1]
        for child in graph[name]:
            if not child in visited:
                visited[child] = (name, path+1)
                if child == e:
                    return (path + 1, getPath(visited, s, e))
                heapq.heappush(pq, (path+1, child))
    return -1

g = {'a': ['b', 'c'], 'b': ['c', 'd', 'g'],
     'c': ['b', 'd', 'e'], 'd': ['g'], 'e': ['d'], 'g': []}

answer = shortestPath(g, argv[1], argv[2])

print("Shortest Path has distance: ", answer[0], " and is ", answer[1])
