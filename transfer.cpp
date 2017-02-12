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
		newColor = (pick[0] , pick[1] , inc ) 
		d.point( (i,j), fill=newColor )


txt = txt.resize((512,512))
txt.show()
print circles
