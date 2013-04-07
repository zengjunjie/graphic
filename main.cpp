#include "quadTree.h"

using namespace std;
float X0=52;
float Y0 =350;
float DX=500/15;
float DY=30;

quadTree qtree = quadTree((float)X0,(float)Y0,(float)DX,(float)DY);
 
 void Initial(void)										//��ʼ������
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);		//���ñ���������ɫΪ��ɫ
    glMatrixMode(GL_PROJECTION);		//ָ������ͶӰ����
    gluOrtho2D(0.0, 650.0, 0.0, 450.0);		//����ͶӰ����
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);		//�õ�ǰ��ɫ��䴰��
    glColor3f(0.0f, 0.0f, 0.0f);					//���õ�ǰ�Ļ�ͼ��ɫΪ��ɫ
     writeFrame(qtree.color);	             //����
    for(int i=0; i<10; i++)
    {
  		for(int j=0; j<15; j++)
		  {
		  		qtree.drawColor((float)X0+j*DX,(float)Y0-i*DY,(float)DX,(float)DY,
				  (float)qtree.data[i][j],(float)qtree.data[i][j+1],qtree.data[i+1][j+1],
				  qtree.data[i+1][j]); 
		  }
  		} 
    glFlush();												//���OpenGL���������ִ��OpenGL����
}


int main(int argc,char *argv[])
{
	qtree.readData();
	cout<<"��ֵ�ߵļ��DC:"<<qtree.getDC()<<endl;
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