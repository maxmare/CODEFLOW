# test.py---------------------------------------------------------------
from PIL import Image
from PIL import ImageDraw
import random
import math

random.seed(12345)
imgSize = 128
#imgSize = 512
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
#d.text((10,10), "Hello", font=fnt, fill=(255,255,255,128))
circles = []
circles.append((80,80,20))
aax = [0.25, 0.75, 0.25, 0.75]
aay = [0.25, 0.25, 0.75, 0.75]

for x in range(51):
	for y in range(51):
		r = int(random.random()*255)
		g = int(random.random()*255)
		b = int(random.random()*255)

r = 0
g = 100
b = 0
r2 = 100
g2 = 0
b2 = 0

leftEdge = 0
rightEdge = 0
	
for i in circles:
	x = i[0]
	y = i[1] - i[2]
	for j in range( int( i[2]*2 ) ):
		width = math.pow( ( i[2]*i[2] - (y-i[1])*(y-i[1]) ) , 0.5) * 2
		xpos = 0
		for k in range(width):
			xpos = x - int(width/2) + k +1
			pick = txt.getpixel((xpos,y))
			newColor = (pick[0] , g , pick[2]) 
			d.point( (xpos,y), fill = newColor )
		leftEdge = x - int(width/2) -1
		rightEdge = leftEdge + width +2
		for l in range(leftEdge, rightEdge):
			pick = txt.getpixel((xpos,y))
			newColor = (r2, pick[1] , pick[2] ) 
#			d.point( (l,y+1), fill = (r2,g2,b2) )
		y += 1
#		print r
result = txt.getpixel((0,0))
print result 
for i in range( imgSize ):
	for j in range( imgSize ):
		pick = txt.getpixel((i,j))
		inc = 0
		for aa in range(4):
			distance  = (circles[0][0]-i+aax[aa])**2 + (circles[0][0]-j+aax[aa])**2
			radius = circles[0][2]**2
			if distance <= radius:
				inc += 50
		if inc < 200 and inc > 0:
				inc = 255
		elif inc > 0:
			inc = 100
		newColor = (pick[0] , pick[1] , inc ) 
		d.point( (i,j), fill=newColor )


txt = txt.resize((512,512))
txt.show()
print circles
# test_line.py----------------------------------------------------------
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
# test_quad.py----------------------------------------------------------
from PIL import Image
from PIL import ImageDraw
import random
import math

random.seed(12345)
imgSize = 128
#imgSize = 512
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
#d.text((10,10), "Hello", font=fnt, fill=(255,255,255,128))
quads = []
# points needs to be in order, CW or CCW
'''
quads.append([10,20])
quads.append([40,15])
quads.append([60,86])
quads.append([30,60])
'''
'''
quads.append([18,7])
quads.append([50,5])
quads.append([60,50])
quads.append([20,30])
'''
quads.append([20,30])
quads.append([18,7])
quads.append([50,5])
quads.append([60,50])
circles = []
circles.append((80,80,20))
aax = [0.25, 0.75, 0.25, 0.75]
aay = [0.25, 0.25, 0.75, 0.75]

r = 0
g = 100
b = 0
r2 = 100
g2 = 0
b2 = 0

leftEdge = 0; rightEdge = 0

#print quads[0]
	
top1 = 0; top2 = 0
for i in range(4):
	if top1 < quads[i][1]:
		top1 = quads[i][1]; t1 = i
for i in range(4):
	if top2 < quads[i][1] and quads[i][1] != top1:
		top2 = quads[i][1]; t2 = i

#print top1, top2
bottom1 = top1; bottom2 = top2

for i in range(4):
#	print quads[i][1]
	if bottom1 > quads[i][1]:
		bottom1 = quads[i][1]; b1 = i
for i in range(4):
	if bottom2 > quads[i][1] and quads[i][1] != bottom1:
		bottom2 = quads[i][1]; b2 = i
