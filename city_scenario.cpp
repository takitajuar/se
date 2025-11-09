#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;

// Global variables for day/night and animations
bool isDay = true;

// Sun variables
float moveSun = 0.0f;
float sunSpeed =0.3f;
float savedSunSpeed = 0.0f;
bool sunPaused = false;

// Moon variables
float moveMoon = 0;
float moonSpeed =0.3f;
float savedMoonSpeed = 0.0f;
bool moonPaused = false;

// Cloud variables
float V_moveCloud1 = 0.0f;
float V_cloudSpeed1 =1.0f;
float V_savedCloudSpeed1 = 0.0f;
bool V_cloudPaused1 = false;

float V_moveCloud2 = 0.0f;
float V_cloudSpeed2 =1.0f;
float V_savedCloudSpeed2 = 0.0f;
bool V_cloudPaused2 = false;

float V_moveCloud3 = 0.0f;
float V_cloudSpeed3 =1.0f;
float V_savedCloudSpeed3 = 0.0f;
bool V_cloudPaused3 = false;

float V_moveCloud4 = 0.0f;
float V_cloudSpeed4 =1.0f;
float V_savedCloudSpeed4 = 0.0f;
bool V_cloudPaused4 = false;

// Train variables
float moveTrain = 0.0f;
float trainSpeed = 1.0f;
float savedTrainSpeed = 0.0f;
bool trainPaused = false;

// Bus variables
float V_moveBus = 0.0f;
float V_busSpeed = 1.0f;
float V_savedBusSpeed = 0.0f;
float V_busTireAngle = 0.0f;
bool V_busPaused = false;

// Cargo truck variables
float V_moveCargo = 0.0f;
float V_cargoSpeed = 1.0f;
float V_savedCargoSpeed = 0.0f;
float V_cargoTireAngle = 0.0f;
bool V_cargoPaused = false;

/// Circle function
void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

/// Sun function
void sun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(moveSun, 0, 0);
        glColor3f(1,1,0);
        circle(50,650,35);
        glPopMatrix();
    }
}

