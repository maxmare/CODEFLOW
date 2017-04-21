:: about sintax highlighting,
https://linusakesson.net/programming/syntaxhighlighting/index.php
# links,
# character designs, (gotcha)
https://www.behance.net/gallery/45512891/Digital-Sketches-and-process-vol-1-
http://68.media.tumblr.com/458b91596991c035a1fdbcd1d59162c9/tumblr_o3y0crgZuU1qi8pxqo1_1280.jpg
https://2.bp.blogspot.com/-Rut6uZ0GK2w/Vs35cGa8WYI/AAAAAAAAF5g/3HZvbPxtMc0/s1600/24.jpg
http://68.media.tumblr.com/458b91596991c035a1fdbcd1d59162c9/tumblr_o3y0crgZuU1qi8pxqo1_1280.jpg
https://1.bp.blogspot.com/-u9mbANGO9pY/Vs35VvAVpcI/AAAAAAAAF4w/vNmHTA5eS4M/s1600/23.jpg
http://68.media.tumblr.com/32f1f1641fd1b9e2a50c51757a418684/tumblr_o3y0fyRFX61qi8pxqo2_1280.jpg
# from Lilo & Stitch,
https://s-media-cache-ak0.pinimg.com/originals/24/d6/fc/24d6fc0c636fa924b5d0fb26d51a0e52.png
http://4.bp.blogspot.com/-xl5sPf90BLg/Tqxe7kNgMqI/AAAAAAAAABs/DVfXL6p_NXE/s1600/StitchSketches2.jpg
https://www.google.ca/imgres?imgurl=http%3A%2F%2F2.bp.blogspot.com%2F_-YOK6-hJ5kY%2FTNyBbhnl9EI%2FAAAAAAAAGxY%2F0vPEq-kFtNU%2Fs1600%2FModelSheet_2Arms.jpg&imgrefurl=http%3A%2F%2Flivlily.blogspot.com%2F2010%2F11%2Flilo-stitch-2002.html&docid=6-Ai61qIET-DvM&tbnid=jrMt7G28HHfTlM%3A&vet=10ahUKEwjFpLeRsZ_TAhUK8GMKHTsIB3gQMwhbKDEwMQ..i&w=800&h=508&bih=665&biw=1280&q=concept%20art%20lilo%20stitch&ved=0ahUKEwjFpLeRsZ_TAhUK8GMKHTsIB3gQMwhbKDEwMQ&iact=mrc&uact=8
https://www.google.ca/imgres?imgurl=https%3A%2F%2Fupload.wikimedia.org%2Fwikipedia%2Fen%2Fthumb%2Fd%2Fd2%2FStitch_%2528Lilo_%2526_Stitch%2529.svg%2F1200px-Stitch_%2528Lilo_%2526_Stitch%2529.svg.png&imgrefurl=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FStitch_(Lilo_%2526_Stitch)&docid=-unY3eCa3nsd1M&tbnid=guRFtnJzHeipyM%3A&vet=10ahUKEwjYppCDsp_TAhUCS2MKHbIeAQs4ZBAzCEUoQzBD..i&w=1200&h=1659&bih=665&biw=1280&q=concept%20art%20lilo%20stitch&ved=0ahUKEwjYppCDsp_TAhUCS2MKHbIeAQs4ZBAzCEUoQzBD&iact=mrc&uact=8
https://www.google.ca/imgres?imgurl=http%3A%2F%2F2.bp.blogspot.com%2F_-YOK6-hJ5kY%2FTNx4JYxuUrI%2FAAAAAAAAGxQ%2FGeMnnMsoK3U%2Fs1600%2Fmsheet-stitch2.png&imgrefurl=http%3A%2F%2Flivlily.blogspot.com%2F2010%2F11%2Flilo-stitch-2002.html&docid=6-Ai61qIET-DvM&tbnid=81Z0fPCTSjI8iM%3A&vet=10ahUKEwjFpLeRsZ_TAhUK8GMKHTsIB3gQMwhdKDMwMw..i&w=900&h=562&bih=665&biw=1280&q=concept%20art%20lilo%20stitch&ved=0ahUKEwjFpLeRsZ_TAhUK8GMKHTsIB3gQMwhdKDMwMw&iact=mrc&uact=8
# parallax example,
http://pixeljoint.com/pixelart/112117.htm

