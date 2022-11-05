import math


class point2D:
    def __init__(self, x, y) :
        self.x = x
        self.y = y

def dt(p1, p2) :
    a = p1.x - p2.x
    b = p1.y - p2.y
    c = math.sqrt(a**2 + b**2)
    return c


x,y,d,t = map(int, input().split())
o = point2D(0, 0)
p = point2D(x,y)
currentDistance = dt(o,p)
time = []
WJtime = 0
JJtime = 0

#걸어서만 가는 경우
time.append(currentDistance)

#점프만 하는 경우
currentDistance = dt(o,p)
while currentDistance > 2*d :
    currentDistance -= d
    JJtime += t
JJtime += 2*t
time.append(JJtime)

#점프하다가 걷는 경우
currentDistance = dt(o,p)
while currentDistance > 2*d :
    currentDistance -= d
    WJtime += t
WJtime += abs(currentDistance - d) + t
time.append(WJtime)



print(min(time))