# procedural generation of a family dwelling
#-------------------------------------------------------------------------------
from PIL import Image, ImageDraw, ImageFont
import random
import time
import math
import random

# boilerplate,
random.seed(time.time())
seed = int( random.random() * 100 )
living_size = 0
kitchen_size = 0
pantry_size = 0
bcdathroom1_size = 0
bathroom2_size = 0
bathroom3_size = 0
bathroom4_size = 0
bathroom5_size = 0
staircase_size = 0
entrance_size = 0
garage_size = 0
den1_size = 0
den2_size = 0

def splitRoom( rl, i ):
	div = int( random.random() * 5 ) + 1
	if rl[i][2] > rl[i][3]:
		oldWidth = int( rl[i][2] )
		newWidth = int( oldWidth / div )
		oldWidth -= newWidth
		rl[i] = [ rl[i][0], rl[i][1], newWidth, rl[i][3] ]
		rl.append( [ rl[i][0]+newWidth, rl[i][1], oldWidth, rl[i][3] ] )
	else:
		oldHeight = int( rl[i][3] )
		newHeight = int( oldHeight / div )
		oldHeight -= newHeight
		rl[i] = [ rl[i][0], rl[i][1], rl[i][2], newHeight ]
		rl.append( [ rl[i][0], rl[i][1]+newHeight, rl[i][2], oldHeight ] )
	pass

imgSize = 64
base = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
lines = []; point = []
newColor = ( 20, 0, 0)
emptyColor = ( 150, 25, 75)
roomList = []
colorList = []
for i in range( 20 ):
	colorList.append( (
		int( random.random()*255 ),
		int( random.random()*255 ),
		int( random.random()*255 ) ) )
print colorList


no_rooms = int( random.random() * 10 )
total_area = no_rooms * 10
level_aspect_ratio = 10
while level_aspect_ratio > 2:
	level_width = int( random.random() * 10 )+1
	level_length = int(10 * 10 / level_width)
	level_aspect_ratio = float(level_width) / float(level_length)
	if level_aspect_ratio < 1:
		level_aspect_ratio = 1 / level_aspect_ratio
roomList.append( [ 0, 0, level_width, level_length ] )

while( len(roomList) < 6):
	maxArea = 0
	for i in range( len(roomList) ):
		area = ( roomList[i][2] - roomList[i][0] ) * ( roomList[i][3] - roomList[i][1] )
		if maxArea < area:
			maxArea = area
			index = i

	splitRoom( roomList, index )	

print roomList

color = newColor
#pickb = txt.getpixel( ( j, row-1 ) )
for i in range( imgSize ):
	for j in range( imgSize ):
		for k in range( len(roomList) ):
			#print i, j, roomList[0], roomList[1], roomList[2], roomList[3]
			if (
				(i >= roomList[k][0] ) and ( i <= (roomList[k][2]+roomList[k][0]) )
				and
				(j >= roomList[k][1] ) and ( j <= (roomList[k][3]+roomList[k][1]) )
				):
				color = colorList[k]
				d.point( ( i, j ), fill = color )
txt = txt.resize((512,512))
txt.show()

random.seed(time.time())
txt = base
d = ImageDraw.Draw(txt)
edgeList = []

# saving the image,
#filename = "raster." + str(no) + ".png"; txt.save(filename, "PNG")
	