https://coldesignltd.com/
#  tutoriales acerca de toonz
https://www.youtube.com/watch?v=fpq7OxSOR0g
https://github.com/tudelft3d/Random3Dcity/blob/master/generateCityGML.py
http://images.thimbleweedpark.com/budget1f.png
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
http://i.imgur.com/EFAvkh1.png
http://i.imgur.com/947tO14.gif
http://i.imgur.com/5eTavBB.gif
http://saltwort.tumblr.com/
https://notgnoshi.github.io/printf/
http://www.killingtimeatlightspeed.com/
https://github.com/InteractiveComputerGraphics/PositionBasedDynamics/tree/master/PositionBasedDynamics
https://github.com/Cyan4973/xxHash
https://asafgartner.github.io/annotations_search/#memory
http://downloads.guru3d.com/download.php?det=2814
http://leshcatlabs.net/downloads_unfil/
# stream from Sssmcgrath talking about text editor and learning sublime text,
https://www.twitch.tv/sssmcgrath/v/97381962


# RE: accesibility issues for app development
There's another very important issue you have to take care of when you want to distribute GUI applications: Accessibility.
This includes (but is not limited to):
1. Can I mark and copy text? Is it any text, or just specific things?
2. Can I enlarge the font or the entire view without breaking the app?
3. Can I resize the window without breaking the app?
4. Can I use the app with just the keyboard, or just the mouse (with an OS-provided on-screen keyboard)?
5. Does it work with a screen reader?
6. Does it play nicely with other OS accessibility features (high-contrast mode or DPI settings)?
7. Will these features work automatically with custom widgets?


# very early days of this proc,...
# raster draw a multi-faced polygon in 2d.
#-----------------------------------------------------------------------
from PIL import Image, ImageDraw, ImageFont
import random
import time
import math

# boilerplate,
random.seed(time.time())
imgSize = 128
base = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
lines = []; point = []

# data,
for i in range( int(random.random()*10)+4 ):
	lines.append([
		(random.random()*2-1)*50.0+64.0,
		(random.random()*2-1)*50.0+64.0])

point.append(50.0); point.append(50.0)
aax = [0.25, 0.75, 0.25, 0.75]; aay = [0.25, 0.25, 0.75, 0.75]
R = 0;	G = 0;	B = 0
r = 0;	g = 0;	b = 0
r1 = 100;	g1 = 0;		b1 = 0
r2 = 0;		g2 = 100;	b2 = 0
r3 = 0;		g3 = 0;		b3 = 100
leftEdge = 0; rightEdge = 0
di = -1

# procedure face_multipoly_raster,
# given a face defined by:
#   number of points and a list of points, 
# and a bitmap defined by:
#   width and height of the bitmap in pixels and a list of pixels,
# raster the pixels that are covered by the points in the order given.
# we will use recursion to deal with concave areas of the face.
def face_multipoly_raster(points, bitmap):
	
	pass