dirTop = t1 - t2
dirBottom = b1 - b2

#print top1, top2, bottom1, bottom2
#print t1, t2, b1, b2
#print dirTop, dirBottom

# now we need to run 3 loops that are linear, from top1 to top2, from top2 to bottom 2, and from bottom 2 to bottom1.
# first find out the deltaX 			

# we draw this qquad from bottom to top,

# processing the two bottoms,
# next point off bottom1 is,
ob1 = b1 + dirBottom
if ob1 > 3:
	ob1 = 0
if ob1 < 0:
	ob1 = 3
# x coord advances for every vertical pixel these values,
deltaX1 = ( float(quads[b1][0]) - float(quads[b2][0]) ) / (float(bottom1)-float(bottom2))
deltaX2 = ( float(quads[b1][0]) - float(quads[ob1][0]) ) / (float(bottom1)-float(quads[ob1][1]))
b1x = float(quads[b1][0])
b2x = float(quads[b1][0])
#print bottom1, bottom2
pLeft = -1; pRight = -1
for i in range(int(bottom1), int(bottom2)):
#	print b2x, b1x
	for l in range(int(b1x), int(b2x)):
		d.point( (l,i), fill = (100,0,0) )
		pass
	left = b1x; right = b2x
	if pLeft >= 0:
		nLeft = pLeft if pLeft < left else left
		nRight = pLeft if pLeft > left else left
		for l in range(nLeft-1, nRight+1):
			pick = txt.getpixel((l,i))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i), fill = newColor )
			pick = txt.getpixel((l,i-1))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i-1), fill = newColor )
		nLeft = pRight if pRight < right else right
		nRight = pRight if pRight > right else right
		for l in range(nLeft-1, nRight+1):
			pick = txt.getpixel((l,i))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i), fill = newColor )
			pick = txt.getpixel((l,i-1))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i-1), fill = newColor )
	pLeft = left; pRight = right
	b1x += deltaX1; b2x += deltaX2
	pass
# processing the middle section,
# next point off bottom2 is,
ob2 = b2 - dirBottom
if ob2 > 3:
	ob2 = 0
if ob2 < 0:
	ob2 = 3
# x coord advances for every vertical pixel these values,
deltaX3 = ( float(quads[b2][0]) - float(quads[ob2][0]) ) / (float(bottom2)-float(quads[ob2][1]))
t2x = float(quads[b2][0])
for i in range(int(bottom2), int(top2)):
	for l in range(int(t2x), int(b2x)):
		d.point( (l,i), fill = (100,0,0) )
		pass
	left = t2x; right = b2x
	nLeft = pLeft if pLeft < left else left
	nRight = pLeft if pLeft > left else left
	for l in range(nLeft-1, nRight+1):
		pick = txt.getpixel((l,i))
		newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
		d.point( (l,i), fill = newColor )
		pick = txt.getpixel((l,i-1))
		newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
		d.point( (l,i-1), fill = newColor )
	nLeft = pRight if pRight < right else right
	nRight = pRight if pRight > right else right
	for l in range(nLeft-1, nRight+1):
		pick = txt.getpixel((l,i))
		newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
		d.point( (l,i), fill = newColor )
		pick = txt.getpixel((l,i-1))
		newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
		d.point( (l,i-1), fill = newColor )
	pLeft = left; pRight = right
	t2x += deltaX3; b2x += deltaX2
	pass

# processing the two tops,
# next point off top1 is,
pLeft = -1; pRight = -1
ot1 = t1 + dirTop
if ot1 > 3:
	ot1 = 0
if ot1 < 0:
	ot1 = 3
