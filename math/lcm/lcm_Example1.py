# Open.kattis.com
# Smallest Multiple
# This is written in python becouse the numbers get really big

def gcd(a,b):
    while b:
        a,b = b, a%b
    return a

def lcm(a,b):
        return a * b // gcd(a,b)

while True:
    try:
        m = [int(x) for x in input().split()]
        num = m[0]
        for x in range(1,len(m)):
            num = lcm(num,m[x])
        print(int(num))
    except:
        break