no = 0
for i in range(1):# no. tests to run (and images to generate),
	random.seed(time.time())
	txt = base
	d = ImageDraw.Draw(txt)
	lines = []
	xmin = 0; xmax = 0; ymin = 0; ymax = 0; xmin_value = 0; ymin_value = 0; xmax_value = 0; ymax_value = 0; xmin_index = 0; ymin_index = 0
	rndN = int(random.random()*10)+3
	for i in range( rndN ):# no. lines
		lines.append([0,0])
	for i in range( rndN ):
		lines[i][0] = (random.random()*2-1)*50.0+64.0
		lines[i][1] = (random.random()*2-1)*50.0+64.0
	a = lines[0][0]# initial max min values for first line
	b = lines[0][1]  
	xmin = xmax = a
	ymin = ymax = b
	for i in range( len(lines) ):# find max min values
		a = lines[i][0]
		b = lines[i][1]
		if a < xmin:
			xmin = a; xmin_index = i
		if a > xmax:
			xmax = a
		if b < ymin:
			ymin = b; ymin_index = i
		if b > ymax:
			ymax = b
	min_index = 0; min_value = 0; max_value = 0
	# agnostic direction min and max
	if xmax - xmin > ymax-ymin:
		df = 0; db = 1# forward and backward direction
		min_index = xmin_index
		min_value = xmin
		max_value = xmax
	else: 
		df = 1; db = 0
		min_index = ymin_index
		min_value = ymin
		max_value = ymax
		
	print lines
	print "these are the corners of the bounding box,"
	print xmin, xmax, ymin, ymax
	
	# we raster the polygon following its point ordering,
	# the outline of the face is build by the ordering of the points,
	lower_row = int(min_value)# rows to run the raster loop
	upper_row = int(max_value)
	linesNo = len(lines)
	total = 1# no. points used in the raster
	leftIndex = min_index - 1# point to the left of the current one
	rightIndex = min_index + 1
	total += 2
	
	for i in range( lower_row , upper_row ):
		if leftIndex < 0:# wrapping on the left
			leftIndex = linesNo-1
		if leftIndex >= linesNo:# wrapping on the right
			leftIndex = 0
		if rightIndex < 0:# wrapping on the left
			rightIndex = linesNo-1
		if rightIndex >= linesNo:# wrapping on the right
			rightIndex = 0
		# how much we move sideways when we move up 1 pixel

		# find leftmost pixel,
		deltaLeft = lines[ leftIndex ][0]
		leftmostPixel = deltaLeft
		
		# find rightmost pixel,
		deltaRight = lines[ rightIndex ][0]
		rightmostPixel = deltaRight

		for j in range( leftmostPixel , rightmostPixel ):
			r += 25; g += 25; b += 25; 
			newColor = (r, g, b)
			d.point( (l,i), fill = newColor )
			pass
	
	# visualizing all the points 
	for i in range(128):
		for l in range(128):
			#for aa in range(4):
				#pt = [float(l)+aax[aa], float(i)+aay[aa]]
			r = 0;	g = 0;	b = 0
			for n in range( len( lines ) ):
				d0 = float(lines[n][0]-l)**2 + float(lines[n][1]-i)**2
				if d0 < 2:
					g += 200
			d0 = float(lines[min_index][0]-l)**2 + float(lines[min_index][1]-i)**2
			if d0 < 2:
				b += 200
			#print "The distance is: ", distance
			if xmin < l < xmax and ymin < i < ymax:
				r += 50
			pick = txt.getpixel( ( l, i ) )
			newColor = ( pick[0]+r, pick[1]+g, pick[2]+b )
			d.point( ( l, i ), fill = newColor )

	txt = txt.resize((512,512))
	d = ImageDraw.Draw(txt)
	#fnt = ImageFont.truetype('LiberationMono.ttf', 40)
	#text = str(round(lines[0][0],2)) + " " + str(round(lines[1][0],2)) + " " + str(round(point[0],2))
	#text = str(lines[0])
	#d.text( (10,10),  text )
	txt.show()
	no += 1
	filename = "img." + str(no) + ".png"
	txt.save(filename, "PNG")


BC Forms that are needed,
BC428, BC Tax
BC479, BC Credits
Line 5804, claim $10027
Line 5838 - children fiteness amount, you can claim if you can claim line 459 on page 4
- Line 458 and 459 - Children's fitness tax credit, 
Line 5841 - children's arts amount.
- Line 370 - children's arts amount.
Line 5836 - Pension income amount, amount on line 314 of federal schedule or $1000, whichever is less ( we made no payments so go for the 1000 amount)
Canadian Child tax benefits (CCTB), to view your CCTB information, go to cra.gc.ca/myaccount
Amounts that are not taxed - any GST/HST, interest from TFSA accounts
Line 101- Employment income from T4 slips
Line 117 - Universal child care benefit (UCCB), report on line 117 the amount shown in box 10 of the RC62 slip
Line 119 - Employment insurance.
Line 121 - Interest and other investment income
Lines 135 to 143 - Self-employment income, 
- T4002, Business and Professional Income (Form T2125)
Line 214 - Child care expenses.

look at Modo i n 2016 september, $44 ???
what's that BCAA insurance? $30 al mes ???

- 2016_01_19, Expenses, $26.25, Air Canada
- 2016_01_20, Expenses, $86.25, Air Canada Aerofleet services
- 2016_01_21, Expenses, $26.25, Air Canada
- 2016_01_22, Expenses, $52.75, Beck taxi
- 2016_01_22, Expenses, $36.00, Pacific Cabs CAR 50
- 2016_01_26, Expenses, $174.62, American Phoenix
- 2016_01_26, Expenses, $575.66, American Phoenix

- 2016_02_07, Expenses, $150.00, Air Transat
- 2016_02_07, Expenses, $2804.97, Air Transat Vacances

