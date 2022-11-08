def d(n) :
    ans = n
    for i in str(n) :
        ans += int(i)
    return ans

sol,an = list(),list()

for i in range(1, 10001) :
    sol.append(i)
    an.append(i)

for n in sol :
    try :
        an.remove(d(n))
    except :
        pass

for n in an :
    print(n)