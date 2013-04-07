#ifndef QUADTREE_H
#define QUADTREE_H

#include "glutools.h"

#define X 11
#define Y 16
#define N 11

class quadTree 
{
  private:
	int DC;
	int ZMax;
	int ZMin;
	float x0,y0;
	float dx,dy;
  public:
    int data[X][Y];
	ColorIndex color[N];
	quadTree(float x0, float y0, float dx, float dy)
	{
		this->x0 = x0;
		this->y0 = y0;
		this->dx = dx;
		this->dy = dy;
	}		

	void drawColor(float x0, float y0, float dx, float dy, 
					float p1,float p2, float p3, float p4);
	void readData();
	void setColor();
	int getDC();
};

#endif