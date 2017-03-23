#-----------------------------------------------------------------------
from PIL import Image
from PIL import ImageDraw
import random
import time
import math

random.seed(time.time())
imgSize = 128
#imgSize = 512
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
lines = []; point = []
#lines.append([38.0,80.0]); lines.append([76.0,40.0]);
lines.append([
	(random.random()*2-1)*50.0+64.0,
	(random.random()*2-1)*50.0+64.0])
lines.append([
	(random.random()*2-1)*50.0+64.0,
	(random.random()*2-1)*50.0+64.0]);
print lines
point.append(50.0); point.append(50.0)
aax = [0.25, 0.75, 0.25, 0.75]; aay = [0.25, 0.25, 0.75, 0.75]
R = 0;	G = 0;	B = 0
r1 = 100;	g1 = 0;		b1 = 0
r2 = 0;		g2 = 100;	b2 = 0
r3 = 0;		g3 = 0;		b3 = 100
leftEdge = 0; rightEdge = 0
di = -1

for i in range(128):
	for l in range(128):
		#for aa in range(4):
			#pt = [float(l)+aax[aa], float(i)+aay[aa]]
		r = 0;	g = 0;	b = 0
		lines.append([lines[0][0]-(lines[1][1] - lines[0][1]), lines[0][1]+(lines[1][0] - lines[0][0])])
		d0 = float(lines[0][0]-l)**2 + float(lines[0][1]-i)**2
		d1 = float(lines[1][0]-l)**2 + float(lines[1][1]-i)**2
		d2 = float(lines[2][0]-l)**2 + float(lines[2][1]-i)**2
		d3 = float(point[0]-l)**2 + float(point[1]-i)**2
		if d0 < 2:
			g = 200
		if d1 < 2:
			g = 100
		if d2 < 2:
			r = 125
		if d3 < 2:
			b = 125
		pt = (i,l)
		x1 = point[0]
		y1 = point[1]
		m = (lines[1][1] - lines[0][1]) / (lines[1][0] - lines[0][0])
		q = lines[1][0] - (lines[1][1] * m)
		#y = m*x + q # ray equation

		A = point[0] - lines[0][0]
		B = point[1] - lines[0][1]
		C = lines[1][0] - lines[0][0]
		D = lines[1][1] - lines[0][1]
		distance = abs(A*D - C*B) / math.sqrt(C*C + D*D)
		
		C = lines[2][0] - lines[0][0]
		D = lines[2][1] - lines[0][1]
		distance2 = abs(A*D - C*B) / math.sqrt(C*C + D*D)

		if d3 < distance**2:
			g += 40
		if d3 < distance2**2:
			r += 40

		#print "The distance is: ", distance
		#print "The distance2 is: ", distance2

		newColor = (r, g, b)
		d.point( (l,i), fill = newColor )

txt = txt.resize((512,512))
txt.show()
____________________________________________________________________________________
____________________________________________________________________________________
____________________________________________________________________________________
____________________________________________________________________________________

