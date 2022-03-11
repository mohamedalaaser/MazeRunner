#include "TextureBuilder.h"
#include "Model_3DS.h"
#include "GLTexture.h"
#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
#include <math.h> 
#include <windows.h>

#define GLUT_KEY_ESCAPE 27
#define GLUT_KEY_SPACEBAR 32
#define DEG2RAD(a) (a * 0.0174532925)

void print(float x, float y, float z, char* string);

int lights = 0;
int prevlights = 0;
int Minutes = 0;
int seconds = 0;
int milisec = 0;

int WIDTH = 1280;
int HEIGHT = 720;

int level = 1;
int score = 0;
bool jumpUp = 0;
bool newStart = 1;

int obstacle1_1 = 0;
int obstacle1_2 = 0;
int obstacle1_3 = 0;
int obstacle1_4 = 0;
int obstacle1_5 = 0;
int obstacle1_6 = 0;
int obstacle1_7 = 0;
int obstacle1_8 = 0;
int obstacle1_9 = 0;
int obstacle1_10 = 0;
int obstacle1_11 = 0;
int obstacle1_12 = 0;
int obstacle1_13 = 0;

int obstacle2_1 = 0;
int obstacle2_2 = 0;
int obstacle2_3 = 0;
int obstacle2_4 = 0;
int obstacle2_5 = 0;
int obstacle2_6 = 0;
int obstacle2_7 = 0;
int obstacle2_8 = 0;
int obstacle2_9 = 0;
int obstacle2_10 = 0;


//zz
int ob1_1[][2] = {
	 {-10,25},
	 {-10,-5},
	{-10,-15} ,
};
int ob1_2[][2] = {
	  {-10,-45},
	 {-20,35},
	{-20,5} ,
};
int ob1_3[][2] = {
	  {-20,-5},
	 {-20,-35},
	{-30,35} ,
};
int ob1_4[][2] = {
	 {-30,25},
	 {-30,15},
	{-30,5} ,
};
int ob1_5[][2] = {
	  {-30,-45},
	 {-40,15},
	{-40,5} ,
};
int ob1_6[][2] = {
 {-40,-15},
{-40,-45} ,
};

//xx
int ob1_7[][2] = {
   {-45,40},
 {-35,30},
{-5,30} ,
};
int ob1_8[][2] = {
 {-45,30},
{-45,20},
{-15,10} ,
};
int ob1_9[][2] = {
  {-5,0},
{-25,0},
{-45,0} ,
};
int ob1_10[][2] = {
   {-15,-10},
{-35,-10},
{-45,-10} ,
};
int ob1_11[][2] = {
	{-5,-20},
{-25,-20},
{-15,-30} ,
};
int ob1_12[][2] = {
	{-35,-30},
{-45,-30},
{-5,-40} ,
};
int ob1_13[][2] = {
	{-15,-40},
{-25,-40},
{-45,-40} ,
};

//zz
int ob2_1[][2] = {
	 { 10, 25},
	 {40,35},
	 { 60,5},
	 {80,-65 },
	 {10,-45 },
};
int ob2_2[][2] = {
	 { 10,15 },
	 {40, 25},
	 {60,-25},
	 {50, 45 },
	 {70,-75},
};
int ob2_3[][2] = {
	 {10,-35 },
	 {40,-35 },
	 {60,-65},
	  {10,-55},
	 {50,15},
};
int ob2_4[][2] = {
	 {10,-65 },
	 {40,-45 },
	 {60,-75 },
	 {30, 15},
	 {50,-25},
};
int ob2_5[][2] = {
	 { 20, 45},
	 { 40,-55},
	 { 70,5},
	 {30, -25 },
	 { 50,-85 },
};
int ob2_6[][2] = {
	{ 20, 35},
	 {40,-65 },
	 {70,-35},
	 {80,-5},
	  {80,-45},
	  {80,-55},
};

//xx
int ob2_7[][2] = {

	 { 5,-40},
	 {5,10 },
	 {85,-40},
	 {45, 10},
	 { 5,-60},
};
int ob2_8[][2] = {
	 {5,20},
	 {45,30},
	 {75,-30},
	 {55,0},
	 {5 - 70},
};
int ob2_9[][2] = {
	 {  55,40 },
	 {  65,-20 },
	 {  25,-20 },
	 { 55,0  },
	 {5 - 70},
};
int ob2_10[][2] = {

	 {  75,0 },
	 {65,-70},
	 {35,10 },
	 { 15,-50},
};

int coin1_1 = 0;
int coin1_2 = 0;
int coin1_3 = 0;
int coin1_4 = 0;
int coin1_5 = 0;
int coin1_6 = 0;
int coin1_7 = 0;
int coin1_8 = 0;
int coin1_9 = 0;
int coin1_10 = 0;

int coin2_1 = 0;
int coin2_2 = 0;
int coin2_3 = 0;
int coin2_4 = 0;
int coin2_5 = 0;
int coin2_6 = 0;
int coin2_7 = 0;
int coin2_8 = 0;
int coin2_9 = 0;
int coin2_10 = 0;
int coin2_11 = 0;
int coin2_12 = 0;
int coin2_13 = 0;
int coin2_14 = 0;

int coinarr1_1[][3] = {
	{-5, 45,2 },
	{-15, 35 ,2},
		{ -25, 25,2},
	{ -35, 15,2},
		{ -45, 5,2},
};
int coinarr1_2[][3] = {
	{-5, 35 ,2},
		{ -15, 25,2},
		{ -25, 15,2},
		{ -35, 5,2},
		{ -45, -5,2},
};
int coinarr1_3[][3] = {
	{-5, 25 ,2},
		{ -15, 15,2},
		{ -25, 5,2},
		{ -35, -5,2},
		{ -45, -15,2},
};
int coinarr1_4[][3] = {
	{-5, 15,2 },
		{ -15, 5,2},
		{ -25, -5,2},
		{ -35, -15,2},
		{ -45, -25,2},
};
int coinarr1_5[][3] = {
	{-5, 5 ,2},
		{ -15, -5,2},
		{ -25, -15,2},
		{ -35, -25,2},
		{ -45, -35,2},
};
int coinarr1_6[][3] = {
	{-5, -5,2 },
		{ -15, -15,2},
		{ -25, -25,2},
		{ -35, -35,2},
		{ -45, -45,2},
};
int coinarr1_7[][3] = {
	{-5, -15,2 },
		{ -15, -25,2},
		{ -25, -35,2},
		{ -35, -45,2},
		{ -45, 45,2},
};
int coinarr1_8[][3] = {
	{-5, -25 ,2},
	{ -15, -35,2},
	{ -25, -45,2},
	{ -35, 45,2},
	{ -45, 35,2},
};
int coinarr1_9[][3] = {
	{-5, -35 ,2},
	{ -15, -45,2},
	{ -25, 45,2},
	{ -35, 35,2},
	{ -45, 25,2},
};
int coinarr1_10[][3] = {
	{-5, -45,2 },
	{ -15, 45,2},
	{ -25, 35,2},
	{ -35, 25,2},
	{ -45, 15,2},
};

int coinarr2_1[][3] = {
	{5, 45,2},
	{ 15, 35,2},
	{ 25, 25,2},
	{ 35, 15,2},
	{ 45, 5,2},
	{ 55, -5 ,2},
	{ 65, -15,2},
	{ 75, -25,2},
	{ 85, -35,2},
};
int coinarr2_2[][3] = {
	{5, 35,2},
	{ 15, 25,2},
	{ 25, 15,2},
	{ 35, 5,2},
	{ 45, -5,2},
	{ 55, -15,2 },
	{ 65, -25,2},
	{ 75, -35,2},
	{ 85, -45,2},
};
int coinarr2_3[][3] = {
	{5, 25,2},
	{ 15, 15,2},
	{ 25, 5,2},
	{ 35, -5,2},
	{ 45, -15,2},
	{ 55, -25 ,2},
	{ 65, -35,2},
	{ 75, -45,2},
	{ 85, -55,2},
};
int coinarr2_4[][3] = {
	{5, 15,2},
	{ 15, 5,2},
	{ 25, -5,2},
	{ 35, -15,2},
	{ 45, -25,2},
	{ 55, -35 ,2},
	{ 65, -45,2},
	{ 75, -55,2},
	{ 85, -65,2},
};
int coinarr2_5[][3] = {
	{5, 5,2},
	{ 15, -5,2},
	{ 25, -15,2},
	{ 35, -25,2},
	{ 45, -35,2},
	{ 55, -45,2 },
	{ 65, -55,2},
	{ 75, -65,2},
	{ 85, -75,2},
};
int coinarr2_6[][3] = {
	{5, -5,2},
	{ 15, -15,2},
	{ 25, -25,2},
	{ 35, -35,2},
	{ 45, -45,2},
	{ 55, -55 ,2},
	{ 65, -65,2},
	{ 75, -75,2},
	{ 85, -85,2},
};
int coinarr2_7[][3] = {
	{5, -15,2},
	{ 15, -25,2},
	{ 25, -35,2},
	{ 35, -45,2},
	{ 45, -55,2},
	{ 55, -65,2 },
	{ 65, -75,2},
	{ 75, -85,2},
	{ 85, 45,2},
};
int coinarr2_8[][3] = {
	{5, -25,2},
	{ 15, -35,2},
	{ 25, -45,2},
	{ 35, -55,2},
	{ 45, -65,2},
	{ 55, -75,2 },
	{ 65, -85,2},
	{ 75, 45,2},
	{ 85, 35,2},
};
int coinarr2_9[][3] = {
	{5, -35,2},
	{ 15, -45,2},
	{ 25, -55,2},
	{ 35, -65,2},
	{ 45, -75,2},
	{ 55, -85,2 },
	{ 65, 45,2},
	{ 75, 35,2},
	{ 85, 25,2},
};
int coinarr2_10[][3] = {
	{5, -45,2},
	{ 15, -55,2},
	{ 25, -65,2},
	{ 35, -75,2},
	{ 45, -85,2},
	{ 55, 45 ,2},
	{ 65, 35,2},
	{ 75, 25,2},
	{ 85, 15,2},
};
int coinarr2_11[][3] = {
	{5, -55,2},
	{ 15, -65,2},
	{ 25, -75,2},
	{ 35, -85,2},
	{ 45, 45,2},
	{ 55, 35 ,2},
	{ 65, 25,2},
	{ 75, 15,2},
	{ 85, 5,2},
};
int coinarr2_12[][3] = {
	{5, -65,2},
	{ 15, -75,2},
	{ 25, -85,2},
	{ 35, 45,2},
	{ 45, 35,2},
	{ 55, 25,2 },
	{ 65, 15,2},
	{ 75, 5,2},
	{ 85, -5,2},
};
int coinarr2_13[][3] = {
	{5, -75,2},
	{ 15, -85,2},
	{ 25, 45,2},
	{ 35, 35,2},
	{ 45, 25,2},
	{ 55, 15,2 },
	{ 65, 5,2},
	{ 75, -5,2},
	{ 85, -15,2},
};
int coinarr2_14[][3] = {
	{5, -85,2},
	{ 15, 45,2},
	{ 25, 35,2},
	{ 35, 25,2},
	{ 45, 15,2},
	{ 55, 5 ,2},
	{ 65, -5,2},
	{ 75, -15,2},
	{ 85, -25,2},
};



