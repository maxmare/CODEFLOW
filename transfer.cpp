from PIL import Image
from PIL import ImageDraw
import random
import math

random.seed(12345)
txt = Image.new('RGBA', (128,128), (5,25,20,0))#base.size
d = ImageDraw.Draw(txt)
#d.text((10,10), "Hello", font=fnt, fill=(255,255,255,128))
circles = []
circles.append((80,80,20))
for x in range(51):
	for y in range(51):
		r = int(random.random()*255)
		g = int(random.random()*255)
		b = int(random.random()*255)

r = 20
g = 30
b = 130
r2 = 120
g2 = 30
b2 = 30

leftEdge = 0
rightEdge = 0
	
for i in circles:
	x = i[0]
	y = i[1] - i[2]
	for j in range( int( i[2]*2 ) ):
		width = math.pow( ( i[2]*i[2] - (y-i[1])*(y-i[1]) ) , 0.5) * 2
		for k in range(width):
			xpos = x - int(width/2) + k
			d.point( (xpos,y), fill = (r,g,b) )
		for l in range(leftEdge, rightEdge):
			d.point( (l,y-1), fill = (r2,g2,b2) )
			
		leftEdge = x - int(width/2)
		rightEdge = leftEdge + width
		y += 1
#		print r
txt = txt.resize((1024,1024))
txt.show()
print circles