:: Handmade Hero Day 371 - OpenGL Vertex Arrays
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Bn97Txqu9No
:: Handmade Hero Day 370 - Shader Fallback sRGB
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=PGNH3SKmgEo
:: Handmade Hero Day 369 - Introduction to Vertex and Fragment Shaders
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=GtNvxxl3AK4
:: Handmade Hero Day 368 - Compiling and Linking Shaders in OpenGL
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=37KXLsjTRBo
:: Handmade Hero Day 367 - Enabling OpenGL Multisampling
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=imW4sX3vVwY
:: Handmade Hero Day 366 - Adding Cubes to the Renderer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=W5tnnhe8TK4
:: Handmade Hero Day 365 - Adjusting Sprite Cards to Counter Projection
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=0h916hXePbw
:: Handmade Hero Day 364 - Enabling the OpenGL Depth Buffer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=m8trVjY2WgI
:: Handmade Hero Day 363 - Making an Orbiting Debug Camera
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=CTTCf79MgDY
:: Handmade Hero Day 362 - Matrix Multiplication and Transform Order
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=5tKiQd73rPk
:: Handmade Hero Day 361 - Introduction to 3D Rotation Matrices
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=zU5Yyls5uwM
:: Handmade Hero Day 360 - Moving the Perspective Divide to OpenGL
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=EDfb-13wgk0
:: Handmade Hero Day 359 - OpenGL Projection Matrices Revisited
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ykOBtVPjzq4
:: Handmade Hero Day 358 - Introduction to Depth Buffers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=7EiCGEgb_No
:: Handmade Hero Day 357 - Room-based Camera Zoom
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ASewPs1n-GA
:: Handmade Hero Day 356 - Making the Debug System CLANG Compatible
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=q_FIMxta6zo
:: Handmade Hero Day 355 - Clearing Out Pending GitHub Bugs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=pqOlYhlfxSE
:: Handmade Hero Day 354 - Simple LZ Compression
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=l8WUqmHD1PU
:: Handmade Hero Day 353 - Simple RLE Compression
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kikLEdc3C1c
:: Handmade Hero Day 352 - Isolating the Camera Update Code
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=m6yAMBpk7Bg
:: Handmade Hero Day 351 - Optimizing Multithreaded Simulation Regions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=6mTkcOlaUUc
:: Handmade Hero Day 350 - Multithreaded World Simulation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tWzslFE9Qvg
:: Handmade Hero Day 349 - Running Multiple Sim Regions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Q3DtXQGTles
:: Handmade Hero Day 348 - Debugging Cutscene Z and Traversable Creation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=KAO3f4oaqWM
:: Handmade Hero Day 347 - Debugging Win32 Memory List Corruption
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=wuYRpxnE9R8
:: Handmade Hero Day 346 - Consolidating Memory Block Headers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=XBft9E6NBDU
:: Handmade Hero Day 345 - Protecting Memory Pages for Underflow Detection
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=imxqyPgUIcM
:: Handmade Hero Day 344 - Selective Memory Restoration
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=7oXRggHaP60
:: Handmade Hero Day 343 - Saving and Restoring Dynamically Allocated Memory Pages
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=MSDl5-akNLE
:: Handmade Hero Day 342 - Supporting Temporary Memory in Dynamic Arenas
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=7COUJ8eef6A
:: Handmade Hero Day 341 - Dynamically Growing Arenas
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lzdKgeovBN0
:: Handmade Hero Chat 012 - Imposter Syndrome
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=NXsWViTB238
:: Handmade Hero Day 340 - Cleaning Up World / Sim-Region Interactions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=WvM38blp5QI
:: Handmade Hero Chat 011 - Undefined Behavior
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=dyI0CwK386E
:: Handmade Hero Day 339 - Debugging Particle Camera Offset Motion
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=76TSb_HiKus
:: Handmade Hero Day 338 - Simulation-space Particles
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lG3j32DTo1E
:: Handmade Hero Day 337 - Convenient SIMD for Particles
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ucZLbYLTmd0
:: Handmade Hero Day 336 - Adding a Particle System Cache
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=RBNjzGeaB_M
:: Handmade Hero Day 335 - Moving Entities on Boost Squares
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Ed13_ISgrU8
:: Handmade Hero Day 334 - Adding Boost Pads
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=6GY-9Uia_2g
:: Handmade Hero Day 333 - Floor-relative Perspective Transforms
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=MplLlRJQ6tQ
:: Handmade Hero Day 332 - Disabling Sort for Debug Overlays
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=9ZUndaaFNzg
:: Handmade Hero Day 331 - Activating Entities by Brain
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=aHv4iYdRZNM
:: Handmade Hero Day 330 - Fixings Bugs from the Issue List
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=a346y2H9JcU
:: Handmade Hero Day 329 - Printing Out Floats Poorly
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Qqp-O4cujVM
:: Handmade Hero Day 328 - Integer and String Support in Printf
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kxHN6ICgjgQ
:: Handmade Hero Day 327 - Parsing Printf Format Strings
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=vpB9hFX_L2Y
:: Handmade Hero Day 326 - Vararg Functions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=WoakE93Lj_w
:: Handmade Hero Day 325 - Ticket Mutexes
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=A2kCmouscjM
:: Handmade Hero Day 324 - Moving Away from Multiple OpenGL Contexts
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=B5LcmXI1O6w
:: Handmade Hero Day 323 - Fixing Miscellaneous Bugs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=YssqJ7eDnv0
:: Handmade Hero Day 322 - Handling Multiple Display Aspect Ratios
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=EKxPnlQ2ipI
:: Handmade Hero Day 321 - Multiple OpenGL Render Targets
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kKj3wzpVrMo
:: Handmade Hero Day 320 - Inverting a 2x2 Matrix by Hand
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kvSbiHrFKNk
:: Handmade Hero Day 319 - Inverse and Transpose Matrices
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=9KaIB7PFWeE
:: Handmade Hero Day 318 - Optimizing Render Target Blends and Clears
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=HB4Dl8NyE2Q
:: Handmade Hero Day 317 - Alpha Blending Multiple Render Targets
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Wv2IAKs7W0A
:: Handmade Hero Day 316 - Multiple Software Render Targets
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=NROKpZtyj_o
:: Handmade Hero Day 315 - Un-reversing Sort Key Order
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=jr55zspbhGc
:: Handmade Hero Day 314 - Breaking Sprites into Layers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=I3pW6bQcxWE
:: Handmade Hero Day 313 - Returning to Work on Z Layers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=PYdOZ_r9RLw
:: Handmade Hero Day 312 - Cross-entity Manual Sorting
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=8ke6OKMFeAI
:: Handmade Hero Day 311 - Allowing Manual Sorting
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=SkTRPn7pjfw
:: Handmade Hero Day 310 - Finishing Sort Acceleration via Gridding
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=maQL_OmS-kM
:: Handmade Hero Day 309 - Grid Partitioning for Overlap Testing
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=BCiQcL_6ceM
:: Handmade Hero Day 308 - Debugging the Cycle Check
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=trtrBITgktg
:: Handmade Hero Day 307 - Visualizing Sort Groups
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=PDg_4lBhTUI
:: Handmade Hero Day 306 - Debugging Graph-based Sort
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=bMjnXBR98UY
:: Handmade Hero Day 305 - Using Memory Arenas in the Platform Layer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ImWSMzMe1kI
:: Handmade Hero Day 304 - Building and Traversing Graphs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=4GmDwulUkPA
:: Handmade Hero Day 303 - Trying Separate Y and Z Sorts
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=93NKevv-n6k
:: Handmade Hero Day 302 - Confirming No Total Ordering
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=DH_QepPBeaI
:: Handmade Hero Day 301 - Sorting with Sprite Bounds
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=SSgo0UdesQg
:: Handmade Hero Day 300 - Changing from Sort Keys to Sort Rules
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=jrKVyIfv1ek
:: Handmade Hero Day 299 - Improving Sort Keys Part 2
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=EbaM2XwuscQ
:: Handmade Hero Day 298 - Improving Sort Keys Part 1
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=3KsEO5-sYBQ
:: Handmade Hero Day 297 - Separating Entities into Z Layers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=hpoNQhVY634
:: Handmade Hero Day 296 - Fog and Alpha for Layers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kAHKTNjaD-Y
:: Handmade Hero Day 295 - Stacking Rooms for Z Layer Debugging
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=N0K0eHnVc1Y
:: Handmade Hero Day 294 - Adding the Glove
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kOHHWPmo1D0
:: Handmade Hero Day 293 - Moving Familiars
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=DIssBI1JBz8
:: Handmade Hero Day 292 - Implementing Snakes
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=NarF07FefqQ
:: Handmade Hero Day 291 - Hopping Monstar and Occupying Trees
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=wAqPNROQZas
:: Handmade Hero Day 290 - Finishing Separated Rendering
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=DCd-abDxftc
:: Handmade Hero Day 289 - Decoupling Visuals from Entity Types
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=9J-ZOWPLYM4
:: Handmade Hero Day 288 - Finishing Brains
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=aY2Lujojmg0
:: Handmade Hero Day 287 - Adding Brains
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=gwtSqvoxU14
:: Handmade Hero Day 286 - Starting to Decouple Entity Behavior
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=rGwAhNAYCKg
:: Handmade Hero Day 285 - Transactional Occupation of Traversables
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=HXLr8tSGIX0
:: Handmade Hero Day 284 - Reorganizing the Head and Body Code
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=sEHDoJnZSKY
:: Handmade Hero 283 - Making Standing-on a More Rigorous Concept
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tZSwGCgo-uE
:: Handmade Hero Day 282 - Z Movement and Camera Motion
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=8f9ggBzjUBE
:: Handmade Hero Day 281 - Animating the Camera Between Rooms
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=TFBo2ziKOW0
:: Handmade Hero Day 280 - Cleaned Up Streaming Entity Simulation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=jdknM4bPUcc
:: Handmade Hero Day 279 - Finishing World Chunk Entity Storage
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=yJjVBh7r9-s
:: Handmade Hero Day 278 - Moving Entity Storage into World Chunks
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=JqflfK5i8qk
:: Handmade Hero Day 277 - The Sparse Entity System
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=wqpxe-s9xyw
:: Handmade Hero Day 276 - Tuning the Body Animation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=xdtQ9fFru0g
:: Handmade Hero Day 275 - Passing Rotation and Shear to the Renderer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kizKx0bdr3Q
:: Handmade Hero Day 274 - Dynamic Animation with Springs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=0MWGM4pte-I
:: Handmade Hero Day 273 - Animation Overview
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ytZbsYjtD_w
:: Handmade Hero Day 272 - Explicit Movement Transitions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=4fJTdIkFwIE
:: Handmade Hero Day 271 - Hybrid Tile-based Movement
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=S5VtscjLjnk
:: Handmade Hero Day 270 - Making Traversable Points
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=xNijkdjXhjg
:: Handmade Hero Day 269 - Cleaning Up Menu Drawing
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tITcs17P-lU
:: Handmade Hero Day 268 - Consolidating Debug Links and Groups
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=r5Lld9FderU
:: Handmade Hero Day 267 - Adding Per-Element Clipping Rectangles
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=WX6r6S5Fm0I
:: Handmade Hero Day 266 - Adding a Top Clocks Profile View
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=qYGNxUu6tjI
:: Handmade Hero Day 265 - Cleaning Up the UI Layout Code
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=BHEJh9Yvsxc
:: Handmade Hero Day 264 - Adding Buttons to the Profiler
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=y7-phAHpweU
:: Handmade Hero Day 263 - Adding a Debug Frame Slider
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=NgWclbqkXJg
:: Handmade Hero Day 262 - Drawing Multi-frame Profile Graphs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=I9W5TVj4BT0
:: Handmade Hero Day 261 - Changing to Static Frame Arrays
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=esRhxNS0Ee8
:: Handmade Hero Day 260 - Implementing Drill-down in the Profiler
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=wklr6ogongg
:: Handmade Hero Day 259 - OpenGL and Software Renderer Cleanup
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=wUbe27tz8Gg
:: Handmade Hero Day 258 - Fixing Profiling Across Code Reloads
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=UxV5GFeCEAc
:: Handmade Hero Day 257 - Cleaning Up Some Win32 Issues
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=HOZQmCXJjmE
:: Handmade Hero Day 256 - XBox Controller Stalls and Fixing GL Blit Gamma
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=FRzg9eYHnTw
:: Handmade Hero Day 255 - Building a Profile Tree
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=6Ym-Nq1g7-s
:: Handmade Hero Day 254 - Reenabling Profiling
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=b48NmnVEvu8
:: Handmade Hero Day 253 - Reenabling More Debug UI
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=aK-E-D-jvds
:: Handmade Hero Day 252 - Allowing Debug Value Edits
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=OsJJizXWN_A
:: Handmade Hero Day 251 - Finishing the Debug Hierarchy
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=LTTaqnFBtwk
:: Handmade Hero Day 250 - Cleaning Up Debug GUIDs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ceMQT1DZkpo
:: Handmade Hero Day 249 - Cleaning Up Debug Macros
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=NVnlQ7KMGa8
:: Handmade Hero Day 248 - Cleaning Up Data Block Display
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Thr10pFx984
:: Handmade Hero Day 247 - Simplifying Debug Values
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=JqcphfRybd4
:: Handmade Hero Day 246 - Moving Worker Context Creation to the Main Thread
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ml5E9-tzEns
:: Handmade Hero Day 245 - Using wglChoosePixelFormatARB
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=SvlirEF-R-4
:: Handmade Hero Day 244 - Finishing Asynchronous Texture Downloads
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=SWtV8B3rssw
:: Handmade Hero Day 243 - Asynchronous Texture Downloads
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=onEloWtN91Y
:: Handmade Hero Chat 010 - Partial Specialization
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=QauD5cAgnT8
:: Handmade Hero Chat 007 - Inverse Kinematics
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=rTF0PWnRUrw
:: Handmade Hero Chat 006 - Error-based Drawing Algorithms
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=q79-Qh2suMY
:: Handmade Hero Chat 005 - SGX and Unbreakable DRM
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=8eULB8uMIuc
:: Handmade Hero Chat 001
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=uT5ao2rSNxI
:: Handmade Hero Chat 003
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=xi2jE3dzhTc
:: Handmade Hero Chat 004
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tlYn2kN0g8c
:: Handmade Hero Chat 002
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=nKkQHa8yOe4
:: Handmade Hero Day 242 - OpenGL Context Escalation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=99kIYIEzbpc
:: Handmade Hero Day 241 - OpenGL VSync and sRGB Extensions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=1OMTFa09lHM
:: Handmade Hero Day 240 - Moving the Renderer into a Third Tier
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=s1S76SBWxcg
:: Handmade Hero Day 239 - Rendering the Game Through OpenGL
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=jH7i0YXN9FU
:: Handmade Hero Day 238 - Making OpenGL Use Our Screen Coordinates
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kBuaCqaCYwE
:: Handmade Hero Day 237 - Displaying an Image with OpenGL
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=YIOpZ9M5pc4
:: Handmade Hero Day 236 - GPU Conceptual Overview
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=vbnozKJM0Oo
:: Handmade Hero Day 235 - Initializing OpenGL on Windows
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=5Klc9RZPG7M
:: Handmade Hero Day 234 - Implementing Radix Sort
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=jhGDPoSLJMo
:: Handmade Hero Day 233 - Can We Merge Sort In Place?
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=A59NnNt9hRo
:: Handmade Hero Day 232 - Examples of Sorting Algorithms
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=cq_PVCgyS5k
:: Handmade Hero Day 231 - Order Notation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=jo9rfWct1OI
:: Handmade Hero Day 230 - Refining Renderer Sort Keys
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=9-jltZmDMHI
:: Handmade Hero Day 229 - Sorting Render Elements
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=b6qZaqL7fxM
:: Handmade Hero Day 228 - Waiting for Dependent Tasks on Metagame Mode Changes
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=4sdqC9V4P_g
:: Handmade Hero Day 227 - Switching Between Metagame Modes
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=a1j15jWJLoc
:: Handmade Hero Day 226 - Handling Multiple Metagame Modes
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=2X6A70ONyO0
:: Handmade Hero Day 225 - Fading In and Out from the Windows Desktop
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=hsKMH89VmR8
:: Handmade Hero Day 224 - Prefetching Cutscene Layers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=C4Il0g8vtg0
:: Handmade Hero Day 223 - Playing Multiple Cutscenes
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=btGVLs4NSOM
:: Handmade Hero Day 222 - Laying Out Cutscenes
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=UHQSoeR6c_Y
:: Handmade Hero Day 221 - Implementing Multi-layer Cutscenes
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=JOoqeKB9lx4
:: Handmade Hero Day 220 - Displaying Data Blocks in the Hierarchy
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=k1h-0MEtcGg
:: Handmade Hero Day 219 - Automatically Constructed Debug Hierarchies
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=FQzGVuWDHcg
:: Handmade Hero Day 218 - Hashing Debug Elements
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=66DXTnHDesc
:: Handmade Hero Day 217 - Per-element Debug Event Storage
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=m2Y7UmUU_xo
:: Handmade Hero Day 216 - On-demand Deallocation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lPnPNaC-KJg
:: Handmade Hero Day 215 - Cleaning Up Debug Event Collation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=VAKkuva8St4
:: Handmade Hero Day 214 - Collating Permanent Debug Values
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=4aeT9T-i3Qs
:: Handmade Hero Day 213 - Turning Debug Switches into Events
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=nc6WawdkDnI
:: Handmade Hero Day 212 - Integrating Debug UI into Game Code
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=fbsZW4BzW6k
:: Handmade Hero Day 211 - Removing Records and Translation Units from the Debug Code
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=hwLSZuxK6aU
:: Handmade Hero Day 210 - Consolidating Debug Data Storage
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=r2l0atxoA4M
:: Handmade Hero Day 209 - Displaying Buffered Debug Data
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=2bQ6mL3yNh0
:: Handmade Hero Day 208 - Adding Data Blocks to the Debug Log
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=SWXxlrjDKW0
:: Handmade Hero Day 207 - Using Introspection Data
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=3_7IMU6l6Pc
:: Handmade Hero Day 206 - Implementing Introspection
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=1IwYEJsvdcs
:: Handmade Hero Day 205 - Picking Entities with the Mouse
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=3RPdhDditMY
:: Handmade Hero Day 204 - Unprojecting the Mouse Cursor
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=FkDJL8zmVFY
:: Handmade Hero Day 203 - Debug UI State Caching
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=6gBJ9f5tUV4
:: Handmade Hero Day 202 - Multiply Appearing Debug Values
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=JTwMFtyuL6M
:: Handmade Hero Day 201 - Isolating the Debug Code
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Nb9ObiFvw3I
:: Handmade Hero Day 200 - Debug Element Layout
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=L81ZcBDnQx4
:: Handmade Hero Day 199 - Reusing Debug Interactions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Pn8JLm3hQfs
:: Handmade Hero Day 198 - Run-time Editing of Debug Hierarchies
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=wyN_xzqz5dk
:: Handmade Hero Day 197 - Integrating Multiple Debug Views
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ovXGlv7Y9wo
:: Handmade Hero Day 196 - Introduction to UI Interactions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=FvWcZ9Tti2k
:: Handmade Hero Day 195 - Implementing an Interactive Tree View
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=WwDytuTI5C8
:: Handmade Hero Day 194 - Organizing Debug Variables into a Hierarchy
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=00bRntapIAk
:: Handmade Hero Day 193 - Run-time Setting of Compile-time Variables
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=9ND-2a_hP0g
:: Handmade Hero Day 192 - Implementing Self-Recompilation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=RQuVq1v2PkE
:: Handmade Hero Day 191 - Implementing a Radial Menu
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ftZIujU3Udw
:: Handmade Hero Day 190 - Cleaning Up Debug Globals
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=7jmDV_Hk42U
:: Handmade Hero Day 189 - Incremental Debug Frame Processing
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=87V4GNfqTpY
:: Handmade Hero Day 188 - Adding Hover to the Debug Graphs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=1llPa4I7gYk
:: Handmade Hero Day 187 - Fixing an Event Recording Bug
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=VsWgUTH45F8
:: Handmade Hero Day 186 - Starting to Debug Event Recording
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=BbfFZLUre3s
:: Handmade Hero Day 185 - Finishing Basic Debug Collation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kkoiLQO5JGo
:: Handmade Hero Day 184 - Collating Debug Events
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=YP9oNMb_VIg
:: Handmade Hero Day 183 - Platform Layer Debug Events
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tdrTk9Ba3VM
:: Handmade Hero Day 182 - Fast Thread ID Retrieval
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=fNufyLQacDw
:: Handmade Hero Day 181 - Log-based Performance Counters
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=s_qSvBp6nFw
:: Handmade Hero Day 180 - Adding Debug Graphs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=U2RnqT6xSFk
:: Handmade Hero Day 179 - Tracking Debug Information Over Time
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=k_1FzhI3kv4
:: Handmade Hero Day 178 - Thread-safe Performance Counters
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=oDZ-sh0cKoY
:: Handmade Hero Day 177 - Automatic Performance Counters
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=uHSLHvWFkto
:: Handmade Hero Day 176 - Introduction to Debug Infrastructure
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=vhSIwxAWDIY
:: Handmade Hero Day 175 - Finishing Sparse Unicode Support
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kXQMyg4Prfo
:: Handmade Hero Day 174 - Adding Sparse Unicode Support
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=pkaKQzq-hrM
:: Handmade Hero Day 173 - Precise Font Alignment
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=xSDhhfcwt4E
:: Handmade Hero Day 172 - Extracting Kerning Tables from Windows
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=xUQRWBpYcsk
:: Handmade Hero Day 171 - Adding Font Metadata to the Asset Builder
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tJMvJaM-BtY
:: Handmade Hero Day 170 - Defining Font Metadata
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=eIi2OYFWfdQ
:: Handmade Hero Day 169 - Aligning Text to a Baseline
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=fVyzTKCfchw
:: Handmade Hero Day 168 - Rendering Lines of Text
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=jG9qVQ450GA
:: Handmade Hero Day 167 - Finishing Win32 Font Glyph Extraction
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Hc33CNhmAg8
:: Handmade Hero Day 166 - Adding Locks to the Asset Operations
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=jIWa0AZz2Sk
:: Handmade Hero Day 165 - Fixing an Asset System Thread Bug
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=9_jVu7RfP88
:: Handmade Hero Day 164 - Asset Processing with Windows Fonts
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=KF0jRm89bRM
:: Handmade Hero Day 163 - Asset Processing with STB TrueType
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lOLRQ01QY48
:: Handmade Hero Day 162 - Introduction to Fonts
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ZK7PezR1KgU
:: Handmade Hero Day 161 - Finishing the General Purpose Allocator
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=1LyHQVYlClw
:: Handmade Hero Day 160 - Basic General Purpose Allocation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=MyGsWY6dezE
:: Handmade Hero Day 159 - Cleaning Up the Loaded Asset Infrastructure
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ZrAoRHSTzMY
:: Handmade Hero Day 158 - Tracking Asset Usage
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=D5JG3XGPf8Y
:: Handmade Hero Day 157 - Introduction to General Purpose Allocation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=MvDUe2evkHg
:: Handmade Hero Day 156 - Lagrangian vs. Eulerian Simulation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=HH_iaJairW8
:: Handmade Hero Day 155 - Introduction to Particle Systems
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=G6OGKP3MaUI
:: Handmade Hero Day 154 - Finding Asset Files with Win32
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=vrZkMo77BI8
:: Handmade Hero Day 153 - Merging Multiple Asset Files
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=9sb8mv6q7WE
:: Handmade Hero Day 152 - New Win32 File API Implementation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=hRYrqGBmfOA
:: Handmade Hero Day 151 - New Platform File API
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=NFptGMDCO0k
:: Handmade Hero Day 150 - Loading Assets from the Asset File
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=h2GoVMArDro
:: Handmade Hero Day 149 - Writing Assets to the Asset File
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=CNTlpoYdKF8
:: Handmade Hero Day 148 - Writing the Asset File Header
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=UNXHK8O-B_g
:: Handmade Hero Day 147 - Defining the Asset File
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=n0RRz3NlHuo
:: Handmade Hero Day 146 - Accumulation vs. Explicit Calculation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=YlKPcSwXh54
:: Handmade Hero Day 145 - SSE Mixer Main Loop
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=W3rrlUEaW1E
:: Handmade Hero Day 144 - SSE Mixer Pre and Post Loops
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=l3zbzEYRLJc
:: Handmade Hero Day 143 - Pitch Shifting in the Mixer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=OOR8A_7JwIY
:: Handmade Hero Day 142 - Per-sample Volume Interpolation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=XxReVrByBYw
:: Handmade Hero Day 141 - Streaming Large Audio in Chunks
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Yvv9nVqGC5w
:: Handmade Hero Day 140 - Implementing a Sound Mixer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=UuqcgQxpfO8
:: Handmade Hero Day 139 - Introduction to Sound Mixing
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=8KvWx4hzdUs
:: Handmade Hero Day 138 - Loading WAV Files
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=RSxUBaoomy0
:: Handmade Hero Day 137 - Matching Periodic Tags
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=gVOuBzVC20g
:: Handmade Hero Day 136 - Tag-based Asset Retrieval
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=7g79J2aMTUM
:: Handmade Hero Day 135 - Typed Asset Arrays
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=meU5RI3J1wc
:: Handmade Hero Day 134 - Mapping Assets to Bitmaps
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=AdscwVnyaQw
:: Handmade Hero Day 133 - Preliminary Asset Structuring
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=u0LjxqHmvkk
:: Handmade Hero Day 132 - Asset Streaming
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=qyHM36RQxAI
:: Handmade Hero Day 131 - Asynchronous Ground Chunk Composition
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=6blXhvPIz5g
:: Handmade Hero Day 130 - Seamless Bilinear Tiling
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=odlnqAsclFo
:: Handmade Hero Day 129 - Adding Orthographic Projection
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=8DX-DPsXvy4
:: Handmade Hero Day 128 - Push-time Transforms
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=8L21Tyh53BQ
:: Handmade Hero Day 127 - Aligning Rendering Memory
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=blcNbU70I9o
:: Handmade Hero Day 126 - Circular FIFO Work Queue
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=0jfDwujUY4Y
:: Handmade Hero Day 125 - Abstracting the Work Queue
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ZAZV_PGlQ0s
:: Handmade Hero Day 124 - Memory Barriers and Semaphores
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=W_szrzjYuvs
:: Handmade Hero Day 123 - Interlocked Operations
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=_olNhuuRYxo
:: Handmade Hero Day 122 - Introduction to Multithreading
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=qkugPXGeX58
:: Handmade Hero Day 121 - Rendering in Tiles (Marathon)
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kZlPYka1T0g
:: Handmade Hero Day 120 - Measuring Port Usage with IACA
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=-c-0s6KiPSw
:: Handmade Hero Day 119 - Counting Intrinsics
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=NPDL1OENYio
:: Handmade Hero Day 118 - Wide Unpacking and Masking
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=-_X0UYCGaVA
:: Handmade Hero Day 117 - Packing Pixels for the Framebuffer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=90eSF6jLzvQ
:: Handmade Hero Day 116 - Converting Math Operations to SIMD
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=1CVmlnhgT3g
:: Handmade Hero Day 115 - SIMD Basics
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=YnnTb0AQgYM
:: Handmade Hero Day 114 - Preparing a Function for Optimization
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=_vkI9BedvKA
:: Handmade Hero Day 113 - Simple Performance Counters
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=QdTqYhv8tL0
:: Handmade Hero Day 112 - A Mental Model of CPU Performance
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=qin-Eps3U_E
:: Handmade Hero Day 111 - Resolution-Independent Ground Chunks
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=qDE7_6K2pyY
:: Handmade Hero Day 110 - Unprojecting Screen Boundaries
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=s-eL7riOnwc
:: Handmade Hero Day 109 - Resolution-Independent Rendering
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=e3d7kEtX6iw
:: Handmade Hero Day 108 - Perspective Projection
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=xgnEOFS8wTw
:: Handmade Hero Day 107 - Fading Z Layers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=CmXCiK8dK9c
:: Handmade Hero Day 106 - World Scaling
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=UCTcu8vJ92c
:: Handmade Hero Day 105 - Cleaning Up the Renderer API
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Jklm_p_qrKU
:: Handmade Hero Day 104 - Switching to Y-is-up Render Targets
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=CfjMu8DwOnY
:: Handmade Hero Day 103 - Card-like Normal Map Reflections
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=-LWk-TVfGTk
:: Handmade Hero Day 102 - Transforming Normals Properly
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=73u0sR4DU9E
:: Handmade Hero Day 101 - The Inverse and the Transpose
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=PPDAqEJvUUQ
:: Handmade Hero Day 100 - Reflection Vectors
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=PHz3ulc_mFk
:: Handmade Hero Day 099 - Test Environment Maps
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=07UpVTmIKdU
:: Handmade Hero Day 098 - Normal Map Code Cleanup
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=xWQfjqAHvxs
:: Handmade Hero Day 097 - Adding Normal Maps to the Pipeline
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=oww19zUryVg
:: Handmade Hero Day 096 - Introduction to Lighting
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=QtepVbq6_pw
:: Handmade Hero Day 095 - Gamma-correct Premultiplied Alpha
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=JTIzGsGqQaA
:: Handmade Hero Day 094 - Converting sRGB to Light-linear Space
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=GKVMOmEGVoQ
:: Handmade Hero Day 093 - Textured Quadrilaterals
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=k5wzQeWRokA
:: Handmade Hero Day 092 - Filling Rotated and Scaled Rectangles
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kVU_QIxm3AA
:: Handmade Hero Day 091 - Bases Part II
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=2yKKcjBIaL0
:: Handmade Hero Day 090 - Bases Part I
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lcmjmOfWPNU
:: Handmade Hero Day 089 - Renderer Push Buffer Entry Types
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lllby5vrEes
:: Handmade Hero Day 088 - Push Buffer Rendering
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=zbufcZ_JBbU
:: Handmade Hero Day 087 - Seamless Ground Textures
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=YAaqiKuSmsk
:: Handmade Hero Day 086 - Aligning Ground Buffers to World Chunks
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=TxowSnU2_cQ
:: Handmade Hero Day 085 - Transient Ground Buffers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=QhjuxnQyBwk
:: Handmade Hero Day 084 - Scrolling Ground Buffer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=U5AAAaiMlYQ
:: Handmade Hero Day 083 - Premultiplied Alpha
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=bidrZj1YosA
:: Handmade Hero Day 082 - Caching Composited Bitmaps
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=09bUpNbRzzc
:: Handmade Hero Day 081 - Creating Ground with Overlapping Bitmaps
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=EGOrMZwQVEk
:: Handmade Hero Day 080 - Handling Traversables in the Collision Loop
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=QxxVwnE8V1c
:: Handmade Hero Day 079 - Defining the Ground
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=HMW1fsXzW-o
:: Handmade Hero Day 078 - Multiple Collision Volumes Per Entity
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=o1DO5sjUhi0
:: Handmade Hero Day 077 - Entity Ground Points
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=9IGZGfVvc0s
:: Handmade Hero Day 076 - Entity Heights and Collision Detection
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=0mGWYcE6yG8
:: Handmade Hero Day 075 - Conditional Movement Based on Step Heights
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=bZxa4fdtI2Y
:: Handmade Hero Day 074 - Moving Entities Up and Down Stairwells
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Hm_CTQwV13U
:: Handmade Hero Day 073 - Temporarily Overlapping Entities
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=e0yjNipizK0
:: Handmade Hero Day 072 - Proper 3D Inclusion Tests
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tcirDivLd8A
:: Handmade Hero Day 071 - Converting to Full 3D Positioning
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=FVPxhovGsuE
:: Handmade Hero Day 070 - Exploration To-do List
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=afWxzIHB5Ss
:: Handmade Hero Day 069 - Pairwise Collision Rules
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=YrqQLA9SOEc
:: Handmade Hero Day 068 - Exact Enforcement of Maximum Movement Distances
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=0ZjYHfYAjQg
:: Handmade Hero Day 067 - Making Updates Conditional
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lnnb49-FYqU
:: Handmade Hero Day 066 - Adding Support for Non-spatial Entities
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=vXPAE5UfcbA
:: Handmade Hero Day 065 - Finishing the Simulation Region Change
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=XfBTNH0nL4I
:: Handmade Hero Day 064 - Mapping Entity Indexes to Pointers
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lHKso30LdU8
:: Handmade Hero Day 063 - Simulation Regions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=a7_vSEEgArQ
:: Handmade Hero Day 062 - Basic Moving Projectiles
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=F7feQINaRnk
:: Handmade Hero Day 061 - Adding a Simple Attack
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=bHGLcGgwpWg
:: Handmade Hero Day 060 - Adding Hitpoints
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=0_xzS8zxuq4
:: Handmade Hero Day 059 - Adding a Basic Familiar Entity
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=KBCNjjeXezM
:: Handmade Hero Day 058 - Using the Spatial Partition
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=W_z9VN1m2Oo
:: Handmade Hero Day 057 - Spatially Partitioning Entities
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=nAFuhA8xqTk
:: Handmade Hero Day 056 - Switching from Tiles to Entities
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=NMfx9eVrNmQ
:: Handmade Hero Day 055 - Hash-based World Storage
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=WyXBawK1jpE
:: Handmade Hero Day 054 - Removing the Dormant Entity Concept
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=yqM04duWiiU
:: Handmade Hero Day 053 - Environment Elements as Entities
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=KAZrNrcgrRc
:: Handmade Hero Day 052 - Entity Movement in Camera Space
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=TfZUAFh-WJg
:: Handmade Hero Day 051 - Separating Entities By Update Frequency
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=RQUP4ql86k0
:: Handmade Hero Day 050 - Basic Minkowski-based Collision Detection
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=_g8DLrNyVsQ
:: Handmade Hero Day 049 - Debugging Canonical Coordinates
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=CIe8J9ScmRo
:: Handmade Hero Day 048 - Line Segment Intersection Collisions
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=rWpZLvbT02o
:: Handmade Hero Day 047 - Vector Lengths
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=5KzJ0TDeLxQ
:: Handmade Hero Day 046 - Basic Multiplayer Support
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=BU5xBpUMdPA
:: Handmade Hero Day 045 - Geometric vs. Temporal Movement Search
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=bERy-zhosqY
:: Handmade Hero Day 044 - Reflecting Vectors
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=2nyNOJoVC8M
:: Handmade Hero Day 043 - The Equations of Motion
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=LoTRzRFEk5I
:: Handmade Hero Day 042 - Basic 2D Vectors
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=eE-D_wSUd0g
:: Handmade Hero Day 041 - Overview of the Types of Math Used in Games
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=WN3_d_QcJZE
:: Handmade Hero Day 040 - Cursor Hiding and Fullscreen Support
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=YBCOijN2fNA
:: Handmade Hero Day 039 - Basic Bitmap Rendering Cleanup
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=R8BiV_uYT6E
:: Handmade Hero Day 038 - Basic Linear Bitmap Blending
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ydiHNs1YQoI
:: Handmade Hero Day 037 - Basic Bitmap Rendering
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=ofMJUSchXwo
:: Handmade Hero Day 036 - Loading BMPs
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=USFTH9mcaKw
:: Handmade Hero Day 035 - Basic Sparse Tilemap Storage
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=i5-oY8EHkzw
:: Handmade Hero Day 034 - Tile Map Memory
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=IJYTwhqfKLg
:: Handmade Hero Day 033 - Virtualized Tile Maps
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=iHSAOSYOt9E
:: Handmade Hero Day 032 - Unified Position Representation
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=vI39C4iR8P0
:: Handmade Hero Day 031 - Tilemap Coordinate Systems
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=lDp4rqcigZs
:: Handmade Hero Day 030 - Moving Between Tile Maps
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=J7suWih0ITQ
:: Handmade Hero Day 029 - Basic Tile Map Collision Checking
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=EwhVulgF16g
:: Handmade Hero Day 028 - Drawing a Tile Map
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=QGmQ714rlAc
:: Handmade Hero Day 027 - Exploration-based Architecture
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Mi98zVBb6Wk
:: Handmade Hero Day 026 - Introduction to Game Architecture
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=rPJfadFSCyQ
:: Handmade Hero Day 025 - Finishing the Win32 Prototyping Layer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=es-Bou2dIdY
:: Handmade Hero Day 024 - Win32 Platform Layer Cleanup
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=nBBTPRO8AMI
:: Handmade Hero Day 023 - Looped Live Code Editing
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=xrUSrVvB21c
:: Handmade Hero Day 022 - Instantaneous Live Code Editing
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=oijEnriqqcs
:: Handmade Hero Day 021 - Loading Game Code Dynamically
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=WMSBRk5WG58
:: Handmade Hero Day 020 - Debugging the Audio Sync
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=hELF8KRqSIs
:: Handmade Hero Day 019 - Improving Audio Synchronization
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=qFl62ka51Mc
:: Handmade Hero Day 018 - Enforcing a Video Frame Rate
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=TPpn2fee77M
:: Handmade Hero Day 017 - Unified Keyboard and Gamepad Input
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=WDB718JId4M
:: Handmade Hero Day 016 - VisualStudio Compiler Switches
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=zN7llTrMMBU
:: Handmade Hero Day 015 - Platform-independent Debug File I/O
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=kdAte9pdLv8
:: Handmade Hero Day 014 - Platform-independent Game Memory
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tcENxzeTjbI
:: Handmade Hero Day 013 - Platform-independent User Input
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Lt9DfMzZ9sI
:: Handmade Hero Day 012 - Platform-independent Sound Output
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=5YhR2zAkQmo
:: Handmade Hero Day 011 - The Basics of Platform API Design
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=_4vnV2Eng7M
:: Handmade Hero Day 010 - QueryPerformanceCounter and RDTSC
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=tAcUIEoy2Yk
:: Handmade Hero Day 009 - Variable-Pitch Sine Wave Output
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=8y9nPk1c45c
:: Handmade Hero Day 008 - Writing a Square Wave to DirectSound
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=uiW1D1Vc7IQ
:: Handmade Hero Day 007 - Initializing DirectSound
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=qGC3xiliJW8
:: Handmade Hero Day 006 - Gamepad and Keyboard Input
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=J3y1x54vyIQ
:: Handmade Hero Day 005 - Windows Graphics Review
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=w7ay7QXmo_o
:: Handmade Hero Day 004 - Animating the Backbuffer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=hNKU8Jiza2g
:: Handmade Hero Day 003 - Allocating a Backbuffer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=GAi_nTx1zG8
:: Handmade Hero Day 002 - Q&amp;A
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=d003_D-9EnY
:: Handmade Hero Day 002 - Opening a Win32 Window
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=4ROiWonnWGk
:: Handmade Hero Day 001 - Q&amp;A
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=uxbJo5DDpWY
:: Handmade Hero Day 001 - Setting Up the Windows Build
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=Ee3EtYb8d1o
:: Handmade Hero - Announcement Trailer
youtube-dl.exe -f 135+140 www.youtube.com/watch?v=A2dxjOjWHxQ
_____________________________________________________________________________________________
_____________________________________________________________________________________________
_____________________________________________________________________________________________
_____________________________________________________________________________________________
struct line2d{
	real32 xa,ya,xb,yb;
};
struct pt2d{
	real32 x,y;
};
struct queryPoint{
	bool32 result;
	real32 x,y;
};