GLuint tex;

class Vector3f {
public:
	float x, y, z;

	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3f operator+(Vector3f& v) {
		return Vector3f(x + v.x, y + v.y, z + v.z);
	}

	Vector3f operator-(Vector3f& v) {
		return Vector3f(x - v.x, y - v.y, z - v.z);
	}

	Vector3f operator*(float n) {
		return Vector3f(x * n, y * n, z * n);
	}

	Vector3f operator/(float n) {
		return Vector3f(x / n, y / n, z / n);
	}

	Vector3f unit() {
		return *this / sqrt(x * x + y * y + z * z);
	}

	Vector3f cross(Vector3f v) {
		return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}
};


class Camera {
public:
	Vector3f eye, center, up;

	Camera(float eyeX = 96.0f, float eyeY = 13.0f, float eyeZ = 84.0f, float centerX = -96.0f, float centerY = 13.0f, float centerZ = 84.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f) {
		eye = Vector3f(eyeX, eyeY, eyeZ);
		center = Vector3f(centerX, centerY, centerZ);
		up = Vector3f(upX, upY, upZ);
	}

	void moveX(float d) {
		Vector3f right = up.cross(center - eye).unit();
		eye = eye + right * d;
		center = center + right * d;
	}

	void moveY(float d) {
		eye = eye + up.unit() * d;
		center = center + up.unit() * d;
	}

	void moveZ(float d) {
		Vector3f view = (center - eye).unit();
		eye = eye + view * d;
		center = center + view * d;
	}

	void rotateX(float a) {
		Vector3f view = (center - eye).unit();
		Vector3f right = up.cross(view).unit();
		view = view * cos(DEG2RAD(a)) + up * sin(DEG2RAD(a));
		up = view.cross(right);
		center = eye + view;
	}

	void rotateY(float a) {
		Vector3f view = (center - eye).unit();
		Vector3f right = up.cross(view).unit();
		view = view * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
		right = view.cross(up);
		center = eye + view;
	}

	void look() {
		gluLookAt(
			eye.x, eye.y, eye.z,
			center.x, center.y, center.z,
			up.x, up.y, up.z
		);
	}
};

Camera camera = level == 1 ? Camera() : Camera(-32.0, 13.0, 80.0, 32.0, 13.0, 80.0, 0.0, 1.0, 0.0);
Camera cammeraFirstPerson = level == 1 ? Camera(93.0, 13.0, 84.0, -93.0, 13.0, 84.0, 0.0, 1.0, 0.0) :
	Camera(-29.0, 13.0, 80, 29.0, 13.0, 80.0, 0.0, 1.0, 0.0);

bool switchCameraMode = 0;


float charcterX = level == 1 ? 90 : -26.0;
float charcterY = 10;
float charcterZ = level == 1 ? 84 : 80.0;
int characterDirection = level == 1 ? 0 : 180;

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, WIDTH / HEIGHT, 5.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (switchCameraMode) {
		cammeraFirstPerson.look();
	}
	else {
		camera.look();
	}

}

// Model Variables
Model_3DS model_gate1;
Model_3DS model_gate2;
Model_3DS model_pikachu;
Model_3DS model_coin;
Model_3DS model_obs1;
Model_3DS model_obs2;

// Textures
GLTexture tex_ground;
GLTexture tex_ground1;

void InitLightSource()
{
	// Enable Lighting for this OpenGL Program
	glEnable(GL_LIGHTING);

	// Enable Light Source number 0
	// OpengL has 8 light sources
	glEnable(GL_LIGHT0);

	// Define Light source 0 ambient light
	GLfloat ambient[] = { 0.1f, 0.1f, 0.1, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

	// Define Light source 0 diffuse light
	GLfloat diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

	// Define Light source 0 Specular light
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Finally, define light source 0 position in World Space
	GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void InitMaterial()
{
	// Enable Material Tracking
	glEnable(GL_COLOR_MATERIAL);

	// Sich will be assigneet Material Properties whd by glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Set Material's Specular Color
	// Will be applied to all objects
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

	// Set Material's Shine value (0->128)
	GLfloat shininess[] = { 96.0f };
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

void obstaclePosition() {

	obstacle1_1 = rand() % 5;
	obstacle1_2 = rand() % 5;
	obstacle1_3 = rand() % 5;
	obstacle1_4 = rand() % 5;
	obstacle1_5 = rand() % 5;
	obstacle1_6 = rand() % 5;
	obstacle1_7 = rand() % 5;
	obstacle1_8 = rand() % 5;
	obstacle1_9 = rand() % 5;
	obstacle1_10 = rand() % 5;
	obstacle1_11 = rand() % 5;
	obstacle1_12 = rand() % 5;
	obstacle1_13 = rand() % 5;

}

void coinPosition() {
	coin1_1 = rand() % 5;
	coin1_2 = rand() % 5;
	coin1_3 = rand() % 5;
	coin1_4 = rand() % 5;
	coin1_5 = rand() % 5;
	coin1_6 = rand() % 5;
	coin1_7 = rand() % 5;
	coin1_8 = rand() % 5;
	coin1_9 = rand() % 5;
	coin1_10 = rand() % 5;
}

void obstaclePosition2() {

	obstacle2_1 = rand() % 5;
	obstacle2_2 = rand() % 5;
	obstacle2_3 = rand() % 5;
	obstacle2_4 = rand() % 5;
	obstacle2_5 = rand() % 5;
	obstacle2_6 = rand() % 5;
	obstacle2_7 = rand() % 5;
	obstacle2_8 = rand() % 5;
	obstacle2_9 = rand() % 5;
	obstacle2_10 = rand() % 5;
}

void coinPosition2() {
	coin2_1 = rand() % 5;
	coin2_2 = rand() % 5;
	coin2_3 = rand() % 5;
	coin2_4 = rand() % 5;
	coin2_5 = rand() % 5;
	coin2_6 = rand() % 5;
	coin2_7 = rand() % 5;
	coin2_8 = rand() % 5;
	coin2_9 = rand() % 5;
	coin2_10 = rand() % 5;
	coin2_11 = rand() % 5;
	coin2_12 = rand() % 5;
	coin2_13 = rand() % 5;
	coin2_14 = rand() % 5;


}

void RenderGround()
{
	//glDisable(GL_LIGHTING);	// Disable lighting 

	glColor3f(0.6, 0.6, 0.6);	// Dim the ground texture a bit
	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	if (level == 1) {
		glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]);	// Bind the ground texture

		glPushMatrix();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);	// Set quad normal direction.
		glTexCoord2f(0, 0);		// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
		glVertex3f(-100, 0, -100);
		glTexCoord2f(5, 0);
		glVertex3f(100, 0, -100);
		glTexCoord2f(5, 5);
		glVertex3f(100, 0, 100);
		glTexCoord2f(0, 5);
		glVertex3f(-100, 0, 100);
		glEnd();
		glPopMatrix();
	}
	else if (level == 2) {
		glBindTexture(GL_TEXTURE_2D, tex_ground1.texture[0]);	// Bind the ground texture

		glPushMatrix();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);	// Set quad normal direction.
		glTexCoord2f(0, 0);		// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
		glVertex3f(-100, 0, -100);
		glTexCoord2f(5, 0);
		glVertex3f(100, 0, -100);
		glTexCoord2f(5, 5);
		glVertex3f(100, 0, 100);
		glTexCoord2f(0, 5);
		glVertex3f(-100, 0, 100);
		glEnd();
		glPopMatrix();
	}

	glEnable(GL_LIGHTING);	// Enable lighting again for other entites coming throung the pipeline.

	glColor3f(1, 1, 1);	// Set material back to white instead of grey used for the ground texture.
}


void RenderWallX(int length, int x, int z) {
	for (int i = 0; i < length; i++) {
		glPushMatrix();
		glTranslatef((2 * i) + x, 0, z);
		glScalef(0.4, 0.4, 0.4);
		glutSolidCube(10);
		glPopMatrix();

	}
}

void RenderWallZ(int length, int x, int z) {
	for (int i = 0; i < length; i++) {

		glPushMatrix();
		glTranslatef(x, 0, (2 * i) + z);
		glScalef(0.4, 0.4, 0.4);
		glutSolidCube(10);
		glPopMatrix();

	}
}


void RenderWall2X(int length, int x, int z) {
	for (int i = 0; i < length; i++) {

		glPushMatrix();
		glTranslatef((2 * i) + x, 0, z);
		glScalef(0.4, 0.4, 0.4);
		glutSolidCube(10);
		glPopMatrix();
	}
}

void RenderWall2Z(int length, int x, int z) {
	for (int i = 0; i < length; i++) {

		glPushMatrix();
		glTranslatef(x, 0, (2 * i) + z);
		glScalef(0.4, 0.4, 0.4);
		glutSolidCube(10);
		glPopMatrix();
	}
}

