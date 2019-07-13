#include<stdio.h>
#include <GL/glut.h>
#include <string.h>
#include <iostream> 
#include <stdlib.h>   
#include <time.h> 

//using namespace std;

void drawBall();
void drawEverything();
void drawWall();
void drawBottle ();
void shoot();
void shoot_2();
void moveball();
void winner();
void scorecalulation();
void display();
void text();
void mydis();
void score_display();


bool lighting_on = false;
bool light_on[] = {false, false, false};
bool w = 0;
bool LightingOn=false;
bool lightingon[]={true,true,true,true};
bool smooth=true;
bool is_shoot=true;
bool is_pins = false;
bool with_eye = false;
bool status;

// manupulations

int count = 0 ;
int score_player[11]={0,0,0,0,0,0,0,0,0,0,0};
int isball[6];
int p1;
int p2;
int speed;
//int sum;


int check=1;
int i=0,mode=0;        
int ww=1200, wh=700;
int upi=0,ortho=0,ortfront=0,ortright=0,orttop=0,main_window=0; 

float ambient_o[] = {0.25f, 0.25f, 0.25f, 1.0f };												
float diffuse_o[] = {1.0f, 1.0f, 1.0f, 1.0f };
float specular_o[] = {1.0f, 1.0f, 1.0f, 1.0f };
float f = 1000.0;
float n = 1.0;
float fov = 110.0;

static GLdouble viewer[]={450.0,200.0,0.0};
static GLdouble object[]={450.0,200.0,-400.0}; 
static GLdouble up[]={0.0,1.0,0.0}; 
static GLdouble ball_pos[]={0.0,1.0,0.0};
static GLdouble target[]={0.0,1.0,0.0};
static GLdouble ort1[]={-200.0,150.0,-200.0,50.0}; 
static GLdouble ort2[]={150.0,1000.0,-200.0,300.0}; 
static GLdouble ort3[]={-800.0,800.0,-100.0,550.0}; 

char str[]="BAPUJI INSTITUTE OF ENGINEERING AND TECHNOLOGY";
char str1[]="DAVANGERE, KARNATAKA 577005";
char str2[]="COMPUTER GRAPHICS & VISUALIZATION";
char str3[]="MINI PROJECT ON";
char str4[]="BOWLING GAME";
char str5[]="TEAM MEMBERS :";
char str6[]="MEGHA S - 4BD16CS052";
char str7[]="NAMAN ANAND - 4BD16CS056";
char str8[]="DEPT OF CS&E, SEM 6TH, SEC B";
char str9[]="PROJECT GUIDED BY :";
char str10[]="ANU C S";
char str11[]="ASSISTANT PROFESSOR ";
char str12[]="DEPT OF COMPUTER SCIENCE & ENGG";
char str13[]="PRESS S TO CONTINUE";
char str14[]="";
char str15[]="PRESS t/T TO CONTINUE";


class bottle
{
public:
	void drawBall1()
	{
		 GLUquadricObj *ball;
		 ball=gluNewQuadric();
		glPushMatrix();
		glTranslatef(230.0,190.0,-550.0);
		gluSphere(ball,15.0, 30,30);
		glPopMatrix();
	}
	void drawBottle()
	{	
		GLUquadricObj *cylin = gluNewQuadric();
		glColor3f(1,0,0);
		glPushMatrix();
		glTranslatef(0, 10, 0);
		glRotatef(90, 1, 0, 0);
		glColor3f(1,1,1);
		gluCylinder(cylin, 60, 20, 85, 360, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 57, 0);
		glRotatef(90, 1, 0, 0);
		glColor3f(1,1,1);
		gluCylinder(cylin, 60, 60, 45, 360, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 140, 0);
		glRotatef(90, 1, 0, 0);
		glColor3f(1,0,0);
		gluCylinder(cylin, 20, 60, 85, 360, 1);
		glPopMatrix();

		glPushMatrix();
		glScalef(1.9, 1.9, 1.9);
		glTranslatef(-320,37,235);
		glPushMatrix();
		glTranslatef(90,-145,300);
		glColor3f(1,1,1);
		drawBall1();
		glPopMatrix();
		glPopMatrix();
	}
};

