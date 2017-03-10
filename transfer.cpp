#-----------------------------------------------------------------------
def findIntersection(n, pt):
	u = []
	u.append([20,20]); u.append([7,76]); u.append([57,36]); u.append([107,46])

	seg1x = abs(u[1][0] - u[0][0])
	seg2x = abs(u[3][0] - u[2][0])
	minX = seg1x if seg1x < seg2x else seg2x
	seg1y = abs(u[0][1] - u[1][1])
	seg2y = abs(u[3][1] - u[2][1])
	minY = seg1y if seg1y < seg2y else seg2y
	h = 2 if minX < minY else 0
	v = 0 if h == 2 else 2
	if pt[0] == 50 and pt[1] == 50:
		print 'minX:', minX
		print 'minY:', minY
		print 'h:', h
		print 'v:', v

	projHX = u[h+1][0] - u[h][0]
	projHY = float( u[h+1][1] - u[h][1] ) / float(projHX)

	#p = ( float(pt[0])-float(u[h]), float(pt[1])-float(u[h+1]), 0 )# delta for pt
	#ppt = (float(p[0]), float(p[1]) - float(p[0])*float(projHY), 0 )# projection pt
	#pppt = ( (float(ppt[0]) - float(ppt[1])*float(projVY) ), float(ppt[1]), 0)

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
lines.append([20,20]); lines.append([7,76]); lines.append([57,36]); lines.append([107,46])
aax = [0.25, 0.75, 0.25, 0.75]; aay = [0.25, 0.25, 0.75, 0.75]
r1 = 100;	g1 = 0;		b1 = 0
r2 = 0;		g2 = 100;	b2 = 0
r3 = 0;		g3 = 0;		b3 = 100
leftEdge = 0; rightEdge = 0
di = -1

# di stands for direction index
if abs(lines[0][1]-lines[1][1]) > abs(lines[0][0]-lines[1][0]):
	di = 1; dj = 0
else: 
	di = 0; dj = 1
B = 0
for i in range(128):
	for l in range(128):
		#for aa in range(4):
			#pt = [float(l)+aax[aa], float(i)+aay[aa]]
		B = 25
		d0 = float(lines[0][0]-l)**2 + float(lines[0][1]-i)**2
		d1 = float(lines[1][0]-l)**2 + float(lines[1][1]-i)**2
		d2 = float(lines[2][0]-l)**2 + float(lines[2][1]-i)**2
		d3 = float(lines[3][0]-l)**2 + float(lines[3][1]-i)**2
		if d0 < 2 or d1 < 2 or d2 < 2 or d3 < 2:
			B = 255
		pt = (i,l)
		result = findIntersection(1, pt)
		if result:
			newColor = (25, 25, B)
		else:
			newColor = (125, 225, B) 
		d.point( (l,i), fill = newColor )

txt = txt.resize((512,512))
txt.show()
