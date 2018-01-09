# test to convert to codeflow unit tests,
# test.py
# common plumbing for test units,
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

# data
# data
circles = []
circles.append((80,80,25))
line = []
line.append([55,80]); line.append([57,7]); line.append([20,20]); line.append([76,7])
lines = []
lines.append([random.random()*128,
	random.random()*128,
	random.random()*128,
	random.random()*128])
lines.append([random.random()*128,
	random.random()*128,
	random.random()*128,
	random.random()*128])
quads = []
# points needs to be in order, CW or CCW
quads.append([20,30]); quads.append([18,7]); quads.append([50,5]); quads.append([60,50])
quads.append([20,20]); quads.append([120,20]); quads.append([80,80]); quads.append([20,120])
quads.append([10,20]); quads.append([40,15]); quads.append([60,86]); quads.append([15,100])
quads.append([60,20]); quads.append([60,115]); quads.append([10,86]); quads.append([10,10])
quads.append([15,100]); quads.append([10,20]); quads.append([40,15]); quads.append([60,86])
curves = []
curves.append([30,60]); curves.append([18,7]); curves.append([50,5])
curves.append([10,20]); curves.append([40,15]); curves.append([60,86])
curves.append([10,10]); curves.append([55,50]); curves.append([100,100])
curves.append([60,50]); curves.append([20,30]); curves.append([0,0])

aax = [0.25, 0.75, 0.25, 0.75]
aay = [0.25, 0.25, 0.75, 0.75]
aax4 = [0.125, 0.375, 0.625, 0.875, 0.125, 0.375, 0.625, 0.875, 0.125, 0.375, 0.625, 0.875, 0.125, 0.375, 0.625, 0.875]
aay4 = [0.125, 0.125, 0.125, 0.125, 0.375, 0.375, 0.375, 0.375, 0.625, 0.625, 0.625, 0.625, 0.875, 0.875, 0.875, 0.875]

for x in range(51):
	for y in range(51):
		r = int(random.random()*255)
		g = int(random.random()*255)
		b = int(random.random()*255)
r = 0;	g = 100;	b = 0
r1 = 100;	g1 = 0;	b1 = 0
r2 = 0;	g2 = 100;	b2 = 0
r3 = 0;	g3 = 0;	b3 = 100
B = 0;	G = 0;	R = 0

leftEdge = 0; pLeftEdge = 0; rightEdge = 0; pRightEdge = 0
di = -1# direction



# CURRENT - test.py - returns the given point as parametric corrdinates relative to a quad < BUG...>
# test_quad_Interp.py - returns the given point as parametric corrdinates relative to a quad
# defined by 4 points (1)
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
for i in range(128):
	for l in range(128):
		Color = (0, 0, 0)
		#for aa in range(4):
			#pt = [float(l)+aax[aa], float(i)+aay[aa]]
		pt = [float(l), float(i)]
		d0 = float(quads[0][0]-l)**2 + float(quads[0][1]-i)**2
		d1 = float(quads[1][0]-l)**2 + float(quads[1][1]-i)**2
		d2 = float(quads[2][0]-l)**2 + float(quads[2][1]-i)**2
		d3 = float(quads[3][0]-l)**2 + float(quads[3][1]-i)**2
		B = 0
		if d0 < 2 or d1 < 2 or d2 < 2 or d3 < 2:
			B = 250
		result = quadInterpolate(quads[0], quads[1], quads[2], quads[3], pt)
		if result[0]:
			input = [ result[1]/1, result[2]/1 ]
			newColor = getGradientPoint(input)
			Color = (int(newColor[0]+Color[0]), int(newColor[1]+Color[1]), int(B))
			d.point( (l+0, i+0), fill=Color )
			pass
		else:
			input = [float(i)/128.0, float(l)/128.0]
			newColor = getGradientStyledPoint(input)
			Color = (int(newColor[0]+Color[0]), int(newColor[1]+Color[1]), int(B))
			d.point( (l+0, i+0), fill=Color )
fulltxt = txt.resize((512,512))
fulltxt.show()


