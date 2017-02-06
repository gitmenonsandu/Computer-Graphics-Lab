#include <graphics.h>
#include <math.h>
#include "bresenham.c"
//front
//door
//window
//lines on window
//roof
//chimney
void initHouse(int h[][2])
{
	int val[][2]={
	{400,100},{500,200},
	{425,150},{475,200},
	{475,120},{495,140},
	{485,120},{485,140},
	{475,130},{495,130},
	{400,100},{450,50},{500,100},
	{490,80},{500,100}
	};
	int i;
	for(i=0;i<15;++i)
	{
		h[i][0]=val[i][0];
		h[i][1]=val[i][1];
	}
}
void reflectHouse(int h[][2],int m,int c)
{
	int i,j;

	float angle=atan(m);
	angle*=(2*M_PI)/180.0;

	float hx=-c*sin(angle);
	float hy=c*(cos(angle)+1);

	int tx,ty;
	for(i=0;i<15;++i)
	{
		tx=h[i][0];
		ty=h[i][1];
		h[i][0]=tx*cos(angle)+ty*sin(angle)+hx;
		h[i][1]=tx*sin(angle)-ty*cos(angle)+hy;
	}	
}

void basicReflectX(int h[][2],int x)
{
	int i,j;
	for(i=0;i<15;++i)
	{
		h[i][0]=h[i][0]-2*(h[i][0]-x);
	}
}
void basicReflectY(int h[][2],int y)
{
	int i,j;
	for(i=0;i<15;++i)
	{
		h[i][1]=h[i][1]-2*(h[i][1]-y);
	}
}
void drawHouse(int h[][2])
{

	drawRectangle(h[0][0],h[0][1],h[1][0],h[1][1]);
	drawRectangle(h[2][0],h[2][1],h[3][0],h[3][1]);
	drawRectangle(h[4][0],h[4][1],h[5][0],h[5][1]);
	drawLine(h[6][0],h[6][1],h[7][0],h[7][1]);
	drawLine(h[8][0],h[8][1],h[9][0],h[9][1]);
	
	drawLine(h[10][0],h[10][1],h[11][0],h[11][1]);
	drawLine(h[11][0],h[11][1],h[12][0],h[12][1]);
	
	drawRectangle(h[13][0],h[13][1],h[14][0],h[14][1]);
	
}

void shearHouseX(int h[][2],float sh)
{
	int i;
	for(i=0;i<15;++i)
	{
		if(h)
		h[i][0]=(h[i][1]-500)*sh+h[i][0];
	}
}


void shearHouseY(int h[][2],float sh)
{
	int i;
	for(i=0;i<15;++i)
	{
		h[i][1]=(h[i][0]-200)*sh+h[i][1];
	}
}