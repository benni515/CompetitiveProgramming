# Look at dfs.py for comments 
# explaining how all this shit works

import sys
sys.setrecursionlimit(1000000)

def dfs(n):
    if n in visited:
        return
    visited.add(n)
    for e in connections[n]:
        dfs(e)

n, m = map(int, input().split())

global visited
global connections

houses = [i+1 for i in range(n)]
connections = {i+1:[] for i in range(n)}
visited = set()

for _ in range(m):
    x, y = map(int, input().split())
    connections[x].append(y)
    connections[y].append(x)

dfs(1)
if len(visited) == n:
    print("Connected")
else:
    for house in houses:
        if house not in visited:
        print(house)
