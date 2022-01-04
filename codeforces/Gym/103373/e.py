import math
 
p, q = map(int, input().split())
 
x = 0
 
x = 0
i = 1
while 1:
    x += p 
    if p <= q * i**5:
        break
    x -= q * i**5
    i += 1
 
print(x)
X = x
 
def f(x):
    return (q * x * x * (x + 1) ** 2 * (2 * x ** 2 + 2 * x -1 ))//12 - p * x + X
 
l, r = 0, 10**99
C = 10**99
res = 0
while l <= r:
    mid = ((l + r) // 2)
    if (f(mid) < C): l = mid+1
    else: r, res = mid - 1, mid
 
print(res)