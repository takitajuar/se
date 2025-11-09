#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

// ========== Scenario 3 (Village) - UPDATED ==========

void vsun(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416f / 180.0f;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

float vbx = 50, vbx2 = -200, vax = 10, vangle = 0, vboatY = 200;
float vfx = 0, vfy = 500;
#define VSTAR_COUNT 50
float vstarX[VSTAR_COUNT], vstarY[VSTAR_COUNT];

int vmode = 1;

void vinitStars() {
    for (int i = 0; i < VSTAR_COUNT; i++) {
        vstarX[i] = rand() % 500;
        vstarY[i] = 350 + rand() % 150;
    }
}

void vclouds()
{
    glPushMatrix();
    float cloudPosX = (vax * 0.08f) - 20.0f;
    glTranslatef(cloudPosX, 0, 0);

    if (vmode == 1) {
        glColor3ub(255, 255, 255);
        vsun(1.6f, 2.4f, 16.8f, 16.8f);
        vsun(1.2f, 1.6f, 15.6f, 16.8f);
        vsun(1.2f, 1.6f, 18.0f, 16.8f);
        vsun(1.6f, 2.4f, 11.2f, 13.6f);
        vsun(1.2f, 1.6f, 12.4f, 13.6f);
        vsun(1.2f, 1.6f, 10.0f, 13.6f);
    } else {
        glColor3ub(150, 150, 180);
        vsun(1.6f, 2.4f, 16.8f, 16.8f);
        vsun(1.2f, 1.6f, 15.6f, 16.8f);
        vsun(1.2f, 1.6f, 18.0f, 16.8f);
        vsun(1.6f, 2.4f, 11.2f, 13.6f);
        vsun(1.2f, 1.6f, 12.4f, 13.6f);
        vsun(1.2f, 1.6f, 10.0f, 13.6f);
    }
    glPopMatrix();
    vax += 0.05f;
    if (vax > 500) vax = -200;
}

void vboat()
{
    glPushMatrix();
    float boatPosX = (vbx * 0.08f) - 20.0f;
    glTranslatef(boatPosX, 0, 0);

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(6.0f, -4.0f);
    glVertex2f(12.0f, -4.0f);
    glVertex2f(14.0f, -1.6f);
    glVertex2f(4.0f, -1.6f);
    glEnd();

    glColor3ub(205, 133, 63);
    glBegin(GL_POLYGON);
    glVertex2f(6.0f, -1.6f);
    glVertex2f(12.0f, -1.6f);
    glVertex2f(11.2f, 0.8f);
    glVertex2f(6.8f, 0.8f);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2f(8.8f, 0.8f);
    glVertex2f(9.6f, 0.8f);
    glVertex2f(9.6f, 3.2f);
    glVertex2f(8.8f, 3.2f);
    glEnd();

    glColor3ub(128, 0, 128);
    glBegin(GL_POLYGON);
    glVertex2f(6.8f, 1.6f);
    glVertex2f(11.2f, 1.6f);
    glVertex2f(11.2f, 8.4f);
    glVertex2f(6.8f, 8.4f);
    glEnd();

    glPopMatrix();
    vbx += 0.13f;
    if (vbx > 500) vbx = -550;
}

void vboat2()
{
    glPushMatrix();
    float boat2PosX = (vbx2 * 0.08f) - 20.0f;
    glTranslatef(boat2PosX, 0, 0);

    glColor3ub(139, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-4.0f, -4.0f);
    glVertex2f(0.8f, -4.0f);
    glVertex2f(2.4f, -2.4f);
    glVertex2f(-5.6f, -2.4f);
    glEnd();

    glColor3ub(255, 215, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.4f, -2.4f);
    glVertex2f(-0.8f, -2.4f);
    glVertex2f(-0.8f, 2.4f);
    glVertex2f(-2.4f, 2.4f);
    glEnd();

    glPopMatrix();
    vbx2 += 0.13f;
    if (vbx2 > 500) vbx2 = -600;
}

void vwindmill()
{
    glColor3ub(169, 169, 169);
    glBegin(GL_POLYGON);
    glVertex2f(16.0f, -1.0f);
    glVertex2f(17.6f, -1.0f);
    glVertex2f(17.6f, -1.0f);
    glVertex2f(16.0f, -1.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(16.8f, -1.0f, 0);
    glRotatef(vangle, 0, 0, 1);
    glColor3ub(255, 255, 255);
    if (vmode == 2) glColor3ub(200, 200, 220);

    for (int i = 0; i < 4; i++) {
        glRotatef(90, 0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(0.8f, 0);
        glVertex2f(0.8f, 5.6f);
        glVertex2f(0, 5.6f);
        glEnd();
    }
    glPopMatrix();
}

void vtree(float x, float y, float height)
{
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 0.8f, y);
    glVertex2f(x + 0.8f, y + height);
    glVertex2f(x, y + height);
    glEnd();

    if (vmode == 1) glColor3ub(0, 128, 0);
    else glColor3ub(0, 100, 0);
    vsun(1.2f, 1.6f, x + 0.4f, y + height + 0.8f);
    vsun(1.2f, 1.6f, x - 0.4f, y + height + 0.4f);
    vsun(1.2f, 1.6f, x + 1.2f, y + height + 0.4f);
}

void vcow(float x, float y)
{
    if (vmode == 1) glColor3ub(255, 255, 255);
    else glColor3ub(150, 150, 150);

    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 4.0f, y);
    glVertex2f(x + 4.0f, y + 1.6f);
    glVertex2f(x, y + 1.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x + 3.6f, y + 0.8f);
    glVertex2f(x + 4.8f, y + 0.8f);
    glVertex2f(x + 4.8f, y + 2.0f);
    glVertex2f(x + 3.6f, y + 2.0f);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x + 0.4f, y);
    glVertex2f(x + 0.8f, y);
    glVertex2f(x + 0.8f, y - 0.8f);
    glVertex2f(x + 0.4f, y - 0.8f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x + 2.8f, y);
    glVertex2f(x + 3.2f, y);
    glVertex2f(x + 3.2f, y - 0.8f);
    glVertex2f(x + 2.8f, y - 0.8f);
    glEnd();

    vsun(0.4f, 0.4f, x + 1.6f, y + 0.8f);
    vsun(0.4f, 0.4f, x + 2.8f, y + 1.2f);
}

