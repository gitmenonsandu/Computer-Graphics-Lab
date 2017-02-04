#include <graphics.h>
#include "polygon.c"
#include <stdio.h>
#include <math.h>
int main()
{
	    int ch,angle;
	 scanf(" %d",&ch);
	     float tx,sx;
	     if(ch==1)
	scanf(" %f %f",&tx,&sx);
else
	scanf(" %d",&angle);
	int i,gd=DETECT,gm=0;
	float x[]={200,300,400,400,200};
	float y[]={200,100,200,300,300};
    initgraph(&gd,&gm," ");

    drawPolygon(x,y,5);




    if(ch==1){

    for(i=0;i<5;++i)
    {
    	x[i]=x[i]+tx;
    }
    drawPolygon(x,y,5);
    for(i=0;i<5;++i)
    {
    	x[i]*=sx;
    	y[i]*=sx;
    }
    drawPolygon(x,y,5);
    getch();
    }
    else if(ch==2){

    drawPolygon(x,y,5);
    int px=300,py=200;
    int r;
    for(i=0;i<5;++i)
    {
    	x[i]=x[i]*cos(M_PI*angle/180)-y[i]*sin(M_PI*angle/180);
    	y[i]=y[i]*cos(M_PI*angle/180)+x[i]*sin(M_PI*angle/180);
    }
    drawPolygon(x,y,5);
    getch();
	}

	closegraph(); 

}