void updateSun(int value)
{
    if(!sunPaused)
    {
        moveSun += sunSpeed;
        if (moveSun > 1050)
        {
            moveSun = -200;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, updateSun, 0);
}

/// Moon function
void moon()
{
    if(!isDay)
    {
        glPushMatrix();
        glTranslatef(moveMoon, 0, 0);

        glColor3f(1,1,1);
        circle(850,650,40);

        glColor3f(0.10f, 0.13f, 0.22f);
        circle(860,660,40);
        glPopMatrix();
    }
}

void updateMoon(int value)
{
    if(!moonPaused)
    {
        moveMoon -= moonSpeed;
        if (moveMoon < -940)
        {
            moveMoon = 200;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, updateMoon, 0);
}

/// Sky function
void sky()
{
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);

    glVertex2f(0,   200);
    glVertex2f(1000,200);
    glVertex2f(1000,700);
    glVertex2f(0,   700);
    glEnd();
}

/// Cloud functions
void V_cloud1()
{
    glPushMatrix();
    glTranslatef(V_moveCloud1, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 200, y = 650, r = 20;
    circle(x,    y, r);
    circle(x-25, y+5, r);
    circle(x+25, y+5, r);
    circle(x-10, y+20, r-3);
    circle(x+10, y+20, r-3);

    glPopMatrix();
}

void V_cloud2()
{
    glPushMatrix();
    glTranslatef(V_moveCloud2, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    circle(337,640,18);
    circle(365,640,20);
    circle(390,640,18);
    circle(350,632,20);
    circle(375,632,20);
    circle(355,648,20);
    circle(375,648,20);

    glPopMatrix();
}

void V_cloud3()
{
    glPushMatrix();
    glTranslatef(V_moveCloud3, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 700, y = 650, r = 20;
    circle(x, y-15, r);
    circle(x+25, y-10, r);
    circle(x-25, y-10, r);
    circle(x-50, y, r);
    circle(x+50, y, r);
    circle(x+30, y+15, r+5);
    circle(x, y+25, r+5);
    circle(x-30, y+15, r+5);

    glBegin(GL_QUADS);
    glVertex2f(650,630);
    glVertex2f(750,630);
    glVertex2f(750,670);
    glVertex2f(650,670);
    glEnd();

    glPopMatrix();
}

void V_cloud4()
{
    glPushMatrix();
    glTranslatef(V_moveCloud4, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);
    circle(830,640,20);
    circle(860,638,22);
    circle(890,640,20);
    circle(845,652,20);
    circle(870,655,28);

    glPopMatrix();
}

// Cloud update functions
void V_updateCloud1(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 -= V_cloudSpeed1+1;
            if (V_moveCloud1 < -250)
            {
                V_moveCloud1 = 860;
            }
            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 += V_cloudSpeed1+1;
            if (V_moveCloud1 >1000)
            {
                V_moveCloud1 = -250;
            }
            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud1, 0);
}

void V_updateCloud2(int value)
{
    if(!V_cloudPaused2)
    {
        V_moveCloud2 -= V_cloudSpeed2+.3;
        if (V_moveCloud2 < -450)
        {
            V_moveCloud2 = 740;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(9, V_updateCloud2, 0);
}

void V_updateCloud3(int value)
{
    if(!V_cloudPaused3)
    {
        V_moveCloud3 -= V_cloudSpeed3;
        if (V_moveCloud3 < -800)
        {
            V_moveCloud3 = 420;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, V_updateCloud3, 0);
}

void V_updateCloud4(int value)
{
    if(!V_cloudPaused4)
    {
        V_moveCloud4 -= V_cloudSpeed4+.5;
        if (V_moveCloud4 < -900)
        {
            V_moveCloud4 = 320;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(14, V_updateCloud4, 0);
}

/// Garden function
void garden()
{
    //Base
    if (isDay)
        glColor3f(0.0f, 0.5f, 0.0f);
    else
        glColor3f(0.1f, 0.3f, 0.1f);

    glBegin(GL_QUADS);
    glVertex2f(0,180);
    glVertex2f(1000,180);
    glVertex2f(1000,200);
    glVertex2f(0,200);
    glEnd();
    /// Triangle Tree
    int shift = 70;

    for(int i = 0; i< 67; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.702,0.333,0.224);
        glVertex2f(15 + shift * i,205);
        glVertex2f(25 + shift * i,205);
        glVertex2f(25 + shift * i,220);
        glVertex2f(15 + shift * i,220);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,0.32,0.004);

        glVertex2f(0  + shift * i,220);
        glVertex2f(40 + shift * i,220);
        glVertex2f(20 + shift * i,230);

        glVertex2f(10  + shift * i,225);
        glVertex2f(30 + shift * i,225);
        glVertex2f(20 + shift * i,235);

        glVertex2f(10  + shift * i,230);
        glVertex2f(30 + shift * i,230);
        glVertex2f(20 + shift * i,240);

        glEnd();

        /// Cloud shape tree
        if (isDay)
            glColor3f(0.0f, 0.5f, 0.0f);
        else
            glColor3f(0.1f, 0.3f, 0.1f);

        for(int i = 0; i<1000; i+=50)
        {
            halfCircle(i+20,190,25);
        }
    }
}

/// Train function
void train()
{
    glPushMatrix();
    glTranslatef(moveTrain, 0, 0);

    if(isDay)
        glColor3f(1, 0, 0);
    else
        glColor3f(1.0f, 0.3f, 0.40f);

    glBegin(GL_POLYGON);
    glVertex2f(300,288);
    glVertex2f(548,288);
    glVertex2f(548,313);
    glVertex2f(319,313);
    glVertex2f(300,302);
    glEnd();

    circle(301,295,6);

    // Front window
    if(isDay)
        glColor3f(0,0,0);
    else
        glColor3f(1.0f, 1.0f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(320,312);
    glVertex2f(335,312);
    glVertex2f(320,303);
    glVertex2f(305,303);
    glEnd();

    // blue polygon
    if(isDay)
        glColor3f(0.38f, 0.84f, 1.0f);
    else
        glColor3f(0.18f, 0.64f, 0.80f);

    glBegin(GL_POLYGON);
    glVertex2f(320,291);
    glVertex2f(548,291);
    glVertex2f(548,311);
    glVertex2f(335,311);
    glVertex2f(320,300);
    glEnd();

    circle(320,295,4);

    // black polygon
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(328,298);
    glVertex2f(545,298);
    glVertex2f(545,309);
    glVertex2f(340,309);
    glVertex2f(325,300);
    glEnd();

    // black polygon
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1,1,.7);

    glBegin(GL_POLYGON);
    glVertex2f(331,301);
    glVertex2f(542,301);
    glVertex2f(542,306);
    glVertex2f(343,306);
    glVertex2f(328,300);
    glEnd();

    //ground deep sky blue
    if(isDay)
        glColor3f(0.02f, 0.61f, 0.93f);
    else
        glColor3f(0.25f, 0.5f, 0.7f);

    glBegin(GL_QUADS);
    glVertex2f(322,288);
    glVertex2f(548,288);
    glVertex2f(548,293);
    glVertex2f(317,293);
    glEnd();

    // window black lines
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 370; x<550; x+=60)
    {
        glVertex2f(x,288);
        glVertex2f(x,313);
    }
    glEnd();
    glPopMatrix();
}

void updateTrain(int value)
{
    if(!trainPaused)
    {
        moveTrain -= trainSpeed;
        if (moveTrain < -550)
        {
            moveTrain = 750;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, updateTrain, 0);
}

/// Flyover function
void flyOver()
{
    ///Pillar
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    for(int x = 50; x<1000; x+=100)
    {
        glVertex2f(x,   205);
        glVertex2f(x+15,205);
        glVertex2f(x+15,275);
        glVertex2f(x,   275);
    }
    glEnd();

    /// Pillar upper box
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_TRIANGLES);
    for(int x = 40; x<1000; x+=100)
    {
        glVertex2f(x,     275);
        glVertex2f(x+35,  275);
        glVertex2f(x+15,255);
    }
    glEnd();

    if(isDay)
        glColor3f(0.80f, 0.80f, 0.80f);
    else
        glColor3f(.4,.4,.4);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(0,   275);
    glVertex2f(1000,275);
    glEnd();

    ///Bridge body
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    glVertex2f(0,   277);
    glVertex2f(1000,277);
    glVertex2f(1000,288);
    glVertex2f(0,   288);
    glEnd();
}

/// Road function
void road()
{
    if (isDay)
        glColor3f(.37f, .37f, .37f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    //Base Gray Color
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(1000,0);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Base white line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0,   40);
    glVertex2f(1000,40);
    glEnd();

    //Main Road
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.15f, 0.15f, 0.15f);
    else
        glColor3f(0,0,0);

    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Upper white line of the road
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glEnd();

    //Upper gray color
    if (isDay)
        glColor3f(0.51f, 0.51f, 0.51f);
    else
        glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,173);
    glVertex2f(0,   173);
    glEnd();

    //Road dash line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 0; x<1000; x+=60)
    {
        glVertex2f(x,   102);
        glVertex2f(x+30,102);
    }
    glEnd();
}

/// Road side wall function
void roadSideWall()
{
    if (isDay)
        glColor3f(0.839f, 0.443f, 0.235f);
    else
        glColor3f(0.42f, 0.22f, 0.13f);

    glBegin(GL_QUADS);
    glVertex2f(0,   170);
    glVertex2f(1000,170);
    glVertex2f(1000,190);
    glVertex2f(0,   190);
    glEnd();

    //Breaks Line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2f(0,   170);
    glVertex2f(1000,170);

    glVertex2f(0,   175);
    glVertex2f(1000,175);

    glVertex2f(0,   180);
    glVertex2f(1000,180);

    glVertex2f(0,   185);
    glVertex2f(1000,185);

    glVertex2f(0,   190);
    glVertex2f(1000,190);

    for(int x = 10; x<1000; x+=20)
    {
        glVertex2f(x,170);
        glVertex2f(x,175);

        glVertex2f(x+10,175);
        glVertex2f(x+10,180);

        glVertex2f(x,180);
        glVertex2f(x,185);

        glVertex2f(x+10,185);
        glVertex2f(x+10,190);
    }

    glEnd();

    //Upper 2 lines
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(0,   200);
    glVertex2f(1000,200);

    glVertex2f(0,   205);
    glVertex2f(1000,205);

    for(int i = 0; i< 1000; i+=45)
    {
        glLineWidth(1);
        glVertex2f(i, 190);
        glVertex2f(i, 205);

        glVertex2f(i+5, 190);
        glVertex2f(i+5, 205);
    }
    glEnd();
}

/// Bus function
void bus()
{
    glPushMatrix();
    glTranslatef(V_moveBus, 0, 0);

    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(1.00f, 0.60f, 0.29f);
    else
        glColor3f(0.70f, 0.35f, 0.20f);

    ///Body
    glVertex2f(400, 130);
    glVertex2f(550, 130);
    glVertex2f(550, 190);
    glVertex2f(400, 190);

    ///Front
    glVertex2f(550, 130);
    glVertex2f(570, 130);
    glVertex2f(570, 160);
    glVertex2f(550, 190);

    glEnd();

    ///  FRONT Light
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,1,0);

    glBegin(GL_QUADS);
    glVertex2f(565, 135);
    glVertex2f(570, 135);
    glVertex2f(570, 142);
    glVertex2f(565, 142);

    if(!isDay)
    {
    glColor3f(1,1,.6);
    glVertex2f(570, 135);
    glVertex2f(640, 125);
    glVertex2f(640, 152);
    glVertex2f(570, 142);
    }

    /// REAR LIGHT
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glVertex2f(400, 135);
    glVertex2f(405, 135);
    glVertex2f(405, 142);
    glVertex2f(400, 142);

    glEnd();

    /// Window
    /// REAR WINDOW
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1,1,.6);

    glBegin(GL_QUADS);
    glVertex2f(410, 160);
    glVertex2f(530, 160);
    glVertex2f(530, 180);
    glVertex2f(410, 180);
    glEnd();

    glColor3f(1.00f, 0.60f, 0.29f);
    glLineWidth(4);
    glBegin(GL_LINES);
    for(int x = 432; x<530; x+=25){
    glVertex2f(x,160);
    glVertex2f(x,180);
    }
    glEnd();

    /// FRONT WINDOW
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1,1,.6);

    glBegin(GL_QUADS);
    glVertex2f(533, 180);
    glVertex2f(550, 180);
    glVertex2f(565, 150);
    glVertex2f(533, 160);
    glEnd();

    /// REAR TIRE
    glColor3f(0,0,0);
    halfCircle(425,130,12);

    glPushMatrix();
    glTranslatef(425, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-425, -130, 0);

   if (isDay)
    glColor3f(0.8f, 0.8f, 0.8f);
else
    glColor3f(0.5f, 0.5f, 0.5f);

    circle(425,130,11);

    if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.7f, 0.7f, 0.7f);

    circle(425,130,5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(414,130);
    glVertex2f(436,130);
    glEnd();

    glPopMatrix();

    /// FRONT TIRE
    glColor3f(0,0,0);
    halfCircle(540,130,12);

    glPushMatrix();
    glTranslatef(540, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-540, -130, 0);

    if (isDay)
    glColor3f(0.8f, 0.8f, 0.8f);
else
    glColor3f(0.5f, 0.5f, 0.5f);

    circle(540,130,11);

    if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.7f, 0.7f, 0.7f);

    circle(540,130,5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(529,130);
    glVertex2f(551,130);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void V_updateBus(int value)
{
    if(!V_busPaused)
    {
        V_moveBus += V_busSpeed+1;
        if (V_moveBus > 700)
        {
            V_moveBus = -550;
        }
        V_busTireAngle -= 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateBus, 0);
}

/// Cargo truck function (simplified)
void cargoTruck()
{
    glPushMatrix();
    glTranslatef(V_moveCargo, 0, 0);

    /// Body
    if (isDay)
        glColor3f(0.51f, 0.86f, 0.92f);
    else
        glColor3f(0.22f, 0.46f, 0.55f);

    glBegin(GL_QUADS);
    glVertex2f(900, 83);
    glVertex2f(750, 83);
    glVertex2f(750, 150);
    glVertex2f(900, 150);
    glEnd();

    /// Head
    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    glBegin(GL_QUADS);
    glVertex2f(745, 138);
    glVertex2f(715, 138);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    glVertex2f(745, 75);
    glVertex2f(690, 70);
    glVertex2f(690, 113);
    glVertex2f(745, 113);
    glEnd();

    /// Lights
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glBegin(GL_QUADS);
    glVertex2f(895, 78);
    glVertex2f(900, 78);
    glVertex2f(900, 90);
    glVertex2f(895, 90);
    glEnd();

    /// Tires
    glColor3f(0,0,0);
    halfCircle(865,69,14);
    halfCircle(725,69,14);

    glPopMatrix();
}

void V_updateCargo(int value)
{
    if(!V_cargoPaused)
    {
        V_moveCargo -= V_cargoSpeed+2;
        if (V_moveCargo < -940)
        {
            V_moveCargo = 450;
        }
        V_cargoTireAngle += 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateCargo, 0);
}

/// Building function (simplified)
void building()
{
    /// 1st Building
    if(isDay)
        glColor3f(0.92f, 0.92f, 0.92f);
    else
        glColor3f(0.55f, 0.55f, 0.55f);

    // body
    glBegin(GL_QUADS);
    glVertex2f(10,  200);
    glVertex2f(100, 200);
    glVertex2f(100, 525);
    glVertex2f(10,  525);

    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    // Top
    glVertex2f(6,   525);
    glVertex2f(104, 525);
    glVertex2f(104, 535);
    glVertex2f(6,   535);
    glEnd();

    // windows
    glBegin(GL_QUADS);
    for(int x = 18; x<80; x+=27 )
    {
        for(int y = 500; y>200; y-=60)
        {
            if(isDay)
                glColor3f(0.52f, 0.78f, 0.96f);
            else
                glColor3f(1.0f, 1.0f, 0.5f);

            glVertex2f(x,  y+5);
            glVertex2f(x+20, y+5);
            glVertex2f(x+20, y-20);
            glVertex2f(x,  y-20);
        }
    }
    glEnd();

    /// 2nd Building
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);

    glVertex2f(90,  200);
    glVertex2f(135, 200);
    glVertex2f(135, 400);
    glVertex2f(90,  400);

    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glVertex2f(135,  200);
    glVertex2f(180, 200);
    glVertex2f(180, 400);
    glVertex2f(135,  400);
    glEnd();

    // More buildings can be added here...
}

