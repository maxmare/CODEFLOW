#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef int32 bool32;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float real32;
typedef double real64;
typedef float f;

real32 R(){return(real32)rand() / RAND_MAX;}

int32 Ri(){return (int32)( (real32)rand() / RAND_MAX * 100 );}

int32 Rc(){return (int32)( (real32)rand() / RAND_MAX * 255 );}// for 8-bit per channel colors

// TODO: decide if we are replacing math.pow!
// define a vector class with constructor and operator: 'v'
struct vec3{
	f x,y,z;  // Vector has three float attributes.
	vec3 operator+(vec3 r){return vec3(x+r.x,y+r.y,z+r.z);} // vector add
	vec3 operator+(f r){return vec3(x+r,y+r,z+r);} // float add
	vec3 operator-(vec3 r){return vec3(x-r.x,y-r.y,z-r.z);} // vector subtract
	vec3 operator-(f r){return vec3(x-r,y-r,z-r);} // float subtract
	vec3 operator*(vec3 r){return vec3(x*r.x,y*r.y,z*r.z);} // vector scaling
	vec3 operator*(f r){return vec3(x*r,y*r,z*r);} // float scaling
	f operator%(vec3 r){return x*r.x+y*r.y+z*r.z;} // dot product
	vec3 operator/(vec3 r){
		if ((r.x!=0)&&(r.y!=0)&&(r.z!=0)){
			return vec3(x/r.x,y/r.y,z/r.z);
			}
		else return vec3(0,0,0);
	} //Division
	f distance(vec3 r){return pow((((x-r.x)*(x-r.x))+((y-r.y)*(y-r.y))+((z-r.z)*(z-r.z))), 0.5); }
	vec3(){}// empty constructor
	vec3 operator^(vec3 r){return vec3(y*r.z-z*r.y,z*r.x-x*r.z,x*r.y-y*r.x); }// cross-product
	vec3(f a,f b,f c){ x=a;y=b;z=c; } //constructor
	vec3 operator!(){ return *this*(1 /sqrt(*this%*this)); }// normalizing the vector
	f& operator[](int i){
		assert(i>=0); assert(i<=2);
		f* p = &x ;// get first memeber address
		p+=i;// shift it
		return *p;
	}
};
typedef vec3 v;

