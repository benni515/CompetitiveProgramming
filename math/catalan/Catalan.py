import sys
d = {}
# This can compute the nth Catalan number
# Call the compose with a bigger number if needed to compute an higher Catalan Number
# Sys.stdout is to write faster out

def compose(n):
    k = 1
    to = (n*2)+1
    for x in range(1,to):
        k*=x
        d[x] = k

compose(5000)

q = int(input())
for x in range(0,q):
    num = int(input())
    first = d[num*2]
    second = d[num+1]*d[num]
    sys.stdout.write(str(int(first//second))+"\n")
