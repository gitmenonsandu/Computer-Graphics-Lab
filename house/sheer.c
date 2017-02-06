#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define PI 3.14159

int sign(x)
{
	if(x>0)
		return 1;
	else if(x<0)
	 	return -1;
	else
	 	return 0;
}

int x[200], y[200];

void drawline(int x1,int y1, int x2, int y2)
{
	int x,y,dx,dy,swap,temp,s1,s2,p,i;
	x=x1;
	y=y1;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	swap=0;
	putpixel(x1,y1,WHITE);
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		swap=1;
	}
	p=2*dy-dx;
	for(i=0;i<dx;i++)
	{
		
		if(p>=0)
	  	{
	  		p=p-2*dx;
	  		if(swap)
	   			x+=s1;
	  		else
	   			y+=s2;
	  	}
	  	p=p+2*dy;
	 	if(swap)
	  		y+=s2;
	 	else
	  		x+=s1;
	  putpixel(x,y,WHITE);
 	}
	putpixel(x2,y2,WHITE);
}

void drawRectangle(int x1, int y1, int x2, int y2){
	drawline(x1, y1, x1, y2);
	drawline(x1, y1, x2, y1);
	drawline(x2, y2, x2, y1);
	drawline(x2, y2, x1, y2);
}

void drawhouse(){
	x[0]= 50;
	y[0] = 50;



	x[1] = 250;
	y[1] = 50;

	x[2] = 250;
	y[2] = 200;

	x[3] = 75;
	y[3] = 75;

	x[4] = 100;
	y[4] = 100;

	x[5] = 150;
	y[5] = 150;

	x[6] = 200;
	y[6] = 200;

	x[7] = 50;
	y[7] = 0;

	x[8] = 250;
	y[8] = 0;

	x[9] = 0;
	y[9] = 50;

	x[10] = 300;
	y[10] = 50;

	// chimney
	x[11] = 5;
	y[11] = 5;

	x[12] = 45;
	y[12] = 50;



	x[13] = 50;
	y[13] = 200;

	x[14] = 250;
	y[14] = 50;



	x[15] = 75;
	y[15] = 100;

	x[16] = 100;
	y[16] = 75;



	x[17] = 150;
	y[17] = 200;

	x[18] = 200;
	y[18] = 150;



	x[19] = 5;
	y[19] = 50;

	x[20] = 45;
	y[20] = 5;

	
	drawline(x[7], y[7], x[8], y[8]);
	drawline(x[7], y[7], x[9], y[9]);

	drawline(x[8], y[8], x[10], y[10]);
	drawline(x[9], y[9], x[10], y[10]);


	drawline(x[0], y[0], x[13], y[13]);
	drawline(x[0], y[0], x[14], y[14]);
	drawline(x[2], y[2], x[13], y[13]);
	drawline(x[2], y[2], x[14], y[14]);


	drawline(x[3], y[3], x[15], y[15]);
	drawline(x[3], y[3], x[16], y[16]);
	drawline(x[4], y[4], x[15], y[15]);
	drawline(x[4], y[4], x[16], y[16]);


	drawline(x[5], y[5], x[17], y[17]);
	drawline(x[5], y[5], x[18], y[18]);
	drawline(x[6], y[6], x[17], y[17]);
	drawline(x[6], y[6], x[18], y[18]);

	drawline(x[11], y[11], x[19], y[19]);
	drawline(x[11], y[11], x[20], y[20]);
	drawline(x[12], y[12], x[19], y[19]);
	drawline(x[12], y[12], x[20], y[20]);
}



void y_sheer(){
	int xx[200], yy[200];
	int i;
	for(i=0; i<21; i++){ 
		xx[i] = x[i];
		yy[i] = y[i];
	}

	for(i=0; i<21; i++){
		y[i] = tan(PI/6)*(300 - x[i]) + y[i];
	}

	drawline(x[7], y[7], x[8], y[8]);
	drawline(x[7], y[7], x[9], y[9]);

	drawline(x[8], y[8], x[10], y[10]);
	drawline(x[9], y[9], x[10], y[10]);


	drawline(x[0], y[0], x[13], y[13]);
	drawline(x[0], y[0], x[14], y[14]);
	drawline(x[2], y[2], x[13], y[13]);
	drawline(x[2], y[2], x[14], y[14]);


	drawline(x[3], y[3], x[15], y[15]);
	drawline(x[3], y[3], x[16], y[16]);
	drawline(x[4], y[4], x[15], y[15]);
	drawline(x[4], y[4], x[16], y[16]);


	drawline(x[5], y[5], x[17], y[17]);
	drawline(x[5], y[5], x[18], y[18]);
	drawline(x[6], y[6], x[17], y[17]);
	drawline(x[6], y[6], x[18], y[18]);

	drawline(x[11], y[11], x[19], y[19]);
	drawline(x[11], y[11], x[20], y[20]);
	drawline(x[12], y[12], x[19], y[19]);
	drawline(x[12], y[12], x[20], y[20]);

}

void x_sheer(){
	int xx[200], yy[200];
	int i;
	for(i=0; i<21; i++){
		x[i] = tan(PI/6)*(200-y[i]) + x[i];
	}

	drawline(x[7], y[7], x[8], y[8]);
	drawline(x[7], y[7], x[9], y[9]);

	drawline(x[8], y[8], x[10], y[10]);
	drawline(x[9], y[9], x[10], y[10]);


	drawline(x[0], y[0], x[13], y[13]);
	drawline(x[0], y[0], x[14], y[14]);
	drawline(x[2], y[2], x[13], y[13]);
	drawline(x[2], y[2], x[14], y[14]);


	drawline(x[3], y[3], x[15], y[15]);
	drawline(x[3], y[3], x[16], y[16]);
	drawline(x[4], y[4], x[15], y[15]);
	drawline(x[4], y[4], x[16], y[16]);


	drawline(x[5], y[5], x[17], y[17]);
	drawline(x[5], y[5], x[18], y[18]);
	drawline(x[6], y[6], x[17], y[17]);
	drawline(x[6], y[6], x[18], y[18]);

	drawline(x[11], y[11], x[19], y[19]);
	drawline(x[11], y[11], x[20], y[20]);
	drawline(x[12], y[12], x[19], y[19]);
	drawline(x[12], y[12], x[20], y[20]);

}


int main(){

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\BGI\\");
	//initwindow(800, 800);

	drawhouse();

	int c;
	scanf("%d", &c);


	// x sheer for 1;
	// y sheer for 2;
	if(c == 1){
		x_sheer();
	}else{
		y_sheer();
	}

	getch();
	closegraph();
	return 0;
}