# developing procedures for Clay, pasar a un testframe en C,
# procedurally generate assets using hash functions
#-----------------------------------------------------------------------
# experimenting with hash functions in c to come up with a system
# to procedurally generate assets
#-----------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;
/*
unsigned elf_hash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0, g;
    int i;

    for (i = 0; i < len; i++)
    {
        h = (h << 4) + p[i];
        g = h & 0xf0000000L;

        if (g != 0)
        {
            h ^= g >> 24;
        }

        h &= ~g;
    }

    return h;
}
*/
static unsigned int ELFHash(string str) {
	unsigned int hash = 0;
	unsigned int x = 0;
	unsigned int i = 0;
	unsigned int len = str.length();

	for (i = 0; i < len; i++)
	{
		hash = (hash << 4) + (str[i]);
		if ((x = hash & 0xF0000000) != 0)
		{
			hash ^= (x >> 24);
		}
		hash &= ~x;
	}

	return hash;
}

int main() {
  std::cout << "Hello World!\n";
  string texto = "Esto es una prueba";
  uint g = ELFHash(texto);
  uint h = 0;
  h -= 1;
  float k = (float)g / (float)h;
  printf("g: %i\n", g);
  printf("h: %u\n", h);
  printf("k: %f\n", k);
  
}

# test_procgen_housing.py
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
	

# test_procgen_tileland.py
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

# generate_gotcha_levels <...>
# notes for converting python code to c code,
# in Python we can grow lists and we can iterate over the contents of lists.
# in C we have to use flat arrays with indices.

# v 1
# procedural generation of a gotcha level we can slice and it uses different 
# primitives to build the world. Boxes, wedges, cylinders, cones,...
#-------------------------------------------------------------------------------
from PIL import Image, ImageDraw, ImageFont
import random
import time
import math
import random
import pprint
import numpy

# testing struct-like constructs in python using classes
class Dog():
	teeth = 0
	eyes = 0
	fur = "soft"
	def __init__(self, arg1, arg2):
		self.teeth = arg1
		self.eyes = arg2
	def bark(self):
		print "woof woof!"

rufus = Dog(55, 7)
rufus.bark()
print rufus.teeth + 2
print float(rufus.eyes) / 2
print rufus.fur + " hair!"

def rotation_matrix(axis, theta):
    """
    Return the rotation matrix associated with counterclockwise rotation about
    the given axis by theta radians.
    """
    axis = numpy.asarray(axis)
    axis = axis/math.sqrt(numpy.dot(axis, axis))
    a = math.cos(theta/2.0)
    b, c, d = -axis*math.sin(theta/2.0)
    aa, bb, cc, dd = a*a, b*b, c*c, d*d
    bc, ad, ac, ab, bd, cd = b*c, a*d, a*c, a*b, b*d, c*d
    return numpy.array([[aa+bb-cc-dd, 2*(bc+ad), 2*(bd-ac)],
                     [2*(bc-ad), aa+cc-bb-dd, 2*(cd+ab)],
                     [2*(bd+ac), 2*(cd-ab), aa+dd-bb-cc]])

v = [3, 5, 0]
axis = [4, 4, 0]
theta = -0.5

print(numpy.dot(rotation_matrix(axis,theta), v)) 
# [ 2.74911638  4.77180932  1.91629719]

#random.seed(9999)
boxes = []
imgSize = 512
bufferPix = [0]*(3+1)# RGB channels + Depth Channel
bufferImg = [0]*imgSize
bufferRow = [0]*imgSize
buf = [0]*imgSize*imgSize*4 #(R,G,B,D)
for i in range( len(bufferImg) ):
	bufferRow = [0]*imgSize
	for j in range( len(bufferRow) ):
		bufferPix = [0]*(3+1)
		bufferRow[j] = bufferPix
	bufferImg[i] = bufferRow

cp = ( random.random()*500, random.random()*500, random.random()*500 )
cp = ( 10, 15, 100 )
at = math.atan2( cp[1], cp[0] )
bt = math.atan2( cp[2], (pow( ( pow(cp[0], 2) + pow(cp[1], 2) ), 0.5 ) ) )
print math.degrees(at)
print math.degrees(bt)
#print math.radian(bt)