void RenderObstacleX(int x, int z) {

	glPushMatrix();
	glTranslatef(85 + x, 0, 40 + z);
	glRotatef(270, 0, 1, 0);
	glScalef(0.1, 0.03, 0.02);
	model_obs1.Draw();
	glPopMatrix();
}

void RenderObstacleZ(int x, int z) {

	glPushMatrix();
	glTranslatef(85 + x, 0, 40 + z);
	glScalef(0.1, 0.03, 0.02);
	model_obs1.Draw();
	glPopMatrix();
}

void RenderObstacle2X(int x, int z) {

	glPushMatrix();
	glTranslatef(x - 30, 0, 40 + z);
	glRotatef(90, 0, 1, 0);
	glScalef(0.08, 0.07, 0.007);
	model_obs2.Draw();
	glPopMatrix();
}

void RenderObstacle2Z(int x, int z) {

	glPushMatrix();
	glTranslatef(x - 30, 0, 40 + z);
	glScalef(0.1, 0.07, 0.007);
	model_obs2.Draw();
	glPopMatrix();
}

void RenderCoin(int position[3]) {
	glPushMatrix();
	glTranslatef(85 + position[0], position[2], 40 + position[1]);
	glScalef(0.07, 0.05, 0.014);
	glRotatef(270, 1, 0, 1);
	model_coin.Draw();
	glPopMatrix();
}

void RenderCoin2(int position[3]) {
	glPushMatrix();
	glTranslatef(position[0] - 30, position[2], position[1] + 40);
	glScalef(0.07, 0.05, 0.014);
	glRotatef(270, 1, 0, 1);
	model_coin.Draw();
	glPopMatrix();
}

void DrawMaze2() {
	glColor3f(1.0f, 0.8f, 0.4f);

	RenderWall2X(45, 0, 50);
	RenderWall2X(15, 20, 40);
	RenderWall2X(20, 0, 30);
	RenderWall2X(40, 10, 20);
	RenderWall2X(10, 10, 10);
	RenderWall2X(15, 50, 10);
	RenderWall2X(15, 30, -20);
	RenderWall2X(35, 0, -30);
	RenderWall2X(35, 10, -40);
	RenderWall2X(35, 20, -50);
	RenderWall2X(35, 10, -60);
	RenderWall2X(25, 10, -70);
	RenderWall2X(10, 70, -70);
	RenderWall2X(10, 50, -80);
	RenderWall2X(45, 0, -90);

	RenderWall2Z(10, 60, 30);
	RenderWall2Z(10, 80, 30);
	RenderWall2Z(10, 50, 20);
	RenderWall2Z(10, 70, 20);
	RenderWall2Z(60, 90, -70);
	RenderWall2Z(75, 0, -90);//here
	RenderWall2Z(15, 40, -10);
	RenderWall2Z(15, 10, -20);
	RenderWall2Z(15, 30, -20);
	RenderWall2Z(10, 50, -10);
	RenderWall2Z(25, 80, -40);
	RenderWall2Z(15, 20, -30);
	RenderWall2Z(10, 60, -20);
	RenderWall2Z(15, 70, -30); //here
	RenderWall2Z(10, 10, -60);
	RenderWall2Z(5, 70, -70);
	RenderWall2Z(5, 10, -80);
	RenderWall2Z(5, 30, -80);
	RenderWall2Z(5, 50, -80);
	RenderWall2Z(5, 20, -90);
	RenderWall2Z(5, 40, -90);
	RenderWall2Z(5, 70, -90);


	glColor3f(1.0f, 1.0f, 1.0f);
}

void DrawMaze() {
	glColor3f(0.8f, 0.5f, 0.0f);

	//draw Wall 
	RenderWallX(25, -50, -50);
	RenderWallX(5, -40, -40);
	RenderWallX(5, -30, -30);
	RenderWallX(10, -50, -20);
	RenderWallX(5, -20, -20);
	RenderWallX(5, -10, -10);
	RenderWallX(5, -30, -10);
	RenderWallX(5, -40, 0);
	RenderWallX(5, -20, 0);
	RenderWallX(5, -50, 10);
	RenderWallX(5, -30, 10);
	RenderWallX(5, -10, 10);
	RenderWallX(5, -40, 20);
	RenderWallX(5, -20, 20);
	RenderWallX(10, -40, 30);
	RenderWallX(5, -30, 40);
	RenderWallX(25, -50, 50);

	//85 40
	RenderWallX(4.5, 2.5, 50);
	RenderWallX(4, 3, 38);


	RenderWallZ(5, -20, -50);
	RenderWallZ(45, -50, -40);
	RenderWallZ(45, 0, -50);
	RenderWallZ(10, -10, -40);
	RenderWallZ(15, -30, -40);
	RenderWallZ(5, -40, -40);
	RenderWallZ(5, -20, -20);
	RenderWallZ(5, -40, -10);
	RenderWallZ(5, -30, 0);
	RenderWallZ(10, -10, 0);
	RenderWallZ(10, -20, 10);
	RenderWallZ(10, -40, 20);
	RenderWallZ(10, -10, 30);
	RenderWallZ(5, -30, 40);

	RenderWallZ(5, 10, 40);

}

void DrawObstacle() {

	if (obstacle1_1 <= 1) {
		RenderObstacleX(-10, 25);
		RenderObstacleX(-10, -5);
		RenderObstacleX(-10, -15);
	}
	if (obstacle1_2 <= 1) {
		RenderObstacleX(-10, -45);
		RenderObstacleX(-20, 35);
		RenderObstacleX(-20, 5);
	}
	if (obstacle1_3 <= 1) {
		RenderObstacleX(-20, -5);
		RenderObstacleX(-20, -35);
		RenderObstacleX(-30, 35);
	}
	if (obstacle1_4 <= 1) {
		RenderObstacleX(-30, 25);
		RenderObstacleX(-30, 15);
		RenderObstacleX(-30, -5);
	}
	if (obstacle1_5 <= 1) {
		RenderObstacleX(-30, -45);
		RenderObstacleX(-40, 15);
		RenderObstacleX(-40, 5);
	}
	if (obstacle1_6 <= 1) {
		RenderObstacleX(-40, -15);
		RenderObstacleX(-40, -45);
	}

	if (obstacle1_7 <= 1) {
		RenderObstacleZ(-45, 40);
		RenderObstacleZ(-35, 30);
		RenderObstacleZ(-5, 30);
	}

	if (obstacle1_8 <= 1) {
		RenderObstacleZ(-45, 30);
		RenderObstacleZ(-45, 20);
		RenderObstacleZ(-15, 10);
	}

	if (obstacle1_9 <= 1) {
		RenderObstacleZ(-5, 0);
		RenderObstacleZ(-25, 0);
		RenderObstacleZ(-45, 0);
	}

	if (obstacle1_10 <= 1) {
		RenderObstacleZ(-15, -10);
		RenderObstacleZ(-35, -10);
		RenderObstacleZ(-45, -10);
	}

	if (obstacle1_11 <= 1) {
		RenderObstacleZ(-5, -20);
		RenderObstacleZ(-25, -20);
		RenderObstacleZ(-15, -30);
	}

	if (obstacle1_12 <= 1) {
		RenderObstacleZ(-35, -30);
		RenderObstacleZ(-45, -30);
		RenderObstacleZ(-5, -40);
	}

	if (obstacle1_13 <= 1) {
		RenderObstacleZ(-15, -40);
		RenderObstacleZ(-25, -40);
		RenderObstacleZ(-45, -40);
	}


}

void DrawObstacle2() {
	if (obstacle2_1 <= 1) {
		RenderObstacle2X(10, 25);
		RenderObstacle2X(40, 35);
		RenderObstacle2X(60, 5);
		RenderObstacle2X(80, -65);
		RenderObstacle2X(10, -45);
	}
	if (obstacle2_2 <= 1) {
		RenderObstacle2X(10, 15);
		RenderObstacle2X(40, 25);
		RenderObstacle2X(60, -25);
		RenderObstacle2X(50, 45);
		RenderObstacle2X(70, -75);
	}
	if (obstacle2_3 <= 1) {
		RenderObstacle2X(10, -35);
		RenderObstacle2X(40, -35);
		RenderObstacle2X(60, -65);
		RenderObstacle2X(10, -55);
		RenderObstacle2X(50, 15);
	}
	if (obstacle2_4 <= 1) {
		RenderObstacle2X(10, -65);
		RenderObstacle2X(40, -45);
		RenderObstacle2X(60, -75);
		RenderObstacle2X(30, 15);
		RenderObstacle2X(50, -25);
	}
	if (obstacle2_5 <= 1) {
		RenderObstacle2X(20, 45);
		RenderObstacle2X(40, -55);
		RenderObstacle2X(70, 5);
		RenderObstacle2X(30, -25);
		RenderObstacle2X(50, -85);
	}
	if (obstacle2_6 <= 1) {
		RenderObstacle2X(20, 35);
		RenderObstacle2X(40, -65);
		RenderObstacle2X(70, -35);
		RenderObstacle2X(80, -5);
		RenderObstacle2X(80, -45);
		RenderObstacle2X(80, -55);
	}
	if (obstacle2_7 <= 1) {

		RenderObstacle2Z(5, -40);
		RenderObstacle2Z(5, 10);
		RenderObstacle2Z(85, -40);
		RenderObstacle2Z(45, 10);
		RenderObstacle2Z(5, -60);
	}
	if (obstacle2_8 <= 1) {

		RenderObstacle2Z(5, 20);
		RenderObstacle2Z(45, 30);
		RenderObstacle2Z(75, -30);
		RenderObstacle2Z(85, 10);
		RenderObstacle2Z(85, -60);
	}
	if (obstacle2_9 <= 1) {

		RenderObstacle2Z(55, 40);
		RenderObstacle2Z(65, -20);
		RenderObstacle2Z(25, -20);
		RenderObstacle2Z(55, 0);
		RenderObstacle2Z(5, -70);
	}
	if (obstacle2_10 <= 1) {
		RenderObstacle2Z(75, 0);
		RenderObstacle2Z(65, -70);
		RenderObstacle2Z(35, 10);
		RenderObstacle2Z(15, -50);
	}




}

