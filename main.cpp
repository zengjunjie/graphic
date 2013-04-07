#include "quadTree.h"

using namespace std;
float X0=52;
float Y0 =350;
float DX=500/15;
float DY=30;

quadTree qtree = quadTree((float)X0,(float)Y0,(float)DX,(float)DY);
 
 void Initial(void)										//初始化窗口
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);		//设置背景窗口颜色为白色
    glMatrixMode(GL_PROJECTION);		//指定设置投影参数
    gluOrtho2D(0.0, 650.0, 0.0, 450.0);		//设置投影参数
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);		//用当前景色填充窗口
    glColor3f(0.0f, 0.0f, 0.0f);					//设置当前的绘图颜色为红色
     writeFrame(qtree.color);	             //绘制
    for(int i=0; i<10; i++)
    {
  		for(int j=0; j<15; j++)
		  {
		  		qtree.drawColor((float)X0+j*DX,(float)Y0-i*DY,(float)DX,(float)DY,
				  (float)qtree.data[i][j],(float)qtree.data[i][j+1],qtree.data[i+1][j+1],
				  qtree.data[i+1][j]); 
		  }
  		} 
    glFlush();												//清空OpenGL命令缓冲区，执行OpenGL程序
}


int main(int argc,char *argv[])
{
	qtree.readData();
	cout<<"等值线的间距DC:"<<qtree.getDC()<<endl;
	qtree.setColor();
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Test");
    glutDisplayFunc(Display);
    Initial();
    cout<<"Hello world";
    glutMainLoop();

    return 0;
	
}