def dot( pt1, pt2 ):
	result = (pt1[0]*pt2[0]) + (pt1[1]*pt2[1]) + (pt1[2]*pt2[2])
	return result
	pass

def cross( pt1, pt2 ):
	result = ( (pt1[1]*pt2[2]) - (pt1[2]*pt2[1]),
		(pt1[2]*pt2[0]) - (pt1[0]*pt2[2]),
		(pt1[0]*pt2[1]) - (pt1[1]*pt2[0]) )
	return result
	pass

#print dot( (0.20,0,0), (1,0,0) )
#print cross( (0,1,0), (1,0,0) )

# triangle : 3 vertices x 3 coordinates ( + 1 normal x 3 components )
# quad : 4 vertices x 3 coordinates ( + 1 normal x 3 components )
# sphere : 1 vertex x 3 coordinates _+_ radius
# wheel : 3 vertices x 3 coordinates ( + 1 normal x 3 components )
# coneSurface : 
# cylinderSurface : 

# box : 6 x quads
# wedge : 3 x quads + 2 x triangles
# cone : 1 x circles + 1 x coneSurface
# cylinder : 2 x circles + 1 x cylinderSurface
# pyramid : 1 x quad + 4 x triangles

# from min and max (coord values) corner we infer the vertices of a box,
def createBox( pt1, pt2 ):
	boxList = []
	p1 = ( pt1[0], pt1[1], pt1[2] )
	p2 = ( pt2[0], pt1[1], pt1[2] )
	p3 = ( pt2[0], pt2[1], pt1[2] )
	p4 = ( pt1[0], pt2[1], pt1[2] )
	p5 = ( pt1[0], pt1[1], pt2[2] )
	p6 = ( pt2[0], pt1[1], pt2[2] )
	p7 = ( pt2[0], pt2[1], pt2[2] )
	p8 = ( pt1[0], pt2[1], pt2[2] )
	boxList.append( ( 
		(p1, p2, p3, p4), #top face
		(p5, p6, p7, p8), #bottom face
		(p1, p2, p6, p5), #sides faces,
		(p2, p3, p7, p6), 
		(p3, p4, p8, p7), 
		(p4, p1, p5, p8) 
		) )
	return boxList

# we return the four corners of a quad from the 3d coordinates of a face,
def sectionVertical( quad, cp, hang ):
	#pprint.pprint(quad)
	v = []
	# using the camera position as the slicing point and the hang as the section 
	# plane direction, calculate 2 points to use for coordinate shearing,
	point = cp
	lineStart = ( cp[0]+500*math.cos(hang), cp[0]+500*math.sin(hang), cp[2] )
	lineEnd = ( cp[0]-500*math.cos(hang), cp[0]-500*math.sin(hang), cp[2] )
	lineMag = length( lineEnd, lineStart )
	#print lineStart
	#print lineEnd
	#print lineMag
	#for n in range(2,6):# ignoring the first two faces, top and bottom.
	for i in range(4):# ignoring the first two faces, top and bottom.
		pt1 = ( quad[i][0] - cp[0], quad[i][1] - cp[1], quad[i][2] - cp[2] )
		pt2 = ( cp[0]+500*math.sin(hang), cp[0]+500*math.cos(hang), cp[2] )
		#print "Box: ", face[m]
		#print dot (pt1, pt2)
		U = ( ( ( quad[i][0] - lineStart[0] ) * ( lineEnd[0] - lineStart[0] ) )
			+ ( ( quad[i][1] - lineStart[1] ) * ( lineEnd[1] - lineStart[1] ) )
			+ ( ( quad[i][2] - lineStart[2] ) * ( lineEnd[2] - lineStart[2] ) )
			) / ( lineMag * lineMag )
		#if ( U < 0.0 ) or ( U > 1.0 ):# projection outside the segment
			#return ( v )
		#else:
		inter = [0] * 3
		inter[0] = lineStart[0] + ( U * (lineEnd[0] - lineStart[0]) )
		inter[1] = lineStart[1] + ( U * (lineEnd[1] - lineStart[1]) )
		inter[2] = lineStart[2] + ( U * (lineEnd[2] - lineStart[2]) )
		distance = length( point, inter )
		v.append( (inter[0], quad[i][2], distance ) )
	#pprint.pprint(v)
	return( v )
	