bottle b11, b21, b22, b31, b32, b33;
bottle b211, b221, b222, b231, b232, b233;

void viewAlley()
{
	object[0]=330;
	object[1]=10;
	object[2]=-750;
	viewer[0]=object[0];
	viewer[1]=object[1]+30;
	viewer[2]=-290;
	ball_pos[0]=viewer[0]-10;
	ball_pos[1]=viewer[1]-20;
	ball_pos[2]=viewer[2]-50;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov,1.0,n,f);
						
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],object[0],object[1],object[2],up[0],up[1],up[2]);
	glPopMatrix();
	glutPostRedisplay(); 
}


void viewAlley_2()
{
	object[0]=530;
	object[1]=10;
	object[2]=-750;
	viewer[0]=object[0];
	viewer[1]=object[1]+30;
	viewer[2]=-290;
	ball_pos[0]=viewer[0]-10;
	ball_pos[1]=viewer[1]-20;
	ball_pos[2]=viewer[2]-50;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov,1.0,n,f);
						
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],object[0],object[1],object[2],up[0],up[1],up[2]);
	glPopMatrix();
	glutPostRedisplay(); 
}

void drawWall()
{
	glPushMatrix();
	glColor3f(1,0.967,0.768);   //roof
	glBegin(GL_QUADS);
	glVertex3f(0,480,0);
	glVertex3f(0,480,-800);
	glVertex3f(1000,480,-800);
	glVertex3f(1000,480,0);
	glEnd();

	glColor3f(0.78,0.39,0.0); //front wall
	glBegin(GL_QUADS);
	glVertex3f(1000,0,-750);
	glVertex3f(0,0,-750);
	glVertex3f(0,480,-750);
	glVertex3f(1000,480,-750);
	glEnd();
	winner();
	

	glColor3f(0.039, 0.474, 0.874);// left wall
	glBegin(GL_QUADS);
	glVertex3f(0,0,0);
	glVertex3f(0,0,-800);
	glVertex3f(0,480,-800);
	glVertex3f(0,480,0);
	glEnd();

	glColor3f(0.039, 0.474, 0.874);//right wall
	glBegin(GL_QUADS);
	glVertex3f(980,0,-800);
	glVertex3f(1000,0,0);
	glVertex3f(1000,480,0);
	glVertex3f(980,480,-800);
	glEnd();

	glColor3f(0.78,0.39,0.0); //back wall
	glBegin(GL_QUADS);
	glVertex3f(1000,0,0);
	glVertex3f(0,0,0);
	glVertex3f(0,480,0);
	glVertex3f(1000,480,0);
	glEnd();

  glPopMatrix();
}

void drawFloor()
{
     glColor3f(0.8705,0.6431,0.0549);
		glBegin(GL_QUADS);//floor
		glVertex3f(0,0,0);
		glVertex3f(1000,0,0);
		glVertex3f(1000,0,-800);
		glVertex3f(0,0,-800);
		glEnd();
}

