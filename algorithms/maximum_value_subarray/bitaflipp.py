n = int(input())

og = []
l = []
for x in input().split():
    og.append(int(x))
    l.append(-1 if x == "1" else 1)

j = 0
left = 0
right = 0

optimal = -2**32
local_sum = 0

for i in range(n):
    local_sum += l[i]
    if local_sum > optimal:
        optimal = local_sum
        left = j
        right = i+1
    if local_sum < 0:
        j = i + 1
        local_sum = 0


bitaflipp = og[0:left] + og[right:] + l[left:right]
print(bitaflipp.count(1))
