#include <graphics.h>
#include <math.h>
#define POINTS 9
#define EDGES 16
int node[10][3]={
{200, 200, 200},
{200, 300,  200},
{300, 300,  200},
{300, 200,  200},
{200, 200, 300},
{200, 300,  300},
{300, 300,  300},
{300, 200,  300},

{250,100,250}
};

int edges[][2]={
	{0,1},
	{1,2},
	{2,3},
	{3,0},
	{4,5},
	{5,6},
	{6,7},
	{7,4},
	{0,4},
	{1,5},
	{2,6},
	{3,7},

	{0,8},
	{3,8},
	{4,8},
	{7,8},
};
void initNodes()
{
	int i;
	for(i=0;i<EDGES;++i)
	{
		int n0=edges[i][0];
		int n1=edges[i][1];
		line(node[n0][0],node[n0][1],node[n1][0],node[n1][1]);
	}
}

void translate(int x,int y)
{
	int i;
	for(i=0;i<POINTS;++i)
	{
		node[i][0]+=200;
		node[i][1]+=200;
	}
}
void rotateY(float theta)
{
	float sint=sin(M_PI*theta/180);
	float cost=cos(M_PI*theta/180);

	int i;
	for(i=0;i<POINTS;++i)
	{
		int x=node[i][0];
		int z=node[i][2];
		node[i][0]=x*cost-z*sint;
		node[i][2]=z*cost+x*sint;
	}
}
void rotateX(float theta)
{
	float sint=sin(M_PI*theta/180);
	float cost=cos(M_PI*theta/180);

	int i;
	for(i=0;i<POINTS;++i)
	{
		int y=node[i][1];
		int z=node[i][2];
		node[i][1]=y*cost-z*sint;
		node[i][2]=z*cost+y*sint;
	}
}
void reflectX(int y)
{
	int i;
	for(i=0;i<POINTS;++i)
	{
		node[i][1]=node[i][1]-2*(node[i][1]-y);
	}
}

void reflectY(int x)
{
	int i;
	for(i=0;i<POINTS;++i)
	{
		node[i][0]=node[i][0]-2*(node[i][0]-x);
	}
}
void drawHouse()
{
	//initNodes();
	//translate(200,200);
	rotateY(30);
	//initNodes();
	translate(100,100);
	rotateX(30);
	initNodes();
	

}

void reflect()
{
	reflectY(200);
	initNodes();
	reflectX(300);
	initNodes();
	reflectY(200);
	initNodes();
}
void sheerX(float sf)
{
	int i;

	for(i=0;i<POINTS;++i)
	{
		node[i][0]=node[i][0]+sf*(node[0][0]-node[i][0]);
	}
	initNodes();

}


void sheerY(float sf)
{
	int i;
	for(i=0;i<POINTS;++i)
	{
		node[i][1]=node[i][1]+sf*(node[0][1]-node[i][1]);
	}
	initNodes();
}