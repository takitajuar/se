#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;

// Global variables
bool isDay = true;

// Bird variables
float moveBird = 0.0f;
float birdSpeed = 1.0f;
float savedBirdSpeed = 0.0f;
bool birdPaused = false;

// Sun variables
float moveSun = 0.0f;
float sunSpeed = 0.3f;
bool sunPaused = false;

// Cloud variables
float moveCloud1 = 0.0f;
float moveCloud2 = 300.0f;
float moveCloud3 = 600.0f;

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

/// Sky function
void sky()
{
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.5f, 0.8f, 1.0f); // Light blue
    else
        glColor3f(0.1f, 0.1f, 0.3f); // Dark blue
    
    glVertex2f(0, 400);
    glVertex2f(1000, 400);
    glVertex2f(1000, 700);
    glVertex2f(0, 700);
    glEnd();
}

/// Sun function
void sun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(moveSun, 0, 0);
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow sun
        circle(100, 600, 30);
        glPopMatrix();
    }
}

void updateSun(int value)
{
    if(!sunPaused)
    {
        moveSun += sunSpeed;
        if (moveSun > 1000)
        {
            moveSun = -150;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(20, updateSun, 0);
}

/// Cloud function
void drawCloud()
{
    // Cloud 1
    glPushMatrix();
    glTranslatef(moveCloud1, 0, 0);
    glColor3f(1.0f, 1.0f, 1.0f); // White clouds
    circle(200, 650, 20);
    circle(220, 660, 18);
    circle(240, 650, 20);
    circle(225, 640, 15);
    glPopMatrix();
    
    // Cloud 2
    glPushMatrix();
    glTranslatef(moveCloud2, 0, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(500, 630, 25);
    circle(525, 640, 20);
    circle(545, 630, 22);
    glPopMatrix();
    
    // Cloud 3
    glPushMatrix();
    glTranslatef(moveCloud3, 0, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(800, 660, 18);
    circle(820, 665, 15);
    circle(835, 655, 20);
    glPopMatrix();
}

void updateCloud(int value)
{
    moveCloud1 -= 0.5f;
    if (moveCloud1 < -300)
        moveCloud1 = 1000;
        
    moveCloud2 -= 0.3f;
    if (moveCloud2 < -300)
        moveCloud2 = 1000;
        
    moveCloud3 -= 0.7f;
    if (moveCloud3 < -300)
        moveCloud3 = 1000;
        
    glutPostRedisplay();
    glutTimerFunc(30, updateCloud, 0);
}

/// Bird function
void bird() 
{
    glPushMatrix();
    glTranslatef(moveBird, 0, 0);

    // Right wing
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(705.0f, 560.0f);
    glVertex2f(720.0f, 570.0f);
    glVertex2f(705.0f, 545.0f);
    glEnd();

    // Left wing
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(695.0f, 560.0f);
    glVertex2f(680.0f, 570.0f);
    glVertex2f(695.0f, 545.0f);
    glEnd();

    // Body
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(695.0f, 555.0f);
    glVertex2f(705.0f, 555.0f);
    glVertex2f(705.0f, 565.0f);
    glVertex2f(695.0f, 565.0f);
    glEnd();

    glPopMatrix();
}

void updateBird(int value)
{
    if(!birdPaused)
    {
        moveBird += birdSpeed;
        if (moveBird > 1000)
        {
            moveBird = -100;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(25, updateBird, 0);
}

/// Buildings functions
void building1()
{
    // Building 1
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.8f, 0.8f, 0.9f); // Light gray
    else
        glColor3f(0.4f, 0.4f, 0.5f); // Dark gray
    
    glVertex2f(50, 200);
    glVertex2f(120, 200);
    glVertex2f(120, 350);
    glVertex2f(50, 350);
    glEnd();
    
    // Windows
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.6f, 0.8f, 1.0f); // Light blue windows
    else
        glColor3f(1.0f, 1.0f, 0.5f); // Yellow lit windows
    
    for(int y = 220; y < 340; y += 30)
    {
        for(int x = 60; x < 110; x += 25)
        {
            glVertex2f(x, y);
            glVertex2f(x+15, y);
            glVertex2f(x+15, y+20);
            glVertex2f(x, y+20);
        }
    }
    glEnd();
}

void building2()
{
    // Building 2
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.9f, 0.7f, 0.6f); // Light brown
    else
        glColor3f(0.5f, 0.3f, 0.2f); // Dark brown
    
    glVertex2f(130, 200);
    glVertex2f(200, 200);
    glVertex2f(200, 380);
    glVertex2f(130, 380);
    glEnd();
    
    // Windows
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.6f, 0.8f, 1.0f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    
    for(int y = 220; y < 370; y += 30)
    {
        for(int x = 140; x < 190; x += 25)
        {
            glVertex2f(x, y);
            glVertex2f(x+15, y);
            glVertex2f(x+15, y+20);
            glVertex2f(x, y+20);
        }
    }
    glEnd();
}

void building3()
{
    // Building 3 - Tallest
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.7f, 0.9f, 0.8f); // Light green
    else
        glColor3f(0.3f, 0.5f, 0.4f); // Dark green
    
    glVertex2f(210, 200);
    glVertex2f(280, 200);
    glVertex2f(280, 420);
    glVertex2f(210, 420);
    glEnd();
    
    // Windows
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.6f, 0.8f, 1.0f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    
    for(int y = 220; y < 410; y += 30)
    {
        for(int x = 220; x < 270; x += 25)
        {
            glVertex2f(x, y);
            glVertex2f(x+15, y);
            glVertex2f(x+15, y+20);
            glVertex2f(x, y+20);
        }
    }
    glEnd();
}

/// Tree function
void tree()
{
    int shift = 100;
    for (int i = 0; i < 10; i++)
    {
        // Tree trunk
        glBegin(GL_QUADS);
        glColor3f(0.6f, 0.3f, 0.1f); // Brown trunk
        glVertex2f(30 + shift * i, 200);
        glVertex2f(40 + shift * i, 200);
        glVertex2f(40 + shift * i, 240);
        glVertex2f(30 + shift * i, 240);
        glEnd();

        // Tree leaves
        glColor3f(0.0f, 0.6f, 0.0f); // Green leaves
        circle(35 + shift * i, 250, 20);
    }
}

/// Road functions
void roadUp()
{
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.4f, 0.4f, 0.4f); // Gray road
    else
        glColor3f(0.2f, 0.2f, 0.2f); // Dark gray road
    
    glVertex2f(0, 380);
    glVertex2f(1000, 380);
    glVertex2f(1000, 400);
    glVertex2f(0, 400);
    glEnd();
    
    // Road markings
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // White markings
    for(int x = 0; x < 1000; x += 50)
    {
        glVertex2f(x, 388);
        glVertex2f(x+25, 388);
        glVertex2f(x+25, 392);
        glVertex2f(x, 392);
    }
    glEnd();
}

void road()
{
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.3f, 0.3f, 0.3f); // Gray road
    else
        glColor3f(0.1f, 0.1f, 0.1f); // Dark gray road
    
    glVertex2f(0, 180);
    glVertex2f(1000, 180);
    glVertex2f(1000, 200);
    glVertex2f(0, 200);
    glEnd();
}