void drawBottleSet()
{
	glPushMatrix();
	glTranslatef(-600,0,0);

	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5000,70,-4850);		
		b33.drawBottle();
    glPopMatrix();
	
    glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4825,70,-4850);	
		b32.drawBottle();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4675,70,-4850);
		b31.drawBottle();
	glPopMatrix();

	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4900,70,-4750);
		b22.drawBottle();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4725,70,-4750);
		b21.drawBottle();
	glPopMatrix();

	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4812,70,-4650);	
		b11.drawBottle();
	glPopMatrix();

	glPopMatrix();
}
/*
void drawBottleSet_2()
{
	glPushMatrix();
	glTranslatef(-400,0,0);

	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5200,70,-4850);		
		b233.drawBottle();
    glPopMatrix();
	
    glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5025,70,-4850);	
		b232.drawBottle();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4875,70,-4850);
		b231.drawBottle();
	glPopMatrix();

	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5100,70,-4750);
		b222.drawBottle();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4925,70,-4750);
		b221.drawBottle();
	glPopMatrix();

	glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5012,70,-4650);	
		b211.drawBottle();
	glPopMatrix();

	glPopMatrix();
}
*/
void drawSeparator()
{
    /*GLfloat amb1[4] = {0.0,0.0,0.0,1.0};
	GLfloat diff1[4] = {0.588,0.333,0.054,1.0};
    GLfloat spec1[4] = {0.588,0.333,0.054,1.0};
	GLfloat shin1[] = {51.6};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,spec1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shin1);*/
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glScalef(2.5,30,490);
	glTranslatef(25,0,-1.7);
	glBegin(GL_QUADS);
		glVertex3f(0,1,1);
		glVertex3f(0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(0,0,1);
		glEnd();
	glPopMatrix();
}

void alley(int chk)
{
	glPushMatrix();
	glPushMatrix();
	drawFloor();
	glPopMatrix();
	glPushMatrix();
    drawSeparator();

	glColor3f(1,0.95,0.81);
	glScalef(50,5,550);
	glTranslatef(0.80,0.5,-1.6);
	glBegin(GL_QUADS);
		glVertex3f(0,1,0);
		glVertex3f(0,1,1);
		glVertex3f(1,1,1);
		glVertex3f(1,1,0);
	glEnd();
	glPopMatrix();
	glTranslatef(20,0,0);


	if (chk!=1)
	{
		printf(" check : %d\n\n",chk);
		drawBottleSet();
	}
	else 
	{
		if (count%2 == 0)
		{
			shoot_2();
		}
		else
		{
			shoot();
		}
		
		
	}
	glPopMatrix();
}

void drawAlleys()
{
	glPushMatrix();
	glTranslatef(-30,0,0);
	alley(0);
	glTranslatef(190,0,0);
	alley(1);
	glTranslatef(200,0,0);
	alley(2);
	glTranslatef(180,0,0);
	alley(3);
	glTranslatef(180,0,0);
	alley(4);
	glTranslatef(180,0,0);
	alley(5);
	
	glColor3f(1,0.95,0.81);
	glScalef(50,5,550);
	glTranslatef(0.80,0.5,-1.6);
	glPopMatrix();
}

void drawAlleys_2()
{
	glPushMatrix();
	glTranslatef(-30,0,0);
	alley(0);
	glTranslatef(190,0,0);
	alley(4);
	glTranslatef(200,0,0);
	alley(1);
	glTranslatef(180,0,0);
	alley(3);
	glTranslatef(180,0,0);
	alley(4);
	glTranslatef(180,0,0);
	alley(5);
	
	glColor3f(1,0.95,0.81);
	glScalef(50,5,550);
	glTranslatef(0.80,0.5,-1.6);
	glPopMatrix();
}

void drawBall()
{
    GLUquadricObj *ball;
    ball=gluNewQuadric();
	glPushMatrix();
	glTranslatef(230.0,190.0,-550.0);
	gluSphere(ball,15.0, 30,30);
	glPopMatrix();
}

void drawHolder()
{
	glColor3f(0.25,0.20,0.15);
	GLfloat mat_chair[4] = {0.2156,0.4470,0.5843,1.0 };
    GLfloat spec_chair[4] = {0.2156,0.4470,0.5843,1.0 };
	GLfloat shin[] = {51.2};
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,  mat_chair);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  spec_chair);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,  shin);
	glPushMatrix();
	glColor3f(0,0,1);
	glTranslatef(-10,-145,300);
	drawBall();
	glColor3f(0,1,0);
	glTranslatef(0,0,25);
	drawBall();
	glColor3f(1.0,0,0);
	glTranslatef(0,0,25);
	drawBall();
	glColor3f(0,0,1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.6,0.6,0.6);
	glTranslatef(220,2,-230);
	glScalef(4,25,7);
	glRotatef(90,1,0,0);
	
	glutSolidTorus(2,7,20,20);
	glPopMatrix();

	GLUquadricObj *cylin = gluNewQuadric();
    glPushMatrix();
    glTranslatef(220, 17, -290);
    glScalef(0.8,2,1);
    gluCylinder(cylin, 15, 40, 35, 360, 1);
    glPopMatrix();
}

