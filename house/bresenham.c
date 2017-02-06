#include <graphics.h>
#define sign(x) ((x > 0)? 1 : ((x < 0)? -1: 0))


void drawLine(int x1,int y1,int x2,int y2)
{
  int dx, dy, x, y, d, s1, s2, swap=0, temp;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  s1 = sign(x2-x1);
  s2 = sign(y2-y1);


  if(dy > dx)
  {
  	temp = dx; 
  	dx = dy; 
  	dy = temp; 
  	swap = 1;
  }


  d = 2 * dy - dx;
  x = x1;
  y = y1;

  int i;
  for(i = 1; i <= dx; i++)
  {
    putpixel(x,y,WHITE);
    
    while(d >= 0) 
    {
      if(swap) 
      	x = x + s1;
      else 
      {
        y = y + s2;
        d = d - 2* dx;
      }
    }
    if(swap) y = y + s2;
    else x = x + s1;
    d = d + 2 * dy;
  }

}

void drawRectangle(int x1,int y1,int x2,int y2)
{
    drawLine(x1,y1,x2,y1);
    drawLine(x1,y1,x1,y2);
    drawLine(x2,y2,x2,y1);
    drawLine(x2,y2,x1,y2);


}
