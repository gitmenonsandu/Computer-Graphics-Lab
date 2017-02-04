#include <graphics.h>
#include <stdio.h>
#include "dda.c"
#include "polarCircle.c"

#define PI 3.14

void drawRectangle(int x1,int y1,int x2,int y2,int color)
{
	int i=y1;
	for(i=y1;i<=y2;++i)
		drawLine(x1,i,x2,i,color);
}
void main()
{
	int i,gd=DETECT,gm=0;

    initgraph(&gd,&gm," ");
	drawRectangle(100,100,550,200,12);
	drawRectangle(100,200,550,300,15);
	drawRectangle(100,300,550,400,2);

	drawCircle(325,250,50,1);

	float ang=0;
	float x1,y1;
	for(ang=0;ang<=2*PI;ang+=(PI/12))
	{

		x1=325+50*cos(ang);
		y1=250+50*sin(ang);
		drawLine(325,250,x1,y1,1);
	}
	getch();
	closegraph(); 
}