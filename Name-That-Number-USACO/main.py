"""
ID: Will Wang [chengti4]
LANG: PYTHON3
TASK: namenum
"""

# fin = open ('namenum.in', 'r')
# fout = open ('namenum.out', 'w')




def permutations(cur_s, i, length):
    if len(cur_s) == length:
        lst.append(cur_s)
    else:
        for j in range(3):
            cur_s += a[i][j]
            permutations(cur_s, i+1, length)
            cur_s = cur_s[:-1]
            
def main():
    with open("dict.txt", "r") as f:
        d = {}
        for line in f:
            d[line.strip()] = 0
    num = fin.readline()
    # num = input()
    length = len(num)
    dict = {
        '2': ['A', 'B', 'C'],
        '3': ['D', 'E', 'F'],
        '4': ['G', 'H', 'I'],
        '5': ['J', 'K', 'L'],
        '6': ['M', 'N', 'O'],
        '7': ['P', 'R', 'S'],
        '8': ['T', 'U', 'V'],
        '9': ['W', 'X', 'Y']
    }
    
    
    a = []
    for chr in num:
        a.append(dict[chr])
    
    lst = []
    lst2 = []
    permutations('', 0, length)
    for word in lst:
        if word in d:
            lst2.append(word)
    lst2.sort()
    for i in lst2:
        # print(i)
        fout.write(i)