# x coord advances for every vertical pixel these values,
deltaX1 = ( float(quads[t1][0]) - float(quads[t2][0]) ) / (float(top1)-float(top2))
deltaX2 = ( float(quads[t1][0]) - float(quads[ot1][0]) ) / (float(top1)-float(quads[ot1][1]))
#print deltaX1, deltaX2
t1x = float(quads[t1][0])
t2x = float(quads[t1][0])
#print top1, top2
for i in range(int(top1)-1, int(top2)-1, -1):
	for l in range(int(t1x), int(t2x)):
		d.point( (l,i), fill = (100,0,0) )
		pass
	left = t1x; right = t2x
	if pLeft >= 0:
		nLeft = pLeft if pLeft < left else left
		nRight = pLeft if pLeft > left else left
		for l in range(nLeft-1, nRight+1):
			pick = txt.getpixel((l,i))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i), fill = newColor )
			pick = txt.getpixel((l,i-1))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i-1), fill = newColor )
		nLeft = pRight if pRight < right else right
		nRight = pRight if pRight > right else right
		for l in range(nLeft-1, nRight+1):
			pick = txt.getpixel((l,i))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i), fill = newColor )
			pick = txt.getpixel((l,i-1))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i-1), fill = newColor )
	pLeft = left; pRight = right
	t1x -= deltaX1; t2x -= deltaX2
	pass

txt = txt.resize((512,512))
txt.show()
#print circles
# test_quad_Interp.py---------------------------------------------------
def getDistance(point):
	return pow( ( pow(point[0],2) + pow(point[1],2) ) ,0.5)

# returns a gradient, red 0-255 on the x and green, 0-255 on the y
def getGradientStyledPoint(point):
	dist = getDistance( ( 0.5-point[0], 0.5-point[1] ) ) 
	gradient  = (255-((dist*250+10)/20), 255-((dist*point[1]*5*250+10)/20), 255-((dist*point[0]*10*250+10)/20) )
	return gradient
 	
def getGradientPoint(point):
	gradient  = (int(point[0]*60), int(point[1]*60), int(point[0]*60) )
	return gradient

# returns the given point as parametric corrdinates relative to a quad
# defined by 4 points
def quadInterpolate(u1,u2,u3,u4,pt):
	result = False
	inBbox = True

	u = []
	u.append(u1); u.append(u2); u.append(u3); u.append(u4);
	#ux = [0,0]#ux[0] is the x that gets a projected y
	#uy = [0,0]#uy[1] is the y that gets a projected x

	seg1x = abs(u1[0] - u2[0])
	seg2x = abs(u3[0] - u2[0])
	minX = seg1x if seg1x < seg2x else seg2x
	seg1y = abs(u1[1] - u2[1])
	seg2y = abs(u3[1] - u2[1])
	minY = seg1y if seg1y < seg2y else seg2y
	#min = minX if minX < minY else minY

	h = 2 if minX < minY else 0
	v = 0 if h == 2 else 2
	
	projHX = u[h][0] - u[1][0]
	projHY = float( u[h][1] - u[1][1] ) / float(projHX)
	projVX = ( u[v][1] - u[1][1] ) - float( u[v][0] - u[1][0] ) * float(projHY)
	projVY = ( u[v][0] - u[1][0] ) / projVX

	#p1 = (u[h], u[h] * projX, 0,)
	#p2 = (u[h], u[h] * projX, 0,)
	#axisX = ux[v]
	#axisY = ux[h]

	p = ( float(pt[0])-float(u2[0]), float(pt[1])-float(u2[1]), 0 )
	ppt = (float(p[0]), float(p[1]) - float(p[0])*float(projHY), 0)
	pppt = ( (float(ppt[0]) - float(ppt[1])*float(projVY) ), float(ppt[1]), 0)

	p4 = ( float(u4[0])-float(u2[0]), float(u4[1])-float(u2[1]), 0 )
	pt4 = (float(p4[0]), float(p4[1]) - float(p4[0])*float(projHY), 0)
	ppt4 = ( (float(pt4[0]) - float(pt4[1])*float(projVY) ), float(pt4[1]), 0)
	# check whether is inside the 0->1 circle,
	ma = pppt[0] / projHX
	mb = pppt[1] / projVX
	
	maa = ppt4[0] / projHX
	mbb = ppt4[1] / projVX

	#if ( ( ma**2 + mb**2 ) > (1+0) ):

	#'''
	if int(pt[0]) == 59 and int(pt[1]) == 86:
		print 'h:', h, 'v:', v
		print 'projHX:', projHX, 'projHY:', projHY
		print 'projVX:', projVX, 'projVY:', projVY
		print 'p:', p, 'ppt:', ppt, 'pppt:', pppt 
		print 'p4:', p4, 'pt4:', pt4, 'ppt4:', ppt4
		print 'ma:', ma, 'mb:', mb, 'maa:', maa, 'mbb:', mbb
	#'''
	ma1 = ma
	ma = ma / (1+( (maa-1)*mb ))
	mb = mb / (1+( (mbb-1)*ma1))
	#mb = (mb / mbb)
	if int(pt[0]) == 59 and int(pt[1]) == 86:
		print 'ma:', ma, 'mb:', mb, 'maa:', maa, 'mbb:', mbb
	

	if ma > 0 and ma < 1 and mb > 0 and mb < 1:
		result = True
	else:
		result = False
	return (result, ma, mb)