void DrawCoin() {
	if (coin1_1 <= 1) {
		RenderCoin(coinarr1_1[0]);
		RenderCoin(coinarr1_1[1]);
		RenderCoin(coinarr1_1[2]);
		RenderCoin(coinarr1_1[3]);
		RenderCoin(coinarr1_1[4]);
	}
	if (coin1_2 <= 1) {
		RenderCoin(coinarr1_2[0]);
		RenderCoin(coinarr1_2[1]);
		RenderCoin(coinarr1_2[2]);
		RenderCoin(coinarr1_2[3]);
		RenderCoin(coinarr1_2[4]);
	}
	if (coin1_3 <= 1) {
		RenderCoin(coinarr1_3[0]);
		RenderCoin(coinarr1_3[1]);
		RenderCoin(coinarr1_3[2]);
		RenderCoin(coinarr1_3[3]);
		RenderCoin(coinarr1_3[4]);
	}
	if (coin1_4 <= 1) {
		RenderCoin(coinarr1_4[0]);
		RenderCoin(coinarr1_4[1]);
		RenderCoin(coinarr1_4[2]);
		RenderCoin(coinarr1_4[3]);
		RenderCoin(coinarr1_4[4]);
	}
	if (coin1_5 <= 1) {
		RenderCoin(coinarr1_5[0]);
		RenderCoin(coinarr1_5[1]);
		RenderCoin(coinarr1_5[2]);
		RenderCoin(coinarr1_5[3]);
		RenderCoin(coinarr1_5[4]);
	}
	if (coin1_6 <= 1) {
		RenderCoin(coinarr1_6[0]);
		RenderCoin(coinarr1_6[1]);
		RenderCoin(coinarr1_6[2]);
		RenderCoin(coinarr1_6[3]);
		RenderCoin(coinarr1_6[4]);
	}
	if (coin1_7 <= 1) {
		RenderCoin(coinarr1_7[0]);
		RenderCoin(coinarr1_7[1]);
		RenderCoin(coinarr1_7[2]);
		RenderCoin(coinarr1_7[3]);
		RenderCoin(coinarr1_7[4]);
	}
	if (coin1_8 <= 1) {
		RenderCoin(coinarr1_8[0]);
		RenderCoin(coinarr1_8[1]);
		RenderCoin(coinarr1_8[2]);
		RenderCoin(coinarr1_8[3]);
		RenderCoin(coinarr1_8[4]);
	}
	if (coin1_9 <= 1) {
		RenderCoin(coinarr1_9[0]);
		RenderCoin(coinarr1_9[1]);
		RenderCoin(coinarr1_9[2]);
		RenderCoin(coinarr1_9[3]);
		RenderCoin(coinarr1_9[4]);
	}
	if (coin1_10 <= 1) {
		RenderCoin(coinarr1_10[0]);
		RenderCoin(coinarr1_10[1]);
		RenderCoin(coinarr1_10[2]);
		RenderCoin(coinarr1_10[3]);
		RenderCoin(coinarr1_10[4]);
	}
}

void DrawCoin2() {
	if (coin2_1 <= 1) {
		RenderCoin2(coinarr2_1[0]);
		RenderCoin2(coinarr2_1[1]);
		RenderCoin2(coinarr2_1[2]);
		RenderCoin2(coinarr2_1[3]);
		RenderCoin2(coinarr2_1[4]);
		RenderCoin2(coinarr2_1[5]);
		RenderCoin2(coinarr2_1[6]);
		RenderCoin2(coinarr2_1[7]);
		RenderCoin2(coinarr2_1[8]);
	}
	if (coin2_2 <= 1) {
		RenderCoin2(coinarr2_2[0]);
		RenderCoin2(coinarr2_2[1]);
		RenderCoin2(coinarr2_2[2]);
		RenderCoin2(coinarr2_2[3]);
		RenderCoin2(coinarr2_2[4]);
		RenderCoin2(coinarr2_2[5]);
		RenderCoin2(coinarr2_2[6]);
		RenderCoin2(coinarr2_2[7]);
		RenderCoin2(coinarr2_2[8]);
	}
	if (coin2_3 <= 1) {
		RenderCoin2(coinarr2_3[0]);
		RenderCoin2(coinarr2_3[1]);
		RenderCoin2(coinarr2_3[2]);
		RenderCoin2(coinarr2_3[3]);
		RenderCoin2(coinarr2_3[4]);
		RenderCoin2(coinarr2_3[5]);
		RenderCoin2(coinarr2_3[6]);
		RenderCoin2(coinarr2_3[7]);
		RenderCoin2(coinarr2_3[8]);
	}
	if (coin2_4 <= 1) {
		RenderCoin2(coinarr2_4[0]);
		RenderCoin2(coinarr2_4[1]);
		RenderCoin2(coinarr2_4[2]);
		RenderCoin2(coinarr2_4[3]);
		RenderCoin2(coinarr2_4[4]);
		RenderCoin2(coinarr2_4[5]);
		RenderCoin2(coinarr2_4[6]);
		RenderCoin2(coinarr2_4[7]);
		RenderCoin2(coinarr2_4[8]);
	}
	if (coin2_5 <= 1) {
		RenderCoin2(coinarr2_5[0]);
		RenderCoin2(coinarr2_5[1]);
		RenderCoin2(coinarr2_5[2]);
		RenderCoin2(coinarr2_5[3]);
		RenderCoin2(coinarr2_5[4]);
		RenderCoin2(coinarr2_5[5]);
		RenderCoin2(coinarr2_5[6]);
		RenderCoin2(coinarr2_5[7]);
		RenderCoin2(coinarr2_5[8]);
	}
	if (coin2_6 <= 1) {
		RenderCoin2(coinarr2_6[0]);
		RenderCoin2(coinarr2_6[1]);
		RenderCoin2(coinarr2_6[2]);
		RenderCoin2(coinarr2_6[3]);
		RenderCoin2(coinarr2_6[4]);
		RenderCoin2(coinarr2_6[5]);
		RenderCoin2(coinarr2_6[6]);
		RenderCoin2(coinarr2_6[7]);
		RenderCoin2(coinarr2_6[8]);
	}
	if (coin2_7 <= 1) {
		RenderCoin2(coinarr2_7[0]);
		RenderCoin2(coinarr2_7[1]);
		RenderCoin2(coinarr2_7[2]);
		RenderCoin2(coinarr2_7[3]);
		RenderCoin2(coinarr2_7[4]);
		RenderCoin2(coinarr2_7[5]);
		RenderCoin2(coinarr2_7[6]);
		RenderCoin2(coinarr2_7[7]);
		RenderCoin2(coinarr2_7[8]);
	}
	if (coin2_8 <= 1) {
		RenderCoin2(coinarr2_8[0]);
		RenderCoin2(coinarr2_8[1]);
		RenderCoin2(coinarr2_8[2]);
		RenderCoin2(coinarr2_8[3]);
		RenderCoin2(coinarr2_8[4]);
		RenderCoin2(coinarr2_8[5]);
		RenderCoin2(coinarr2_8[6]);
		RenderCoin2(coinarr2_8[7]);
		RenderCoin2(coinarr2_8[8]);
	}
	if (coin2_9 <= 1) {
		RenderCoin2(coinarr2_9[0]);
		RenderCoin2(coinarr2_9[1]);
		RenderCoin2(coinarr2_9[2]);
		RenderCoin2(coinarr2_9[3]);
		RenderCoin2(coinarr2_9[4]);
		RenderCoin2(coinarr2_9[5]);
		RenderCoin2(coinarr2_9[6]);
		RenderCoin2(coinarr2_9[7]);
		RenderCoin2(coinarr2_9[8]);
	}
	if (coin2_10 <= 1) {
		RenderCoin2(coinarr2_10[0]);
		RenderCoin2(coinarr2_10[1]);
		RenderCoin2(coinarr2_10[2]);
		RenderCoin2(coinarr2_10[3]);
		RenderCoin2(coinarr2_10[4]);
		RenderCoin2(coinarr2_10[5]);
		RenderCoin2(coinarr2_10[6]);
		RenderCoin2(coinarr2_10[7]);
		RenderCoin2(coinarr2_10[8]);
	}
	if (coin2_11 <= 1) {
		RenderCoin2(coinarr2_11[0]);
		RenderCoin2(coinarr2_11[1]);
		RenderCoin2(coinarr2_11[2]);
		RenderCoin2(coinarr2_11[3]);
		RenderCoin2(coinarr2_11[4]);
		RenderCoin2(coinarr2_11[5]);
		RenderCoin2(coinarr2_11[6]);
		RenderCoin2(coinarr2_11[7]);
		RenderCoin2(coinarr2_11[8]);
	}
	if (coin2_12 <= 1) {
		RenderCoin2(coinarr2_12[0]);
		RenderCoin2(coinarr2_12[1]);
		RenderCoin2(coinarr2_12[2]);
		RenderCoin2(coinarr2_12[3]);
		RenderCoin2(coinarr2_12[4]);
		RenderCoin2(coinarr2_12[5]);
		RenderCoin2(coinarr2_12[6]);
		RenderCoin2(coinarr2_12[7]);
		RenderCoin2(coinarr2_12[8]);
	}
	if (coin2_13 <= 1) {
		RenderCoin2(coinarr2_13[0]);
		RenderCoin2(coinarr2_13[1]);
		RenderCoin2(coinarr2_13[2]);
		RenderCoin2(coinarr2_13[3]);
		RenderCoin2(coinarr2_13[4]);
		RenderCoin2(coinarr2_13[5]);
		RenderCoin2(coinarr2_13[6]);
		RenderCoin2(coinarr2_13[7]);
		RenderCoin2(coinarr2_13[8]);
	}
	if (coin2_14 <= 1) {
		RenderCoin2(coinarr2_14[0]);
		RenderCoin2(coinarr2_14[1]);
		RenderCoin2(coinarr2_14[2]);
		RenderCoin2(coinarr2_14[3]);
		RenderCoin2(coinarr2_14[4]);
		RenderCoin2(coinarr2_14[5]);
		RenderCoin2(coinarr2_14[6]);
		RenderCoin2(coinarr2_14[7]);
		RenderCoin2(coinarr2_14[8]);
	}
}


