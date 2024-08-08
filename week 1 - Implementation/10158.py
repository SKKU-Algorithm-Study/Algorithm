w, h = map(int, input().split())
p, q = map(int, input().split())
t = int(input())

flag_p = (p + t) // w
flag_q = (q + t) // h

if flag_p % 2 == 0:
    p = (p + t) % w
else:
    p = w - (p + t) % w
if flag_q % 2 == 0:
    q = (q + t) % h
else:
    q = h - (q + t) % h
print(p, q)
