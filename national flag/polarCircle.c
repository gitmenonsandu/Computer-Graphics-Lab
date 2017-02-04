#include <graphics.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14
void drawCircle(int xc,int yc,int radius,int color)
{
	float theta=0;
	float x,y;
	//printf("hello\n");
	while(theta<=2*PI)
	{
		x=xc+radius*cos(theta);
		y=yc+radius*sin(theta);
		putpixel(x,y,color);
		theta+=(1.0/radius);
		//printf("%d\n",theta );
	}

}
