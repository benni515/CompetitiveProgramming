# Pretty sure this is a valid Data Structure for Union-Find in python
# But this is really slow, aint even fast enough for the union-find on kattis
# This is still the same concept as the C++ Implemenation

class UnionFind:
    def __init__(self,n):
        self.p = list(range(n))
    def find(self,x):
        if self.p[x] == x:
            return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    def unite(self,a,b):
        self.p[self.find(a)] = self.find(b)
    def joined(self,a,b):
        if self.find(a) == self.find(b):
            return True
        return False

