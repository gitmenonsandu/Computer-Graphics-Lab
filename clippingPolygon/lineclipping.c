#include <graphics.h>
#include "bresenham.c"
const int inside=0;
const int left=1;
const int right=2;
const int bottom=4;
const int top=8;

typedef int outcode;

outcode computeOutCode(int x,int y,int xmax,int ymax,int xmin,int ymin)
{
	outcode code=inside;

	if(x<xmin)
		code|=left;
	else if(x>xmax)
		code|=right;

	if(y<ymin)
		code|=bottom;
	else if (y>ymax)
		code|=top;

	return code;

}
void CohenSutherClip(double x1,double y1,double x2,double y2,int xmax,int ymax,int xmin,int ymin)
{
	
	outcode out1=computeOutCode(x1,y1,xmax,ymax,xmin,ymin);
	outcode out2=computeOutCode(x2,y2,xmax,ymax,xmin,ymin);

	int accept=0;

	while(1)
	{
		if((out1==0 && out2==0))
		{
			accept=1;
			break;
		}
		else if(out1 & out2)
			break;
		else
		{
			double x,y;
			outcode outWindowPoint=out1?out1:out2;

			if(outWindowPoint & top)
			{
				x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
				y=ymax;
			
			}
			else if(outWindowPoint & bottom)
			{
				x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
				y=ymin;
			}
			else if(outWindowPoint & right)
			{
				y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
				x=xmax;
			}
			else if(outWindowPoint & left)
			{
				y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
				x=xmin;
			}

			if(outWindowPoint==out1)
			{
				x1=x;
				y1=y;
				out1=computeOutCode(x1,y1,xmax,ymax,xmin,ymin);
			}
			else
			{
				x2=x;
				y2=y;
				out2=computeOutCode(x2,y2,xmax,ymax,xmin,ymin);
			}
		}
	}
	if(accept)
	{
		line(x1,y1,x2,y2);
	}
	else
	{
		//drawRectangle(xmin,ymin,xmax,ymax);
	}

}

void LiangBaskyClip(double x1,double y1,double x2,double y2,int xwmax,int ywmax,int xwmin,int ywmin)
{
	int p[5],q[5];
	double t[5],t1,t2;
	int i,dx,dy;
	dx=x2-x1;
	dy=y2-y1;
	p[1]=-dx;
	p[2]=dx;
	p[3]=-dy;
	p[4]=dy;
	q[1]=x1-xwmin;
	q[2]=xwmax-x1;
	q[3]=y1-ywmin;
	q[4]=ywmax-y1;

	for(i=1;i<=4;++i)
	{
		if(p[i]!=0)
			t[i]=1.0*q[i]/p[i];
		else
		{
			if(p[i]==0 && q[i]<0)
				printf("Line outside window\n");
			else if(p[i]==0 && q[i]>=0)
				printf("Line completely inside the window\n");
		}
	}
	t1=0;
	t2=1;
	int xx1,xx2,yy1,yy2;
	for(i=1;i<=4;++i)
	{
		if(p[i]<0)
			t1=t1>=t[i]?t1:t[i];
		else
			t2=t2<=t[i]?t2:t[i];
	}

	if(t1<t2)
	{
		xx1=x1+t1*dx;
		xx2=x1+t2*dx;
		yy1=y1+t1*dy;
		yy2=y1+t2*dy;
		drawRectangle(xwmin,ywmin,xwmax,ywmax);
		drawLine(xx1,yy1,xx2,yy2);
	}


}