void vdrawStars() {
    if (vmode == 2) {
        glColor3ub(255, 255, 255);
        glPointSize(2);
        for (int i = 0; i < VSTAR_COUNT; i++) {
            float starPosX = (vstarX[i] * 0.08f) - 20.0f;
            float starPosY = (vstarY[i] * 0.08f) - 20.0f;
            glBegin(GL_POINTS);
            glVertex2f(starPosX, starPosY);
            glEnd();
        }
        glPointSize(3);
        glBegin(GL_POINTS);
        float shootingStarX = (vfx * 0.08f) - 20.0f;
        float shootingStarY = (vfy * 0.08f) - 20.0f;
        glVertex2f(shootingStarX, shootingStarY);
        glEnd();
        glPointSize(1);
    }
}

void villageScenarioDisplay(void)
{
    glLoadIdentity();

    if (vmode == 1) glClearColor(0.0, 0.9, 0.9, 0.0);
    else glClearColor(0.05, 0.05, 0.2, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    vdrawStars();

    // ---------- Ground (green) ----------
    if (vmode == 1) glColor3ub(0, 255, 0);
    else glColor3ub(0, 100, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-20.0f, -20.0f);
    glVertex2f(20.0f, -20.0f);
    glVertex2f(20.0f, -1.0f);   // raised to -1.0f (shoreline)
    glVertex2f(-20.0f, -1.0f);
    glEnd();

    // ---------- Water: single clean area (covers hull area) ----------
    glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2f(-20.0f, -1.0f);  // top of water (shore)
    glVertex2f(20.0f, -1.0f);
    glVertex2f(20.0f, -20.0f);
    glVertex2f(-20.0f, -20.0f);
    glEnd();

    // ---------- Hills (bases follow shoreline at y = -1.0f) ----------
    glColor3ub(34,139,34);
    glBegin(GL_POLYGON);
    glVertex2f(-23.2f, -1.0f);      // moved up
    glVertex2f(-4.0f,  -1.0f);
    glVertex2f(-12.0f, 16.0f);
    glEnd();

    glColor3ub(50,205,50);
    glBegin(GL_POLYGON);
    glVertex2f(-8.0f, -1.0f);
    glVertex2f(8.0f,  -1.0f);
    glVertex2f(0.0f,  16.0f);
    glEnd();

    // ---------- Trees on top/edge of hills ----------
    vtree(-15.2f, 8.0f, 2.0f);
    vtree(-8.8f, 8.8f, 2.24f);
    vtree(-2.4f, 9.6f, 2.0f);
    vtree(5.6f, 7.2f, 2.4f);
    vtree(10.4f, 8.8f, 2.0f);

    // boat(s) (inside water now)
    vboat();
    vboat2();

    // ---------- Trees along shoreline/hill slope (raised) ----------
    vtree(-16.8f, -1.8f, 4.4f);  // raised from -8.8 -> -1.8
    vtree(-15.2f, -1.0f, 4.8f);  // raised from -8.0 -> -1.0
    vtree(-13.6f, -1.0f, 4.0f);  // raised
    vtree(-12.0f, -0.2f, 4.4f);  // raised from -7.2 -> -0.2
    vtree(-10.4f, -1.4f, 4.0f);  // raised from -8.4 -> -1.4

    // ---------- Houses clustered on hillside (baseline moved up) ----------
    if (vmode == 1) {
        glColor3ub(244,164,96);
        glBegin(GL_POLYGON);
        glVertex2f(-12.0f, -1.0f);
        glVertex2f(-4.0f,  -1.0f);
        glVertex2f(-4.0f,  -1.0f + 6.4f);  // preserved house height
        glVertex2f(-12.0f, -1.0f + 6.4f);
        glEnd();

        glColor3ub(165,42,42);
        glBegin(GL_POLYGON);
        glVertex2f(-12.8f, -1.0f + 0.0f);
        glVertex2f(-3.2f,  -1.0f + 0.0f);
        glVertex2f(-8.0f,  2.4f);
        glEnd();

        glColor3ub(139,69,19);
        glBegin(GL_POLYGON);
        glVertex2f(-10.4f, -1.0f);
        glVertex2f(-7.2f,  -1.0f);
        glVertex2f(-7.2f,  -1.0f + 3.2f);
        glVertex2f(-10.4f, -1.0f + 3.2f);
        glEnd();

        glColor3ub(173,216,230);
        glBegin(GL_POLYGON);
        glVertex2f(-11.2f, -1.0f + 0. -  + 0.); // keep relative-window (small window)
        glVertex2f(-10.0f, -1.0f + 0.0f);
        glVertex2f(-10.0f, -1.0f + 1.2f);
        glVertex2f(-11.2f, -1.0f + 1.2f);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-6.0f, -1.0f + 0.0f);
        glVertex2f(-4.8f, -1.0f + 0.0f);
        glVertex2f(-4.8f, -1.0f + 1.2f);
        glVertex2f(-6.0f, -1.0f + 1.2f);
        glEnd();

        glColor3ub(210,180,140);
        glBegin(GL_POLYGON);
        glVertex2f(-16.0f, -1.0f - 2.4f);
        glVertex2f(-10.4f, -1.0f - 2.4f);
        glVertex2f(-10.4f, -1.0f + 1.0f);
        glVertex2f(-16.0f, -1.0f + 1.0f);
        glEnd();

        glColor3ub(139,69,19);
        glBegin(GL_POLYGON);
        glVertex2f(-16.4f, -1.0f + 0.0f);
        glVertex2f(-10.0f, -1.0f + 0.0f);
        glVertex2f(-13.2f, -1.0f + 3.8f);
        glEnd();

        glColor3ub(160,82,45);
        glBegin(GL_POLYGON);
        glVertex2f(-14.0f, -1.0f - 2.4f);
        glVertex2f(-12.4f, -1.0f - 2.4f);
        glVertex2f(-12.4f, -1.0f + 1.8f);
        glVertex2f(-14.0f, -1.0f + 1.8f);
        glEnd();

        glColor3ub(173,216,230);
        glBegin(GL_POLYGON);
        glVertex2f(-15.6f, -1.0f - 1.8f);
        glVertex2f(-14.4f, -1.0f - 1.8f);
        glVertex2f(-14.4f, -1.0f - 0.6f);
        glVertex2f(-15.6f, -1.0f - 0.6f);
        glEnd();
    } else {
        glColor3ub(50,30,20);
        glBegin(GL_POLYGON);
        glVertex2f(-12.0f, -1.0f);
        glVertex2f(-4.0f,  -1.0f);
        glVertex2f(-4.0f,  -1.0f + 6.4f);
        glVertex2f(-12.0f, -1.0f + 6.4f);
        glEnd();

        glColor3ub(30,10,10);
        glBegin(GL_POLYGON);
        glVertex2f(-12.8f, -1.0f + 0.0f);
        glVertex2f(-3.2f,  -1.0f + 0.0f);
        glVertex2f(-8.0f,  2.4f);
        glEnd();

        glColor3ub(20,10,5);
        glBegin(GL_POLYGON);
        glVertex2f(-10.4f, -1.0f);
        glVertex2f(-7.2f,  -1.0f);
        glVertex2f(-7.2f,  -1.0f + 3.2f);
        glVertex2f(-10.4f, -1.0f + 3.2f);
        glEnd();

        glColor3ub(30,40,60);
        glBegin(GL_POLYGON);
        glVertex2f(-11.2f, -1.0f + 0.0f);
        glVertex2f(-10.0f, -1.0f + 0.0f);
        glVertex2f(-10.0f, -1.0f + 1.2f);
        glVertex2f(-11.2f, -1.0f + 1.2f);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-6.0f, -1.0f + 0.0f);
        glVertex2f(-4.8f, -1.0f + 0.0f);
        glVertex2f(-4.8f, -1.0f + 1.2f);
        glVertex2f(-6.0f, -1.0f + 1.2f);
        glEnd();

        glColor3ub(60,40,20);
        glBegin(GL_POLYGON);
        glVertex2f(-16.0f, -1.0f - 2.4f);
        glVertex2f(-10.4f, -1.0f - 2.4f);
        glVertex2f(-10.4f, -1.0f + 1.0f);
        glVertex2f(-16.0f, -1.0f + 1.0f);
        glEnd();

        glColor3ub(50,30,20);
        glBegin(GL_POLYGON);
        glVertex2f(-16.4f, -1.0f + 0.0f);
        glVertex2f(-10.0f, -1.0f + 0.0f);
        glVertex2f(-13.2f, -1.0f + 3.8f);
        glEnd();

        glColor3ub(50,30,20);
        glBegin(GL_POLYGON);
        glVertex2f(-14.0f, -1.0f - 2.4f);
        glVertex2f(-12.4f, -1.0f - 2.4f);
        glVertex2f(-12.4f, -1.0f + 1.8f);
        glVertex2f(-14.0f, -1.0f + 1.8f);
        glEnd();

        glColor3ub(60,80,100);
        glBegin(GL_POLYGON);
        glVertex2f(-15.6f, -1.0f - 1.8f);
        glVertex2f(-14.4f, -1.0f - 1.8f);
        glVertex2f(-14.4f, -1.0f - 0.6f);
        glVertex2f(-15.6f, -1.0f - 0.6f);
        glEnd();
    }

    // cow position (raised slightly so it's on land)
    vcow(-12.0f, -10.0f);

    if (vmode == 1) glColor3ub(255,215,0);
    else glColor3ub(200,200,220);
    vsun(2.0f, 2.4f, -6.0f, 16.0f);

    vclouds();
    vwindmill();
    glutSwapBuffers();
}

void vupdateVillage(int value)
{
    vangle += 2;
    if (vangle > 360) vangle -= 360;

    if (vmode == 2) {
        vfx += 5;
        vfy -= 3;
        if (vfx > 500 || vfy < 0) { vfx = 0; vfy = 500; }
    }

    glutPostRedisplay();
    glutTimerFunc(16, vupdateVillage, 0);
}

void villageKeyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D') vmode = 1;
    if (key == 'n' || key == 'N') vmode = 2;
    glutPostRedisplay();
}

// ========== Setup ==========

void init()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20, 20, -20, 20);
    vinitStars();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1500, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Village Day & Night Scene (Scenario 3 Only) - UPDATED");
    init();
    glutDisplayFunc(villageScenarioDisplay);
    glutKeyboardFunc(villageKeyboard);
    glutTimerFunc(16, vupdateVillage, 0);
    glutMainLoop();
    return 0;
}