// findIntersection(l1, l2, pt)
// find point of intersection between 2 line segments,
pt2d findIntersection(line2d line1, line2d line2, pt2d qPoint){
	real32 l1[] = {line1.xa, line1.ya, line1.xb, line1.yb};
	real32 l2[] = {line2.xa, line2.ya, line2.xb, line2.yb};
	real32 pt[] = {qPoint.x, qPoint.y};
	
	real32 p1[2] = {0,0};
	real32 point[2] = {0,0};
	int di,dj = 0;
	if( abs(l1[1]-l1[1]) > abs(l1[0]-l1[0]) ){// di stands for direction index
		di = 1; dj = 0;
	}
	else{ 
		di = 0; dj = 1;
	}
	real32 pivot[2] = { l1[di+2], l1[dj+2] };
	int ppu = ( l1[di+2] - l1[di] ) / ( l1[dj+2] - l1[dj] );// projection per unit
	real32 line2b[] = {l2[di], l2[dj], l2[di+2], l2[dj+2]};
	line2b[di] = line2b[di] + ppu * ( l1[dj+2] - l2[dj] );
	line2b[di+2] = line2b[di+2] + ppu * ( l1[dj+2] - l2[dj+2] );
	p1[di] = pivot[di];
	p1[dj] = line2b[dj] - ( line2b[di] - pivot[di] ) * ( (line2b[dj+2]-line2b[dj])/(line2b[di+2]-line2b[di]) );
	point[dj] = p1[dj];
	point[di] = pivot[di] - ppu * ( l1[dj+2] - p1[dj] );
	pt2d rPoint;
	rPoint.x = point[0];
	rPoint.y = point[1];
  
	return rPoint;
}