void holderSet()
{
	glPushMatrix();
	glTranslatef(20,0,0);
	drawHolder();
	glTranslatef(180,0,0);
	drawHolder();
	glTranslatef(180,0,0);
	drawHolder();
	glTranslatef(180,0,0);
	drawHolder();
	glPopMatrix();
}

void drawEverything()
{
	printf("count : %d\n", count);
	drawWall();
	if(count%2 == 0){
		printf("one caleed\n");
		drawAlleys_2();
	}
	else{
		printf("drwa allegs 2\n");
		drawAlleys();
	}
	holderSet()	;
	glPushMatrix();
	glTranslated(290,200,50);
	glScaled(0.9,1,1);
	if(mode==1)
	{
		GLUquadricObj *ball;
		ball=gluNewQuadric();
		glPopMatrix();
		glPushMatrix();
		glTranslated(ball_pos[0],ball_pos[1],ball_pos[2]);
		glColor3f(1.756,0.2,0);
		gluSphere(ball,15.0, 30,30);
		glPopMatrix();
	}
	glPopMatrix();
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    ww=w;
    wh=h;
}

void light(GLenum Light,float *amb,float *diff,float *spec,float *pos)
{
	glLightfv(Light,GL_AMBIENT,amb);
	glLightfv(Light,GL_DIFFUSE,diff);
	glLightfv(Light,GL_SPECULAR,spec);
	glLightfv(Light,GL_POSITION,pos);
}

void setlight(){

	if(LightingOn){
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glShadeModel(GL_FLAT);
        glEnable(GL_NORMALIZE);
	}
	else{ 
		glDisable(GL_LIGHTING);
	}

	if(smooth==true){
		glShadeModel(GL_SMOOTH);
		glEnable(GL_NORMALIZE);
	}
	else{
		glShadeModel(GL_FLAT);
	}
}

void flyby(int val)
{
	if (mode==1) {
		if (!is_shoot){
			moveball();
			glutPostRedisplay();
			glutTimerFunc(20,flyby,val);
		}
	}		
}

void right_menu(int id){
	if(id==1){
		is_shoot=true;
	    viewAlley();
		right_menu(4);
		fov=110.0;
		
		viewer[0]=450.0;  
		viewer[1] = 200.0;
		viewer[2] = -7.0;
		object[0] = 450.0;
		object[1] = 200.0;
		object[2] = -400.0;
		mode =0;
	}

	if(id==2){
		LightingOn =! LightingOn;	
		smooth =! smooth;
		right_menu(1);
	}

	if(id==3){
		object[0]=270;
		object[1]=10;
		object[2]=-750;
		viewer[0]=object[0];
		viewer[1]=object[1]+30;
		viewer[2]=-600;
		glutPostRedisplay();
	}

	if(id==4){
		viewer[0]=450.0;  
		viewer[1] = 200.0;
		viewer[2] = -7.0;
		object[0] = 450.0;
		object[1] = 200.0;
		object[2] = -400.0;
 
		myReshape(ww,wh);
		ortho=0;
		ortfront=0;
		ortright=0;
		orttop=0;
		status=false;
		glutPostRedisplay();
	}

	if(id==5){
		exit(1);
	}

}

