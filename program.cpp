//✅ 🔹 For Linux / macOS (most common)
// 👉 Step 1: Compile
// g++ filename.cpp -o output -lGL -lGLU -lglut
// 👉 Step 2: Run
// ./output


// ✅ 🔹 For Windows (MinGW)
// 👉 Compile
// g++ filename.cpp -o output -lfreeglut -lopengl32 -lglu32
// 👉 Run
// output



// ======================================================
// Q1: Implement DDA Line Drawing Algorithm (x1,y1 to x2,y2)
// ======================================================

#include <GL/glut.h>
#include <iostream>
#include <cmath>

float x1, y1, x2, y2;

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
    glPointSize(2);
}

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDA(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    float xi = dx / steps;
    float yi = dy / steps;

    for (int i = 0; i <= steps; i++)
    {
        drawPixel(round(x1), round(y1));
        x1 += xi;
        y1 += yi;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    DDA(x1, y1, x2, y2);
    glFlush();
}

int main(int argc, char **argv)
{
    std::cout << "Enter x1 y1 x2 y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q2: Implement Bresenham Line Drawing Algorithm
// ======================================================

#include <GL/glut.h>
#include <iostream>
#include <cmath>

int x1, y1, x2, y2;

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
    glPointSize(2);
}

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void Bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;

    int p = 2 * dy - dx;

    while (x1 != x2)
    {
        plot(x1, y1);
        x1 += sx;

        if (p < 0)
            p += 2 * dy;
        else
        {
            y1 += sy;
            p += 2 * (dy - dx);
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    Bresenham(x1, y1, x2, y2);
    glFlush();
}

int main(int argc, char **argv)
{
    std::cout << "Enter x1 y1 x2 y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q3: Draw a Solid Filled Circle (Parametric Method)
// ======================================================

#include <GL/glut.h>
#include <cmath>

float cx = 250, cy = 250, r = 100;

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

void drawCircle()
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (float a = 0; a <= 6.28; a += 0.01)
    {
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0.7, 1);
    drawCircle();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Filled Circle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q4: Draw Ellipse and Stretched Ellipse
// ======================================================

#include <GL/glut.h>
#include <cmath>

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void ellipse(float rx, float ry)
{
    glBegin(GL_LINE_LOOP);
    for (float t = 0; t < 6.28; t += 0.01)
        glVertex2f(rx * cos(t), ry * sin(t));
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    ellipse(0.5, 0.3);

    ellipse(0.7, 0.2);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Ellipse");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q5: Draw 5 Nested Concentric Ellipses (Target Pattern)
// ======================================================

#include <GL/glut.h>
#include <cmath>

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void circle(float cx, float cy, float r)
{
    glBegin(GL_LINE_LOOP);
    for (float t = 0; t < 6.28; t += 0.01)
        glVertex2f(cx + r * cos(t), cy + r * sin(t));
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float radius = 0.8f;
    for (int i = 0; i < 5; i++)
    {
        glColor3f(1.0 - i * 0.2, i * 0.2, 1.0 - i * 0.15);
        circle(0, 0, radius);
        radius -= 0.15f;
    }

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Concentric Ellipses");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q6: Archery Target (5 Rings) using Loop
// ======================================================

#include <GL/glut.h>
#include <cmath>

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void circle(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (float a = 0; a <= 6.28; a += 0.01)
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float radius = 0.8f;
    float colors[5][3] = {{1, 0, 0}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 1, 0}};

    for (int i = 0; i < 5; i++)
    {
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        circle(0, 0, radius);
        radius -= 0.15f;
    }

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Archery Target");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q7: Delivery Truck using Primitive Shapes
// ======================================================

#include <GL/glut.h>
#include <cmath>

void circle(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (float t = 0; t <= 6.28; t += 0.01)
        glVertex2f(cx + r * cos(t), cy + r * sin(t));
    glEnd();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Truck body
    glColor3f(0.2, 0.6, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.6, -0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, 0.2);
    glVertex2f(-0.6, 0.2);
    glEnd();

    // Wheels
    glColor3f(0, 0, 0);
    circle(-0.3, -0.25, 0.1);
    circle(0.3, -0.25, 0.1);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Delivery Truck");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q8: Color Cube (2D Representation with Faces Colored)
// ======================================================

#include <GL/glut.h>

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(-0.5, -0.5);
    glColor3f(0, 1, 0);
    glVertex2f(0.5, -0.5);
    glColor3f(0, 0, 1);
    glVertex2f(0.5, 0.5);
    glColor3f(1, 1, 0);
    glVertex2f(-0.5, 0.5);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Color Cube");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q9: Draw a Simple Ellipse
// ======================================================

#include <GL/glut.h>
#include <cmath>

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void ellipse(float rx, float ry)
{
    glBegin(GL_LINE_LOOP);
    for (float t = 0; t <= 6.28; t += 0.01)
        glVertex2f(rx * cos(t), ry * sin(t));
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    ellipse(0.5, 0.3); // normal ellipse
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Simple Ellipse");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q10: Draw a Stretched Ellipse
// ======================================================

#include <GL/glut.h>
#include <cmath>

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void ellipse(float rx, float ry)
{
    glBegin(GL_LINE_LOOP);
    for (float t = 0; t <= 6.28; t += 0.01)
        glVertex2f(rx * cos(t), ry * sin(t));
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);
    ellipse(0.7, 0.2); // stretched horizontally
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Stretched Ellipse");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q11: Draw Nested/Concentric Ellipses (Target Pattern)
// ======================================================

#include <GL/glut.h>
#include <cmath>

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void ellipse(float rx, float ry)
{
    glBegin(GL_LINE_LOOP);
    for (float t = 0; t <= 6.28; t += 0.01)
        glVertex2f(rx * cos(t), ry * sin(t));
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float rx = 0.8, ry = 0.5;

    for (int i = 0; i < 5; i++)
    {
        glColor3f(1.0 - i * 0.2, 0.2 * i, 1.0 - i * 0.15);
        ellipse(rx, ry);
        rx -= 0.15;
        ry -= 0.1;
    }

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Concentric Ellipses");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q12: Cohen-Sutherland Line Clipping
// ======================================================

#include <GL/glut.h>
#include <iostream>

float xmin = 100, ymin = 100, xmax = 400, ymax = 400;
float x1, y1, x2, y2;

const int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;

int computeCode(float x, float y)
{
    int code = INSIDE;
    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;
    return code;
}

bool cohenSutherland(float &x1, float &y1, float &x2, float &y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true)
    {
        if ((code1 | code2) == 0)
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
            break;
        else
        {
            int codeOut = code1 ? code1 : code2;
            float x, y;

            if (codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    return accept;
}

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // draw window
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    float cx1 = x1, cy1 = y1, cx2 = x2, cy2 = y2;

    if (cohenSutherland(cx1, cy1, cx2, cy2))
    {
        glColor3f(0, 1, 0); // clipped line
        glBegin(GL_LINES);
        glVertex2f(cx1, cy1);
        glVertex2f(cx2, cy2);
        glEnd();
    }
    glFlush();
}

int main(int argc, char **argv)
{
    std::cout << "Enter line x1 y1 x2 y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cohen-Sutherland Clipping");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q13: Liang-Barsky Line Clipping Algorithm
// ======================================================

#include <GL/glut.h>
#include <iostream>

float xmin = 100, ymin = 100, xmax = 400, ymax = 400;
float x1, y1, x2, y2;

bool liangBarsky(float &x1, float &y1, float &x2, float &y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    float u1 = 0, u2 = 1;

    for (int i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
                return false;
        }
        else
        {
            float u = q[i] / p[i];
            if (p[i] < 0)
                u1 = std::max(u1, u);
            else
                u2 = std::min(u2, u);
        }
    }

    if (u1 > u2)
        return false;

    float nx1 = x1 + u1 * dx;
    float ny1 = y1 + u1 * dy;
    float nx2 = x1 + u2 * dx;
    float ny2 = y1 + u2 * dy;

    x1 = nx1;
    y1 = ny1;
    x2 = nx2;
    y2 = ny2;

    return true;
}

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // window
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    float a = x1, b = y1, c = x2, d = y2;

    if (liangBarsky(a, b, c, d))
    {
        glColor3f(0, 1, 0);
        glBegin(GL_LINES);
        glVertex2f(a, b);
        glVertex2f(c, d);
        glEnd();
    }

    glFlush();
}

int main(int argc, char **argv)
{
    std::cout << "Enter x1 y1 x2 y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Liang-Barsky Clipping");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q14: Rotate Triangle about Origin and Fixed Point
// ======================================================

#include <GL/glut.h>
#include <cmath>

float angle = 0;

float A[2] = {100, 100}, B[2] = {200, 100}, C[2] = {150, 200};

void drawTriangle(float A[2], float B[2], float C[2])
{
    glBegin(GL_TRIANGLES);
    glVertex2f(A[0], A[1]);
    glVertex2f(B[0], B[1]);
    glVertex2f(C[0], C[1]);
    glEnd();
}

void rotate(float &x, float &y, float cx, float cy)
{
    float rad = angle * 3.14159 / 180;

    float tx = x - cx;
    float ty = y - cy;

    x = cx + (tx * cos(rad) - ty * sin(rad));
    y = cy + (tx * sin(rad) + ty * cos(rad));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float a[2] = {A[0], A[1]}, b[2] = {B[0], B[1]}, c[2] = {C[0], C[1]};

    rotate(a[0], a[1], 150, 150);
    rotate(b[0], b[1], 150, 150);
    rotate(c[0], c[1], 150, 150);

    glColor3f(1, 0, 0);
    drawTriangle(a, b, c);

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 300, 0, 300);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangle Rotation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

// ======================================================
// Q15: Resizable Ellipse using Keyboard
// ======================================================

#include <GL/glut.h>

float rx = 0.5, ry = 0.3;

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

void ellipse()
{
    glBegin(GL_LINE_LOOP);
    for (float t = 0; t <= 6.28; t += 0.01)
        glVertex2f(rx * cos(t), ry * sin(t));
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 1);
    ellipse();
    glFlush();
}

void keyboard(unsigned char key, int, int)
{
    if (key == 'x')
        rx += 0.05;
    if (key == 'y')
        ry += 0.05;
    if (key == 'X')
        rx -= 0.05;
    if (key == 'Y')
        ry -= 0.05;

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Resizable Ellipse");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

// ======================================================
// Q16: Ellipse with Aspect Ratio Preservation
// ======================================================

#include <GL/glut.h>

float rx = 0.7, ry = 0.4;

void init()
{
    glClearColor(0, 0, 0, 1);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)w / h;

    if (w > h)
        gluOrtho2D(-aspect, aspect, -1, 1);
    else
        gluOrtho2D(-1, 1, -1 / aspect, 1 / aspect);

    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);

    glBegin(GL_LINE_LOOP);
    for (float t = 0; t <= 6.28; t += 0.01)
        glVertex2f(rx * cos(t), ry * sin(t));
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Aspect Ratio Ellipse");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}