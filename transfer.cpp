#_________________________________________________________________________________________
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

	p = ( float(pt[0]-u2[0]), float(pt[1]-u2[1]), 0 )
	ppt = (float(p[0]), float(p[1])-float(p[0])*float(projHY), 0)
	pppt = ( (float(ppt[0]) + float(ppt[1])*float(projVY) ), float(ppt[1]), 0)

	if pt[0] == 30 and pt[1] == 20:
		print 'h:', h, 'v:', v
		print 'projHX:', projHX, 'projHY:', projHY
		print 'projVX:', projVX, 'projVY:', projVY
		print 'p:', p, 'ppt:', ppt, 'pppt:', pppt, 

	ma = pppt[0] / projHX
	mb = pppt[1] / projVX
	if ( ( ma**2 + mb**2 ) > 1 ):
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
		pt = [l,i]
		d0 = float(curves[0][0]-i)**2 + float(curves[0][1]-l)**2
		d1 = float(curves[1][0]-i)**2 + float(curves[1][1]-l)**2
		d2 = float(curves[2][0]-i)**2 + float(curves[2][1]-l)**2
		G = 25
		if d0 < 2 or d1 < 2 or d2 < 2:
			G = 200
		result = curveInside(curves[0], curves[1], curves[2], pt)
		if result:
			d.point( (l,i), fill = (0,G,150) )
		else:
			pick = txt.getpixel((l,i))
			newColor = (pick[0]+0, pick[1]+150, pick[2]+0) 
			d.point( (l,i), fill = (150,G,0) )
		pass

txt = txt.resize((512,512))
txt.show()
#print circles
#_________________________________________________________________________________________
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
		for k in range( int(width) ):
			xpos = x - int(width/2) + k
			pick = txt.getpixel((xpos,y))
			newColor = (pick[0] , g , pick[2]) 
			d.point( (xpos,y), fill = newColor )
		leftEdge = x - int(width/2) -1
		rightEdge = leftEdge + width +2
		for l in range( leftEdge, int(rightEdge) ):
			pick = txt.getpixel((xpos,y))
			newColor = (r2, pick[1] , pick[2] ) 
			d.point( (l,y+1), fill = (r2,g2,b2) )
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
#_________________________________________________________________________________________
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
#___________________________________________________________________________________________
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

lines.append([55,80])
lines.append([76,7])
aax = [0.25, 0.75, 0.25, 0.75]
aay = [0.25, 0.25, 0.75, 0.75]
r = 0; g = 100; b = 0
r2 = 100; g2 = 0; b2 = 0
leftEdge = 0; rightEdge = 0

# this fails when the line is nearly or totally horizontal,
if abs(lines[0][1]-lines[1][1]) > abs(lines[0][0]-lines[1][0]):
#if False:
	if lines[0][1] < lines[1][1]:
		bottom1 = lines[0][1]
		bottom2 = lines[1][1]
		m = 0
	else:
		bottom1 = lines[1][1]
		bottom2 = lines[0][1]
		m = 1

	deltaX = ( float(lines[0][0]) - float(lines[1][0]) ) / (float(lines[0][1])-float(lines[1][1]))
	l = int(lines[m][0])
	for i in range(int(bottom1)-1, int(bottom2)+2):
		if i >= int(bottom1) and i <= (int(bottom2)+0):
			d.point( (l,i), fill = (100,0,0) )
		for n in range(l-1, l+2):
			pick = txt.getpixel((n,i))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (n,i), fill = newColor )
		l += deltaX
		pass
#if True:
else:
	if lines[0][0] < lines[1][0]:
		bottom1 = lines[0][0]
		bottom2 = lines[1][0]
		m = 0
	else:
		bottom1 = lines[1][0]
		bottom2 = lines[0][0]
		m = 1

	deltaX = ( float(lines[0][1]) - float(lines[1][1]) ) / (float(lines[0][0])-float(lines[1][0]))
	l = int(lines[m][1])
	for i in range(int(bottom1)-1, int(bottom2)+2):
		if i >= int(bottom1) and i <= (int(bottom2)+0):
			d.point( (i,l), fill = (100,0,0) )
		for n in range(l-1, l+2):
			pick = txt.getpixel((i,n))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (i,n), fill = newColor )
		l += deltaX
		pass

txt = txt.resize((512,512))
txt.show()
#print circles