from PIL import Image
from PIL import ImageDraw
import random
import math

random.seed(12345)
imgSize = 128
#imgSize = 512
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)

quads = []

quads.append([20,20])
quads.append([120,20])
quads.append([80,80])
quads.append([20,120])

quads.append([10,20])
quads.append([40,15])
quads.append([60,86])
quads.append([15,100])

quads.append([60,20])
quads.append([60,115])
quads.append([10,86])
quads.append([10,10])

quads.append([15,100])
quads.append([10,20])
quads.append([40,15])
quads.append([60,86])

aax = [0.25, 0.75, 0.25, 0.75]
aay = [0.25, 0.25, 0.75, 0.75]

r = 0
g = 100
b = 0
r2 = 100
g2 = 0
b2 = 0

for i in range(128):
	for l in range(128):
		Color = (0, 0, 0)
		for aa in range(4):
			pt = [float(l)+aax[aa], float(i)+aay[aa]]
			d0 = float(quads[0][0]-l)**2 + float(quads[0][1]-i)**2
			d1 = float(quads[1][0]-l)**2 + float(quads[1][1]-i)**2
			d2 = float(quads[2][0]-l)**2 + float(quads[2][1]-i)**2
			d3 = float(quads[3][0]-l)**2 + float(quads[3][1]-i)**2
			B = 0
			if d0 < 2 or d1 < 2 or d2 < 2 or d3 < 2:
				B = 250
			result = quadInterpolate(quads[0], quads[1], quads[2], quads[3], pt)
			#if False:
			if result[0]:
				input = [ result[1]/1, result[2]/1 ]
				newColor = getGradientStyledPoint(input)
				Color = (newColor[0]+Color[0], newColor[1]+Color[1], B)
				d.point( (l+0, i+0), fill=newColor )
				pass
			else:
				input = [float(i)/128.0, float(l)/128.0]
				newColor = getGradientStyledPoint(input)
				Color = (newColor[0]+Color[0], newColor[1]+Color[1], B)
				d.point( (l+0, i+0), fill=newColor )