void keys(unsigned char key, int x, int y)
{
    
	if(key=='p'||key=='P')
	{ 
			if(i>0)
				right_menu(1);
			if(count %2 == 0){

			viewAlley();
			}
			else{
			viewAlley_2();
			}
			mode=1;
			i++;
	}
	if (key=='x' ) 
	{
		if (viewer[0]<=650)
			viewer[0]-- ; 
	}
	if (key=='X' ) 
	{
	   if (viewer[0]<=750)
			viewer[0]++;  
	}
	if (key=='y' ) 
	{
		if (viewer[1]<=650)
			viewer[1]-- ; 
	}
	if (key=='Y' ) 
	{
	   if (viewer[1]<=750)
			viewer[1]++;  
	}
	if (key=='z' )
	{	
	   if (viewer[2]>=-700) 	
			viewer[2]--;
	}
	if (key=='Z' )
	{

		if (viewer[2]>=-700)
			viewer[2]++;
	}

	if (key=='v') 
	{
		fov--;
	}
	if (key=='V')
	{
		fov++;
	}
	if(key == 'r'){
		right_menu(1);
	}
	if (key=='b') 
	{
		speed =0;
	}
	if (key=='B')
	{
		speed = 1;
	}
	if(key == 's'){
		main_window = 1;
		
	}
	if(key == 'q' || key == 'Q'){
		right_menu(5);
	}
	if(key == 27){
		exit(0);
	}
	if(key == 'l' || key == 'L'){
		right_menu(2);
	}
	glutPostRedisplay();
}

void shoot()
{
	//int sum = 0;
	//int isball[6] = {0,0,0,0,0,0};
	

	if(ball_pos[2]>-680)
	{
		printf("if come in shoot\n");
		drawBottleSet();
	}
	else 
	{
		glPushMatrix();
		glTranslatef(-600,0,0);

		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5000,70,-4850);

		if(ball_pos[0]>=300 && ball_pos[0]<=350)	
		{
			//printf("1");
			isball[0] = 1;
			glRotatef(90.0,1,0,1);
		}
		b33.drawBottle();
		//
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4825,70,-4850);
		
		if (ball_pos[0]>290 && ball_pos[0]<330){
			glRotatef(90.0,0,0,1);
			//printf("2");
			isball[1] = 1;	
		}
		
		b32.drawBottle();
			//
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4675,70,-4850);
			
		if (ball_pos[0]>270 && ball_pos[0]<=305){
			//printf("3");
			isball[2] = 1;
			glRotatef(45.0,0,0,1);
		}
		
		b31.drawBottle();
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4900,70,-4750);
			
		if (ball_pos[0]>280 && ball_pos[0]<=335){
			glRotatef(90.0,1,0,1);
			//printf("4");
			isball[3] = 1;
		}
		
		b22.drawBottle();
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4725,70,-4750);
			
		if (ball_pos[0]>270 && ball_pos[0]<=315){
			glRotatef(135.0,1,0,1);
				//printf("5");
			isball[4] = 1;
		}
		
		b21.drawBottle();//
		glPopMatrix();
		glPushMatrix();
			
		glScalef(0.15,0.15,0.15);	
		glTranslatef(4812,70,-4650);	
			
		if (ball_pos[0]>280 && ball_pos[0]<=325){
				//printf("6");
			isball[5] = 1;
			glRotatef(90.0,0,0,1);}
			b11.drawBottle();//
			glPopMatrix();
		
			scorecalulation();
			glPopMatrix();
		}
}

