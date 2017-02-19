import string

class Node():
    def __init__(self, s=""):
        self.value = s
        self.edges = {s: None for s in string.ascii_lowercase}
        self.prefixes = 0

    def __str__(self):
        return self.value

    def __len__(self):
        return self.prefixes

class Trie():
    def __init__(self):
        self.root = Node()
        self.visited = set()

    def insert(self, s):
        #Inserts a word into the trie
        node = self.root
        for c in s:
            if node.edges[c] == None:
                newnode = Node(c)
                node.edges[c] = newnode
            # Move the prefixes += 1 before the node line
            # to change it into a true prefix only count
            node = node.edges[c]
            node.prefixes += 1

    def find(self):
        pass
    
    def count(self, s):
        # Counts the number of prefixes for a word
        # NOTE: Includes the word itself as a prefix
        node = self.root
        for c in s:
            if node.edges[c] == None:
                break
            node = node.edges[c]
        else:
            return len(node)
        return 0

# example of usage:
# bing on open.kattis.com
t = Trie()
n = int(input())
for _ in range(n):
    s = input()
    print(t.count(s))
    t.insert(s)