int wallsXCords[][2][2] = {
	  { {-50,-50}, {0,-50} },
	  { {-40,-40}, {-30,-40} },
	  { {-30,-30}, {-20,-30} },
	  { {-50,-20}, {-30,-20} },
	  { {-20,-20}, {-10,-20} },
	  { {-10,-10}, {0,-10} },
	  { {-30,-10}, {-20,-10} },
	  { {-40,0}, {-30,0} },
	  { {-20,0}, {-10,0} },
	  { {-50,10}, {-40,10} },
	  { {-30,10}, {-20,10} },
	  { {-10,10}, {0,10} },
	  { {-40,20}, {-30,20} },
	  { {-20,20}, {-10,20} },
	  { {-40,30}, {-20,30} },
	  { {-30,40}, {-20,40} },
	  { {-50,50}, {0,50} },

	  { {2.5,50}, {11.5,50} },
	  { {3,38}, {11,38} }

};
int wallsZCords[][2][2] = {
	  { {-20,-50}, {-20,-40} },
	  { {-50,-40}, {-50,50} },
	  { {0,-50}, {0,40} },
	  { {-10,-40}, {-10,-20} },
	  { {-30,-40}, {-30,-10} },
	  { {-40,-40}, {-40,-30} },
	  { {-20,-20}, {-20,-10} },
	  { {-40,-10}, {-40,0} },
	  { {-30,0}, {-30,10} },
	  { {-10,0}, {-10,20} },
	  { {-20,10}, {-20,30} },
	  { {-40,20}, {-40,40} },
	  { {-10,30}, {-10,50} },
	  { {-30,40}, {-30,50} },

	   { {10,40}, {10,50} },
};

int wallsXCords2[][2][2] = {
 { {0,50}, {90,50} },
  { {20,40}, {50,40} },
  { {0,30}, {40,30} },
  { {10,20}, {90,20} },
  { {10,10}, {30,10} },
  { {50,10}, {80,10} },
  { {30,-20}, {60,-20} },
  { {0,-30}, {70,-30} },
  { {10,-40}, {80,-40} },
  { {20,-50}, {90,-50} },
  { {10,-60}, {80,-60} },
  { {10,-70}, {60,-70} },
  { {70,-70}, {90,-70} },
  { {50,-80}, {70,-80} },
  { {0,-90}, {90,-90} },
};
int wallsZCords2[][2][2] = {
  {  {60,30} ,{60,50}},
  {  {80,30} ,{80,50}},
  {  {50,20} ,{50,40}},
  {  {70,20} ,{70,40}},
  {  {90,-70},{90,50} },
  {  {0,-90} ,{0,50}},
  {  {40,-10} ,{40,20} },
  {  {10,-20} ,{10,10} },
  {  {30,-20} ,{30,10} },
  {  {50,-10} ,{50,10} },
  {  {80,-40} ,{80,10} },
  {  {20,-30} ,{20,0}},
  {  {60,-20} ,{60,0}},
  {  {70,-30} ,{70,0}},
  {  {10,-60}, {10,-40} },
  {  {70,-70}, {70,-60} },
  {  {10,-80}, {10,-70} },
  {  {30,-80}, {30,-70} },
  {  {50,-80}, {50,-70} },
  {  {20,-90}, {20,-80} },
  {  {40,-90}, {40,-80} },
  {  {70,-90}, {70,-80} },

};