- 2016_02_10, Expenses, $309.22, EasyJet Luton beds 147.85 GBP @ 2.0914
- 2016_02_10, Expenses, $758.69, Ryanair Dublin
- 2016_02_14, Expenses, $1538.74, Monarch Airlines 958.52 EUR @ 1.605 paid by Roberto
- 2016_02_20, Expenses, $26.25, American phoenix
- 2016_02_21, Expenses, $173.94, Miami Katsuya
- 2016_02_21, Expenses, $142.41, Caffe Milano
- 2016_02_22, Expenses, $251.64, The Miami Beach Edition
- 2016_02_22, Expenses, $33.25, The Setai Resort & Res Miami Beach
- 2016_02_23, Expenses, $25.33, American Miami
- 2016_02_24, Expenses, $94.24, Fido additional contract
- 2016_02_26, Expenses, $180, RSRS Record Storage North york
- 2016_02_19, Expenses, $20, BCAA-Insurance (paid by Roberto) ???

- 2016_03_11, Expenses, $9, Vancouver Airport
- 2016_03_24, Expenses, $30.00, BCAA Insurance (credit paid by Roberto) ??? 
- 2016_03_28, Expenses, $86.26, Fido Additional contract (credit) 

- 2016_04_11, Expenses, $159.27, Dreamhost cristinabelmontepr.com  (credit by Rob)
- 2016_04_21, Expenses, $648.31, Cathay Pacific (credit)

- 2016_05_01, Expenses, $80.19, Fido mobile additional contract (credit)
- 2016_05_09, Expenses, $30.25, BCAA Insurance (credit paid by Roberto) ???
- 2016_05_10, Expenses, $136.62, Chase New york 103.00 USD (credit)
- 2016_05_10, Expenses, $92.41, NYC Taxi 70.01 USD (credit)
- 2016_05_11, Expenses, $20.20, Wine Therapy NY 15.23 USD (credit)
- 2016_05_12, Expenses, $64.93, Bacaro Restaurant NY 49.19 USD (credit)
- 2016_05_12, Expenses, $14.24, Bouchon Bakery NY 10.72 USD (credit)
- 2016_05_13, Expenses, $23.08, IT'SUGAR Central Park NY 17.38 USD (credit)
- 2016_05_13, Expenses, $137.12, Valley National NY 103.25 USD (credit)
- 2016_05_13, Expenses, $148.41, Cafeteria NY 111.75 USD (credit)
- 2016_05_13, Expenses, $66.52, The Smith Lincoln Centre NY 50.09 USD (credit)
- 2016_05_15, Expenses, $72.48, Socarrat Nolita NY 54.64 USD (credit)
- 2016_05_16, Expenses, $28.89, J Crew NY 21.78 USD (credit)
- 2016_05_17, Expenses, $169.63, Anthom NY 127.38 USD (credit)
- 2016_05_18, Expenses, $41.10, Teich NY 30.49 USD (credit)
- 2016_05_19, Expenses, $18.35, Dean&Deluca NY 13.61 USD (credit)
- 2016_05_19, Expenses, $13.91, McDonald's NY 10.32 USD (credit)
- 2016_05_19, Expenses, $29.37, HBookseller NY 21.78 USD (credit)
- 2016_05_19, Expenses, $8.78, Balducci NY 6.51 USD (credit)
- 2016_05_27, Expenses, $19.63, Skype subscription (credit)
- 2016_05_28, Expenses, $176.96, Fido additional contract (credit)

- 2016_06_01, Expenses, $355.00, AirBNB (credit)
- 2016_06_02, Expenses, $46.44, Expedia (credit)
- 2016_06_02, Expenses, $774.01, Air Canada (credit)
- 2016_06_06, Expenses, $292.90, R J McCarthy-Burnaby (credit)
- 2016_06_07, Expenses, $145.10, EB2016 AZ Awards GAL (credit)
- 2016_06_16, Expenses, $26.25, Air Canada ??? (credit)
- 2016_06_19, Expenses, $26.25, Air Canada ??? (credit)
- 2016_06_19, Expenses, $8.00, YVR Parking (credit paid by Roberto)
- 2016_06_29, Expenses, $669.26, Air Canada (credit)

- 2016_07_01, Expenses, $31.00, RBC Travel Insurance (credit)
- 2016_07_04, Expenses, $132.73, Fido Additional contract (credit)
- 2016_07_10, Expenses, $26.25, Air Canada (credit)
- 2016_07_11, Expenses, $75.35, Yellow Card Services SF 55.95 USD (credit)
- 2016_07_11, Expenses, $48.05, Falletti Foods SF 35.68 USD (credit)
- 2016_07_12, Expenses, $53.35, Izakaya Sozai SF 39.80 USD (credit)
- 2016_07_13, Expenses, $71.73, Alembic SF 54.01 USD (credit)
- 2016_07_14, Expenses, $25.28, United Airlines TX 19.00 USD (credit)
- 2016_07_14, Expenses, $40.00, Delta Taxi Surrey (credit)
- 2016_07_28, Expenses, $130.01, Fido Additional contract (credit)