/// Main city scenario function
void cityScene()
{
    sky();
    moon();
    sun();
    V_cloud1();
    V_cloud2();
    V_cloud3();
    V_cloud4();
    building();
    train();
    flyOver();
    garden();
    road();
    roadSideWall();
    bus();
    cargoTruck();
}

/// Keyboard function
void keyboard(unsigned char key, int x, int y)
{
    if(key == 'd' || key == 'D')
    {
        isDay = true;
    }
    if(key == 'n' || key == 'N')
    {
        isDay = false;
    }
    if(key == ' ')
    {
        // Pause/unpause all animations
        trainPaused = !trainPaused;
        sunPaused = !sunPaused;
        moonPaused = !moonPaused;
        V_cloudPaused1 = !V_cloudPaused1;
        V_cloudPaused2 = !V_cloudPaused2;
        V_cloudPaused3 = !V_cloudPaused3;
        V_cloudPaused4 = !V_cloudPaused4;
        V_busPaused = !V_busPaused;
        V_cargoPaused = !V_cargoPaused;
    }
}

/// Mouse function
void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(isDay)
            trainPaused = !trainPaused;
        else
            moonPaused = !moonPaused;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        if(isDay)
            sunPaused = !sunPaused;
        else
            V_cargoPaused = !V_cargoPaused;
    }
}