# we return the four corners of a quad from the 3d coordinates of a face,
def rasterQuad( quad, cp, hang, vang ):# quad is [4] vertices x [3] coords x,y,z
	v = []
	hang2 = math.pi/2 - hang
	#print math.degrees(hang2)
	for i in range(4):
		vertFactor = quad[i][2] * math.cos(vang)
		x = (quad[i][0] * math.cos( hang )) + (quad[i][1] * math.sin( hang ) )
		y = -(quad[i][0] * math.sin( hang )) + (quad[i][1] * math.cos( hang ) )
		x = ( x * math.sin(vang) ) + vertFactor

		d = pow( (
			pow( (cp[0] - quad[i][0]), 2 ) + pow( (cp[1] - quad[i][1]), 2 ) + pow( (cp[2] - quad[i][2]), 2 )
			), 0.5)
		v.append( (x, y, d) )
	return( v )

# boilerplate variables,
maxPixelsX = 100.0
maxPixelsY = 100.0
R = int( random.random()*255 )
G = int( random.random()*255 )
B = int( random.random()*255 )
Z = random.random()

# create a random amount of boxes with rnd. dimensions
'''
for i in range(20):
	pt = ( random.random()*200,random.random()*200, random.random()*200 )
	size = random.random()*20
	pmax = ( pt[0]+size, pt[1]+size, pt[2]+size )
	pmin = ( pt[0]-size, pt[1]-size, pt[2]-size )
	box = createBox( pmin, pmax )
	boxes.append(box)
#'''
#'''
pt = ( 0,0,0 )
size = 50
pmax = ( pt[0]+size, pt[1]+size, pt[2]+size )
pmin = ( pt[0]-size, pt[1]-size, pt[2]-size )
box = createBox( pmin, pmax )
boxes.append(box)
#'''
#print rasterQuad( ((0,0,0),(10,0,0),(10,10,0),(0,10,0)),0 )

def length( v1, v2 ):
	return pow( pow( (v2[0]-v1[0]),2) + pow( (v2[1]-v1[1]),2) , 0.5)

div = 1
a1 = True

#pprint.pprint(box[0])
#q = sectionVertical( box, cp, at )
#pprint.pprint(q)

if True:
	for box in boxes:
		if a1:
			#pprint.pprint( box )
			#print len(box)
			#pprint.pprint(box[0])
			a1 = False


		for face in box[0]:# 6 faces
			#pprint.pprint( face )
			#print len(face)
			# pick a random color,
			R2 = int( random.random()*200 )
			G2 = int( random.random()*200 )
			B2 = int( random.random()*200 )

			if True:
				q = sectionVertical( face, cp, at )
				#q = rasterQuad( face, cp, at, bt )
				#print q
				v1 = q[0]; v2 = q[1]; v3 = q[2]; v4 = q[3]
				l1 = int(length(v1, v4))+1
				l2 = int(length(v2, v3))+1
				div = max(l1, l2) + 10
				for i in range(div):
					# interpolate n values between 4 edges
					v5 = (
						( v1[0] + (i*(v4[0]-v1[0])/div) ),
						( v1[1] + (i*(v4[1]-v1[1])/div) ),
						( v1[2] + (i*(v4[2]-v1[2])/div) )
						)
					v6 = ( 
						( v2[0] + (i*(v3[0]-v2[0])/div) ),
						( v2[1] + (i*(v3[1]-v2[1])/div) ),
						( v2[2] + (i*(v3[2]-v2[2])/div) )
						)
					div2 = int(length(v5, v6))+10
					currentDepth = 0
					for j in range(div2):
						v7 = (
							( v5[0] + (j*(v6[0]-v5[0])/div2) ),
							( v5[1] + (j*(v6[1]-v5[1])/div2) ),
							( v5[2] + (j*(v6[2]-v5[2])/div2) )
							)
						d = v7[2]
						a1 = 150+int( v7[0] )
						a2 = 150+int( v7[1] )
						if a1 < 512 and a2 < 512:
							currentDepth = bufferImg[a1][a2][3]
							if (currentDepth > d) or (currentDepth == 0):
								Z = d
								bufferImg[a1][a2] = ( R2, G2, B2, Z)

