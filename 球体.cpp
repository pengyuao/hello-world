#define GLUT_DISABLE_ATEXIT_HACK
#include<stdio.h>
#include<stdlib.h>
#include <gl/glut.h>
#include"math.h"
float angle=0;
float angle2=0;
//初始化OpenGL
#define pi 3.1415926
#define SOLID 3000
#define WIRE  3001
typedef int SPHERE_MODE;

typedef struct Point3f
{
 GLfloat x;
 GLfloat y;
 GLfloat z;
}point;

void init(void) 
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);//设置背景颜色
	glShadeModel(GL_SMOOTH);//设置明暗处理,有两种选择模式：GL_FLAT（不渐变）和GL_SMOOTH（渐变过渡）
}

//根据半径radius，a角（半径与Z轴正向的夹角），b角（半径在xy平面的投影与x轴正向的夹角）算出球面上点的坐标并记录到point类型的参数p中。
int getPoint(GLfloat radius,GLfloat a,GLfloat b,point &p)
{
 p.x=radius*sin(a*pi/180.0)*cos(b*pi/180.0);
 p.y=radius*sin(a*pi/180.0)*sin(b*pi/180.0);
 p.z=radius*cos(a*pi/180.0);
 return 1;
}
//根据提供的半径radius和分块数slices计算出一系列球面上的点的坐标，储存在一个动态创建的矩阵中，并返回指向该矩阵的指针，
point* getPointMatrix(GLfloat radius,GLint slices)
{
 int i,j,w=2*slices,h=slices;
 float a=0.0,b=0.0;
 float hStep=180.0/(h-1);
 float wStep=360.0/w;
 int length=w*h;
 point *matrix;
	 matrix=(point *)malloc(length*sizeof(point));
 if(!matrix)return NULL;
 for(a=0.0,i=0;i<h;i++,a+=hStep)
  for(b=0.0,j=0;j<w;j++,b+=wStep)  
   getPoint(radius,a,b,matrix[i*w+j]); 
 return matrix;
}

//根据实际调用时提供的4个点的坐标在空间画四边形，并用mode参数确定所画四边形是空心还是实心的。
void drawSlice(point &p1,point &p2,point &p3,point &p4,SPHERE_MODE mode)
{
 switch(mode)
 {
 case SOLID:
  glBegin(GL_QUADS);
  break;
 case WIRE:
  glBegin(GL_LINE_LOOP);
  break;
 }
 glColor3f(1,0,0);
 glVertex3f(p1.x,p1.y,p1.z);
 glVertex3f(p2.x,p2.y,p2.z);
 glVertex3f(p3.x,p3.y,p3.z);
 glVertex3f(p4.x,p4.y,p4.z);
 glEnd();
}
//绘球所调用的函数，根据提供的半径radius和分块数slices在窗体中绘制球体
int drawSphere(GLfloat radius,GLint slices,SPHERE_MODE mode)
{
 int i=0,j=0,w=2*slices,h=slices;
 point *mx;
 mx=getPointMatrix(radius,slices);
 if(!mx)return 0;
 for(;i<h-1;i++)
 {
  for(j=0;j<w-1;j++)
   drawSlice(mx[i*w+j],mx[i*w+j+1],mx[(i+1)*w+j+1],mx[(i+1)*w+j],mode);
  drawSlice(mx[i*w+j],mx[i*w],mx[(i+1)*w],mx[(i+1)*w+j],mode);
 }
 free(mx);
 return 1;
}
void Drawpic()
{
		/** 太阳 */

	
	glPushMatrix();	
	
	  glColor3f(1.0f, 0.0f, 0.0f);	/**< 红色 */
	  glutWireSphere(1.0,20,20);
		
	glPopMatrix();

  	

 /** 绘制地球 */
	glPushMatrix();
  		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		glTranslatef(3.0,0.0,0.0);	
	    glColor3f(0.0f, 0.0f, 1.0f);
		glutWireSphere(0.5,20,20);
		
    glPushMatrix();
	
 /** 绘制月亮 */
		glRotatef(angle2, 0.0f, 0.0f, 1.0f);
	
		glTranslatef(1.0,0.0,0.0);
		
		glColor3f(1.0f, 1.0f, 0.0f);
		glutWireSphere(0.2,20,20);
		

	glPopMatrix();

	glPopMatrix();
 
	glFlush();		

}
//主要的绘制过程
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//清除颜色缓存  
	glEnable(GL_DEPTH_TEST);

     glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();

	
	glTranslatef(0,0,-6);
	glRotatef(angle, 1.0f, 1.0f, 1.0f);
//	glColor3f(1.0,0,0);
drawSphere(2,50,3001);
//	Drawpic();
    glFlush();
}
//在窗口改变大小时调用
void reshape(int w, int h){
       glViewport(0, 0, w, h);//设置视口
       glMatrixMode(GL_PROJECTION);//设置当前为投影变换模式
       glLoadIdentity();//用单位矩阵替换当前变换矩阵
       gluPerspective(45, (float)w/h, 4, 100.0);//设置正交投影视图体
        glMatrixMode (GL_MODELVIEW);
       glLoadIdentity();
}
void TimerFunction(int value)
{
    angle+=10;
	if(angle==360)
		angle=0;
	
	angle2+=30;
	if(angle2==360)
		angle2=0;
	
	// Redraw the scene with new coordinates
    glutPostRedisplay();
	glutTimerFunc(500,TimerFunction, 1);
}

void main( )
{
	
	
	glutCreateWindow("Basic");//设置窗口标题
	init();//初始化OpenGL
	glutDisplayFunc(display);//设置显示回调函数 
	glutReshapeFunc(reshape);//设置reshape回调函数
	glutTimerFunc(500,TimerFunction, 1);

	glutMainLoop();//进入主循环

}

