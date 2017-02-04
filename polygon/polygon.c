#include <graphics.h>

void drawPolygon(float x[],float y[],int points)
{
	int i;
	for(i=0;i<points;++i)
	{
		line(x[i],y[i],x[(i+1)%5],y[(i+1)%5]);
	}
}