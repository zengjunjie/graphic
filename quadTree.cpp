#include "quadTree.h"

using namespace std;

void quadTree::readData() 
{
	int Zmax, Zmin;
	ifstream fin("data.txt");
	for(int i=0; i<X; i++)
	{
		for(int j=0; j<Y; j++)
		{
			fin>>data[i][j];
			cout<<data[i][j]<<"-";
		}
		cout<<endl;
	}	
	Zmax = Zmin = data[0][0];
	for(int i=0; i<X; i++)
	{
		for(int j=0; j<Y; j++)
		{
			if(data[i][j]>Zmax)
				Zmax = data[i][j];
			else if(data[i][j]<Zmin)
				Zmin = data[i][j];
		}
	}	
	ZMax = Zmax;
	ZMin = Zmin;
	cout<<"Zmax: "<<Zmax<<"  Zmin:"<<Zmin<<endl;
	DC =(Zmax-Zmin)/N;
}

int quadTree::getDC(){
	return DC;
}

void quadTree::setColor()
{
	for(int i=0; i<=N; i++)
	{
		float m =1-float(i)*1/float(N);
		float n = float(i) * 1/float(N);
		color[i] = ColorIndex(m, n, 0);
		cout<<"m -  n"<<m<<n<<endl;
		cout<<"color"<<i<<"R - G - B:"<<color[i].R<<" - "<<color[i].G<<" - "<<color[i].B<<endl;
		
	}
}

void quadTree::drawColor(float x0,float y0, float dx, float dy, 
					float p1,float p2, float p3, float p4)
{
	int ic1 = (p1 - ZMin)/DC;					
	int ic2 = (p2 - ZMin)/DC;		
	int ic3 = (p3 - ZMin)/DC;		
	int ic4 = (p4 - ZMin)/DC;		
	
	if(dx <= 1 && dy <= 1)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glRectf(x0, y0, x0+dx ,y0-dy);
	}
	else if((ic1 == ic2 && ic2 == ic3 && ic3==ic4 && ic4==ic1))
	{
		glColor3f(color[ic1].R, color[ic1].G, color[ic1].B);
		glRectf(x0, y0, x0+dx, y0-dy);
	}
	else
	{
		dx = dx/2;
		dy = dy/2;
		drawColor(x0, y0,  dx, dy, 
				 p1,(p2+p1)/2, (p1+p2+p3+p4)/4, (p1+p4)/2);
		drawColor(x0+dx, y0, dx, dy, 
				 (p1+p2)/2, p2, (p2+p3)/2, (p1+p2+p3+p4)/4);
	    drawColor(x0, y0-dy,  dx,  dy, 
				 (p1+p4)/2, (p2+p1+p3+p4)/2, (p3+p4)/2, p4);
		drawColor(x0+dx, y0-dy,  dx, dy, 
				 (p1+p2+p3+p4)/4,(p2+p3)/2, p3, (p3+p4)/2);
	}
}