void myDisplay(void)
{

	if (level == 1) {
		setupCamera();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (lights == 0) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			GLfloat light0Specular[] = { 1.0f, 0.6f, 0.3f, 0.0f };
			GLfloat light0Ambience[] = { 1.0f, 0.9f, 0.2f, 0.0f };
			GLfloat light0Position[] = { 0.8f, 0.9f, 0.6f, 0.0f };

			GLfloat light1Specular[] = { 1.0f, 0.4f, 0.4f, 1.0f };
			GLfloat light1Ambience[] = { 0.4f, 0.6f, 1.0f, 1.0f };
			GLfloat light1Position[] = { 1.0f, 0.6f, 0.2f, 1.0f };

			GLfloat light2Specular[] = { 1.0f, 0.5f, 0.2f, 1.0f };
			GLfloat light2Ambience[] = { 0.5f, 0.9f, 0.0f, 1.0f };
			GLfloat light2Position[] = { 1.0f, 0.7f, 0.3f, 1.0f };

			glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
			glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
			glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);

			glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambience);
			glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambience);
			glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambience);

			glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
			glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
			glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
		}
		else if (lights == 1) {
			GLfloat light0Specular[] = { 1.0f, 0.9f, 0.2f, 1.0f };
			GLfloat light0Ambience[] = { 0.5f, 0.9f, 0.2f, 1.0f };
			GLfloat light0Position[] = { 0.5f, 0.9f, 0.2f, 1.0f };

			GLfloat light1Specular[] = { 1.0f, 0.9f, 0.6f, 1.0f };
			GLfloat light1Ambience[] = { 0.3f, 0.9f, 0.3f, 1.0f };
			GLfloat light1Position[] = { 0.7f, 0.9f, 0.0f, 1.0f };

			GLfloat light2Specular[] = { 1.0f, 0.9f, 0.0f, 1.0f };
			GLfloat light2Ambience[] = { 0.5f, 0.5f, 0.2f, 1.0f };
			GLfloat light2Position[] = { 1.0f, 1.0f, 0.5f, 1.0f };

			glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
			glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
			glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);

			glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambience);
			glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambience);
			glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambience);

			glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
			glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
			glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
		}

		if (switchCameraMode == 0) {
			//print score
			glColor3f(1, 0, 0);
			char* p0s[20];
			sprintf((char*)p0s, "Score: %d", score);
			print(charcterX, charcterY + 6.1, charcterZ, (char*)p0s);

			//print time
			glColor3f(1, 1, 1);
			char* p1s[20];
			sprintf((char*)p1s, "Time:%d:%d", Minutes, seconds);
			print(charcterX, charcterY + 5.9, charcterZ, (char*)p1s);

			//Level
			glColor3f(1, 0, 1);
			char* p2s[20];
			sprintf((char*)p2s, "Level:%d", level);
			print(charcterX, charcterY + 6.3, charcterZ, (char*)p2s);
		}
		else {
			//print score
			glColor3f(0, 0, 0);
			char* p0s[20];
			sprintf((char*)p0s, "Score: %d", score);
			print(charcterX + 3, charcterY + 6.1, charcterZ, (char*)p0s);

			//print time
			glColor3f(1, 1, 1);
			char* p1s[20];
			sprintf((char*)p1s, "Time:%d:%d", Minutes, seconds);
			print(charcterX + 3, charcterY + 5.9, charcterZ, (char*)p1s);

			//Level
			glColor3f(1, 0, 1);
			char* p2s[20];
			sprintf((char*)p2s, "Level:%d", level);
			print(charcterX + 3, charcterY + 6.3, charcterZ, (char*)p2s);
		}

		// Draw Ground
		RenderGround();

		//Draw Maze walls
		glPushMatrix();
		glTranslatef(85, 4, 40);
		glScalef(1, 3, 1);
		DrawMaze();
		glPopMatrix();


		//Draw gate
		glPushMatrix();
		glTranslatef(34, 5, -5);
		glRotatef(90, 0, 1, 0);
		glRotatef(90, 1, 0, 0);
		glScalef(0.08, 0.1, 0.1);
		model_gate1.Draw();
		glPopMatrix();

		//Draw obstacle
		DrawObstacle();

		//Draw coin
		DrawCoin();

		//draw human model 
		glPushMatrix();
		glTranslatef(charcterX, charcterY, charcterZ);
		glScalef(0.5, 0.5, 0.5);

		if (characterDirection == 90 || characterDirection == 270) {
			glRotatef(180, 0, 1, 0);
		}
		glRotatef(characterDirection, 0, 1, 0);
		glRotatef(270, 0, 1, 0);
		glRotatef(90, 1, 0, 0);

		model_pikachu.Draw();
		glPopMatrix();

		glutSwapBuffers();
	}
	else if (level == 2) {

		setupCamera();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (lights == 0) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			GLfloat light0Specular[] = { 1.0f, 0.6f, 0.0f, 0.0f };
			GLfloat light0Ambience[] = { 0.4f, 0.4f, 0.2f, 0.0f };
			GLfloat light0Position[] = { 0.6f, 1.0f, 0.4f, 0.0f };

			GLfloat light1Specular[] = { 1.0f, 0.4f, 0.6f, 1.0f };
			GLfloat light1Ambience[] = { 0.4f, 0.6f, 1.0f, 1.0f };
			GLfloat light1Position[] = { 1.0f, 0.7f, 0.2f, 1.0f };

			GLfloat light2Specular[] = { 1.0f, 0.7f, 0.2f, 1.0f };
			GLfloat light2Ambience[] = { 0.5f, 0.6f, 0.0f, 1.0f };
			GLfloat light2Position[] = { 1.0f, 0.6f, 0.4f, 1.0f };

			glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
			glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
			glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);

			glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambience);
			glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambience);
			glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambience);

			glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
			glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
			glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
		}
		else if (lights == 1) {
			GLfloat light0Specular[] = { 0.6f, 0.9f, 1.0f, 1.0f };
			GLfloat light0Ambience[] = { 0.7f, 1.0f, 1.0f, 1.0f };
			GLfloat light0Position[] = { 1.0f, 0.8f, 1.0f, 1.0f };

			GLfloat light1Specular[] = { 1.0f, 0.5f, 0.4f, 1.0f };
			GLfloat light1Ambience[] = { 0.4f, 0.2f, 0.5f, 1.0f };
			GLfloat light1Position[] = { 0.9f, 1.0f, 1.0f, 1.0f };

			GLfloat light2Specular[] = { 1.0f, 1.0f, 0.4f, 1.0f };
			GLfloat light2Ambience[] = { 1.0f, 1.0f, 0.1f, 1.0f };
			GLfloat light2Position[] = { 0.5f, 0.6f, 1.0f, 1.0f };

			glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
			glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
			glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);

			glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambience);
			glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambience);
			glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambience);

			glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
			glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
			glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
		}

		if (switchCameraMode == 0) {
			//print score
			glColor3f(1, 0, 0);
			char* p0s[20];
			sprintf((char*)p0s, "Score: %d", score);
			print(charcterX, charcterY + 6.1, charcterZ, (char*)p0s);

			//print time
			glColor3f(1, 1, 1);
			char* p1s[20];
			sprintf((char*)p1s, "Time:%d:%d", Minutes, seconds);
			print(charcterX, charcterY + 5.9, charcterZ, (char*)p1s);

			//Level
			glColor3f(1, 0, 1);
			char* p2s[20];
			sprintf((char*)p2s, "Level:%d", level);
			print(charcterX, charcterY + 6.3, charcterZ, (char*)p2s);
		}
		else {
			//print score
			glColor3f(1, 0, 0);
			char* p0s[20];
			sprintf((char*)p0s, "Score: %d", score);
			print(charcterX + 3, charcterY + 6.1, charcterZ, (char*)p0s);

			//print time
			glColor3f(1, 1, 1);
			char* p1s[20];
			sprintf((char*)p1s, "Time:%d:%d", Minutes, seconds);
			print(charcterX + 3, charcterY + 5.9, charcterZ, (char*)p1s);

			//Level
			glColor3f(1, 0, 1);
			char* p2s[20];
			sprintf((char*)p2s, "Level:%d", level);
			print(charcterX + 3, charcterY + 6.3, charcterZ, (char*)p2s);
		}

		// Draw Ground
		RenderGround();

		//Draw Maze walls
		glPushMatrix();
		glTranslatef(-30, 4, 40);
		glScalef(1, 3, 1);
		DrawMaze2();
		glPopMatrix();

		//Draw gate
		glPushMatrix();
		glTranslatef(60, 0, -40);
		glRotatef(90, 0, 1, 0);
		glRotatef(90, 1, 0, 0);
		glScalef(0.020, 0.005, 0.020);
		model_gate2.Draw();
		glPopMatrix();


		//Draw obstacle
		DrawObstacle2();

		//Draw coin
		DrawCoin2();

		//draw human model 
		glPushMatrix();
		glTranslatef(charcterX, charcterY, charcterZ);
		glScalef(0.5, 0.5, 0.5);

		if (characterDirection == 90 || characterDirection == 270) {
			glRotatef(180, 0, 1, 0);
		}
		glRotatef(characterDirection, 0, 1, 0);
		glRotatef(270, 0, 1, 0);
		glRotatef(90, 1, 0, 0);

		model_pikachu.Draw();
		glPopMatrix();

		glutSwapBuffers();
	}
	else if (level == 3) {
	setupCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (lights == 0) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		GLfloat light0Specular[] = { 1.0f, 0.6f, 0.0f, 0.0f };
		GLfloat light0Ambience[] = { 0.4f, 0.4f, 0.2f, 0.0f };
		GLfloat light0Position[] = { 0.6f, 1.0f, 0.4f, 0.0f };

		GLfloat light1Specular[] = { 1.0f, 0.4f, 0.6f, 1.0f };
		GLfloat light1Ambience[] = { 0.4f, 0.6f, 1.0f, 1.0f };
		GLfloat light1Position[] = { 1.0f, 0.7f, 0.2f, 1.0f };

		GLfloat light2Specular[] = { 1.0f, 0.7f, 0.2f, 1.0f };
		GLfloat light2Ambience[] = { 0.5f, 0.6f, 0.0f, 1.0f };
		GLfloat light2Position[] = { 1.0f, 0.6f, 0.4f, 1.0f };

		glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);

		glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambience);
		glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambience);
		glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambience);

		glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
		glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
		glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
	}
	else if (lights == 1) {
		GLfloat light0Specular[] = { 0.6f, 0.9f, 1.0f, 1.0f };
		GLfloat light0Ambience[] = { 0.7f, 1.0f, 1.0f, 1.0f };
		GLfloat light0Position[] = { 1.0f, 0.8f, 1.0f, 1.0f };

		GLfloat light1Specular[] = { 1.0f, 0.5f, 0.4f, 1.0f };
		GLfloat light1Ambience[] = { 0.4f, 0.2f, 0.5f, 1.0f };
		GLfloat light1Position[] = { 0.9f, 1.0f, 1.0f, 1.0f };

		GLfloat light2Specular[] = { 1.0f, 1.0f, 0.4f, 1.0f };
		GLfloat light2Ambience[] = { 1.0f, 1.0f, 0.1f, 1.0f };
		GLfloat light2Position[] = { 0.5f, 0.6f, 1.0f, 1.0f };

		glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);

		glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambience);
		glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambience);
		glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambience);

		glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
		glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
		glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
	}

		if (switchCameraMode == 0) {

			//print score
			glColor3f(1, 0, 0);
			char* p0s[20];
			sprintf((char*)p0s, "Score: %d", score);
			print(charcterX, charcterY + 3.5, charcterZ, (char*)p0s);

			//print time
			glColor3f(1, 1, 1);
			char* p1s[20];
			sprintf((char*)p1s, "Time:%d:%d", Minutes, seconds);
			print(charcterX, charcterY + 3.3, charcterZ, (char*)p1s);

			//YOU WIN
			glColor3f(1, 1, 1);
			char* p2s[20];
			sprintf((char*)p2s, "YOU WIN");
			print(charcterX, charcterY + 3.8, charcterZ, (char*)p2s);
		}
		else {
			//print score
			glColor3f(1, 0, 0);
			char* p0s[20];
			sprintf((char*)p0s, "Score: %d", score);
			print(charcterX, charcterY + 3.5, charcterZ, (char*)p0s);

			//print time
			glColor3f(1, 1, 1);
			char* p1s[20];
			sprintf((char*)p1s, "Time:%d:%d", Minutes, seconds);
			print(charcterX, charcterY + 3.3, charcterZ, (char*)p1s);

			//YOU WIN
			glColor3f(1, 1, 1);
			char* p2s[20];
			sprintf((char*)p2s, "YOU WIN");
			print(charcterX, charcterY + 3.8, charcterZ, (char*)p2s);

		}
	}

}


void LoadAssets()
{
	// Loading Model files
	model_gate1.Load("Models/gate1/gate1.3DS");
	model_gate2.Load("Models/gate2/gate2.3DS");
	model_pikachu.Load("Models/Pikachu/pikachu.3DS");
	model_obs1.Load("Models/obs1/obs1.3DS");
	model_obs2.Load("Models/obs2/obs2.3DS");
	model_coin.Load("Models/coin/coin.3DS");
	// Loading texture files
	tex_ground.Load("textures/sahara.bmp");
	tex_ground1.Load("textures/ground.bmp");
	loadBMP(&tex, "Textures/blu-sky-3.bmp", true);
}