def render():
	# extra random point render,
	for i in range(100):
		R = int( random.random()*255 )
		G = int( random.random()*255 )
		B = int( random.random()*255 )
		Z = random.random()
		bufferImg[ int( random.random()*imgSize ) ][ int( random.random()*imgSize ) ] = ( R, G, B, Z)

	return bufferImg
	pass

#print bufferImg[0]
#print bufferImg
createBox( (0,0,0), (50,7,2) )
#print boxList

# raster all the boxes,
bufferImg = render()

# copy the buffer to the screen buffer,
base = Image.new( 'RGBA', (imgSize,imgSize), (0,0,0,0) )#base.size
d = ImageDraw.Draw(base)
for i in range( imgSize ):
	for j in range( imgSize ):
		d.point( ( i, j ), fill = (
			bufferImg[j][i][0],
			bufferImg[j][i][1],
			bufferImg[j][i][2]
			),)

base = base.resize( (512,512) )
base.show()
#filename = 'temp_boxes.png'
#base.save(filename, "PNG")


# converting this to a cpp test first, then adding to clay,
# projecting boxes in an isometric view
//random.seed(9999)
// vars,
maxPixelsX = 100.0
maxPixelsY = 100.0
R = int( random.random()*255 )
G = int( random.random()*255 )
B = int( random.random()*255 )
Z = random.random()
boxes = [512]
int imgSize = 512;
bufferPix = [0]*(3+1)# RGB channels + Depth Channel
bufferImg = [0]*imgSize
bufferRow = [0]*imgSize
buf = [0]*imgSize*imgSize*4 #(R,G,B,D)

for i in range( len(bufferImg) ):
	bufferRow = [0]*imgSize
	for j in range( len(bufferRow) ):
		bufferPix = [0]*(3+1)
		bufferRow[j] = bufferPix
	bufferImg[i] = bufferRow

cp = ( random.random()*500, random.random()*500, random.random()*500 )
cp = ( 10, 15, 100 )
at = math.atan2( cp[1], cp[0] )
bt = math.atan2( cp[2], (pow( ( pow(cp[0], 2) + pow(cp[1], 2) ), 0.5 ) ) )
print math.degrees(at)
print math.degrees(bt)

// dot product
def dot( pt1, pt2 ):
	result = (pt1[0]*pt2[0]) + (pt1[1]*pt2[1]) + (pt1[2]*pt2[2])
	return result
	pass

// cross product
def cross( pt1, pt2 ):
	result = ( (pt1[1]*pt2[2]) - (pt1[2]*pt2[1]),
		(pt1[2]*pt2[0]) - (pt1[0]*pt2[2]),
		(pt1[0]*pt2[1]) - (pt1[1]*pt2[0]) )
	return result
	pass
