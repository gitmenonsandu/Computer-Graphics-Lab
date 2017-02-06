#include <graphics.h>
#include <math.h>
#include "house.c"




int main()
{
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm," ");
	int h[15][2];
	initHouse(h);
	drawHouse(h);

	basicReflectX(h,300);
	drawHouse(h);
	basicReflectY(h,250);
	drawHouse(h);
	initHouse(h);
	basicReflectY(h,250);
	drawHouse(h);

	initHouse(h);
	//float sh=(M_PI)*30/180;
	//shearHouseX(h,sh);
	//drawHouse(h);
	getch();
	closegraph();
	return 0;
}