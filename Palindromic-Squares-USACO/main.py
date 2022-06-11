"""
ID: Will Wang [chengti4]
LANG: PYTHON3
TASK: palsquare
"""

fin = open ('palsquare.in', 'r')
fout = open ('palsquare.out', 'w')

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
# n = int(input())
n = int(fin.readline())



for i in range(1, 301):
    int_squared = i**2
    if isPalindrome(numberToBase(int_squared, n)):
        # print(numberToBase(i, n), numberToBase(int_squared, n))
        fout.write(f"{numberToBase(i, n)} {numberToBase(int_squared, n)}\n")
    
    