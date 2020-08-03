//#define GLUT_DISABLE_ATEXIT_HACK

#include "gl/glut.h"
#include <GL/gl.h>
#include <GL/glaux.h>
#include <math.h>
const int n=50;
const GLfloat R=0.5f;
const GLfloat factor = 0.1f;
const GLfloat Pi=3.1415926536f;
void display()
{

      glClearColor (0.0,0,0,0.0);//，设置背景色，默认为黑色
	glClear(GL_COLOR_BUFFER_BIT);//清除帧缓存

/*	GLfloat x;
/	glBegin(GL_LINES);         //多组双顶点线段
	glVertex2f(-1.0f, 0.0f);         
	glVertex2f(1.0f, 0.0f);         // 以上两个点可以画x轴        
	glVertex2f(0.0f, -1.0f);         
	glVertex2f(0.0f, 1.0f);         // 以上两个点可以画y轴    
	glEnd();     
	glBegin(GL_LINE_STRIP);     
	for(x=-1.0f/factor; x<1.0f/factor; x+=0.01f)     
	{        
		glVertex2f(x*factor, sin(x)*factor);    
	}    
	glEnd();
*/

/*GLfloat a = 1 / (2-2*cos(72*Pi/180));    
GLfloat bx = a * cos(18 * Pi/180);     
GLfloat by = a * sin(18 * Pi/180);     
GLfloat cy = -a * cos(18 * Pi/180);    
 GLfloat         
	 PointA[2] = { 0, a },         
	 PointB[2] = { bx, by },         
	 PointC[2] = { 0.5, cy },         
	 PointD[2] = { -0.5, cy },         
	 PointE[2] = { -bx, by };      
     // 按照A->C->E->B->D->A的顺序，可以一笔将五角星画出     
 glBegin(GL_LINE_LOOP);       //闭合折线  
 glVertex2fv(PointA);         
 glVertex2fv(PointC);         
 glVertex2fv(PointE);         
 glVertex2fv(PointB);         
 glVertex2fv(PointD);     
 glEnd();
*/



/*	int i;  //画圆
	glBegin(GL_POLYGON); //单个简单填充凸多边形
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<n;++i)
	{
		glVertex2f(R*cos(2*Pi/n*i),R*sin(2*Pi/n*i));

	}
	glEnd();*/

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

/*	glBegin(GL_POLYGON); //画圆

        glColor3f(1.0,1.0,1.0);

	 	glVertex2d(-1, 0);
		glVertex2d(-0.9, 0.436);
		glVertex2d(-0.8,0.6);
		glVertex2d(-0.7,0.714);
		glVertex2d(-0.6,0.8);
		glVertex2d(-0.5,0.866);
		glVertex2d(-0.4,0.916);
		glVertex2d(-0.3,0.954);
		glVertex2d(-0.2,0.980);
		glVertex2d(-0.1,0.995);
		glVertex2d(0,1);
	
		glVertex2d(0.1,0.995);
		glVertex2d(0.2,0.980);
		glVertex2d(0.3,0.954);
		glVertex2d(0.4,0.916);
		glVertex2d(0.5,0.866);
		glVertex2d(0.6,0.8);
		glVertex2d(0.7,0.714);
		glVertex2d(0.8,0.6);
		glVertex2d(0.9, 0.436);
		glVertex2d(1, 0);

		glVertex2d(0.9, -0.436);
		glVertex2d(0.8,-0.6);
		glVertex2d(0.7,-0.714);
		glVertex2d(0.6,-0.8);
		glVertex2d(0.5,-0.866);
		glVertex2d(0.4,-0.916);
		glVertex2d(0.3,-0.954);
		glVertex2d(0.2,-0.980);
		glVertex2d(0.1,-0.995);
		glVertex2d(0,-1);

		
	
		
		glVertex2d(-0.1,-0.995);
		glVertex2d(-0.2,-0.980);
		glVertex2d(-0.3,-0.954);
		glVertex2d(-0.4,-0.916);
		glVertex2d(-0.5,-0.866);
		glVertex2d(-0.6,-0.8);
		glVertex2d(-0.7,-0.714);
		glVertex2d(-0.8,-0.6);
		glVertex2d(-0.9, -0.436);

	glEnd();
*/








	glFlush();
	

}
void main() 
{	glutCreateWindow("简单示例");
	glutDisplayFunc(display);// mydisplay是回调函数
	glutMainLoop();
}
