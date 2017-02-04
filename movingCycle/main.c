#include <graphics.h>
#include "cycle.c"
 int main()
 {
 	int i,gd=DETECT,gm=0;

    initgraph(&gd,&gm," ");

    int bxc=100,byc=300,fxc=250,fyc=300,radius=40;
    double angle=0;
    while(fxc+radius<=630)
    {
    	cleardevice();
    	drawCycle(bxc,byc,fxc,fyc,radius,angle);
    	bxc+=2;
    	fxc+=2;
    	angle+=2;
    	delay(20);
    	//break;
    }
    //cleardevice();
    drawCycle(bxc,byc,fxc,fyc,radius+10,angle);
    getch();
	closegraph(); 
 }