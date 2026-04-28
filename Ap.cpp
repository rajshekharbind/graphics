//How to install Open Gl in Ubuntu 
//sudo apt update
//sudo apt install freeglut3-dev

//How to remove 
//sudo apt remove freeglut3-dev




.
.
.
CODES JUST SEARCH WITH CTRL +F 
.
.
.

// Truck code
#include <GL/glut.h>
#include <cmath>
using namespace std;

void circle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1416f * i / 100;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(100, 200);
    glVertex2f(400, 200);
    glVertex2f(400, 350);
    glVertex2f(100, 350);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(400, 200);
    glVertex2f(500, 200);
    glVertex2f(500, 300);
    glVertex2f(400, 300);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    circle(180, 180, 40);
    circle(420, 180, 40);

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(50, 140);
    glVertex2f(550, 140);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(200, 270);
    const char *text = "CG LAB";
    for (int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 400);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Truck");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

g++ file.cpp -o truck -lGL -lGLU -lglut -lm

//Archer Code
#include <GL/glut.h>
#include <cmath>
using namespace std;

float colors[5][3] = {
    {1,1,1},
    {0,0,0},
    {0,0,1},
    {1,0,0},
    {1,1,0}
};

void circle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1416f * i / 100;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}

void drawText(float x, float y, const char* str) {
    glRasterPos2f(x, y);
    for (int i = 0; str[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float cx = 300, cy = 300;
    float r = 150;

    for (int i = 0; i < 5; i++) {
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        circle(cx, cy, r);
        r -= 30;
    }

    glColor3f(0,0,0);
    drawText(295, 300, "50");
    drawText(285, 330, "40");
    drawText(275, 360, "30");
    drawText(265, 390, "20");
    drawText(255, 420, "10");

    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,600,0,600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutCreateWindow("Archery Target");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}


// Parametric Circles
#include <GL/glut.h>
#include <cmath>
using namespace std;

int segments = 20;
float radius = 0.7f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1,0,0);
    glVertex2f(0,0);

    glColor3f(0,0,1);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * 3.1416f * i / segments;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }

    glEnd();
    glFlush();
}

void specialKeys(int key, int, int) {
    if (key == GLUT_KEY_UP) segments += 2;
    if (key == GLUT_KEY_DOWN && segments > 3) segments -= 2;
    glutPostRedisplay();
}

void init() {
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutCreateWindow("Parametric Circle");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
}


//Adjustable Ellipse

#include <GL/glut.h>
#include <cmath>
using namespace std;

float a = 0.7f, b = 0.4f;
int segments = 100;
int w = 600, h = 600;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,0,0);
    glVertex2f(0,0);

    glColor3f(0,0,1);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * 3.1416f * i / segments;
        float x = a * cos(theta);
        float y = b * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-a, -b);
    glVertex2f(a, -b);
    glVertex2f(a, b);
    glVertex2f(-a, b);
    glEnd();

    glFlush();
}

void reshape(int width, int height) {
    w = width;
    h = height;
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)w / h;

    if (aspect >= 1)
        gluOrtho2D(-aspect, aspect, -1, 1);
    else
        gluOrtho2D(-1, 1, -1/aspect, 1/aspect);
}

void keyboard(unsigned char key, int, int) {
    if (key == 'w') b += 0.05f;
    if (key == 's' && b > 0.05f) b -= 0.05f;
    if (key == 'd') a += 0.05f;
    if (key == 'a' && a > 0.05f) a -= 0.05f;
    glutPostRedisplay();
}

