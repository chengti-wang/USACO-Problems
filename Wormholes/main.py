"""
ID: Will Wang [chengti4]
LANG: PYTHON3
TASK: wormhole
"""

holeTo = [0]*13
# fin = open ('wormhole.in', 'r')
# fout = open ('wormhole.out', 'w')

Cnt = 0
def check(b):
	start_pos = []
	pos = []

	for i in range(1,len(b)+1):
		iam = i
		Inf = 1
		for i in range(1, len(b)+1):
			igo = holeTo[iam]
			near = 100000001
			will_go
			for k in range(1, len(b)+1):
				if k!=i and b[k,1]==b[i,1]:
					dest = b[k,0] - b[i,0]
					if dest < near:
						near = dest
						will_go = k
			if near == 100000001:
				Inf = 0
				break
			else:
				iam = will_go
		if Inf == 1:
			Cnt=Cnt+1
		
def recr(b):
	# find the unused HoleTo
	temp = 0
	for i in range(1, len(b)+1):
		if not holeTo[i]:
			temp = i
	if(temp == 0):
		check(b)
		
	else:
		for i in range(temp + 1, len(b)+1):
			if not holeTo[i]:
				holeTo[i] = temp
				holeTo[temp] = i
				recr(b)
				holeTo[i] = 0
				holeTo[temp] = 0
a = []
for i in range(13):
	a.append([])
	for j in range(13):
		a[i].append(0)

n = input()
b = []
for i in range(n):
	g = input().split()
	b.append(g)