- 2016_08_01, Expenses, $149.10, BCAA Insurance (credit by Roberto)
- 2016_08_02, Expenses, $176.68, Hilton Gatwick (credit) ???
- 2016_08_04, Expenses, $210.88, Hagenbeck Hamburg (credit) ???
- 2016_08_06, Expenses, $38.64, Ryanair (credit) ???
- 2016_08_07, Expenses, $30.14, LS Travel retail (credit) ???
- 2016_08_24, Expenses, $1087.70, Bristish Airways (credit)
- 2016_08_25, Expenses, $888.88, Air Canada (credit)
- 2016_08_28, Expenses, $176.96, Fido Additional contract (credit)
- 2016_08_29, Expenses, $31.00, RBC Travel Insurance (credit)
- 2016_08_29, Expenses, $367.45, Hilton Gatwick ??? (credit)
- 2016_08_31, Expenses, $185.00, Arts Umbrella (credit)
- 2016_08_31, Expenses, $210.00, Air Canada (credit)

- 2016_09_02, Expenses, $775.19, Clarkdale Motors ??? (credit)
- 2016_09_09, Expenses, $166.90, www.AddisonLee.com Mini Cab (credit)
- 2016_09_09, Expenses, $243.04, Kitty Fisher's 137.25 GBP (credit)
- 2016_09_10, Expenses, $8.86, Studio Benjamin Loyau 5.00 GBP (credit)
- 2016_09_10, Expenses, $122.36, V&A Museum 69.10 GBP (credit)
- 2016_09_11, Expenses, $30.06, Waterstones 16.98 GBP (credit)
- 2016_09_11, Expenses, $15.36, Itsu 8.68 GBP (credit)
- 2016_09_11, Expenses, $17.71, LUL ticket machine 10.00 GBP (credit)
- 2016_09_21, Expenses, $625.74, BCAA Insurance (paid by Roberto) ???
- 2016_09_21, BC Hydro, $58.12, bi-monthly bill???
+ 2016_09_21, Fuse FX. $3149.28, Payslip.
- 2016_09_26, Expenses, $967.47, Air Canada (credit)
- 2016_09_27, Appraisal Fee, $147.00, ???
- 2016_09_28, Expenses, $217.43, Fido mobile additional contract (credit)
- 2016_09_28, VolksWagen, $487.54, Credit???
- 2016_09_28, ICBC, $218.33, car insurance
- 2016_09_29, Expenses, $177.56, Air Canada (credit)
- 2016_09_29, Expenses, $210.00, Air Canada (credit)
- 2016_09_30, House Loan, $780.91, bi-weekly mortgage payment
- 2016_10_03, AA Strata, $267.90, monthly fee
+ 2016_10_05, Alpha Kilo Creative, $8582.63, USD 6633.66
+ 2016_10_06, Fuse FX. $2823.73, Payslip.
- 2016_10_12, Strata Levy, $12682.15, Cheque 0039 - month 02 October
- 2016_10_14, House Loan, $780.91, bi-weekly mortgage payment
+ 2016_10_20, Fuse FX. $2657.04, Payslip.


- 2017_01_19, Expenses, $16.87, Skype Subscription (credit)
- 2017_01_21, Arts, $555.00, Arts umbrella Miranda (credit)
- 2017_01_21, Arts, $335.00, Arts umbrella Miranda (credit)
- 2017_01_29, Expenses, $81.76, Fido Additional contract (credit)
- 2017_01_30, ICBC, $228.06, car insurance
- 2017_01_31, BC Hyddro, $525.49, January bill

- 2017_02_01, AA Strata, $267.90, monthly fee
+ 2017_02_03, Double Negative, $2677.72, payslip
+ 2017_02_03, Alpha Kilo Creative, $6924.44, USD 5422
- 2017_02_03, House Loan, $780.91, bi-weekly mortgage payment
- 2017_02_08, Home Expenses, $153.78, Vancouver Glass (credit)
- 2017_02_08, Home Expenses, $204.96, Vaglio fireplace glass (credit)
+ 2017_02_17, Double Negative, $2639.01, payslip
- 2017_02_17, House Loan, $780.91, bi-weekly mortgage payment
- 2017_02_20, VolksWagen, $474.62, Credit???
- 2017_02_28, Expenses, $81.76, Fido Additional contract (credit)
- 2017_02_28, ICBC, $228.06, car insurance

