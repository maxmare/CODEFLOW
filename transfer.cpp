enum edgeLayout{
	top,
	bottom,
	left,
	right
};

struct panelPositionNorm{
	uint8 index;
	real32 left;
	real32 bottom;
	real32 right;
	real32 top;
};

struct panelPositionPixel{
	int8 index;
	uint16 left;
	uint16 bottom;
	uint16 right;
	uint16 top;
};

struct panelDiv{
	int index;
	real32 percent;//from top or left
	bool divDir;
};

struct screenLayout{
	uint8 count;
	// which edge the profiler view grows from
	enum edgeLayout profilerViewEdgeLaid;
	bool isMaximized;//whether the focused panel is maximized
	bool isGUIFree;
	// we need the max. potential future size of any panel affected by this division,
	int divBeingResized;
	panelDiv div[256];
	panelPositionNorm posN[256];// final panel sizes from 0 to 1(screen size)
	panelPositionPixel posP[256];// final panel sizes in pixels
};
____________________________________________________________________________________________________________________
// NOT IN USE
/*
void bakePanelDivs(screenLayout* scr){
	i c = scr->count;
	// we start with a full screen sized panel,
	panelPosition tmpPos={0};
	tmpPos.right=(int)(1*screenSizeWidth);
	tmpPos.top=(int)(1*screenSizeHeight);
	scr->div[0].pos=tmpPos;

	for (i it=0; it<c; ++it){
		
	}
}
//*/

void createDivPanel(screenLayout* scr, int ind, real32 perc, bool vert){
	int c = scr->count;
	if (c<256){
		scr->div[c].index = ind;
		scr->div[c].divDir = vert;
		scr->div[c].percent = perc;
		scr->count++;
	}
}

void removeDivPanel(screenLayout* scr, i index){
	int it = 0;
	for (; it < (256-1); ++it){
		if (it==index){
//			scr->div[index]=scr->dic[index+1];
		}
		scr->count--;
	}
}

/*
TODO
panelPosition getPanelLayout(screenLayout* scr, i index, f posX, f posY){
	panelPosition pos = {0};
	// when resizing we need the max. potential future size of any panel 
	// affected by the division changing,
	return scr->div[index].pos;
}
*/

// if index is given(not neg), we will ignore the pos,
int getPanelIndex(screenLayout* scr, real32 coordX, real32 coordY){
	int c = 1;
	for(;c<=scr->count;++c){// for each panel
		if ((scr->posP[c].left<=coordX)&&(coordX<( scr->posP[c].left + scr->posP[c].right ) ) ){
			if ((scr->posP[c].bottom<=coordY)&&(coordY<( scr->posP[c].bottom + scr->posP[c].top ) ) ){
				return c;
			}
		}
	}
//	printf("FAIL!!!");
	return 0;
}

void initializeScreenLayout(screenLayout* scr, int resW, int resH){
	int it = 0;
	for (; it<256; ++it){
		scr->posN[it] = {it,0,0,1,1};
		scr->posP[it] = {it,resW,resH,resW,resH};
	}
}
____________________________________________________________________________________________________________________
if(test==9){
	int screenSizeWidth = 512;
	int screenSizeHeight = 512;
	screenLayout layout = {0};
	initializeScreenLayout(&layout, screenSizeWidth, screenSizeHeight);
	///*
	createDivPanel(&layout, 0, 0.0, true);
	createDivPanel(&layout, 0, 0.25, false);
	createDivPanel(&layout, 1, 0.5, false);
	createDivPanel(&layout, 2, 0.15, true);
	createDivPanel(&layout, 3, 0.8, false);
	//*/
	int k = 0;
	bool vert = true;
	bool horiz = false;
	uint8 panelCount = layout.count;
	int32 origPixelSize = screenSizeWidth*screenSizeHeight;

	real32 tmpSize = 0.0f;
	int pn = 0;
	real32 tmp = 0.0f;
	k = 1;
	for(; k < panelCount; ++k){
		if(layout.div[k].percent > 0.1){
			pn = layout.div[k].index + 1;
			if(layout.div[k].divDir == vert){
				tmp = layout.posN[pn].right;
				layout.posN[pn].right *= layout.div[k].percent;
				// creating a new panel,
				layout.posN[k+1].left = 
					layout.posN[pn].left +
					layout.posN[layout.div[k].index+1].right;
				layout.posN[k+1].bottom = layout.posN[pn].bottom;
				layout.posN[k+1].right = tmp - layout.posN[pn].right;
				layout.posN[k+1].top = layout.posN[pn].top;
			}
			if(layout.div[k].divDir == horiz){
				tmp = layout.posN[pn].top;
				layout.posN[pn].top *= layout.div[k].percent;
				// creating a new panel,
				layout.posN[k+1].left = layout.posN[pn].left;
				layout.posN[k+1].bottom = 
					layout.posN[pn].bottom +
					layout.posN[layout.div[k].index+1].top;
				layout.posN[k+1].right = layout.posN[pn].right;
				layout.posN[k+1].top = tmp - layout.posN[pn].top;
			}
		}
	}
	for(k=0; k<=panelCount; ++k){
		layout.posP[k].left *= layout.posN[k].left;
		layout.posP[k].bottom *= layout.posN[k].bottom;
		layout.posP[k].right *= layout.posN[k].right;
		layout.posP[k].top *= layout.posN[k].top;
	}
	int area = 0;
	int tmpArea = 0;
	for(k=1; k<=panelCount; ++k){
		tmpArea = layout.posP[k].right * layout.posP[k].top;
		area += tmpArea;
	}
	
	for(k=1; k<=panelCount; ++k){
		printf("%i %f %d, %i %f %f %f %f, %i %i %i %i %i, ",
			layout.div[k].index, layout.div[k].percent, layout.div[k].divDir,
			layout.posN[k].index,
			layout.posN[k].left, layout.posN[k].bottom,
			layout.posN[k].right, layout.posN[k].top,
			layout.posP[k].index,
			layout.posP[k].left, layout.posP[k].bottom, 
			layout.posP[k].right, layout.posP[k].top
			);
		printf("\n");
	}
	printf("Area: %i, vs full screen: %i\n", area, screenSizeWidth*screenSizeHeight);
	// writing out images
	v p(0,0,0);
	v color[256];
	color[0] = v(255, 0, 255);
	int n = 1;
	printf("1\n");
	for (; n<256; n++){
		color[n] = v( (R()*125)+100, (R()*125)+100, (R()*125)+100 );
	}
	k=0;
	printf("2\n");
	for(int x=0;x<512;x++){// for each column
		for(int y=0;y<512;y++){// for each pixel in a line
//			printf("%i %1\n", x, y);
			p = v(0,0,0);
			p = color[getPanelIndex(&layout, x, y)];
			buf[k+0]=(ui)p.x;
			buf[k+1]=(ui)p.y;
			buf[k+2]=(ui)p.z;
			buf[k+3]=0;
			k += 4;
		}
	}
}