int main()
{

// unique id, door rule matrix,
// do not change the order or the use matrix will be affected,
uint8 exterior_name =	0;
uint8 stair_down_name =	1;
uint8 stair_name =	2;
uint8 stair_up_name =	3;
uint8 living_name =	4;
uint8 kitchen_name =	5;
uint8 pantry_name =	6;
uint8 bathroom1_name =	7;
uint8 bathroom2_name =	8;
uint8 bathroom3_name =	9;

uint8 bathroom4_name =	10;
uint8 bathroom5_name =	11;
uint8 entrance_name =	12;
uint8 garage_name =	13;
uint8 den1_name =	14;
uint8 den2_name =	15;
uint8 bedroom1_name =	16;
uint8 bedroom2_name =	17;
uint8 bedroom3_name =	18;
uint8 bedroom4_name =	19;

uint8 bedroom5_name =	20;
uint8 bedroom6_name =	21;
uint8 corridor1_name =	22;
uint8 corridor2_name =	23;
uint8 corridor3_name =	24;
uint8 corridor4_name =	25;
uint8 undefined_name =	100;

// doors can be connected according to the following matrix,
	// pantry can only be connected to a kitchen
	// bathroom can not be connected to a kitchen,
	// bathrooms can only have one door
	// kitchens can tear a hole on a wall if connecting to a corridor or the living room,
	// only the entrance, kitchen or the living can connect to the outside,
uint8 doorRule[30][30] = {
	{ 0,1,1,1,1,1,0,0,0,0, 0,0,0,1,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, // exterior
	{ 1,0,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,0,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1 }, 
	{ 1,1,1,1,0,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,0,0 }, 
	{ 1,1,1,1,1,0,1,0,0,0, 0,0,1,1,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, // kitchen
	{ 0,1,1,1,1,1,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, // pantry
	{ 0,1,1,1,1,0,0,0,0,0, 0,0,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,1,0,0,0,0,0, 0,0,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,1,0,0,0,0,0, 0,0,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,0,0 }, 

	{ 0,1,1,1,1,0,0,0,0,0, 0,0,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,1,0,0,0,0,0, 0,0,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,0,0 }, 
	{ 1,1,1,1,1,1,1,0,0,0, 0,0,0,1,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, 
	{ 1,1,1,1,1,0,0,1,1,1, 1,1,1,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,0,0, 0,0,1,1,1,1,0,0,0,0 }, 
	{ 0,1,1,1,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },// bedroom 

	{ 0,1,1,1,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,0,0, 0,0,0,0,0,1,0,0,0,0 }, 
	{ 0,1,1,1,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,0,0, 0,0,0,0,0,1,0,0,0,0 }, 
	{ 1,1,1,1,1,1,1,1,1,1, 1,1,0,1,1,1,1,1,1,0, 0,0,0,0,0,1,0,0,0,0 }, 
	{ 1,1,1,1,1,1,1,1,1,1, 1,1,0,1,1,1,1,1,1,0, 0,0,0,0,0,1,0,0,0,0 }, 
	{ 1,1,1,1,1,1,1,1,1,1, 1,1,0,1,1,1,1,1,1,0, 0,0,0,0,0,1,0,0,0,0 },// bedroom 
	{ 1,1,1,1,1,1,1,1,1,1, 1,1,0,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,0,0 },// corridor
	{ 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, 
	{ 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 }, 
	{ 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 },// corridor 
	{ 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0 } 
};

// ideal / projected sizes for different room types,
uint8 roomListSize[200];
roomListSize[stair_down_name] = 25;
roomListSize[stair_name] = 25;
roomListSize[stair_up_name] = 25;

roomListSize[living_name] = 50;
roomListSize[kitchen_name] = 35;
roomListSize[pantry_name] = 10;
roomListSize[entrance_name] = 15;
roomListSize[garage_name] = 30;

roomListSize[bathroom1_name] = 20;
roomListSize[bathroom2_name] = 25;
roomListSize[bathroom3_name] = 15;
roomListSize[bathroom4_name] = 15;
roomListSize[bathroom5_name] = 15;

roomListSize[den1_name] = 15;
roomListSize[den2_name] = 20;

roomListSize[bedroom1_name] = 35;
roomListSize[bedroom2_name] = 30;
roomListSize[bedroom3_name] = 25;
roomListSize[bedroom4_name] = 25;
roomListSize[bedroom5_name] = 25;
roomListSize[bedroom6_name] = 15;

roomListSize[corridor1_name] = 15;
roomListSize[corridor2_name] = 15;
roomListSize[corridor3_name] = 15;
roomListSize[corridor4_name] = 15;
// typical entrance level layout could be,
	// entrance, living, kitchen, bathroom, stair, pantry, corridor (7 rooms)
	// area: 155
	// factor: 400 / 155 = *2.58
// typical basement level layout could be,
	// stair_down, bathroom, bedroom1, bedroom2, den1 (5 rooms)
	// area: 120
	// factor: 400 / 120 = *3.33
// typical basement level layout could be,
	// stair_up, bathroom, bedroom1, bedroom2, den1 (5 rooms)
	// area: 120
	// factor: 400 / 120 = *3.33

uint8 imgSize = 64;
vec3 newColor = {20, 0, 0};
vec3 emptyColor = {150, 25, 75};

uint8 roomListUse[4][200];// [ room id, use id, ... ]// sorted by room id,
vec3 colorList[200];

for(int i=0; i<200; ++i){// store a list of random colors,
	colorList[i] = vec3( Rc(), Rc(), Rc() );
}

// specific persistent colors based on room use,
colorList[exterior_name] = vec3( 30, 30, 30);
colorList[living_name] = vec3( 220, 170, 60);
colorList[kitchen_name] = vec3( 50, 220, 50);
colorList[pantry_name] = vec3( 180, 240, 120);
colorList[bathroom1_name] = vec3( 230, 240, 40);
colorList[bathroom2_name] = vec3( 230, 240, 40);
colorList[bathroom3_name] = vec3( 230, 240, 40);
colorList[bathroom4_name] = vec3( 230, 240, 40);
colorList[bathroom5_name] = vec3( 230, 240, 40);
colorList[stair_down_name] = vec3( 255, 0, 0);
colorList[stair_up_name] = vec3( 255, 0, 0);
colorList[stair_name] = vec3( 255, 0, 0);
colorList[entrance_name] = vec3( 100, 100, 100);
colorList[garage_name] = vec3( 150, 150, 150);
colorList[den1_name] = vec3( 60, 220, 150);
colorList[den2_name] = vec3( 60, 220, 150);
colorList[bedroom1_name] = vec3( 50, 50, 200);
colorList[bedroom2_name] = vec3( 50, 50, 200);
colorList[bedroom3_name] = vec3( 50, 50, 200);
colorList[bedroom4_name] = vec3( 50, 50, 200);
colorList[bedroom5_name] = vec3( 50, 50, 200);
colorList[bedroom6_name] = vec3( 50, 50, 200);
colorList[undefined_name] = vec3( 255, 200, 25);
colorList[corridor1_name] = vec3( 15, 200, 25);
colorList[corridor2_name] = vec3( 15, 200, 25);
colorList[corridor3_name] = vec3( 15, 200, 25);
colorList[corridor4_name] = vec3( 15, 200, 25);
//print colorList

bool32 minimumHabitability = false;
//while not minimumHabitability:

// check for conditions when we layout every level, 
// eg. the lower level needs a kitchen and a living room,
// eg. the ground level needs a bathroom, the upper level too.

// we decide on a number of levels,
// this is meant for uni-familiar dwellings or attached townhouse complexes,
// not for apartment / condo buildings. For game leviathan they are not visually interesting,

uint8 levelCount = ((uint8)(R()*2.99f) )+1;
uint8 entranceLevel = 0;// lowest level,
if(levelCount > 1){
	// as we get to three levels most likely the entrance is raised,
	if( (R() + (real32)levelCount / 4.0f ) > 1.20f){
		entranceLevel += 1;// we have a basement below
	}
}
// units are equal to 20cm (the minimum distance in a house element is 10cm so to create partition walls and add doors to them, or to create steps on stairs we will scale everything by 2 so our unit will then be 10cm,
uint8 facade_length = 20 + uint8( R()*2.99 );

printf("levelCount: %i, entranceLevel: %i, facade_length: %i\n", levelCount, entranceLevel, facade_length);

// specific rules regarding detached house design,
// name,ed
// unique id,
// needed room for habitability,
  // 0 - not necesary
  // 1 - necesary
  // 2 - depend on vertical layout
// level it can be placed
  // -n - can be placed -n levels below entrance
  // 0  - needs 1 at every level
  // 1  - entrance level only
  // n  - can be placed at any level below n (including entrance and below)
uint8 id = 0;
uint8 must_exist = 1;
uint8 level_to_be_placed = 2;
uint8 marked = 3;
uint8 roomUse[50][4] = {
	{0, 0, 1, 0},// exterior
	{1, 2, 0, 0},// stair_down
	{2, 1, 1, 0},// living
	{3, 1, 1, 0},// kitchen
	{4, 0, 1, 0},// pantry
	{5, 1, 0, 0},// bathroom1
	{6, 1, 2, 0},// bathroom2
	{7, 0, 2, 0},// bathroom3
	{8, 0, 2, 0},// bathroom4
	{9, 0, 2, 0},// bathroom5
	{10, 0, 1, 0},// entrance
	{11, 0, 0, 0},// garage
	{12, 0, 2, 0},// den1
	{13, 0, 2, 0},// den2
	{14, 1, 2, 0},// bedroom1
	{15, 0, 2, 0},// bedroom2
	{16, 0, 2, 0},// bedroom3
	{17, 0, 2, 0},// bedroom4
	{18, 0, 2, 0},// bedroom5
	{19, 0, 2, 0},// bedroom6
	{20, 2, 2, 0},// stair_up
	{21, 2, 1, 0},// stair
	{100, 0, 0, 0}// undefined
};
uint8 roomCount = 23;
uint8 basementHasStair = 0;

// use entranceLevel in this logic to account for a possible basement,
for( uint8 i=0; i<roomCount; ++i){
	if( roomUse[i][must_exist] == 0){
		if( R()*10 < 1.0f ){
			roomUse[i][marked] = 1;
		}
	}
	if( roomUse[i][must_exist] == 1){
		if( roomUse[i][level_to_be_placed] > 1){
			if( levelCount > 1 ){
				roomUse[i][marked] = 1;
			}
		}
		else{
			roomUse[i][marked] = 1;
		}
	}
	if( roomUse[i][must_exist] == 2){// stairs<_________________
		if( levelCount > 1 ){
			if( roomUse[i][level_to_be_placed] < 1 ){
				if( entranceLevel > 0 ){
					if( R()*10 < 3.0f ){// maybe the basement has its own entrance from the outside
						roomUse[i][marked] = 1;
						basementHasStair = 1;
					}
				}
			}
			if( roomUse[i][level_to_be_placed] == 1 ){
				if( basementHasStair == 1 ){
					roomUse[i][marked] = 1;
				}
				if(( levelCount > 1 )&&( entranceLevel == 0 )){
					roomUse[i][marked] = 1;
				}
				if( levelCount > 2 ){
					roomUse[i][marked] = 1;
				}
			}
			if( roomUse[i][level_to_be_placed] > 1){
				if(( levelCount == 2 )&&( entranceLevel == 0 )){
					roomUse[i][marked] = 1;
				}
				if(( levelCount == 3 )&&( entranceLevel == 1 )){
					roomUse[i][marked] = 1;
				}
			}
		}
	}
}
uint32 areaLevel[3] = {0, 0, 0};

for( uint8 i=0; i<roomCount; ++i){
	if( roomUse[i][marked] == 1 ){
		if( roomUse[i][level_to_be_placed] < 1 ){// basement
			if( entranceLevel > 0 ){
				areaLevel[0] += roomListSize[roomUse[i][id]];
				roomUse[i][marked] = -1;
			}
		}
		if( roomUse[i][level_to_be_placed] == 1 ){// entrance level
			areaLevel[entranceLevel] += roomListSize[roomUse[i][id]];
			roomUse[i][marked] = 1;
		}
		if( roomUse[i][level_to_be_placed] > 1 ){// upper levels
			if( entranceLevel == 0 and levelCount > 2 ){
				areaLevel[2] += roomListSize[roomUse[i][id]];
				roomUse[i][marked] = 2;
			}
			if( entranceLevel == 0 and levelCount < 2 ){
				areaLevel[1] += roomListSize[roomUse[i][id]];
				roomUse[i][marked] = 2;
			}
			if( entranceLevel == 1 and levelCount > 2 ){
				areaLevel[2] += roomListSize[roomUse[i][id]];
				roomUse[i][marked] = 2;
			}
		}
	}
}
//print "roomUse: ", pprint.pprint(roomUse)
//print "arealevel: ", areaLevel

real32 level_aspect_ratio = 10;
uint8 level_length = 0;
uint8 level_width = 0;
// creating a random floor plan based on an facade length and a total footprint area,
uint8 bldgRatio = 1;
uint32 footprint_area = facade_length * facade_length * bldgRatio;
while( level_aspect_ratio > 2 ){// don't want slender floor plans,
	level_width = (uint8)( R() * facade_length )+1;
	level_length = int(footprint_area / level_width);
	level_aspect_ratio = float(level_width) / float(level_length);
	if( level_aspect_ratio < 1 ){
		level_aspect_ratio = 1 / level_aspect_ratio;
	}
}
printf("house width and length: %i, %i\n", level_width, level_length); 

// allow for 5 levels, 50 rooms, each has 2 x XY coordinates,
uint8 roomList[5][10][4] = {
	{
		{ 0, 0, level_width, level_length }
	},// entrance level,
	{
		{ 0, 0, level_width, level_length }
	}// upper level,
};
uint8 roomListCount[5] = { 1, 1, 0, 0, 0 };// counts for all 5 levels,
uint32 index = 0;
// we need a minimun of rooms to create based on planned family size,


    printf("Hello World");

    return 0;
}