- 2017_03_01, AA Strata, $267.90, monthly fee
+ 2017_03_03, Double Negative, $2561.61, payslip
+ 2017_03_03, Alpha Kilo Creative, $7122.77, USD 5422.33
- 2017_03_03, House Loan, $780.91, bi-weekly mortgage payment
- 2017_03_06, Fitness, $17.60, the Hive Bouldering Gym for Miranda
- 2017_03_08, Expenses, $970.03, Bristish Airways 574.80 GBP (credit)
- 2017_03_13, Strata Levy, $12682.15, Cheque 0085 - month 07 March
+ 2017_03_17, Double Negative, $2614.88, payslip
- 2017_03_17, House Loan, $780.91, bi-weekly mortgage payment
+ 2017_03_20, Pablo, $2745.14, PABLO???
- 2017_03_20, VolksWagen, $474.62, Credit???

- 2017_04_08, Expenses, $1204.36, Air Canada (credit)

#-----------------------------------------------------------------------
:: procedures

:: given an ortho camera position and a world point, find the minimun distance to the camera ray and the minimum distance to the normal to the camera ray. Everything done in 2d.
:: 

#-----------------------------------------------------------------------
# this version of finding the distance between a point and camera normal
# has been converted to a procedure,
from PIL import Image, ImageDraw, ImageFont
import random
import time
import math

random.seed(time.time())
imgSize = 128
#imgSize = 512
base = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
txt = Image.new('RGBA', (imgSize,imgSize), (0,0,0,0))#base.size
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

def raytrace_distance(lines, point, i, l):
	A = point[0] - lines[0][0]
	B = point[1] - lines[0][1]
	C = lines[1][0] - lines[0][0]
	D = lines[1][1] - lines[0][1]
	distance = abs(A*D - C*B) / math.sqrt(C*C + D*D)
	C = lines[2][0] - lines[0][0]
	D = lines[2][1] - lines[0][1]
	distance2 = abs(A*D - C*B) / math.sqrt(C*C + D*D)
	return (distance, distance2)

no = 0
for i in range(150):
	random.seed(time.time())
	txt = base
	d = ImageDraw.Draw(txt)
	lines = []
	lines.append([
		(random.random()*2-1)*50.0+64.0,
		(random.random()*2-1)*50.0+64.0])
	lines.append([
		(random.random()*2-1)*50.0+64.0,
		(random.random()*2-1)*50.0+64.0]);

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
			#x1 = point[0]
			#y1 = point[1]
			#m = (lines[1][1] - lines[0][1]) / (lines[1][0] - lines[0][0])
			#q = lines[1][0] - (lines[1][1] * m)
			#y = m*x + q # ray equation
			A = point[0] - lines[0][0]
			B = point[1] - lines[0][1]
			C = lines[1][0] - lines[0][0]
			D = lines[1][1] - lines[0][1]
			distance = abs(A*D - C*B) / math.sqrt(C*C + D*D)
			C = lines[2][0] - lines[0][0]
			D = lines[2][1] - lines[0][1]
			distance2 = abs(A*D - C*B) / math.sqrt(C*C + D*D)

			pair = raytrace_distance(lines, point, i, l)
			distance = pair[0]
			distance2 = pair[1]

			if d3 < distance**2:
				g += 75
			if d3 < distance2**2:
				r += 75
			#print "The distance is: ", distance
			#print "The distance2 is: ", distance2
			newColor = (r, g, b)
			d.point( (l,i), fill = newColor )

	txt = txt.resize((512,512))
	d = ImageDraw.Draw(txt)
	#fnt = ImageFont.truetype('LiberationMono.ttf', 40)
	#text = str(round(lines[0][0],2)) + " " + str(round(lines[1][0],2)) + " " + str(round(point[0],2))
	text = str(lines[0])
	d.text( (10,10),  text )
	text = str(lines[1])
	d.text( (10,20),  text )
	text = str(point)
	d.text( (10,30),  text )
	#txt.show()
	no += 1
	filename = "img." + str(no) + ".png"
	txt.save(filename, "PNG")
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
