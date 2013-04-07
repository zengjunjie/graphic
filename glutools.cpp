#include "glutools.h"

void writeWords(const char* str)
{
	static int isFirstCall = 1;
	static GLuint lists;
	if(isFirstCall) 
	{
		isFirstCall = 0;
		lists = glGenLists(MAX_CHAR);
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists); 
	}
		while(*str != '\0')
		{
			glCallList(lists + *str);
			++str;
		} 
}

void writeFrame(ColorIndex color[])
{
	int m = 340;
	int w = 0;
	glColor3f(0.0f, 0.0f, 0.0f);
	
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
			glVertex2f(590.0, 390.0);
			glVertex2f(590.0, 10.0);
			glVertex2f(10.0, 10.0);
	    	glVertex2f(10.0, 390.0);
  	glEnd();
 	
 	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(550.0, 350.0);
		glVertex2f(550.0, 50.0);
		glVertex2f(50.0, 50.0);
    	glVertex2f(50.0, 350.0);
 	glEnd();

	for(int i=0; i<10; i++)
	{
		glColor3f(color[i].R, color[i].G, color[i].B);
		glRectf(600, 40+i*20, 620, 60+20*i);
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
			glVertex2f(600.0, 40+i*20);
			glVertex2f(620.0, 40+i*20);
			glVertex2f(620.0, 60+i*20);
			glVertex2f(600.0, 60+i*20);
		glEnd();
		glRasterPos2f(622, 40 +20*i);
		char str[25];
		itoa(w, str, 10);
		char* string = str;
		writeWords(string);
		w =w - 20;
	}
	glFlush();
}

void writeData()
{
	int m1=0;
	int m2=0;
	int m3=0;
	int m4=0;

	for(int i=350; i>50;i-=20)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
				glVertex2f(50, i);
				glVertex2f(40.0, i);
			glEnd();
			glRasterPos2f(10.0f, i);
			char str[10];
			itoa(m1, str, 10);
			char* string = str;
			writeWords(string);
			m1 =m1 + 20;
	}
	for(int j=350; j<550;j+=20)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
				glVertex2f(j, 350);
				glVertex2f(j, 360);
			glEnd();
			glRasterPos2f(j, 360.0f);
			char str[10];
			itoa(m3, str, 10);
			char* string = str;
			writeWords(string);
			m3 =m3 + 20;
	}
	for(int j=350; j>50;j-=20)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
				glVertex2f(550.0, j);
				glVertex2f(560.0, j);
			glEnd();
			glRasterPos2f(560.0f, j);
			char str[10];
			itoa(m2, str, 10);
			char* string = str;
			writeWords(string);
			m2 =m2 + 20;
	}
	for(int j=50; j<=550;j+=20)
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
				glVertex2f(j, 50);
				glVertex2f(j, 40);
			glEnd();
			glRasterPos2f(j, 33.0f);
			char str[10];
			itoa(m3, str, 10);
			char* string = str;
			writeWords(string);
			m4 =m4 + 20;
	}
}