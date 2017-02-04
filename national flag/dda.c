/*
     BLACK          BLUE          GREEN         CYAN

     RED            MAGENTA       BROWN         LIGHTGRAY

     DARKGRAY       LIGHTBLUE     LIGHTGREEN    LIGHTCYAN

     LIGHTRED       LIGHTMAGENTA  YELLOW        WHITE
*/



#include <graphics.h>
#include <math.h>
#include <stdio.h>
void drawLine(float x1,float y1,float x2,float y2,float color)
{
        float x,y,dx,dy,pixel;

        int i;
        dx=abs(x2-x1);
        dy=abs(y2-y1);

        if(dx>=dy)
        pixel=dx;
        else
        pixel=dy;

        dx=(x2-x1)/pixel;
        dy=(y2-y1)/pixel;

        x=x1;
        y=y1;

        i=1;
        while(i<=pixel)
        {
              putpixel(x,y,color);
              x=x+dx;
              y=y+dy;
              i=i+1;
        }
}