void init() {
    glClearColor(1,1,1,1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutCreateWindow("Ellipse");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

//Cohen Sutherland 
#include <GL/glut.h>

float xmin=100, ymin=100, xmax=400, ymax=300;
float x_start=50, y_start=50, x_end=450, y_end=350;

const int INSIDE=0, LEFT=1, RIGHT=2, BOTTOM=4, TOP=8;

int code(float x, float y){
    int c=INSIDE;
    if(x < xmin) c |= LEFT;
    else if(x > xmax) c |= RIGHT;
    if(y < ymin) c |= BOTTOM;
    else if(y > ymax) c |= TOP;
    return c;
}

void cohen(){
    float x=x_start, y=y_start, xE=x_end, yE=y_end;
    int c1=code(x,y), c2=code(xE,yE);
    bool accept=false;

    while(true){
        if((c1 | c2) == 0){
            accept = true;
            break;
        }
        else if(c1 & c2){
            break;
        }
        else{
            float xint=0, yint=0;
            int out = c1 ? c1 : c2;

            if(out & TOP){
                if(yE != y){
                    xint = x + (xE-x)*(ymax-y)/(yE-y);
                    yint = ymax;
                }
            }
            else if(out & BOTTOM){
                if(yE != y){
                    xint = x + (xE-x)*(ymin-y)/(yE-y);
                    yint = ymin;
                }
            }
            else if(out & RIGHT){
                if(xE != x){
                    yint = y + (yE-y)*(xmax-x)/(xE-x);
                    xint = xmax;
                }
            }
            else if(out & LEFT){
                if(xE != x){
                    yint = y + (yE-y)*(xmin-x)/(xE-x);
                    xint = xmin;
                }
            }

            if(out == c1){
                x = xint; y = yint;
                c1 = code(x,y);
            } else {
                xE = xint; yE = yint;
                c2 = code(xE,yE);
            }
        }
    }

    if(accept){
        glColor3f(1,0,0);
        glLineWidth(3);   // 🔴 visibility
        glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(xE,yE);
        glEnd();
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // window
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();

    // original line
    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex2f(x_start,y_start);
    glVertex2f(x_end,y_end);
    glEnd();

    // clipped
    cohen();

    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Cohen Sutherland");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}


//Lians -Barsky line Clipping
#include <GL/glut.h>
#include <iostream>
using namespace std;

float xmin=2,xmax=4,ymin=2,ymax=4;
float x1=1,y1=1,x2=5,y2=5;

void liang(){
    float dx=x2-x1, dy=y2-y1;
    float p[4]={-dx,dx,-dy,dy};
    float q[4]={x1-xmin,xmax-x1,y1-ymin,ymax-y1};
    float t1=0,t2=1;

    for(int i=0;i<4;i++){
        if(p[i]==0 && q[i]<0) return;
        float t=q[i]/p[i];
        if(p[i]<0) t1=max(t1,t);
        else if(p[i]>0) t2=min(t2,t);
    }

    if(t1<=t2){
        float nx1=x1+t1*dx, ny1=y1+t1*dy;
        float nx2=x1+t2*dx, ny2=y1+t2*dy;

        glColor3f(1,0,0);
        glBegin(GL_LINES);
        glVertex2f(nx1,ny1); glVertex2f(nx2,ny2);
        glEnd();
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin); glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax); glVertex2f(xmin,ymax);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex2f(x1,y1); glVertex2f(x2,y2);
    glEnd();

    liang();
    glFlush();
}

void init(){ glClearColor(1,1,1,1); gluOrtho2D(0,6,0,6); }

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Liang Barsky");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
//Bresenham line algorithm

#include <GL/glut.h>
#include <cmath>

void plot(int x,int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void bres(int x1,int y1,int x2,int y2){
    int dx=abs(x2-x1), dy=abs(y2-y1);
    int sx=(x1<x2)?1:-1;
    int sy=(y1<y2)?1:-1;
    int err=dx-dy;

    while(true){
        plot(x1,y1);
        if(x1==x2 && y1==y2) break;
        int e2=2*err;
        if(e2>-dy){ err-=dy; x1+=sx; }
        if(e2<dx){ err+=dx; y1+=sy; }
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    bres(50,50,400,300);
    glFlush();
}

void init(){ glClearColor(1,1,1,1); gluOrtho2D(0,500,0,500); }

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}


// 2-D triangle Rotation
#include <GL/glut.h>

float angle = 0;

void drawTriangle(){
    glBegin(GL_TRIANGLES);
    glVertex2f(0,50);
    glVertex2f(-50,-50);
    glVertex2f(50,-50);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 🔵 Rotation about ORIGIN
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(100,200,0);   // move origin visually
    glRotatef(angle,0,0,1);    // rotate about origin
    drawTriangle();
    glPopMatrix();

    // 🔴 Rotation about FIXED POINT (200,200)
    glColor3f(0,0,1);
    glPushMatrix();
    glTranslatef(200,200,0);   // move pivot to origin
    glRotatef(angle,0,0,1);    // rotate
    glTranslatef(-200,-200,0); // move back
    glTranslatef(200,200,0);   // draw at pivot
    drawTriangle();
    glPopMatrix();

    glFlush();
}

void timer(int){
    angle += 2;
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

void init(){
    glClearColor(1,1,1,1);
    gluOrtho2D(0,400,0,400);
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitWindowSize(400,400);
    glutCreateWindow("Rotation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
}
//3D Colour Blue
#include <GL/glut.h>

float angle = 0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(3,3,3, 0,0,0, 0,1,0);

    glRotatef(angle,1,1,0);

    glColor3f(0,1,1);
    glutSolidCube(1);

    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60, (float)w/h, 1, 20);
}

void timer(int){
    angle += 1;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("3D Cube");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);   // 🔴 important
    glutTimerFunc(0,timer,0);

    glutMainLoop();
}


//Bezier Curve
#include <GL/glut.h>
#include <cmath>
using namespace std;

float t = 0;

float bez(float p0,float p1,float p2,float p3,float u){
    return (1-u)*(1-u)*(1-u)*p0 +
           3*u*(1-u)*(1-u)*p1 +
           3*u*u*(1-u)*p2 +
           u*u*u*p3;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,1);
    glLineWidth(3);

    glBegin(GL_LINE_STRIP);
    for(float u=0; u<=1; u+=0.01){
        float x = 100 + 300*u;
        float y = bez(200, 250 + 40*sin(t), 150, 200, u);
        glVertex2f(x,y);
    }
    glEnd();

    glFlush();
}

void timer(int){
    t += 0.1;
    glutPostRedisplay();
    glutTimerFunc(30,timer,0);
}

void init(){
    glClearColor(1,1,1,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);   // 🔴 VERY IMPORTANT
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bezier Flag");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);

    glutMainLoop();
}

//Polygon Clippping
#include <GL/glut.h>
#include <vector>
using namespace std;

float xmin=100,xmax=300,ymin=100,ymax=300;

struct P{float x,y;};

vector<P> clip(vector<P> poly){
    vector<P> out=poly;

    for(int edge=0;edge<4;edge++){
        vector<P> input=out;
        out.clear();

        for(int i=0;i<input.size();i++){
            P curr=input[i];
            P prev=input[(i+input.size()-1)%input.size()];

            bool currIn = (edge==0?curr.x>=xmin:edge==1?curr.x<=xmax:edge==2?curr.y>=ymin:curr.y<=ymax);
            bool prevIn = (edge==0?prev.x>=xmin:edge==1?prev.x<=xmax:edge==2?prev.y>=ymin:prev.y<=ymax);

            if(currIn){
                if(!prevIn){
                    float x,y;
                    if(edge<2){
                        float xedge=(edge==0?xmin:xmax);
                        y=prev.y+(curr.y-prev.y)*(xedge-prev.x)/(curr.x-prev.x);
                        x=xedge;
                    }else{
                        float yedge=(edge==2?ymin:ymax);
                        x=prev.x+(curr.x-prev.x)*(yedge-prev.y)/(curr.y-prev.y);
                        y=yedge;
                    }
                    out.push_back({x,y});
                }
                out.push_back(curr);
            }
            else if(prevIn){
                float x,y;
                if(edge<2){
                    float xedge=(edge==0?xmin:xmax);
                    y=prev.y+(curr.y-prev.y)*(xedge-prev.x)/(curr.x-prev.x);
                    x=xedge;
                }else{
                    float yedge=(edge==2?ymin:ymax);
                    x=prev.x+(curr.x-prev.x)*(yedge-prev.y)/(curr.y-prev.y);
                    y=yedge;
                }
                out.push_back({x,y});
            }
        }
    }
    return out;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    vector<P> poly={{50,150},{200,350},{350,150}};

    vector<P> clipped=clip(poly);

    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    for(auto p:clipped) glVertex2f(p.x,p.y);
    glEnd();

    glFlush();
}

void init(){ glClearColor(1,1,1,1); gluOrtho2D(0,500,0,500); }

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Polygon Clip");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}


//DDA Line ALgorithm
#include <GL/glut.h>
#include <cmath>
using namespace std;

float x_start = 50, y_start = 50;
float x_end   = 400, y_end   = 300;

void DDA() {
    float dx = x_end - x_start;
    float dy = y_end - y_start;

    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x_start;
    float y = y_start;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2f(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);
    glPointSize(4);

    DDA();

    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//Bresenham Line algorithm
#include <GL/glut.h>
#include <cmath>

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void Bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        drawPixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);
    glPointSize(4);   // 🔴 makes line visible

    Bresenham(50, 50, 400, 300);

    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//COncenctric Ellipse

#include <GL/glut.h>
#include <cmath>
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float rx = 0.1f;
    float ry = 0.05f;

    glLineWidth(2);   // better visibility

    for (int j = 0; j < 5; j++) {

        glColor3f((j+1)*0.18f, 0.2f, 1.0f - j*0.18f);  // safe color range

        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.1416f / 180.0f;
            float x = rx * cos(theta);
            float y = ry * sin(theta);
            glVertex2f(x, y);
        }
        glEnd();

        rx += 0.1f;
        ry += 0.05f;
    }

    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutCreateWindow("Concentric Ellipses");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//Resizable Ellipse
#include <GL/glut.h>
#include <cmath>
using namespace std;

float w = 0.5f;
float h = 0.3f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // filled ellipse
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,0,0);
    glVertex2f(0,0);

    glColor3f(0,0,1);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 3.1416f / 180.0f;
        float x = w * cos(theta);
        float y = h * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // boundary (for clarity)
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 3.1416f / 180.0f;
        glVertex2f(w * cos(theta), h * sin(theta));
    }
    glEnd();

    glFlush();
}

