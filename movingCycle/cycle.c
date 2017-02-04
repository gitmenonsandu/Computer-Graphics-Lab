#include <graphics.h>
#include <math.h>
#include "midpoint.c"

void drawCycle(int bxc,int byc,int fxc,int fyc,int radius,double angle)
{
	int i,x,y;
	double theta;
	//two wheels and back rim
	drawCircleMidPoint(bxc,byc,radius);
	drawCircleMidPoint(fxc,fyc,radius);
	drawCircleMidPoint(bxc,byc,0.3*radius);
	for(i=0;i<18;++i)
	{
		theta=M_PI*angle/180;
		x=fxc+radius*cos(theta);
		y=fyc+radius*sin(theta);
		angle+=20;
		line(fxc,fyc,x,y);
		x=bxc+radius*cos(theta);
		y=byc+radius*sin(theta);
		line(bxc,byc,x,y);
	}


	line(bxc,byc,bxc+2.5*radius*cos(M_PI/3),byc-2.5*radius*sin(M_PI/3));
	line(fxc,fyc,fxc,fyc-3*radius);
	line(bxc+2.5*radius*cos(M_PI/3),byc-2.5*radius*sin(M_PI/3),fxc,fyc-2.5*radius*sin(M_PI/3));
	int pxc=(bxc+fxc)*0.5,pyc=byc;
	line(bxc+2.5*radius*cos(M_PI/3),byc-2.5*radius*sin(M_PI/3),pxc,pyc);	
	
	drawCircleMidPoint(pxc,pyc,0.4*radius);
	line(bxc,byc+0.3*radius,pxc,pyc+0.4*radius);
	line(bxc,byc-0.3*radius,pxc,pyc-0.4*radius);

	line(bxc+2.5*radius*cos(M_PI/3),byc-2.5*radius*sin(M_PI/3),bxc+2.5*radius*cos(M_PI/3),byc-2.5*radius*sin(M_PI/3)-20);
	line(bxc+2.5*radius*cos(M_PI/3)-10,byc-2.5*radius*sin(M_PI/3)-20,bxc+2.5*radius*cos(M_PI/3)+10,byc-2.5*radius*sin(M_PI/3)-20);

	line(fxc,fyc-3*radius,fxc-20,fyc-3*radius);


	//stickman
	int sxc=bxc+2.5*radius*cos(M_PI/3);
	int syc=byc-2.5*radius*sin(M_PI/3)-20;
	line(sxc,syc,sxc+2*radius*cos(45),syc-2*radius*sin(45));
	drawCircleMidPoint(sxc+2.5*radius*cos(45),syc-2.5*radius*sin(45),0.5*radius);

	line(sxc+1.7*radius*cos(45),syc-1.5*radius*sin(45),fxc-20,fyc-3*radius);
}
