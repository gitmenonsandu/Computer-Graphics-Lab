#include <stdio.h>
#include <graphics.h>
#include "lineclipping.c"
#define PI 3.14
float a[5],b[5];
void drawstar(float x,float y,int l)
{
	int i;
	a[0]=x;b[0]=y;
	a[1]=x+l*cos(PI/3);b[1]=y-l*sin(PI/3);
	a[4]=x+1.25*l*cos(PI/6);b[4]=y-1.25*l*sin(PI/6);
	a[2]=a[1]+l*cos(PI/3);b[2]=b[1]+l*sin(PI/3);
	a[3]=a[2]-1.25*l*cos(PI/6);b[3]=b[2]-1.25*l*sin(PI/6);

	for(i=0;i<4;i++)
		line(a[i],b[i],a[i+1],b[i+1]);
	line(a[i],b[i],a[0],b[0]);
}

void main()
{
	int x,y,z,o,x1,x2,y1,y2;
	int gd=DETECT,gm;
	int ch,i;
	float sf;
	//scanf(" %d",&ch);
	ch=2;
	int xmax,ymax,xmin,ymin;
	xmax=175;
	ymax=175;
	xmin=100;
	ymin=100;
	initgraph(&gd,&gm," ");

	//polygon clipping for a star
	if(ch==1)
	{
		
		//line(100,100,200,200);
		drawstar(100,200,100);
		drawRectangle(xmax,ymax,xmin,ymin);
		getch();
		cleardevice();
		i=0;
		//printf("%f %f %f %f\n",a[i],b[i],a[(i+1)%5],b[(i+1)%5]);
		for(i=0;i<5;++i)
			CohenSutherClip(a[i],b[i],a[(i+1)%5],b[(i+1)%5],xmax,ymax,xmin,ymin);
		
		drawRectangle(xmin,ymin,xmax,ymax);
		
	}

	//character clipping
	else if(ch==2)
	{
		drawRectangle(xmin,ymin,xmax,ymax);
		
		line(150,50,150,200);
		getch();
		cleardevice();
		CohenSutherClip(150,50,150,200,xmax,ymax,xmin,ymin);
		drawRectangle(xmin,ymin,xmax,ymax);
	
	}
	getch();
	closegraph();
}