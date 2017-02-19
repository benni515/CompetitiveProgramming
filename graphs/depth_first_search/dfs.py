import sys
sys.setrecursionlimit(1000000)
# Important for large graphs,
# this is almost always needed

def dfs(n):
    # Searches an undirected
    # or a directed graph
    if n in visited:
        return
    visited.add(n)
    for e in connections[n]:
        #Recursively dfs every vertice
        dfs(e)


# Gotta have the global keyword
global visited
global connections

# Nodes is a list of keys for the
# vertices dictionary
nodes = []

# Connections is a collection of all 
# the connections between all the nodes
connections = {}

# Visited is a set for fast lookup times
# You can also access an array by indices,
# if you don't want to use a set
visited = set()

for n in nodes:
    #dfs every node
    dfs(n)
