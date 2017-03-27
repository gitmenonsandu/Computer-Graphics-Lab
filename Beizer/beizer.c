//Bezeir curves

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>


int fact[20];
void calc_factorial()
{	
	fact[0] = 1;
	int i;
	for(i=1;i<=10;i++)
		fact[i] = i*fact[i-1];

}

long long ncr(int n,int r)
{
	return fact[n]/(fact[n-r]*fact[r]);
}
void bezier_curve(int x[],int y[],int n)
{
	double t;
	int gd = DETECT, gm;
	initgraph (&gd, &gm, NULL);
	putpixel(x[0],y[0],WHITE);
	for(t=0.001; t <=1.0; t+=0.001)
	{
		int i;
		double  pointX = 0;
		double pointY = 0;
		for( i=0;i<n;i++)
		{
			pointX+= ncr(n-1,i)*(pow(1-t,n-i-1))*(pow(t,i))*x[i];
			pointY+= ncr(n-1,i)*(pow(1-t,n-i-1))*(pow(t,i))*y[i];
		}
		putpixel((int)pointX,(int)pointY,WHITE);
	}
}


void main()
{
    int x[20], y[20];
    int i;
    printf ("Enter x- and y-coordinates of the control points.\n");
    printf("Enter value of n");
    int n;
    calc_factorial();
    scanf("%d",&n);
    for (i=0; i<n; i++)
		scanf ("%d%d", &x[i], &y[i]);


    bezier_curve(x, y,n);
    getch();
    closegraph();

}
