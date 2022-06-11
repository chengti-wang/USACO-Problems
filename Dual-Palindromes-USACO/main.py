"""
ID: Will Wang [chengti4]
LANG: PYTHON3
TASK: dualpal
"""

fin = open ('dualpal.in', 'r')
fout = open ('dualpal.out', 'w')

letter = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K']

def isPalindrome(s):
    return s == s[::-1]

def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    digits = digits[::-1]
    new_digits = []
    for i in digits:
        if i > 9:
            new_digits.append(letter[i])
        else:
            new_digits.append(i)
    new_digits = [str(x) for x in new_digits]
    base_num = ''
    for string in new_digits:
        base_num += string
    return base_num



# print(numberToBase(204, 10))
# a = list(map(int, input().split()))
a = list(map(int, fin.readline().split()))
n = a[0]
s = a[1]




counter = 0
while counter < n:
    s += 1
    counter_2 = 0
    for i in range(2, 11):
           if isPalindrome(numberToBase(s, i)):
               counter_2 += 1
               if counter_2 >= 2:
                   fout.write(f"{s}\n")
                   counter += 1
                   break
    