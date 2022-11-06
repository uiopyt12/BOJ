C = int(input())

import decimal

for i in range(C) :
    rat, gstu = 0, 0
    each = list(map(int, input().split()))
    each.reverse()
    dmom = each.pop()
    
    avr = decimal.Decimal(sum(each) / dmom)
    
    for stu in each :
        if stu > decimal.Decimal(avr) :
            gstu += 1
            
    rat = decimal.Decimal(100*float(gstu)/float(dmom))
    print('{0:0.3f}%'.format(decimal.Decimal(rat)))