txt = txt.resize((512,512))
txt.show()
#print circles
# test_curve.py---------------------------------------------------------
# returns whether or not a point falls inside a curve slice
# curve slice is defined by 3 points, the first and last are the end
# points
def curveInside(u1,u2,u3,pt):
	result = False
	inBbox = True

	u = []
	u.append(u1); u.append(u2); u.append(u3); 
	#ux = [0,0]#ux[0] is the x that gets a projected y
	#uy = [0,0]#uy[1] is the y that gets a projected x

	seg1x = abs(u1[0] - u2[0])
	seg2x = abs(u3[0] - u2[0])
	minX = seg1x if seg1x < seg2x else seg2x
	seg1y = abs(u1[1] - u2[1])
	seg2y = abs(u3[1] - u2[1])
	minY = seg1y if seg1y < seg2y else seg2y
	#min = minX if minX < minY else minY

	h = 2 if minX < minY else 0
	v = 0 if h == 2 else 2
	
	projHX = u[h][0] - u[1][0]
	projHY = float( u[h][1] - u[1][1] ) / float(projHX)
	projVX = ( u[v][1] - u[1][1] ) - float( u[v][0] - u[1][0] ) * float(projHY)
	projVY = ( u[v][0] - u[1][0] ) / projVX

	#p1 = (u[h], u[h] * projX, 0,)
	#p2 = (u[h], u[h] * projX, 0,)
	#axisX = ux[v]
	#axisY = ux[h]

	p = ( float(pt[0])-float(u2[0]), float(pt[1])-float(u2[1]), 0 )
	ppt = (float(p[0]), float(p[1]) - float(p[0])*float(projHY), 0)
	pppt = ( (float(ppt[0]) - float(ppt[1])*float(projVY) ), float(ppt[1]), 0)

	if pt[0] > 30 and pt[1] > 20 and pt[0] < 31 and pt[1] < 21:
		print 'h:', h, 'v:', v
		print 'projHX:', projHX, 'projHY:', projHY
		print 'projVX:', projVX, 'projVY:', projVY
		print 'p:', p, 'ppt:', ppt, 'pppt:', pppt, 

	ma = pppt[0] / projHX
	mb = pppt[1] / projVX
	if ( ( ma**2 + mb**2 ) > (1+0) ):
		result = True
	else:
		result = False
	return result

from PIL import Image
from PIL import ImageDraw
import random
import math

random.seed(12345)
imgSize = 128
#imgSize = 512
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)

curves = []
curves.append([10,20])
curves.append([40,15])
curves.append([60,86])

curves.append([60,50])
curves.append([20,30])
curves.append([0,0])

curves.append([30,60])
curves.append([18,7])
curves.append([50,5])

aax = [0.25, 0.75, 0.25, 0.75]
aay = [0.25, 0.25, 0.75, 0.75]

r = 0
g = 100
b = 0
r2 = 100
g2 = 0
b2 = 0

for i in range(128):
	for l in range(128):
		for aa in range(4):
			pt = [float(l)+aax[aa], float(i)+aay[aa]]
			d0 = float(curves[0][0]-l)**2 + float(curves[0][1]-i)**2
			d1 = float(curves[1][0]-l)**2 + float(curves[1][1]-i)**2
			d2 = float(curves[2][0]-l)**2 + float(curves[2][1]-i)**2
			G = 25
			if d0 < 2 or d1 < 2 or d2 < 2:
				G = 200
			result = curveInside(curves[0], curves[1], curves[2], pt)
			if result:
				pick = txt.getpixel((l,i))
				newColor = (pick[0]+0, G, pick[2]+60) 
				d.point( (l+0,i+0), fill = newColor )
			else:
				pick = txt.getpixel((l,i))
				newColor = (25, G, pick[2]+0) 
				d.point( (l,i), fill = newColor )
			pass

