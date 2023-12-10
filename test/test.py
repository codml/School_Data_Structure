import random as rd
import numpy as np

size = 12
p = 8 # 0 ~ 9
minimum = -7
maximum = 30
graph = np.zeros([size, size])

f = open("graph_L.txt", 'w')
g = open("graph_M.txt", 'w')
f.write('L\n')
f.write('%d\n' % size)
g.write('M\n')
g.write('%d\n' % size)
for i in range(1, size + 1):
	f.write('%d\n' % i)
	for j in range(1, size + 1):
		if i == j:
			g.write('0 ')
		else:
			randnum = rd.randint(0, 9)
			if randnum >= p and graph[j - 1, i - 1] == 0:
				rand = rd.randint(minimum, maximum)
				if rand != 0:
					f.write('%d %d\n' % (j, rand))
					g.write('%d ' % rand)
					graph[i - 1, j - 1] = rand
				else:
					g.write('0 ')
			else:
				g.write('0 ')
	g.write('\n')
f.close()
g.close()