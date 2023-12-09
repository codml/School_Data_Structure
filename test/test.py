import random as rd

f = open("graph_L.txt", 'w')
f.write('L\n')
f.write('15\n')
for i in range(1, 16):
	f.write('%d\n' % i)
	for j in range(i + 1, 16):
		randnum = rd.randint(0, 9)
		if randnum >= 5:
			rand = rd.randint(-100, 100)
			f.write('%d %d\n' % (j, rand))
f.close()