// getDistance(point)
real32 getDistance(pt2d point){
	return pow( ( point.x*point.x + point.y*point.y ) ,0.5);
}

/*
// getGradientStyledPoint(point)
def getGradientStyledPoint(point):
	dist = getDistance( ( 0.5-point[0], 0.5-point[1] ) ) 
	gradient  = (255-((dist*250+10)/20), 255-((dist*point[1]*5*250+10)/20), 255-((dist*point[0]*10*250+10)/20) )
	return gradient
 	

// getGradientPoint(point)
# returns a gradient, red 0-255 on the x and green, 0-255 on the y
def getGradientPoint(point):
	gradient  = (int(point[0]*60), int(point[1]*60), 0 )
	return gradient

// quadInterpolate(u1,u2,u3,u4,pt)
queryPoint quadInterpolate( point1, point2, point3, point4, pt ){
	bool32 result = 0;

	real32 u1[] = {point1.x, point1.y};
	real32 u2[] = {point2.x, point2.y};
	real32 u3[] = {point3.x, point3.y};
	real32 u4[] = {point4.x, point4.y};
	real32 u[4][2] = {u1,u2,u3,u4};
	u.append(u1); u.append(u2); u.append(u3); u.append(u4);

	seg1x = abs(u1[0] - u2[0]);
	seg2x = abs(u3[0] - u2[0]);
	minX = (seg1x < seg2x)? seg1x : seg2x;
	seg1y = abs(u1[1] - u2[1]);
	seg2y = abs(u3[1] - u2[1]);
	minY = (seg1y < seg2y)? seg1y : seg2y;

	h = (minX < minY)? 2 : 0;
	v = (h == 2)? 0 : 2;
	
	projHX = u[h][0] - u[1][0];
	projHY = float( u[h][1] - u[1][1] ) / float(projHX);
	projVX = ( u[v][1] - u[1][1] ) - float( u[v][0] - u[1][0] ) * float(projHY);
	projVY = ( u[v][0] - u[1][0] ) / projVX;

	p = ( float(pt[0])-float(u2[0]), float(pt[1])-float(u2[1]), 0 );
	ppt = (float(p[0]), float(p[1]) - float(p[0])*float(projHY), 0);
	pppt = ( (float(ppt[0]) - float(ppt[1])*float(projVY) ), float(ppt[1]), 0);

	p4 = ( float(u4[0])-float(u2[0]), float(u4[1])-float(u2[1]), 0 );
	pt4 = (float(p4[0]), float(p4[1]) - float(p4[0])*float(projHY), 0);
	ppt4 = ( (float(pt4[0]) - float(pt4[1])*float(projVY) ), float(pt4[1]), 0);
	// check whether is inside the 0->1 circle,
	ma = pppt[0] / projHX;
	mb = pppt[1] / projVX;
	maa = ppt4[0] / projHX;
	mbb = ppt4[1] / projVX;
	ma1 = ma;
	ma = ma / (1+( (maa-1)*mb ));
	mb = mb / (1+( (mbb-1)*ma1));
	if ( (int(pt[0]) == 59)&&( int(pt[1]) == 86) ){
		//print 'ma:', ma, 'mb:', mb, 'maa:', maa, 'mbb:', mbb
	}
	if( ma > 0 && ma < 1 && mb > 0 && mb < 1){
		result = 1;
	}
	else{
		result = 0;
	}
	return (result, ma, mb)
}
// curveInside(u1,u2,u3,pt)
def curveInside(u1,u2,u3,pt):
	result = False
	inBbox = True

	u = []
	u.append(u1); u.append(u2); u.append(u3); 

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

	ma = pppt[0] / projHX
	mb = pppt[1] / projVX
	if ( ( ma**2 + mb**2 ) > (1+0) ):
		result = True
	else:
		result = False
	return result

*/






