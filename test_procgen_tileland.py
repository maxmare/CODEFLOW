# procedural generation of a tiling patch of land
#-------------------------------------------------------------------------------
from PIL import Image, ImageDraw, ImageFont
import random
import time
import math
import random

def changeToLand(i,j):
	pxPos = [ (-1,0), (0,-1), (1,0), (0,1) ]
	count = 0
	for m in range(4):
		newPxPos = (i + pxPos[m][0], j + pxPos[m][1] )
		pickb = txt.getpixel( newPxPos )
		if pickb[1] == 175:
			count += 1
	if count > 1:
		return True
	else:
		return False
	pass

def changeToSea(i,j):
	pxPos = [ (-1,0), (0,-1), (1,0), (0,1) ]
	count = 0
	for m in range(4):
		newPxPos = (i + pxPos[m][0], j + pxPos[m][1] )
		pickb = txt.getpixel( newPxPos )
		if pickb[2] == 175:
			count += 1
	if count > 3:
		return True
	else:
		return False
	pass

# boilerplate,
random.seed(time.time())
seed = int( random.random() * 100 )
imgSize = 64
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)

greenHue = ( 15, 175, 25)
blueHue = ( 60, 25, 175)
color = (0,0,0)
#pickb = txt.getpixel( ( j, row-1 ) )
j = 0
for i in range( imgSize ):
	for j in range( imgSize ):
		change = int(random.random() * 10 )
		if change == 5:
			if color == greenHue:
				color = blueHue
			else:
				color = greenHue
		d.point( ( i, j ), fill = color )

for k in range(1000*10):
	i = int( random.random() * 60 ) + 2
	j = int( random.random() * 60 ) + 2
	if changeToLand( i, j ):
		d.point( ( i, j ), fill = greenHue )
	if changeToSea( i, j ):
		d.point( ( i, j ), fill = blueHue )

txt = txt.resize((512,512))
txt.show()


'''
for i in range( imgSize ):
	for j in range( imgSize ):
		#print i, j, roomList[0], roomList[1], roomList[2], roomList[3]
		if ():
			color = colorList[k]
			d.point( ( i, j ), fill = color )
txt = txt.resize((512,512))
txt.show()
'''