txt = txt.resize((512,512))
txt.show()
# test_line_intersection.py---------------------------------------------
# in python, don't use multi-dimension arrays, only flat arrays
# in c, don't use structs for anything that contains homogeneous types,
# use only flat arrays
'''
//-C--------------------------------------------------------------------
// find point of intersection between 2 line segments
#include <stdio.h>
#include <math.h>

struct point{
	float* ptx;
	float* pty;
};

struct line{
	float* cd;
};

point findIntersection(line l1, line l2, point pt){
	point p1 = {0,0}; 
	point pInt = {0,0};
	if( abs(l1.cd[1]-l1.cd[1]) > abs(l1.cd[0]-l1.cd[0]) ){// di stands for direction index
		int di = 1; int dj = 0;
		}
	else{ 
		int di = 0; int dj = 1;
		}
/*
	point pivot = { l1.cd[di+2], l1.cd[dj+2] };
	float ppu = ( l1.cd[di+2] - l1.cd[di] ) / ( l1.cd[dj+2] - l1.cd[dj] );// projection per unit
	float line2b = { l2.cd[di], l2.cd[dj], l2.cd[di+2], l2.cd[dj+2] };
	line2b[di] = line2b.cd[di] + ppu * ( l1[dj+2] - l2[dj] );
	line2b[di+2] = line2b[di+2] + ppu * ( l1[dj+2] - l2[dj+2] );
	p1[di] = pivot[di];
	p1[dj] = line2b[dj] - ( line2b[di] - pivot[di] ) * ( (line2b[dj+2]-line2b[dj])/(line2b[di+2]-line2b[di]) );
	pInt[dj] = p1[dj];
	pInt[di] = pivot[di] - ppu * ( l1[dj+2] - p1[dj] );
//*/
	return pInt;
}

int main(){
	printf("Hello world!");
}

/*
'''
#-PYTHON----------------------------------------------------------------
# find point of intersection between 2 line segments
# no comments
def findIntersectionClean(l1, l2, pt):
	p1 = [0,0];
	point = [0,0]
	if abs(l1[1]-l1[1]) > abs(l1[0]-l1[0]):# di stands for direction index
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
# find point of intersection between 2 line segments
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
import time

random.seed(time.time()*1000)
imgSize = 128
#imgSize = 512
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
lines = []
#lines.append([20.0,20.0,7.0,76.0]); lines.append([57.0,36.0,107.0,46.0])
#lines.append([10.0,30.0,7.0,76.0]); lines.append([57.0,36.0,107.0,46.0])
#lines.append([20.0,20.0,7.0,76.0]); lines.append([52.0,45.0,107.0,46.0])
#lines.append([52.0,45.0,7.0,76.0]); lines.append([20.0,20.0,107.0,46.0])
#lines.append([22.0,22.0,88.0,88.0]); lines.append([22.0,88.0,88.0,22.0])
lines.append([random.random()*128,
	random.random()*128,
	random.random()*128,
	random.random()*128])
lines.append([random.random()*128,
	random.random()*128,
	random.random()*128,
	random.random()*128])
aax = [0.25, 0.75, 0.25, 0.75]; aay = [0.25, 0.25, 0.75, 0.75]
r1 = 100;	g1 = 0;		b1 = 0
r2 = 0;		g2 = 100;	b2 = 0
r3 = 0;		g3 = 0;		b3 = 100
leftEdge = 0; rightEdge = 0
di = -1

B = 0; G = 0; R = 0
for i in range(128):
	for l in range(128):
		#for aa in range(4):
			#pt = [float(l)+aax[aa], float(i)+aay[aa]]
		B = 25; G = 25; R = 25
		d0 = float(lines[0][0]-l)**2 + float(lines[0][1]-i)**2
		d1 = float(lines[0][2]-l)**2 + float(lines[0][3]-i)**2
		if d0 < 2 or d1 < 2:
			R = 255
		d2 = float(lines[1][0]-l)**2 + float(lines[1][1]-i)**2
		d3 = float(lines[1][2]-l)**2 + float(lines[1][3]-i)**2
		if d2 < 2 or d3 < 2:
			B = 255
		pt = (i,l)
		result = findIntersection(lines[0], lines[1], pt)

		d4 = float(result[0]-l)**2 + float(result[1]-i)**2
		if d4 < 4:
			G = 255
		newColor = (R, G, B) 
		d.point( (l,i), fill = newColor )

txt = txt.resize((512,512))
txt.show()

//*/