void shoot_2()
{
	//int sum = 0;
	//int isball[6] = {0,0,0,0,0,0};
	printf("%d",ball_pos[2]);
	
	if(ball_pos[2]>-680)
	{	
		drawBottleSet();
		//drawBottleSet_2();
	}
	else 
	{
		printf("comes under if condition");
		glPushMatrix();
		glTranslatef(-600,0,0);

		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5200,70,-4850);

		if(ball_pos[0]>=500 && ball_pos[0]<=550)	
		{
			printf("\nsoot 2  : 1");
			isball[0] = 1;
			glRotatef(180.0,1,0,1);
		}
		b233.drawBottle();
		//
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5025,70,-4850);
		
		if (ball_pos[0]>490 && ball_pos[0]<530){
			glRotatef(180.0,0,0,1);
			printf("\nsoot 2  : 2");
			isball[1] = 1;	
		}
		
		b232.drawBottle();
			
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4875,70,-4850);
			
		if (ball_pos[0]>570 && ball_pos[0]<=505){
			printf("\nsoot 2  : 3");
			isball[2] = 1;
			glRotatef(180.0,0,0,1);
		}
		
		b231.drawBottle();
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(5100,70,-4750);
			
		if (ball_pos[0]>480 && ball_pos[0]<=535){
			glRotatef(180.0,1,0,1);
			printf("\nsoot 2  : 4");
			isball[3] = 1;
		}
		
		b222.drawBottle();
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.15,0.15,0.15);
		glTranslatef(4925,70,-4750);
			
		if (ball_pos[0]>470 && ball_pos[0]<=515){
			glRotatef(180.0,1,0,1);
				printf("\nsoot 2  : 5");
			isball[4] = 1;
		}
		
		b221.drawBottle();//
		glPopMatrix();
		glPushMatrix();
			
		glScalef(0.15,0.15,0.15);	
		glTranslatef(5012,70,-4650);	
			
		if (ball_pos[0]>480 && ball_pos[0]<=525){
				printf("\nsoot 2  : 6");
			isball[5] = 1;
			glRotatef(90.0,0,0,1);
		}
			b211.drawBottle();//
			glPopMatrix();
		
			scorecalulation();
			glPopMatrix();
		}
}

void scorecalulation(){
	
	int sum=0;
	char da0[20]="0";
	char da1[20]="0";

	for(int i =0;i<6;i++){
		sum = sum + isball[i];
		isball[i]=0;
	}

	score_player[count]=sum;	
	int k;
	k=count;

	if(k%2)
	{
		itoa(score_player[count],da0,10);
		glColor3f(1,1,1);
		glRasterPos3f(680,350,-700);
		for(int j=0;j<strlen(da0);j++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da0[j]);
		}
	}
	else
	{
		itoa(score_player[count],da1,10);
		glColor3f(1,1,1);
		glRasterPos3f(1080,350,-700);
		for(int j=0;j<strlen(da1);j++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da1[j]);
		}
	}

	
//if(count%2)
	
	//printf("%d : %d\n",count ,score_player[count]);
	//winner();
	
}

void score_display(){
	char da8[20]="0";
	char da12[20] = "0";
	char da9[20]="PLAYER ONE WINS";
	char da10[30] = "Score Player One : ";
	char da11[30] = "Score Player Two : ";
	
	setlight();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (ortho==0) 
	{	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fov,1.333,n,f);	
	
		if(p1 > p2){
			char da8[20]="0";
			char da12[20] = "0";
			char da9[20]="PLAYER ONE WINS";
			char da10[30] = "Score Player One : ";
			char da11[30] = "Score Player Two : ";
			
			glColor3f(.498,1,0);
			glRasterPos3f(-520,300,-700);
			for(int j=0;j<strlen(da9);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da9[j]);
			}
			
			itoa(p1,da8,10);
			strcat(da10, da8);
			glColor3f(.498,1,0);
			glRasterPos3f(-520,150,-700);
			for(j=0;j<strlen(da10);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da10[j]);
			}

			itoa(p2,da12,10);
			strcat(da11, da12);
			glColor3f(.498,1,0);
			glRasterPos3f(-520,0,-700);
			for(j=0;j<strlen(da11);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da11[j]);
			}
			
		}
		else if(p1 < p2){
			//char da6[20]="0";
			char da7[20]="PLAYER TWO WINS";
			
			
			glColor3f(.498,1,0);
			glRasterPos3f(-480,300,-700);
			for(int j=0;j<strlen(da7);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da7[j]);
			}
			itoa(p1,da8,10);
			strcat(da10, da8);
			glColor3f(.498,1,0);
			glRasterPos3f(-520,150,-700);
			for(j=0;j<strlen(da10);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da10[j]);
			}

			itoa(p2,da12,10);
			strcat(da11, da12);
			glColor3f(.498,1,0);
			glRasterPos3f(-520,0,-700);
			for(j=0;j<strlen(da11);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da11[j]);
			}
		}

		else if(p1 == p2){
			char match_draw[] = "MATCH TIED";
			glColor3f(.498,1,0);
			glRasterPos3f(-380,300,-700);
			for(int j=0;j<strlen(match_draw);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,match_draw[j]);
			}

			itoa(p1,da8,10);
			strcat(da10, da8);
			glColor3f(.498,1,0);
			glRasterPos3f(-520,150,-700);
			for(j=0;j<strlen(da10);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da10[j]);
			}

			itoa(p2,da12,10);
			strcat(da11, da12);
			glColor3f(.498,1,0);
			glRasterPos3f(-520,0,-700);
			for(j=0;j<strlen(da11);j++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da11[j]);
			}
		}
 
	}
	glutSwapBuffers();
}