/*
# triangle : 3 vertices x 3 coordinates ( + 1 normal x 3 components )
# quad : 4 vertices x 3 coordinates ( + 1 normal x 3 components )
# sphere : 1 vertex x 3 coordinates _+_ radius
# wheel : 3 vertices x 3 coordinates ( + 1 normal x 3 components )
# coneSurface : 
# cylinderSurface : 

# box : 6 x quads
# wedge : 3 x quads + 2 x triangles
# cone : 1 x circles + 1 x coneSurface
# cylinder : 2 x circles + 1 x cylinderSurface
# pyramid : 1 x quad + 4 x triangles
*/
// from min and max (coord values) corner we infer the vertices of a box,
def createBox( pt1, pt2 ):
	boxList = []
	p1 = ( pt1[0], pt1[1], pt1[2] )
	p2 = ( pt2[0], pt1[1], pt1[2] )
	p3 = ( pt2[0], pt2[1], pt1[2] )
	p4 = ( pt1[0], pt2[1], pt1[2] )
	p5 = ( pt1[0], pt1[1], pt2[2] )
	p6 = ( pt2[0], pt1[1], pt2[2] )
	p7 = ( pt2[0], pt2[1], pt2[2] )
	p8 = ( pt1[0], pt2[1], pt2[2] )
	boxList.append( ( 
		(p1, p2, p3, p4), #top face
		(p5, p6, p7, p8), #bottom face
		(p1, p2, p6, p5), #sides faces,
		(p2, p3, p7, p6), 
		(p3, p4, p8, p7), 
		(p4, p1, p5, p8) 
		) )
	return boxList
	
// we return the four corners of a quad from the 3d coordinates of a face,
def rasterQuad( quad, cp, hang, vang ):// quad is [4] vertices x [3] coords x,y,z
	v = []
	hang2 = math.pi/2 - hang
	#print math.degrees(hang2)
	for i in range(4):
		vertFactor = quad[i][2] * math.cos(vang)
		x = (quad[i][0] * math.cos( hang )) + (quad[i][1] * math.sin( hang ) )
		y = -(quad[i][0] * math.sin( hang )) + (quad[i][1] * math.cos( hang ) )
		x = ( x * math.sin(vang) ) + vertFactor

		d = pow( (
			pow( (cp[0] - quad[i][0]), 2 ) + pow( (cp[1] - quad[i][1]), 2 ) + pow( (cp[2] - quad[i][2]), 2 )
			), 0.5)
		v.append( (x, y, d) )
	return( v )

///*
// create a random amount of boxes with rnd. dimensions
for( int i=0; i<20; ++i){
	pt = ( random.random()*200,random.random()*200, random.random()*200 )
	size = random.random()*20
	pmax = ( pt[0]+size, pt[1]+size, pt[2]+size )
	pmin = ( pt[0]-size, pt[1]-size, pt[2]-size )
	box = createBox( pmin, pmax )
	boxes.append(box);
	}
//*/
/*
pt = ( 0,0,0 )
size = 50
pmax = ( pt[0]+size, pt[1]+size, pt[2]+size )
pmin = ( pt[0]-size, pt[1]-size, pt[2]-size )
box = createBox( pmin, pmax )
boxes.append(box)
//*/

float length( vec2 v1, vec2 v2 ){
	return pow( pow( (v2[0]-v1[0]),2) + pow( (v2[1]-v1[1]),2) , 0.5);
	}

int div = 1;
int a1 = 1;

if True:
	for box in boxes:
		if a1:
			#pprint.pprint( box )
			#print len(box)
			#pprint.pprint(box[0])
			a1 = False

		for face in box[0]:# 6 faces
			#pprint.pprint( face )
			#print len(face)
			# pick a random color,
			R2 = int( random.random()*200 )
			G2 = int( random.random()*200 )
			B2 = int( random.random()*200 )

			q = rasterQuad( face, cp, at, bt )
			#print q
			v1 = q[0]; v2 = q[1]; v3 = q[2]; v4 = q[3]
			l1 = int(length(v1, v4))+1
			l2 = int(length(v2, v3))+1
			div = max(l1, l2) + 10
			for i in range(div):
				# interpolate n values between 4 edges
				v5 = (
					( v1[0] + (i*(v4[0]-v1[0])/div) ),
					( v1[1] + (i*(v4[1]-v1[1])/div) ),
					( v1[2] + (i*(v4[2]-v1[2])/div) )
					)
				v6 = ( 
					( v2[0] + (i*(v3[0]-v2[0])/div) ),
					( v2[1] + (i*(v3[1]-v2[1])/div) ),
					( v2[2] + (i*(v3[2]-v2[2])/div) )
					)
				div2 = int(length(v5, v6))+10
				currentDepth = 0
				for j in range(div2):
					v7 = (
						( v5[0] + (j*(v6[0]-v5[0])/div2) ),
						( v5[1] + (j*(v6[1]-v5[1])/div2) ),
						( v5[2] + (j*(v6[2]-v5[2])/div2) )
						)
					d = v7[2]
					a1 = 150+int( v7[0] )
					a2 = 150+int( v7[1] )
					if a1 < 512 and a2 < 512:
						currentDepth = bufferImg[a1][a2][3]
						if (currentDepth > d) or (currentDepth == 0):
							Z = d
							bufferImg[a1][a2] = ( R2, G2, B2, Z)

