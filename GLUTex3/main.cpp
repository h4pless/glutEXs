#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

int size_x = 450;
int size_y = 450;

struct p{
    int x, y;
};

vector<p> points;

float toRGBf(int x);
void myMouse(int button, int state, int x, int y);
void pListaPontos();
void addPoint(int x, int y);
void draw();
void init();
void makePoint(int x, int y);
void drawPoints();
void drawLines();
float calcDistancia(int x1, int y1, int x2, int y2);
int menorDistancia(int x, int y);

float toRGBf(int x){
    return (float)x/255;
}

void myMouse(int button, int state, int x, int y){

    int md;

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        makePoint(x, y);
        if(points.size()>1)
        drawLines();
    }else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        md = menorDistancia(x, y);
        points.erase(points.begin()+md);
        drawLines();
    }
    glFlush();
}

int menorDistancia(int x, int y){

    int md = 0;
    int aux;

    for(int i = 1; i < points.size(); i++){
        aux = calcDistancia(x, y, points.at(i).x, points.at(i).y);
        if(aux < calcDistancia(x, y, points.at(md).x, points.at(md).y))
            md = i;
    }
    return md;
}

float calcDistancia(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void pListaPontos(){

    for(int i = 0; i < points.size(); i++){
        cout << endl << "x: [" << i << "]" << points.at(i).x << "\ny: [" << i << "]" << points.at(i).y << endl << endl;
    }
}


void makePoint(int x, int y){

    p p1;
    p1.x = x;
    p1.y = y;
    points.push_back(p1);
    drawPoints();

    cout << "######" << endl;
    pListaPontos();
    cout << "######" << endl;

    glFlush();
}

void drawPoints(){

    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < points.size(); i++){
        glBegin(GL_POINTS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2i(points.at(i).x, points.at(i).y);
        glEnd();
    }
    glFlush();
}

void drawLines(){

    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 1; i < points.size(); i++){

        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2i(points.at(i-1).x, points.at(i-1).y);
            glVertex2i(points.at(i).x, points.at(i).y);
            glVertex2i(points.at(i-1).x, points.at(i-1).y);
            glVertex2i(points.at(i).x, points.at(i).y);
        glEnd();
        glFlush();
    }


}


void draw(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);
    glFlush();
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, size_x, size_y, 0);
    glClearColor(toRGBf(85), toRGBf(125), toRGBf(145), 1.0f);
}



int main(void){

     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(size_x,size_y);
     glutInitWindowPosition(400,200);
     glutCreateWindow("Exercicio 1");
     glutDisplayFunc(draw);
     glutMouseFunc(myMouse);
     init();
     glutMainLoop();
}