void DetectCoinsCollision() {
	glEnable(GL_LIGHTING);	// Enable lighting
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (level == 1) {

		if (coin1_1 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_1[i][0];
				int coinz = coinarr1_1[i][1];
				int coiny = coinarr1_1[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_1[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin1_2 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_2[i][0];
				int coinz = coinarr1_2[i][1];
				int coiny = coinarr1_2[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_2[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin1_3 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_3[i][0];
				int coinz = coinarr1_3[i][1];
				int coiny = coinarr1_3[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_3[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin1_4 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_4[i][0];
				int coinz = coinarr1_4[i][1];
				int coiny = coinarr1_4[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_4[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin1_5 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_5[i][0];
				int coinz = coinarr1_5[i][1];
				int coiny = coinarr1_5[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_5[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin1_6 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_6[i][0];
				int coinz = coinarr1_6[i][1];
				int coiny = coinarr1_6[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_6[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
				}
			}
		}
		if (coin1_7 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_7[i][0];
				int coinz = coinarr1_7[i][1];
				int coiny = coinarr1_7[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_7[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin1_8 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_8[i][0];
				int coinz = coinarr1_8[i][1];
				int coiny = coinarr1_8[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_8[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}
		if (coin1_9 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_9[i][0];
				int coinz = coinarr1_9[i][1];
				int coiny = coinarr1_9[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_9[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
				}
			}

		}
		if (coin1_10 < 2) {
			for (int i = 0; i < 5; i++) {
				int coinx = coinarr1_10[i][0];
				int coinz = coinarr1_10[i][1];
				int coiny = coinarr1_10[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx + 85 - 2 && charcterX < coinx + 85 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr1_10[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}

	}

	else if (level == 2) {

		if (coin2_1 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_1[i][0];
				int coinz = coinarr2_1[i][1];
				int coiny = coinarr2_1[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_1[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin2_2 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_2[i][0];
				int coinz = coinarr2_2[i][1];
				int coiny = coinarr2_2[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_2[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin2_3 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_3[i][0];
				int coinz = coinarr2_3[i][1];
				int coiny = coinarr2_3[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_3[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin2_4 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_4[i][0];
				int coinz = coinarr2_4[i][1];
				int coiny = coinarr2_4[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_4[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin2_5 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_5[i][0];
				int coinz = coinarr2_5[i][1];
				int coiny = coinarr2_5[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_5[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin2_6 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_6[i][0];
				int coinz = coinarr2_6[i][1];
				int coiny = coinarr2_6[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_6[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin2_7 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_7[i][0];
				int coinz = coinarr2_7[i][1];
				int coiny = coinarr2_7[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_7[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}
		}
		if (coin2_8 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_8[i][0];
				int coinz = coinarr2_8[i][1];
				int coiny = coinarr2_8[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_8[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}
		if (coin2_9 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_9[i][0];
				int coinz = coinarr2_9[i][1];
				int coiny = coinarr2_9[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_9[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}
		if (coin2_10 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_10[i][0];
				int coinz = coinarr2_10[i][1];
				int coiny = coinarr2_10[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_10[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}
		if (coin2_11 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_11[i][0];
				int coinz = coinarr2_11[i][1];
				int coiny = coinarr2_11[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_11[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}
		if (coin2_12 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_12[i][0];
				int coinz = coinarr2_12[i][1];
				int coiny = coinarr2_12[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_12[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}
		if (coin2_13 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_13[i][0];
				int coinz = coinarr2_13[i][1];
				int coiny = coinarr2_13[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_13[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}
		if (coin2_14 < 2) {
			for (int i = 0; i < 9; i++) {
				int coinx = coinarr2_14[i][0];
				int coinz = coinarr2_14[i][1];
				int coiny = coinarr2_14[i][2];
				if (charcterY < coiny + 1 && (charcterX > coinx - 30 - 2 && charcterX < coinx - 30 + 2) &&
					(charcterZ > coinz + 40 - 2 && charcterZ < coinz + 40 + 2)) {
					coinarr2_14[i][2] = -10;
					score++;
					//sound coins here
					//lights coins here
					PlaySound(TEXT("sounds/coin.wav"), NULL, SND_ASYNC);
					lights = 1;
					return;
				}
			}

		}
	}

}



float DetectObstacleCollision(char axis, float magnitude) {

	if (level == 1) {

		if (axis == 'x') {
			float tempx = charcterX + magnitude;

			if (obstacle1_1 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_1[i][0] + 85;
					int obsz = ob1_1[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 2.5 || tempx == obsx - 0.5) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_2 < 2) {

				for (int i = 0; i < 3; i++) {

					int obsx = ob1_2[i][0] + 85;
					int obsz = ob1_2[i][1] + 40;

					if (charcterY < 1.5 && (tempx == obsx + 2.5 || tempx == obsx - 0.5) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_3 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_3[i][0] + 85;
					int obsz = ob1_3[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 2.5 || tempx == obsx - 0.5) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_4 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_4[i][0] + 85;
					int obsz = ob1_4[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 2.5 || tempx == obsx - 0.5) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_5 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_5[i][0] + 85;
					int obsz = ob1_5[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 2.5 || tempx == obsx - 0.5) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_6 < 2) {
				for (int i = 0; i < 2; i++) {
					int obsx = ob1_6[i][0] + 85;
					int obsz = ob1_6[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 2.5 || tempx == obsx - 0.5) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
		}

		else if (axis == 'z') {
			float tempz = charcterZ + magnitude;

			if (obstacle1_7 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_7[i][0] + 85;
					int obsz = ob1_7[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 2.5) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_8 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_8[i][0] + 85;
					int obsz = ob1_8[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 2.5) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_9 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_9[i][0] + 85;
					int obsz = ob1_9[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 2.5) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_10 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_10[i][0] + 85;
					int obsz = ob1_10[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 2.5) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_11 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_11[i][0] + 85;
					int obsz = ob1_11[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 2.5) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_12 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_12[i][0] + 85;
					int obsz = ob1_12[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 2.5) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle1_13 < 2) {
				for (int i = 0; i < 3; i++) {
					int obsx = ob1_13[i][0] + 85;
					int obsz = ob1_13[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 2.5) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle here
						//lights obstacle here
						PlaySound(TEXT("sounds/Collision1.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}

		}


	}
	else if (level == 2) {

		if (axis == 'z') {
			float tempz = charcterZ + magnitude;

			if (obstacle2_7 < 2) {
				for (int i = 0; i < 5; i++) {
					int obsx = ob2_7[i][0] - 30;
					int obsz = ob2_7[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 1) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle2_8 < 2) {
				for (int i = 0; i < 5; i++) {
					int obsx = ob2_8[i][0] - 30;
					int obsz = ob2_8[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 1) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle2_9 < 2) {
				for (int i = 0; i < 5; i++) {
					int obsx = ob2_9[i][0] - 30;
					int obsz = ob2_9[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 1) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle2_10 < 2) {
				for (int i = 0; i < 4; i++) {
					int obsx = ob2_10[i][0] - 30;
					int obsz = ob2_10[i][1] + 40;
					if (charcterY < 1.5 && (tempz == obsz + 0.5 || tempz == obsz - 1) && charcterX<obsx + 2.5 && charcterX>obsx - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}

		}

		else if (axis == 'x') {
			float tempx = charcterX + magnitude;

			if (obstacle2_1 < 2) {
				for (int i = 0; i < 5; i++) {

					int obsx = ob2_1[i][0] - 30;
					int obsz = ob2_1[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 0.5 || tempx == obsx - 1) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle2_2 < 2) {
				for (int i = 0; i < 5; i++) {

					int obsx = ob2_2[i][0] - 30;
					int obsz = ob2_2[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 0.5 || tempx == obsx - 1) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle2_3 < 2) {
				for (int i = 0; i < 5; i++) {

					int obsx = ob2_3[i][0] - 30;
					int obsz = ob2_3[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 0.5 || tempx == obsx - 1) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle2_4 < 2) {
				for (int i = 0; i < 5; i++) {

					int obsx = ob2_4[i][0] - 30;
					int obsz = ob2_4[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 0.5 || tempx == obsx - 1) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle2_5 < 2) {
				for (int i = 0; i < 5; i++) {

					int obsx = ob2_5[i][0] - 30;
					int obsz = ob2_5[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 0.5 || tempx == obsx - 1) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}
			if (obstacle2_6 < 2) {
				for (int i = 0; i < 6; i++) {

					int obsx = ob2_6[i][0] - 30;
					int obsz = ob2_6[i][1] + 40;
					if (charcterY < 1.5 && (tempx == obsx + 0.5 || tempx == obsx - 1) && charcterZ<obsz + 2.5 && charcterZ>obsz - 2.5) {
						score--;
						//sound obstacle2 here
						//lights obstacle2 here
						PlaySound(TEXT("sounds/Collision2.wav"), NULL, SND_ASYNC);
						return -magnitude * 3;
					}
				}
			}

		}


	}


	return magnitude;
}


float DetectWallCollision(char axis, float magnitude) {

	if (level == 1) {
		if (axis == 'x') {
			float tempx = charcterX + magnitude;

			for (int i = 0; i < sizeof(wallsXCords) / 16; i++) {

				if (charcterZ > wallsXCords[i][0][1] + 40 + 3 - 6.5 && charcterZ < wallsXCords[i][0][1] + 40 + 3.5
					&& (tempx == wallsXCords[i][0][0] + 85 - 3 || tempx == wallsXCords[i][1][0] + 85 + 1)) {
					return -magnitude;
				}

			}

			for (int i = 0; i < sizeof(wallsZCords) / 16; i++) {
				if (charcterZ > wallsZCords[i][0][1] + 40 - 3.5 && charcterZ < wallsZCords[i][1][1] + 40 + 1.5
					&& (tempx == wallsZCords[i][0][0] + 85 + 3 || tempx == wallsZCords[i][0][0] + 85 + 3 - 6)
					) {
					return -magnitude;
				}
			}

			if (tempx == 34.0 && charcterZ >= -6.5 && charcterZ <= -3.5) {
				camera = Camera(-32.0, 13.0, 80.0, 32.0, 13.0, 80.0, 0.0, 1.0, 0.0);
				cammeraFirstPerson = Camera(-29.0, 13.0, 80, 29.0, 13.0, 80.0, 0.0, 1.0, 0.0);
				characterDirection = 180;
				charcterX = -26.0;
				charcterZ = 80;
				charcterY = 10;

				level++;
				newStart = 1;
				//sound level complete here
				//lights level complete here
				PlaySound(TEXT("sounds/LevelComplete.wav"), NULL, SND_ASYNC);
				return 0;

			}

		}
		else {
			float tempz = charcterZ + magnitude;

			for (int i = 0; i < sizeof(wallsZCords) / 16; i++) {
				if (charcterX > wallsZCords[i][0][0] + 85 + 3 - 6.5 && charcterX < wallsZCords[i][0][0] + 85 + 3.5
					&& (tempz == wallsZCords[i][0][1] + 40 - 3 || tempz == wallsZCords[i][1][1] + 40 + 1)) {
					return -magnitude;
				}

			}

			for (int i = 0; i < sizeof(wallsXCords) / 16; i++) {

				if (charcterX > wallsXCords[i][0][0] + 85 - 3.5 && charcterX < wallsXCords[i][1][0] + 85 + 1.5
					&& (tempz == wallsXCords[i][0][1] + 40 + 3 || tempz == wallsXCords[i][0][1] + 40 + 3 - 6)
					) {
					return -magnitude;
				}
			}

		}
	}

	else
		if (level == 2) {
			if (axis == 'x') {
				float tempx = charcterX + magnitude;

				for (int i = 0; i < sizeof(wallsXCords2) / 16; i++) {
					if (charcterZ > wallsXCords2[i][0][1] + 40 + 3 - 6.5 && charcterZ < wallsXCords2[i][0][1] + 40 + 3.5
						&& (tempx == wallsXCords2[i][0][0] - 30 - 3 || tempx == wallsXCords2[i][1][0] - 30 + 1)) {
						return -magnitude;
					}

				}

				for (int i = 0; i < sizeof(wallsZCords2) / 16; i++) {
					if (charcterZ > wallsZCords2[i][0][1] + 40 - 3.5 && charcterZ < wallsZCords2[i][1][1] + 40 + 1.5
						&& (tempx == wallsZCords2[i][0][0] - 30 + 3 || tempx == wallsZCords2[i][0][0] - 30 + 3 - 6)
						) {
						return -magnitude;
					}
				}

				if (tempx == 60.0 && charcterZ >= -47 && charcterZ <= -33) {
					level++;
					//sound game over here
					//game over
					PlaySound(TEXT("sounds/GameOver.wav"), NULL, SND_ASYNC);
				}

			}
			else {
				float tempz = charcterZ + magnitude;

				for (int i = 0; i < sizeof(wallsZCords2) / 16; i++) {
					if (charcterX > wallsZCords2[i][0][0] - 30 + 3 - 6.5 && charcterX < wallsZCords2[i][0][0] - 30 + 3.5
						&& (tempz == wallsZCords2[i][0][1] + 40 - 3 || tempz == wallsZCords2[i][1][1] + 40 + 1)) {
						return -magnitude;
					}

				}

				for (int i = 0; i < sizeof(wallsXCords2) / 16; i++) {

					if (charcterX > wallsXCords2[i][0][0] - 30 - 3.5 && charcterX < wallsXCords2[i][1][0] - 30 + 1.5
						&& (tempz == wallsXCords2[i][0][1] + 40 + 3 || tempz == wallsXCords2[i][0][1] + 40 + 3 - 6)
						) {
						return -magnitude;
					}
				}

			}
		}


	return DetectObstacleCollision(axis, magnitude);
}

bool canMove = 1; //changes on click mouse
void Keyboard(unsigned char key, int x, int y) {
	float d = 0.5;
	float temp;

	if (canMove) {


		switch (key) {
		case 'c':
			switchCameraMode = !switchCameraMode;
			glutPostRedisplay();
			break;
		case 'z':
			printf("here: x=%f   z=%f   y=%f  score=%d \n", charcterX, charcterZ, charcterY, score);
			break;
		case GLUT_KEY_SPACEBAR: //jump
			jumpUp = 1;
			//sound jump here
			PlaySound(TEXT("sounds/jump.wav"), NULL, SND_ASYNC);
			break;
		case 'q': //left  //rotate the whole object and adjust camera to look at its back
			if (characterDirection == 0) {
				characterDirection = 270;
			}
			else {
				characterDirection += -90;
			}
			camera.rotateY(90);
			camera.moveX(-6);
			camera.moveZ(-6);
			cammeraFirstPerson.rotateY(90);
			cammeraFirstPerson.moveX(-3);
			cammeraFirstPerson.moveZ(-3);

			glutPostRedisplay();
			break;
		case 'e': //right
			if (characterDirection == 270) {
				characterDirection = 0;
			}
			else {
				characterDirection += 90;
			}
			camera.rotateY(-90);
			camera.moveX(6);
			camera.moveZ(-6);
			cammeraFirstPerson.rotateY(-90);
			cammeraFirstPerson.moveX(3);
			cammeraFirstPerson.moveZ(-3);

			glutPostRedisplay();
			break;
		case GLUT_KEY_ESCAPE:
			exit(EXIT_SUCCESS);
		}


		if (characterDirection == 0) {

			switch (key) {
			case 'w':
				temp = DetectWallCollision('x', -d);
				camera.moveZ(-temp);
				cammeraFirstPerson.moveZ(-temp);
				charcterX += temp;  //front
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 's':
				temp = DetectWallCollision('x', d);
				camera.moveZ(-temp);
				cammeraFirstPerson.moveZ(-temp);
				charcterX += temp;  //back
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 'a':
				temp = DetectWallCollision('z', d);
				camera.moveX(temp);
				cammeraFirstPerson.moveX(temp);
				charcterZ += temp; //left
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 'd':
				temp = DetectWallCollision('z', -d);
				camera.moveX(temp);
				cammeraFirstPerson.moveX(temp);
				charcterZ += temp; //right
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			}

		}
		else if (characterDirection == 90) {

			switch (key) {
			case 'w':
				temp = DetectWallCollision('z', -d);
				camera.moveZ(-temp);
				cammeraFirstPerson.moveZ(-temp);
				charcterZ += temp; //right
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 's':
				temp = DetectWallCollision('z', d);
				camera.moveZ(-temp);
				cammeraFirstPerson.moveZ(-temp);
				charcterZ += temp; //left
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 'a':
				temp = DetectWallCollision('x', -d);
				camera.moveX(-temp);
				cammeraFirstPerson.moveX(-temp);
				charcterX += temp;  //front
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 'd':
				temp = DetectWallCollision('x', d);
				camera.moveX(-temp);
				cammeraFirstPerson.moveX(-temp);
				charcterX += temp;  //back
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			}

		}
		else if (characterDirection == 180) {

			switch (key) {
			case 'w':
				temp = DetectWallCollision('x', d);
				camera.moveZ(temp);
				cammeraFirstPerson.moveZ(temp);
				charcterX += temp;  //back
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 's':
				temp = DetectWallCollision('x', -d);
				camera.moveZ(temp);
				cammeraFirstPerson.moveZ(temp);
				charcterX += temp;  //front
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 'a':
				temp = DetectWallCollision('z', -d);
				camera.moveX(-temp);
				cammeraFirstPerson.moveX(-temp);
				charcterZ += temp; //right
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 'd':
				temp = DetectWallCollision('z', d);
				camera.moveX(-temp);
				cammeraFirstPerson.moveX(-temp);
				charcterZ += temp; //left
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			}

		}
		else if (characterDirection == 270) {

			switch (key) {
			case 'w':
				temp = DetectWallCollision('z', d);
				camera.moveZ(temp);
				cammeraFirstPerson.moveZ(temp);
				charcterZ += temp; //left
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 's':
				temp = DetectWallCollision('z', -d);
				camera.moveZ(temp);
				cammeraFirstPerson.moveZ(temp);
				charcterZ += temp; //right
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 'a':
				temp = DetectWallCollision('x', d);
				camera.moveX(temp);
				cammeraFirstPerson.moveX(temp);
				charcterX += temp;  //back
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			case 'd':
				temp = DetectWallCollision('x', -d);
				camera.moveX(temp);
				cammeraFirstPerson.moveX(temp);
				charcterX += temp;  //front	
				DetectCoinsCollision();
				glutPostRedisplay();
				break;
			}

		}


	}

}




void Special(int key, int x, int y) {
	float a = 1.0 * 10;

	switch (key) {
	case GLUT_KEY_UP:
		camera.rotateX(a);
		break;
	case GLUT_KEY_DOWN:
		camera.rotateX(-a);
		break;
	case GLUT_KEY_LEFT:
		camera.rotateY(a);
		break;
	case GLUT_KEY_RIGHT:
		camera.rotateY(-a);
		break;
	}

	glutPostRedisplay();
}


void Mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		canMove = 0;
		camera.rotateY(90);
		camera.moveX(-6);
		camera.moveZ(-6);
		cammeraFirstPerson.rotateY(90);
		cammeraFirstPerson.moveX(-3);
		cammeraFirstPerson.moveZ(-3);
		glutPostRedisplay();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		canMove = 1;
		cammeraFirstPerson.moveZ(3);
		cammeraFirstPerson.moveX(3);
		cammeraFirstPerson.rotateY(-90);
		camera.moveZ(6);
		camera.moveX(6);
		camera.rotateY(-90);
		glutPostRedisplay();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		canMove = 0;
		camera.rotateY(-90);
		camera.moveX(6);
		camera.moveZ(-6);
		cammeraFirstPerson.rotateY(-90);
		cammeraFirstPerson.moveX(3);
		cammeraFirstPerson.moveZ(-3);
		glutPostRedisplay();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		canMove = 1;
		cammeraFirstPerson.moveZ(3);
		cammeraFirstPerson.moveX(-3);
		cammeraFirstPerson.rotateY(90);
		camera.moveZ(6);
		camera.moveX(-6);
		camera.rotateY(90);
		glutPostRedisplay();
	}
}

void Timer2(int t) {
	if (prevlights == 1) {
		lights = 0;
		prevlights = 0;

	}
	else if (lights == 1) {
		prevlights = 1;
	}
	glutPostRedisplay();
	glutTimerFunc(400, Timer2, 0);
}

void Timer(int value) {

	if (newStart == 1) {

		if (charcterY > 0) {
			charcterY -= 0.2;
			camera.moveY(-0.2);
			cammeraFirstPerson.moveY(-0.2);
		}
		else {
			newStart = 0;
		}

	}


	if (jumpUp == 1) {
		if (charcterY < 3) {
			charcterY += 0.1;
			camera.moveY(0.1);
			cammeraFirstPerson.moveY(0.1);
		}
		else {
			jumpUp = 0;
			glutPostRedisplay();
			glutTimerFunc(400, Timer, 0);
			return;
		}
	}
	else {
		if (charcterY > 0) {
			charcterY -= 0.1;
			camera.moveY(-0.1);
			cammeraFirstPerson.moveY(-0.1);
		}
	}

	glutPostRedisplay();
	glutTimerFunc(5, Timer, 0);

}

void Timer3(int value) {
	if (level != 3) {

		if (seconds >= 60) {
			Minutes += 1;
			seconds = 0;
		}
		else if (milisec >= 60) {
			seconds += 1;
			milisec = 0;

		}
		else {
			milisec += 1;
		}
		glutPostRedisplay();
		glutTimerFunc(5, Timer3, 0);
	}
}
void print(float x, float y, float z, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos3f(x, y, z);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);

	}
}

void main(int argc, char** argv)
{
	srand(time(NULL));

	obstaclePosition();

	coinPosition();

	obstaclePosition2();

	coinPosition2();

	glutInit(&argc, argv);



	glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(WIDTH, HEIGHT);

	glutInitWindowPosition(100, 150);

	glutCreateWindow("Maze runner");

	glutDisplayFunc(myDisplay);

	glutKeyboardFunc(Keyboard);
	//glutSpecialFunc(Special);

	glutMouseFunc(Mouse);

	glutTimerFunc(0, Timer, 0); // sets the Timer handler function; which runs every `Threshold` milliseconds (1st argument)
	glutTimerFunc(0, Timer2, 0);
	glutTimerFunc(0, Timer3, 0);

	InitLightSource();
	InitMaterial();

	LoadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();


}