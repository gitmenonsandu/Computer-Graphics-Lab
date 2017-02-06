#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include "house.c"
int maxx,maxy,midx,midy;
void axis()
{
	getch();
	cleardevice();
	line(midx,0,midx,maxy);
	line(0,midy,maxx,midy);
}
void main()
{
	int x,y,z,o,x1,x2,y1,y2;
	int gd=DETECT,gm;
	int ch;
	scanf(" %d",&ch);
	initgraph(&gd,&gm," ");
	drawHouse();
	if(ch==1)
		reflect();
	
	else if(ch==2)
		sheerX(2);
	else if(ch==2)
		sheerY(2);
	getch();
	closegraph();
}