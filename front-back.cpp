//#define GLUT_DISABLE_ATEXIT_HACK

#include "gl/glut.h"
#include <GL/gl.h>
#include <GL/glaux.h>
#include <math.h>
const int n=10;
const GLfloat R=0.5f;
const GLfloat factor = 0.1f;
const GLfloat Pi=3.1415926536f;
void display()
{

      glClearColor (0.0,0,0,0.0);//，设置背景色，默认为黑色
	glClear(GL_COLOR_BUFFER_BIT);//清除帧缓存


	glPolygonMode(GL_FRONT, GL_FILL); // 设置正面为填充模式      
	glPolygonMode(GL_BACK, GL_LINE);  // 设置反面为线形模式      
	glFrontFace(GL_CCW);              // 设置逆时针方向为正面      
	glBegin(GL_POLYGON);              // 按逆时针绘制一个正方形，在左下方    
	glColor3f(1,0,0);
	glVertex2f(-0.5f, -0.5f);          
	glVertex2f(0.0f, -0.5f);          
	glVertex2f(0.0f, 0.0f);          
	glVertex2f(-0.5f, 0.0f);      
	glEnd();      

	glBegin(GL_POLYGON);              // 按顺时针绘制一个正方形，在右上方          
	glVertex2f(0.0f, 0.0f);         
	glVertex2f(0.0f, 0.5f);          
	glVertex2f(0.5f, 0.5f);          
	glVertex2f(0.5f, 0.0f);      
	glEnd();  




	glFlush();
	

}
void main() 
{	glutCreateWindow("简单示例");
	glutDisplayFunc(display);// mydisplay是回调函数
	glutMainLoop();
}
