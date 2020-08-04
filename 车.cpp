#define GLUT_DISABLE_ATEXIT_HACK

#include <gl/glut.h>
#include"math.h"
float angle=0;
float angle2=0;
const int n=50;
//初始化OpenGL
const GLfloat R=0.25f;

const GLfloat Pi=3.1415926536f;
void init(void) 
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);//设置背景颜色
	glShadeModel(GL_SMOOTH);//设置明暗处理,有两种选择模式：GL_FLAT（不渐变）和GL_SMOOTH（渐变过渡）
}


//主要的绘制过程
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//清除颜色缓存  
	glEnable(GL_DEPTH_TEST);

     glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
glTranslatef(angle,0.0,0.0);
		if(angle==9)
		glLoadIdentity();
	glPushMatrix();

	glTranslatef(0,0,-15);
	glScalef(2,1,1);
	glColor3f(1.0,0,0);
 glBegin(GL_QUADS);
	glVertex2d(1,1);
glVertex2d(-1,1);
glVertex2d(-1,-1);
glVertex2d(1,-1);
 glEnd();
glPopMatrix();
 
glPushMatrix();	
int i;  //画圆
 glTranslatef(1.5, -1.25, -15);
 glRotatef(angle2,0.0f,0.0f,-1.0f);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<n;++i)
	{
		glVertex2f(R*cos(2*Pi/n*i),R*sin(2*Pi/n*i));

	}
	glEnd();
glPopMatrix();

glPushMatrix();	
  //画圆
 glTranslatef(-1.5, -1.25, -15);
 glRotatef(angle2,0.0f,0.0f,-1.0f);
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<n;++i)
	{
		glVertex2f(R*cos(2*Pi/n*i),R*sin(2*Pi/n*i));

	}
	glEnd();
	glPopMatrix();

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
    angle+=1;
	if(angle==9)
		angle=0;
	
	angle2+=10;
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