void wining_logic(){
	if(count == 11){
		glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(400,400);
		glutInitWindowPosition(400,200);
		glutCreateWindow("Score Board");
		
		glutDisplayFunc(score_display);
		glutKeyboardFunc(keys);

	}
}

void winner(){
	int player_one=0;
	int player_two=0;
	char da[]= "Player One : ";
	char da1[] = "Player Two : ";
	char da2[20]="0";
	char da3[20]="0";
	int score_count = 0; 

	//if(count==10){
	glPushMatrix();
	glClear(GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		for(int i=0;i<=10;i++){
			//printf("%d\n",i);
			if(i%2){
			//player1
				player_one+=score_player[i];
				//printf("[%d] : %d\n ",i,score_player[i]);
				itoa(player_one,da2,10);
				//strcat(da, da2);
			}
			else{
				//player2
				player_two+=score_player[i];
				itoa(player_two,da3,10);
			}
		
		}
		//printf(" \n value of i : %d\n",i);
		
		glColor3f(1,1,1);
		glRasterPos3f(65,350,-700);
		for(int j=0;j<strlen(da);j++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da[j]);
		}

		glColor3f(1,1,1);
		glRasterPos3f(500,350,-700);
		for(j=0;j<strlen(da1);j++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da1[j]);
		}


		char da10[]="Total:";
		glColor3f(1,1,1);
		glRasterPos3f(60,240,-700);
		for(j=0;j<strlen(da10);j++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da10[j]);
		}
		i=count;
			//if(i%2){
				//int x=450;
				//x=x+i*20;
		glColor3f(1,1,1);
		glRasterPos3f(200,240,-700);
		for(int k=0;k<strlen(da2);k++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da2[k]);
		}
			//}
			//else{
				//int x=650;
				//x=x+i*20;
		glColor3f(1,1,1);
		glRasterPos3f(500,240,-700);
		for( k=0;k<strlen(da3);k++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,da3[k]);
		}
			//}
		
		
		glPopMatrix();

	//}
//	wining_logic();
	//printf("1====%d \n",player_one);
	//printf("2====%d \n",player_two);
		p1= player_one;
		p2=player_two;
}

	
void moveball()
{
	//printf("%f",ball_pos[2]);
	if (ball_pos[2]>-620)
	{
	//	if(with_eye)
	//	viewer[2]-=1.5;
		if(speed == 0)
			ball_pos[2]-=5.5; // ball speed
		else
			ball_pos[2]-=20.9;
	}
	else if (ball_pos[2]>-720)
	{
		if(count%2 == 0){
			shoot_2();
			ball_pos[2]-=100.5;
		}
		else
		{
			shoot();
			ball_pos[2]-=100.5;
		}
		
		
		
	}
}