--------------------------------
	
	
	
	
	
	
	

# _____________________________________________________________________________
# test_line.py - find the intersection between two line segments
# result gives a code for whether there is an intersection or not,
# and the point of intersection (or 0,0 if there isn't)
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
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
fulltxt = txt.resize((512,512))
fulltxt.show()

# _____________________________________________________________________________
# test_quad.py - rasterizes a quad that consist of 4 convex points.
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
top1 = 0; top2 = 0
for i in range(4):
	if top1 < quads[i][1]:
		top1 = quads[i][1]; t1 = i
for i in range(4):
	if top2 < quads[i][1] and quads[i][1] != top1:
		top2 = quads[i][1]; t2 = i
bottom1 = top1; bottom2 = top2
for i in range(4):
	if bottom1 > quads[i][1]:
		bottom1 = quads[i][1]; b1 = i
for i in range(4):
	if bottom2 > quads[i][1] and quads[i][1] != bottom1:
		bottom2 = quads[i][1]; b2 = i
dirTop = t1 - t2
dirBottom = b1 - b2

# now we need to run 3 loops that are linear, from top1 to top2, from top2 to bottom 2, and from bottom 2 to bottom1.
# we draw this qquad from bottom to top.
# processing the two bottoms,
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
pLeft = -1; pRight = -1
for i in range(int(bottom1), int(bottom2)):
	for l in range(int(b1x), int(b2x)):
		d.point( (l,i), fill = (100,0,0) )
		pass
	left = b1x; right = b2x
	if pLeft >= 0:
		nLeft = pLeft if pLeft < left else left
		nRight = pLeft if pLeft > left else left
		for l in range(int(nLeft-1), int(nRight+1)):
			pick = txt.getpixel((l,i))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i), fill = newColor )
			pick = txt.getpixel((l,i-1))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i-1), fill = newColor )
		nLeft = pRight if pRight < right else right
		nRight = pRight if pRight > right else right
		for l in range(int(nLeft-1), int(nRight+1)):
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
	for l in range(int(nLeft-1), int(nRight+1)):
		pick = txt.getpixel((l,i))
		newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
		d.point( (l,i), fill = newColor )
		pick = txt.getpixel((l,i-1))
		newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
		d.point( (l,i-1), fill = newColor )
	nLeft = pRight if pRight < right else right
	nRight = pRight if pRight > right else right
	for l in range(int(nLeft-1), int(nRight+1)):
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
t1x = float(quads[t1][0])
t2x = float(quads[t1][0])
for i in range(int(top1)-1, int(top2)-1, -1):
	for l in range(int(t1x), int(t2x)):
		d.point( (l,i), fill = (100,0,0) )
		pass
	left = t1x; right = t2x
	if pLeft >= 0:
		nLeft = pLeft if pLeft < left else left
		nRight = pLeft if pLeft > left else left
		for l in range(int(nLeft-1), int(nRight+1)):
			pick = txt.getpixel((l,i))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i), fill = newColor )
			pick = txt.getpixel((l,i-1))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i-1), fill = newColor )
		nLeft = pRight if pRight < right else right
		nRight = pRight if pRight > right else right
		for l in range(int(nLeft-1), int(nRight+1)):
			pick = txt.getpixel((l,i))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i), fill = newColor )
			pick = txt.getpixel((l,i-1))
			newColor = (pick[0]+0, pick[1]+50, pick[2]+75) 
			d.point( (l,i-1), fill = newColor )
	pLeft = left; pRight = right
	t1x -= deltaX1; t2x -= deltaX2
	pass
