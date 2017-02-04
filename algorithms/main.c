#include <graphics.h>
#include <math.h>
#include "bresenham.c"
#include "midpoint.c"

#define pi 3.14

int main()
{
	int i,gd=DETECT,gm=0;

    initgraph(&gd,&gm," ");
    int ch;
    //scanf(" %d",&ch);
    ch=0;
    if(ch==2)
    {
        drawCircleMidPoint(100,100,100);
	    drawCircleMidPoint(100,100,50);
        
        drawLine(100,50,100,0);
        drawLine(100,150,100,200);
        drawLine(50,100,0,100);
        drawLine(150,100,200,100);

        drawCircleMidPoint(500,100,50);
    	drawCircleMidPoint(500,100,25);
        
        drawLine(500,75,500,50);
        drawLine(500,125,500,150);
        drawLine(475,100,450,100);
        drawLine(525,100,550,100);

        drawLine(500,50,100,0);
        drawLine(500,150,100,200);
    }
    else if(ch==3)
    {
        drawCircleMidPoint(200,200,100);
        drawRectangle(100,100,300,300);

        drawLine(100,100,300,300);
        drawLine(100,200,300,200);
        drawLine(100,300,300,100);
        drawLine(200,100,200,300);
    }
    else if(ch==4)
    {
        
    }


    //drawLine(100,100,120,200);
    //drawLine(100,100,200,80);
    //drawLine(100,100,120,200);
    getch();
	closegraph(); 
}