void pressKeyControls(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT :
		{
			if(is_shoot)
				if(ball_pos[0]>280)
					ball_pos[0]--;
			break;
		}
		case GLUT_KEY_RIGHT :
		{
			if (mode==1)
				if(is_shoot)
					if(ball_pos[0]<360)
						ball_pos[0]++;
			break;
		}
		case GLUT_KEY_UP :
		{
			if (mode==1 ){	
				count++;
				printf("%d",count);
					if(count == 11){
						wining_logic();
					}
			//	if(count<11){
			is_shoot=false;
			//	}	
				
			}
		//	if(count<11){
			flyby(0);
			//	}	
			
				//scorecalulation();
			break;
		}
	}
	glutPostRedisplay();
}

void display()
{
	setlight();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(main_window == 0){
		text();
		glutKeyboardFunc(keys);
	}

	else if (ortho==0) 
	{	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fov,1.333,n,f);	
	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(viewer[0],viewer[1],viewer[2],object[0],
        object[1],object[2],up[0],up[1],up[2]);

 		drawEverything();
	}
	glutSwapBuffers();
}


void text()
{	
	setlight();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
	//	glMatrixMode(GL_PROJECTION);
	//	glLoadIdentity();
	gluPerspective(fov,1.1,2,f);			
	glColor3f(1,0,0);
	
	// 1
	glRasterPos3f(-550,750,-600);	
	for(i=0;i<strlen(str);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
		
	}
	
	//2
	glRasterPos3f(-400,700,-700);
	for(i=0;i<strlen(str1);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[i]);
	}
	
	// 3
	glColor3f(0,0,1);
	glRasterPos3f(-500,500,-700);
	for(i=0;i<strlen(str2);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);
	}

	//4
	glColor3f(.498,1,0);
	glRasterPos3f(-300,300,-700);
	for(i=0;i<strlen(str3);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[i]);
	}

	//5	
	glRasterPos3f(-270,200,-700);
	for(i=0;i<strlen(str4);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str4[i]);
	}

	//6
	glColor3f(1,0,1);
	glRasterPos3f(-1000,-350,-700);
	for(i=0;i<strlen(str5);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str5[i]);
	}
	
	//7
	glColor3f(.498,1,0);
	glRasterPos3f(-1000,-450,-700);
	for(i=0;i<strlen(str6);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str6[i]);
	}
	
	//8
	glRasterPos3f(-1000,-550,-700);
	for(i=0;i<strlen(str7);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str7[i]);
	}

	//9
	glColor3f(0,1,1);
	glRasterPos3f(-1000,-650,-700);	
	for(i=0;i<strlen(str8);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str8[i]);
	}
	
	//10
	glColor3f(1,0,1);
	glRasterPos3f(200,-350,-700);
	for(i=0;i<strlen(str9);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str9[i]);
	}
	
	//11
	glColor3f(.498,1,0);
	glRasterPos3f(200,-450,-700);
	for(i=0;i<strlen(str10);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str10[i]);
	}
	
	//12
	glRasterPos3f(200,-550,-700);
	for(i=0;i<strlen(str11);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str11[i]);
	}
	
	//13
	glColor3f(0,1,1);
	glRasterPos3f(200,-650,-700);
	for(i=0;i<strlen(str12);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str12[i]);
	}
	
	//14
	glColor3f(1,1,1);
	glRasterPos3f(-350,-850,-700);
	for(i=0;i<strlen(str13);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str13[i]);
	}
			
	
//	glutSwapBuffers();
}


void main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize(ww,wh);
	glutCreateWindow("Bowling Court");
//	glutInitWindowPosition(0,0);


//for(int i =1;i<=10;i++)

	glutDisplayFunc(display);
//	glutReshapeFunc(myReshape);
	glutSpecialFunc(pressKeyControls);
	glutKeyboardFunc(keys);

	glutCreateMenu(right_menu);	
	glutAddMenuEntry("1.Reset",1);
	glutAddMenuEntry("2.Lights On/Off",2);
	glutAddMenuEntry("3.See Pins",3);
	glutAddMenuEntry("4.Perspective View",4);
	glutAddMenuEntry("5.Quit Program",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}

