#define GLUT_DISABLE_ATEXIT_HACK

#include <gl/glut.h>
#include"math.h"
double angle=0;
double angle2=0;
double angle3=0;
double angle4=0;
const int n=50;
//初始化OpenGL
const GLfloat R=0.5f;

const GLfloat Pi=3.1415926536f;
void init(void) 
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//设置背景颜色
	glShadeModel(GL_SMOOTH);//设置明暗处理,有两种选择模式：GL_FLAT（不渐变）和GL_SMOOTH（渐变过渡）
}


//主要的绘制过程
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//清除颜色缓存  
	glEnable(GL_DEPTH_TEST);

     glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();

glPushMatrix();	
  //画圆
 glTranslatef(0, 0,-4 );
 //glRotatef(angle2,0.0f,0.0f,-1.0f);
int i;
	glBegin(GL_LINE_STRIP); 
	glColor3f(1.0,0.0,0.0);
	for(i=0;i<n;++i)
	{
		glVertex2f(R*cos(2*Pi/n*i),R*sin(2*Pi/n*i));

	}
	glEnd();
	glPopMatrix();


glPushMatrix();
glTranslatef(0, 0,-4 );//时
glRotatef(angle4,0.0f,0.0f,-1.0f);
glBegin(GL_LINE_STRIP); 
glColor3f(0.0,0.0,0.0);
	glVertex2f(0,0);
	glVertex2f(0.3,0);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslatef(0, 0,-4 );//分
glRotatef(angle3,0.0f,0.0f,-1.0f);
glBegin(GL_LINE_STRIP); 
glColor3f(0.0,0.0,0.0);
	glVertex2f(0,0);
	glVertex2f(0,0.45);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0, 0,-4 );//秒
glRotatef(angle2,0.0f,0.0f,-1.0f);
glBegin(GL_LINE_STRIP); 
glColor3f(1.0,0.0,0.0);
	glVertex2f(0,-0.05);
	glVertex2f(0,0.45);
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
	
	angle2+=3600.0/600.0;
	angle3+=60.0/600.0;
	angle4+=5.0/600.0;
	if(angle2==360)
		angle2=0;
		if(angle3==360)
		angle3=0;
		if(angle4==360)
		angle4=0;
	// Redraw the scene with new coordinates
    glutPostRedisplay();
	glutTimerFunc(1000,TimerFunction, 1);
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

