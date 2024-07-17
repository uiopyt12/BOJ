N = int(input())
x, y = 0, 0

if N == 4 or N == 7 :
    print('-1')
else :
    while N%5 != 0 :
        N -= 3
        y += 1

    print('{0}'.format(y + int(N/5)))