/// Special keys function
void specialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
    {
        if(isDay)
            trainSpeed += 0.1f;
    }
    if(key == GLUT_KEY_DOWN)
    {
        if(isDay && trainSpeed > 0.1f)
            trainSpeed -= 0.1f;
    }
    if(key == GLUT_KEY_LEFT)
    {
        if(!isDay && moonSpeed > 0.1f)
            moonSpeed -= 0.1f;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        if(!isDay)
            moonSpeed += 0.1f;
    }
}

/// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    cityScene();
    glutSwapBuffers();
}

/// Main function
int main(int argc, char** argv)
{
    cout<<"City to Village Traveling - City Scenario"<<endl;
    cout<<"Press D or d for Day"<<endl;
    cout<<"Press N or n for Night"<<endl;
    cout<<"Press space key to stop/start everything"<<endl;
    cout<<"Press key_up and key_down for Train speed update at day"<<endl;
    cout<<"Press key_left and key_right for Moon speed update at night"<<endl;
    cout<<"Press mouse_left_button to stop and start The Train at day"<<endl;
    cout<<"Press mouse_right_button to stop and start The Sun at day"<<endl;
    cout<<"Press mouse_left_button to stop and start The Moon at night"<<endl;
    cout<<"Press mouse_right_button to stop and start The Cargo Truck at night"<<endl<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,700);
    glClearColor(0, 0, 0, 1);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("City Scenario - City to Village Traveling");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 700);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKeys);

    // Start all timers
    glutTimerFunc(16, updateSun, 0);
    glutTimerFunc(16, updateMoon, 0);
    glutTimerFunc(16, V_updateCloud1, 0);
    glutTimerFunc(9, V_updateCloud2, 0);
    glutTimerFunc(16, V_updateCloud3, 0);
    glutTimerFunc(14, V_updateCloud4, 0);
    glutTimerFunc(16, updateTrain, 0);
    glutTimerFunc(2, V_updateBus, 0);
    glutTimerFunc(2, V_updateCargo, 0);

    glutMainLoop();
    return 0;
}

