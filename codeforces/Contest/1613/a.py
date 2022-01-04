import math
for _ in range(int(input())):
    a1, p1 = map(int, input().split())
    a1 = str(a1)
    l1 = len(a1) + p1
    a2, p2 = map(int, input().split())
    a2 = str(a2)
    l2 = len(a2) + p2

    if a1 == a2:
        if a1 == "0":  print("=")
        else:
            if p1 > p2:     print(">")
            elif p1 == p2:  print("=")
            else:  print("<")
    elif l1 == l2:
        lmax = max(len(a1), len(a2))
        t1, t2 = int(a1[:lmax].ljust(lmax, "0")), int(a2[:lmax].ljust(lmax, "0"))
        if t1 > t2:  print(">")
        elif t1 == t2: print("=")
        else:  print("<")
    else:
        if l1 > l2: print(">")
        else:  print("<")