void roadDown()
{
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.2f, 0.2f, 0.2f); // Dark gray road
    else
        glColor3f(0.05f, 0.05f, 0.05f); // Very dark road
    
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 180);
    glVertex2f(0, 180);
    glEnd();
}

/// Railing functions
void upRailing()
{
    glBegin(GL_LINES);
    glColor3f(0.6f, 0.6f, 0.6f); // Gray railing
    glLineWidth(3);
    
    for(int x = 0; x < 1000; x += 20)
    {
        glVertex2f(x, 400);
        glVertex2f(x, 410);
    }
    glEnd();
}

void downRailing()
{
    glBegin(GL_LINES);
    glColor3f(0.6f, 0.6f, 0.6f); // Gray railing
    glLineWidth(3);
    
    for(int x = 0; x < 1000; x += 20)
    {
        glVertex2f(x, 200);
        glVertex2f(x, 210);
    }
    glEnd();
}

/// Main sub-city scenario function
void subCityScene()
{
    sky();
    sun();
    drawCloud();
    bird();
    roadUp();
    building1();
    building2();
    building3();
    tree();
    road();
    downRailing();
    upRailing();
    roadDown();
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
        // Pause/unpause animations
        birdPaused = !birdPaused;
        sunPaused = !sunPaused;
    }
}

/// Mouse function
void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        birdPaused = !birdPaused;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        sunPaused = !sunPaused;
    }
}

/// Special keys function
void specialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
    {
        birdSpeed += 0.1f;
    }
    if(key == GLUT_KEY_DOWN)
    {
        if(birdSpeed > 0.1f)
            birdSpeed -= 0.1f;
    }
    if(key == GLUT_KEY_LEFT)
    {
        if(sunSpeed > 0.1f)
            sunSpeed -= 0.1f;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        sunSpeed += 0.1f;
    }
}

/// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    subCityScene();
    glutSwapBuffers();
}

/// Main function
int main(int argc, char** argv)
{
    cout<<"City to Village Traveling - Sub-City Scenario"<<endl;
    cout<<"Press D or d for Day"<<endl;
    cout<<"Press N or n for Night"<<endl;
    cout<<"Press space key to stop/start animations"<<endl;
    cout<<"Press key_up and key_down for bird speed update"<<endl;
    cout<<"Press key_left and key_right for sun speed update"<<endl;
    cout<<"Press mouse_left_button to stop and start bird"<<endl;
    cout<<"Press mouse_right_button to stop and start sun"<<endl<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,700);
    glClearColor(0, 0, 0, 1);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Sub-City Scenario - City to Village Traveling");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 700);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKeys);

    // Start all timers
    glutTimerFunc(20, updateSun, 0);
    glutTimerFunc(30, updateCloud, 0);
    glutTimerFunc(25, updateBird, 0);

    glutMainLoop();
    return 0;
}