createBox( (0,0,0), (50,7,2) )
// raster all the boxes,
bufferImg = render()

// copy the buffer to the screen buffer,
base = Image.new( 'RGBA', (imgSize,imgSize), (0,0,0,0) )#base.size
d = ImageDraw.Draw(base)
for i in range( imgSize ):
	for j in range( imgSize ):
		d.point( ( i, j ), fill = (
			bufferImg[j][i][0],
			bufferImg[j][i][1],
			bufferImg[j][i][2]
			),)

base = base.resize( (512,512) )
base.show()


# procedures,
# getDistance(point)
def getDistance(point):
	return pow( ( pow(point[0],2) + pow(point[1],2) ) ,0.5)

# getGradientStyledPoint(point)
# returns a stylized gradient to use in game textures background, etc...,
def getGradientStyledPoint(point):
	dist = getDistance( ( 0.5-point[0], 0.5-point[1] ) ) 
	gradient  = (255-((dist*250+10)/20), 255-((dist*point[1]*5*250+10)/20), 255-((dist*point[0]*10*250+10)/20) )
	return gradient
 	

# getGradientPoint(point)
# returns a gradient, red 0-255 on the x and green, 0-255 on the y
def getGradientPoint(point):
	gradient  = (int(point[0]*60), int(point[1]*60), 0 )
	return gradient

# quadInterpolate(u1,u2,u3,u4,pt)
# returns the given point as parametric corrdinates relative to a quad
# defined by 4 points
def quadInterpolate(u1,u2,u3,u4,pt):
	result = False
	inBbox = True

	u = []
	u.append(u1); u.append(u2); u.append(u3); u.append(u4);

	seg1x = abs(u1[0] - u2[0])
	seg2x = abs(u3[0] - u2[0])
	minX = seg1x if seg1x < seg2x else seg2x
	seg1y = abs(u1[1] - u2[1])
	seg2y = abs(u3[1] - u2[1])
	minY = seg1y if seg1y < seg2y else seg2y

	h = 2 if minX < minY else 0
	v = 0 if h == 2 else 2
	
	projHX = u[h][0] - u[1][0]
	projHY = float( u[h][1] - u[1][1] ) / float(projHX)
	projVX = ( u[v][1] - u[1][1] ) - float( u[v][0] - u[1][0] ) * float(projHY)
	projVY = ( u[v][0] - u[1][0] ) / projVX

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

	'''
	if int(pt[0]) == 59 and int(pt[1]) == 86:
		print 'h:', h, 'v:', v
		print 'projHX:', projHX, 'projHY:', projHY
		print 'projVX:', projVX, 'projVY:', projVY
		print 'p:', p, 'ppt:', ppt, 'pppt:', pppt 
		print 'p4:', p4, 'pt4:', pt4, 'ppt4:', ppt4
		print 'ma:', ma, 'mb:', mb, 'maa:', maa, 'mbb:', mbb
	'''
	ma1 = ma
	ma = ma / (1+( (maa-1)*mb ))
	mb = mb / (1+( (mbb-1)*ma1))
	if int(pt[0]) == 59 and int(pt[1]) == 86:
		#print 'ma:', ma, 'mb:', mb, 'maa:', maa, 'mbb:', mbb
		pass
	if ma > 0 and ma < 1 and mb > 0 and mb < 1:
		result = True
	else:
		result = False
	return (result, ma, mb)


