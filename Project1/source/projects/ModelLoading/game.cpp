#include <iostream>
#include <gl/glew.h>
#include "vector2D.h"
//#include <entity.h>
#include <stdio.h>
#include "game.h"
#include "object.h"
#include <math.h>

#include "myTypes.h"

#include "myTypes.h"

using namespace std;

Vector2D 	dotPos(0.0f,0.0f);
Vector2D 	dotVelocity(0.0f,0.0f);
Vector2D 	mousePos(0.0f,0.0f);
Vector2D 	mouseVelocity(0.0f,0.0f);
//Object 	cube("cube.obj",-1.5f,0.1f,-5.0f);
Object * 	cube;
//Object 	monkey("monkey.obj",-0.5f,0.1f,-5.0f);
Object * 	monkey;
Object * 	plane;
Object * 	tower;
GLdouble 	cameraMatrix[9];
GLdouble 	camX = 0;
GLdouble 	camZ = 0;
Vector2D 	camRotation(0.0f,0.0f);
int 		keyUp = 0;
int 		keyDown = 0;
int 		keyLeft = 0;
int 		keyRight = 0;
float		camSpeed = 0.03f;

Vector2D 	dotPos2(200.0f,200.0f);

//>>>>>>SDL_Event 	e;

int 		frame = 0;

Vector2D Delta(Vector2D,Vector2D);
void draw();
void cameraMove();

void initGame(){
	monkey = new Object("monkey.obj",-1.5f,0.1f,-5.0f,DrawType::OldNormal);
	
	printf("hilo\n");
	//plane = new Object("planeR.obj",-1.5f,0.1f,-5.0f);
	//cube = new Object("cube.obj",1.5f,0.1f,-5.0f);
	tower = new Object("towerTest.obj", -0.0f, -1.0f, -6.0f, OldNormal);
	//SDL_bool MouseModeRelative enabled;
	//>>>>>>>>>>>>>>>>>>>SDL_SetRelativeMouseMode(SDL_TRUE);
}

void loop(){
	//mousePos.Print();
	//printf("lo %d\n",add(1,3));
	//printf("lo %d\n",frame);
	//frame++;
				
    //Handle events on queue
	//SDL_FillRect(gScreenSurface,NULL,0x000000);
	
	draw();
	//>>>>>>>>>>>>>>>SDL_GL_SwapWindow(gWindow);
}


float theta = 0.0f;

void draw(){
    theta += 0.1f;
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable (GL_BLEND);
	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	
	// positiond light
    GLfloat lightZero[] = {0.0f,0.0f,0.0f,1.0f};
	GLfloat lightColor0[] = {1.0f,1.0f,1.0f,1.0f};
    GLfloat lightPos0[] = {0.0f,3.0f,-5.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightZero);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	glLoadIdentity();
	glPushMatrix();
		cameraMove();
		glColor4f(0.5f, 1.0f, 1.0f, 1.0f);
		if(plane!=NULL){
			plane->draw();
		}
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		if(monkey!=NULL){
			monkey->draw();
		}
		if(tower!=NULL){
			glPushMatrix();
				//glRotatef(theta, 0.0f, 1.0f, 0.0f);
				glColor4f(0.5f, 1.0f, 0.5f, 0.5f);
				tower->draw();
			glPopMatrix();	
		}
		
		glPushMatrix();
			glTranslatef(2.0f,0.0f,-3.0f);
			glRotatef(theta, 0.0f, 0.0f, 1.0f);
			glScalef(0.1f, 0.1f, 0.1f);
			glBegin(GL_TRIANGLES);
				glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
				glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
				glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
			glEnd();
		glPopMatrix();
		
		glPushMatrix();
			//glRotatef(theta, theta, theta, theta);
			glTranslatef(0.0f,-1.0f,-6.0f);
			glScalef(1.7f,1.7f,1.7f);
			//glBegin(GL_LINE_LOOP);
			glBegin(GL_QUADS);
					glVertex3f(-1.0f,   -1.0f , -1.0f);
					glVertex3f(1.0f,   -1.0f , -1.0f);
					glVertex3f(1.0f, -1.0f ,1.0f);
					glVertex3f(-1.0f, -1.0f ,1.0f);
			glEnd();
		glPopMatrix();
	glPopMatrix();
}

void cameraMove(){
	camRotation.x+=mouseVelocity.x;
	camRotation.y+=mouseVelocity.y;
	mouseVelocity = Vector2D(0,0);
	//camX += camSpeed*(keyLeft-keyRight);
	//camZ += camSpeed*(keyUp-keyDown);
	//printf("KeyBoard Button Pressed( Z=%f X=%f) is pressed.\n",camZ,camX);
	
	
	//printf("mousePos");
	//mousePos.Print();
	//printf("Velocity");
	//mouseVelocity.Print();
	//printf("Rotaiton");
	//camRotation.Print();
	
	
	//glRotatef(0, camRotation.x, camRotation.y, 1.0f);
	glRotatef(camRotation.y*1.0f, 1, 0, 0); //pitch
	glRotatef(camRotation.x*1.0f, 0, 1, 0); //yaw
	
	camX += cos((camRotation.x+90) / 180 * 3.14f) * (keyUp-keyDown)*0.03f;
    camZ += sin((camRotation.x+90) / 180 * 3.14f) * (keyUp-keyDown)*0.03f;
	
	camX += cos((camRotation.x+180) / 180 * 3.14f) * (keyRight-keyLeft)*0.03f;
    camZ += sin((camRotation.x+180) / 180 * 3.14f) * (keyRight-keyLeft)*0.03f;
	
	//glRotatef(camRotation.y*1.0f, 0, 0, 1); //roll
	//glScalef(0.1f, 0.1f, 0.1f);
	glTranslatef(camX,0.0f,camZ);
}