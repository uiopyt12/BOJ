import sys

n,m,b = map(int,sys.stdin.readline().split())
ground = list()
top,bot = 0,256
total = 0
time = 0




for i in range(n) :    #땅만들기
    ip = sys.stdin.readline().split()
    
    for a in range(m) :
        ground.append(int(ip[a]))



        
for g in ground :    #바닥과 천장
     if g > top :
        top = g
     if g < bot :
        bot = g
     total += g
    



if len(ground) % 3 == 0 :
    mini = int(len(ground)/3)
else :
    mini = int(len(ground)//3 + 1)
ground.sort()
ground.reverse()


if (total + b) // len(ground) >= ground[mini-1] : # 극소 전에서 만들 수 있는 경우, 그냥 극소에서 값 반환
    std = ground[mini-1]
    for i in ground :
            if i < std : #기준점보다 낮은 블록
                time += (std - i)
            elif i > std : #기준점보다 높은 블록
                time += 2*(i-std)
    print(time, std)
            

else : #극소를 지나야 되는 경우 (total + b) // len(ground)층까지만 만들 수 있음
    std = (total + b) // len(ground)
    for i in ground :
            if i < std : #기준점보다 낮은 블록
                time += (std - i)
            elif i > std : #기준점보다 높은 블록
                time += 2*(i-std)
    print(time, std)