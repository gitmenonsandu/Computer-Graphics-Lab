#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void drawHouseWorld(int x, int y)
{
	int house[] = {x,y,x+100,y,x+100,y+100,x,y+100,x,y};
	int door[] = {x+25,y+100,x+75,y+100,x+75,y+50,x+25,y+50,x+25,y+100};
	int roof[] = {x,y,x+100,y,x+50,y-50,x,y};
	int window[] = {x+60,y+10,x+80,y+10,x+80,y+30,x+60,y+30,x+60,y+10};

	drawpoly(5,house);
	drawpoly(5,door);
	drawpoly(4,roof);
	drawpoly(5,window);
}

void drawHouseView(int x, int y, int xwmin, int ywmin, int xwmax, int ywmax, int xvmin, int yvmin, int xvmax, int yvmax)
{
	float sx = (float)(xvmax-xvmin)/(xwmax-xwmin);
	float sy = (float)(yvmax-yvmin)/(ywmax-ywmin);

	int house[] = {xvmin+sx*x,yvmin+sy*y,xvmin+sx*(x+100),yvmin+sy*y,xvmin+sx*(x+100),yvmin+sy*(y+100),xvmin+sx*x,yvmin+sy*(y+100),xvmin+sx*x,yvmin+sy*y};
	int roof[] = {xvmin+sx*x,yvmin+sy*y,xvmin+sx*(x+100),yvmin+sy*y,xvmin+sx*(x+50),yvmin+sy*(y-50),xvmin+sx*x,yvmin+sy*y};
	int door[] = {xvmin+sx*(x+25),yvmin+sy*(y+100),xvmin+sx*(x+75),yvmin+sy*(y+100),xvmin+sx*(x+75),yvmin+sy*(y+50),xvmin+sx*(x+25),yvmin+sy*(y+50),xvmin+sx*(x+25),yvmin+sy*(y+100)};
	int window[] = {xvmin+sx*(x+60),yvmin+sy*(y+10),xvmin+sx*(x+80),yvmin+sy*(y+10),xvmin+sx*(x+80),yvmin+sy*(y+30),xvmin+sx*(x+60),yvmin+sy*(y+30),xvmin+sx*(x+60),yvmin+sy*(y+10)};

	drawpoly(5,house);
	drawpoly(5,door);
	drawpoly(4,roof);
	drawpoly(5,window);
}

int main()
{
	int gd=DETECT,gm,x=250,y=250;

	int xwmin,ywmin,xwmax,ywmax;
	int xvmin,yvmin,xvmax,yvmax;
	printf("Enter top-left and bottom-right of world co-ordinate system\n");
	scanf("%d%d%d%d",&xwmin,&ywmin,&xwmax,&ywmax);	

	printf("Enter top-left and bottom-right of view co-ordinate system\n");
	scanf("%d%d%d%d",&xvmin,&yvmin,&xvmax,&yvmax);	

	initgraph(&gd, &gm, NULL);
	
	setcolor(RED);
	rectangle(xwmin,ywmin,xwmax,ywmax);
	drawHouseWorld(x,y);

	delay(3000);
	cleardevice();

    setcolor(YELLOW);
	rectangle(xvmin,yvmin,xvmax,yvmax);
	drawHouseView(x-xwmin,y-ywmin,xwmin,ywmin,xwmax,ywmax,xvmin,yvmin,xvmax,yvmax);

	delay(3000);
	cleardevice();

	closegraph();
	return 0;
}