fulltxt = txt.resize((512,512))
fulltxt.show()

# _____________________________________________________________________________
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

# _____________________________________________________________________________
# test_curve.py
# returns whether or not a point falls inside a curve slice
# curve slice is defined by 3 points, the first and last are the end points
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
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
fulltxt = txt.resize((512,512))
fulltxt.show()

#_________________________________________________________________________________________
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)

loopCount = 0
for i in circles:
	x = i[0]
	y = i[1] - i[2]
	for j in range( int( i[2]*2 ) ):
		width = math.pow( ( i[2]*i[2] - (y-i[1])*(y-i[1]) ) , 0.5) * 2
		xpos = 0
		# drawing the solid shape with no AA,
		for k in range(1, int(width)+1 ):
			xpos = int(x - width/2 + k)
			pick = txt.getpixel((xpos,y))
			newColor = (pick[0] , g , pick[2]) 
#			d.point( (xpos,y), fill = newColor )
		leftEdge = int(x - width/2)
		rightEdge = int(x - width/2 + width)

		# drawing the raytracing mask,
		for l in range( leftEdge-0, leftEdge+1+2 ):
			pick = txt.getpixel((l,y))
			d.point( (l,y), fill = (r2,pick[1],pick[2]) )
		for l in range( rightEdge-0, rightEdge+1+2 ):
			pick = txt.getpixel((l,y))
			d.point( (l,y), fill = (r2,pick[1],pick[2]) )

		leftEdge -= 1
		rightEdge += 1
		if loopCount == 0:
			#print leftEdge
			#print rightEdge
			vOffset = -1
			for l in range( leftEdge, rightEdge ):
				pick = txt.getpixel((l,y+vOffset))
