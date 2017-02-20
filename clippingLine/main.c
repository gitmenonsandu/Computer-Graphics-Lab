#include <stdio.h>
#include <graphics.h>
#include "lineclipping.c"

void main()
{
	int x,y,z,o,x1,x2,y1,y2;
	int gd=DETECT,gm;
	int ch;
	float sf;
	//scanf(" %d",&ch);
	ch=2;
	int xmax,ymax,xmin,ymin;
	xmax=170;
	ymax=170;
	xmin=150;
	ymin=150;
	initgraph(&gd,&gm," ");
	if(ch==1)
	{
		
		//line(100,100,200,200);
		drawLine(100,100,200,200);
		drawRectangle(xmax,ymax,xmin,ymin);
		getch();
		cleardevice();
		CohenSutherClip(100,100,200,200,xmax,ymax,xmin,ymin);
	}
	else if(ch==2)
	{
		drawLine(100,100,200,200);
		drawRectangle(xmax,ymax,xmin,ymin);
		getch();
		cleardevice();
		LiangBaskyClip(100,100,200,200,xmax,ymax,xmin,ymin);
		
	}
	getch();
	closegraph();
}