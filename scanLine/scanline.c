#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void draw();

void scanline(int x1, int y1, int x2, int y2, int color);


double face1[4][2]={{100,150},{200,150},{200,250},{100,250}};
double face2[4][2]={{150,100},{250,100},{250,200},{150,200}};


int main(int argc, char *argv)
{
	int gd = DETECT, gm = DETECT,i, j, x, y, x1, y1;
	initgraph(&gd, &gm, "");
        
    setcolor(1);
    
    for(i=0;i<4;i++)
    {
        face1[i][0]+=50;
        face2[i][0]+=50;
        face1[i][1]-=50;
        face2[i][1]-=50;
    }
    
    draw();   
    
    setcolor(1);
     
    for(i=0;i<4;i++)
    {
        face1[i][0]-=100;
        face2[i][0]-=100;
        face1[i][1]+=100;
        face2[i][1]+=100;
    }
      
    draw();
    
    getch();
    
    
    scanline(0,0,400,400,10);
    scanline(101,151,151,199,1);
    scanline(151,200,199,249,1);
    
    getch();
    
    return 0;  

}
    
void draw()
{
    int i, tempx1, tempy1, tempx2, tempy2;
    
    line(face1[0][0],face1[0][1],face1[1][0],face1[1][1]);
    line(face1[1][0],face1[1][1],face1[2][0],face1[2][1]);
    line(face1[0][0],face1[0][1],face1[3][0],face1[3][1]);
    line(face1[3][0],face1[3][1],face1[2][0],face1[2][1]);
   
    tempx1 = face1[0][0];
    tempy1 = face1[0][1];
    tempx2 = face1[1][0];
    tempy2 = face1[1][1];
    
    line(face2[0][0],face2[0][1],face2[1][0],face2[1][1]);
    line(face2[1][0],face2[1][1],face2[2][0],face2[2][1]);
    setcolor(10);
    line(face2[0][0],face2[0][1],face2[3][0],face2[3][1]);
    line(face2[3][0],face2[3][1],face2[2][0],face2[2][1]);
    
    tempx1 = face2[0][0];
    tempy1 = face2[0][1];
    tempx2 = face2[1][0];
    tempy2 = face2[1][1];
	setcolor(1);
    line(face1[0][0], face1[0][1], face2[0][0], face2[0][1]);
    line(face1[1][0], face1[1][1], face2[1][0], face2[1][1]);
    line(face1[2][0], face1[2][1], face2[2][0], face2[2][1]);
    
    setcolor(10);
    line(face1[3][0], face1[3][1], face2[3][0], face2[3][1]);
    
    tempx1 = face1[0][0];
    tempy1 = face1[0][1];
    tempx2 = face2[0][0];
    tempy2 = face2[0][1];
    
    tempx1 = face1[1][0];
    tempy1 = face1[1][1];
    tempx2 = face2[1][0];
    tempy2 = face2[1][1];
   
    tempx1 = face1[3][0];
    tempy1 = face1[3][1];
    tempx2 = face2[3][0];
    tempy2 = face2[3][1];

}
    
void scanline(int x1, int y1, int x2, int y2, int color)
{
    int i, j;
    
    for(i=x1; i<=x2; i++)
    {
        for(j=y1; j<=y2; j++)
        {
            if(getpixel(i,j)==color)
                putpixel(i,j,BLACK);
        }
    }
    
}



