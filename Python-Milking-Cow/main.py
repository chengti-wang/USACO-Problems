"""
ID: Will Wang [chengti4]
LANG: PYTHON3
TASK: milk2
"""

# fin = open ('milk2.in', 'r')
# fout = open ('milk2.out', 'w')
# n = fin.readline()
n = input()
n = int(n)
a = {}
mini = 1000001
maxi = -1
for i in range(n):
    first, second = list(map(int, input().split()))
    if first < mini:
        mini = first
    if second > maxi:
        maxi = second
    for j in range(first, second):
        a[j] = 0
# print(mini, maxi)
big_milk = 0
big_gap = 0
#print(a)
i = mini
while i < maxi:
    if i in a:
        milk = 0
        while i in a:
            i += 1
            milk += 1
        # print(milk)
        if milk > big_milk:
            big_milk = milk

        if i < maxi:
            gap = 0
            while i not in a:
                i += 1
                gap += 1
                if i >= maxi:
                    break
            if gap > big_gap:
                big_gap = gap
    
print(big_milk, big_gap)
            


# fout.close()