#				d.point( (l,y+vOffset), fill = (r2,pick[1],pick[2]) )
			loopCount += 1
		else:
			if leftEdge > pLeftEdge:
				vOffset = 0
				for l in range( pLeftEdge, leftEdge ):
					pick = txt.getpixel((l,y+vOffset))
#					d.point( (l,y+vOffset), fill = (r2,pick[1],pick[2]) )
			else:
				vOffset = -1
				for l in range( leftEdge, pLeftEdge ):
					pick = txt.getpixel((l,y+vOffset))
#					d.point( (l,y+vOffset), fill = (r2,pick[1],pick[2]) )
			if rightEdge < pRightEdge:
				vOffset = 0
				for l in range( rightEdge, pRightEdge ):
					pick = txt.getpixel((l,y+vOffset))
#					d.point( (l,y+vOffset), fill = (r2,pick[1],pick[2]) )
			else:
				vOffset = -1
				for l in range( pRightEdge, rightEdge ):
					pick = txt.getpixel((l,y+vOffset))
#					d.point( (l,y+vOffset), fill = (r2,pick[1],pick[2]) )

		index = 0
		y += 1
		pLeftEdge = leftEdge
		pRightEdge = rightEdge

# raytracing for comparison,
for i in range( imgSize ):
	for j in range( imgSize ):
		pick = txt.getpixel((i,j))
		inc = 0
		for aa in range(16):
			distance  = (circles[0][0]-i+aax4[aa])**2 + (circles[0][0]-j+aay4[aa])**2
			radius = circles[0][2]**2
			if distance <= radius:
				inc += 12.5#50
		if inc < 200 and inc > 0:
				inc = 255
		elif inc > 0:
			inc = 10#100
		newColor = (pick[0] , pick[1] , inc ) 
		d.point( (i,j), fill=newColor )
fulltxt = txt.resize((512,512))
fulltxt.show()

#_________________________________________________________________________________________
# rasterizing a line with a raytracing marked mask.
# this fails when the line is nearly or totally horizontal,
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
d = ImageDraw.Draw(txt)
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
		for n in range( int(l-1), int(l+2) ):
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
fulltxt = txt.resize((512,512))
fulltxt.show()
