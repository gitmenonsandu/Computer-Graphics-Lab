#include <graphics.h>


void pixel(int xc,int yc,int x,int y)
{
    putpixel(xc+x,yc+y,7);
    putpixel(xc+y,yc+x,7);
    putpixel(xc-y,yc+x,7);
    putpixel(xc-x,yc+y,7);
    putpixel(xc-x,yc-y,7);
    putpixel(xc-y,yc-x,7);
    putpixel(xc+y,yc-x,7);
    putpixel(xc+x,yc-y,7);
}
void drawCircleMidPoint(int xc,int yc,int radius)
{
	int x=0;
	int y=radius;
	int p=1-radius;

	pixel(xc,yc,x,y);
	while(x<y)
	{
		if(p<0)
		{
			x++;
			p=p+2*x+1;
		}
		else
		{
			x++;
			y--;
			p=p+2*x-2*y+1;
		}
		pixel(xc,yc,x,y);
	}

}