void specialKeys(int key, int, int) {
    if (key == GLUT_KEY_RIGHT) w += 0.05f;
    if (key == GLUT_KEY_LEFT && w > 0.05f)  w -= 0.05f;

    if (key == GLUT_KEY_UP)    h += 0.05f;
    if (key == GLUT_KEY_DOWN && h > 0.05f)  h -= 0.05f;

    glutPostRedisplay();
}

void init() {
    glClearColor(1,1,1,1);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutCreateWindow("Resizable Ellipse");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
}


//Line CLiipping COhen SUtherland #include <GL/glut.h>

float xmin = 100, ymin = 100, xmax = 400, ymax = 300;
float x_start = 50, y_start = 50, x_end = 450, y_end = 350;

int code(float x, float y) {
    int c = 0;
    if (x < xmin) c |= 1;
    if (x > xmax) c |= 2;
    if (y < ymin) c |= 4;
    if (y > ymax) c |= 8;
    return c;
}

void clip() {
    float x = x_start, y = y_start;
    float xE = x_end, yE = y_end;

    int c1 = code(x, y);
    int c2 = code(xE, yE);

    bool accept = false;

    while (true) {
        if ((c1 | c2) == 0) {
            accept = true;
            break;
        }
        else if (c1 & c2) {
            break;
        }
        else {
            float xint, yint;
            int c = c1 ? c1 : c2;

            if (c & 8) {
                xint = x + (xE - x) * (ymax - y) / (yE - y);
                yint = ymax;
            }
            else if (c & 4) {
                xint = x + (xE - x) * (ymin - y) / (yE - y);
                yint = ymin;
            }
            else if (c & 2) {
                yint = y + (yE - y) * (xmax - x) / (xE - x);
                xint = xmax;
            }
            else {
                yint = y + (yE - y) * (xmin - x) / (xE - x);
                xint = xmin;
            }

            if (c == c1) {
                x = xint;
                y = yint;
                c1 = code(x, y);
            } else {
                xE = xint;
                yE = yint;
                c2 = code(xE, yE);
            }
        }
    }

    if (accept) {
        glColor3f(1, 0, 0);
        glLineWidth(3);   // 🔴 visible clipped line
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(xE, yE);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // window
    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    // original line (blue dashed look)
    glColor3f(0, 0, 1);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(x_start, y_start);
    glVertex2f(x_end, y_end);
    glEnd();

    // clipped line
    clip();

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cohen Sutherland Clipping");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//Ellipse
#include <GL/glut.h>
#include <cmath>
using namespace std;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    float a=0.6, b=0.3;

    glColor3f(0,0,0);   // 🔴 important
    glLineWidth(3);     // 🔴 makes it visible

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++){
        float t = i * 3.1416 / 180;
        glVertex2f(a*cos(t), b*sin(t));
    }
    glEnd();

    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Ellipse");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//Circle
#include <GL/glut.h>
#include <cmath>
using namespace std;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);   // 🔴 important
    glLineWidth(3);     // 🔴 makes circle visible

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++){
        float t = i * 3.1416 / 180;
        glVertex2f(0.5 * cos(t), 0.5 * sin(t));
    }
    glEnd();

    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}


//Line Drawing DDA
#include <GL/glut.h>
#include <cmath>
using namespace std;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);
    glPointSize(5);   // 🔴 IMPORTANT

    float x1=50, y1=50, x2=400, y2=300;
    float dx=x2-x1, dy=y2-y1;

    float steps = fabs(dx)>fabs(dy)?fabs(dx):fabs(dy);

    float xi=dx/steps, yi=dy/steps;

    float x=x1, y=y1;

    glBegin(GL_POINTS);
    for(int i=0;i<=steps;i++){
        glVertex2f(round(x), round(y));   // 🔴 FIX
        x+=xi;
        y+=yi;
    }
    glEnd();

    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//Triangle
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(100,100);
    glVertex2f(200,100);
    glVertex2f(150,200);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//Parallel Lines
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex2f(100,200); glVertex2f(400,200);
    glVertex2f(100,250); glVertex2f(400,250);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Parallel Lines");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//Perpendicular Lines
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2f(250,100); glVertex2f(250,400);
    glVertex2f(100,250); glVertex2f(400,250);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Perpendicular Lines");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

//g++ file.cpp -o run -lGL -lGLU -lglut
//./run