import random as rd

f = open("test.txt", 'w')
for i in range(1, 11):
	f.write('%d\n' % i)
	for j in range(i + 1, 11):
		rand = rd.randint(1, 100)
		f.write('%d %d\n' % (j, rand))
f.close()