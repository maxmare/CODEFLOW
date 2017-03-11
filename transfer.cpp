#-----------------------------------------------------------------------
def findIntersectionClean(l1, l2, pt):
	p1 = [0,0]; point = [0,0]
	# di stands for direction index
	if abs(l1[1]-l1[1]) > abs(l1[0]-l1[0]):
		di = 1; dj = 0
	else: 
		di = 0; dj = 1
	pivot = [ l1[di+2], l1[dj+2] ]
	ppu = ( l1[di+2] - l1[di] ) / ( l1[dj+2] - l1[dj] )# projection per unit
	line2b = [l2[di], l2[dj], l2[di+2], l2[dj+2]]
	line2b[di] = line2b[di] + ppu * ( l1[dj+2] - l2[dj] )
	line2b[di+2] = line2b[di+2] + ppu * ( l1[dj+2] - l2[dj+2] )
	p1[di] = pivot[di]
	p1[dj] = line2b[dj] - ( line2b[di] - pivot[di] ) * ( (line2b[dj+2]-line2b[dj])/(line2b[di+2]-line2b[di]) )
	point[dj] = p1[dj]
	point[di] = pivot[di] - ppu * ( l1[dj+2] - p1[dj] )
	return point
#-----------------------------------------------------------------------
def findIntersection(l1, l2, pt):
	# di stands for direction index
	if abs(l1[1]-l1[1]) > abs(l1[0]-l1[0]):
		di = 1; dj = 0
	else: 
		di = 0; dj = 1
	print 'we are using the first line to base the projection'
	print 'and we use direction ', 'X' if di == 0 else 'Y', 'to project our point to'

	pivot = [ l1[di+2], l1[dj+2] ]
	ppu = ( l1[di+2] - l1[di] ) / ( l1[dj+2] - l1[dj] )# projection per unit
	print 'projection per unit: ', ppu
	print 'axis localion: ', l1[di+2]
	line2b = [l2[di], l2[dj], l2[di+2], l2[dj+2]]
	print l1[dj+2]
	print line2b
	line2b[di] = line2b[di] + ppu * ( l1[dj+2] - l2[dj] )
	line2b[di+2] = line2b[di+2] + ppu * ( l1[dj+2] - l2[dj+2] )
	print line2b# projected line
	print 'pivot is: ', pivot[di]
	p1 = [0,0]
	p1[di] = pivot[di]
	p1[dj] = line2b[dj] - ( line2b[di] - pivot[di] ) * ( (line2b[dj+2]-line2b[dj])/(line2b[di+2]-line2b[di]) )
	print line2b[di]
	print line2b[dj]
	print ((line2b[di+2]-line2b[di])/(line2b[dj+2]-line2b[dj]))
	print 'point on axis: ', p1# projected point
	point = [0,0]
	point[dj] = p1[dj]
	point[di] = pivot[di] - ppu * ( l1[dj+2] - p1[dj] )
	print 'projected point: ', point# projected point
	return point

#-----------------------------------------------------------------------
# find the intersection between two line segments
# result gives a code for whether there is an intersection or not,
# and the point of intersection (or 0,0 if there isn't)
from PIL import Image
from PIL import ImageDraw
import random
import math

random.seed(12345)
imgSize = 128
#imgSize = 512
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
lines = []
#lines.append([20.0,20.0,7.0,76.0]); lines.append([57.0,36.0,107.0,46.0])
#lines.append([10.0,30.0,7.0,76.0]); lines.append([57.0,36.0,107.0,46.0])
#lines.append([20.0,20.0,7.0,76.0]); lines.append([52.0,45.0,107.0,46.0])
#lines.append([52.0,45.0,7.0,76.0]); lines.append([20.0,20.0,107.0,46.0])
lines.append([22.0,22.0,88.0,88.0]); lines.append([22.0,88.0,88.0,22.0])
aax = [0.25, 0.75, 0.25, 0.75]; aay = [0.25, 0.25, 0.75, 0.75]
r1 = 100;	g1 = 0;		b1 = 0
r2 = 0;		g2 = 100;	b2 = 0
r3 = 0;		g3 = 0;		b3 = 100
leftEdge = 0; rightEdge = 0
di = -1

B = 0; G = 0
for i in range(128):
	for l in range(128):
		#for aa in range(4):
			#pt = [float(l)+aax[aa], float(i)+aay[aa]]
		B = 25; G = 25
		d0 = float(lines[0][0]-l)**2 + float(lines[0][1]-i)**2
		d1 = float(lines[0][2]-l)**2 + float(lines[0][3]-i)**2
		d2 = float(lines[1][0]-l)**2 + float(lines[1][1]-i)**2
		d3 = float(lines[1][2]-l)**2 + float(lines[1][3]-i)**2
		if d0 < 2 or d1 < 2 or d2 < 2 or d3 < 2:
			B = 255
		pt = (i,l)
		result = findIntersection(lines[0], lines[1], pt)

		d4 = float(result[0]-l)**2 + float(result[1]-i)**2
		if d4 < 4:
			G = 255
		newColor = (125, G, B) 
		d.point( (l,i), fill = newColor )

txt = txt.resize((512,512))
txt.show()
