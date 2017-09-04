#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct p{
    int x, y;
};

vector<p> points ;

int size_x = 450;
int size_y = 450;

float toRGBf(int x);
void makePoint(int x, int y);
void myMouse(int button, int state, int x, int y);
void draw(int x, int y);
void init();
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void pListaPontos();
void drawPoints();
int menorDistancia(int x, int y);

void pListaPontos(){

    for(int i = 0; i < points.size(); i++){
        cout << endl << "x: [" << i << "]" << points.at(i).x << "\ny: [" << i << "]" << points.at(i).y << endl << endl;
    }
}

float toRGBf(int x){
    return (float)x/255;
}

void makePoint(int x, int y){

    p p1;
    p1.x = x;
    p1.y = y;
    points.push_back(p1);
    drawPoints();
    glFlush();
    cout << "######" << endl;
    pListaPontos();
    cout << "######" << endl;
}

void drawPoints(){

    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < points.size(); i++){
        glBegin(GL_POINTS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2i(points.at(i).x, points.at(i).y);
        glEnd();
    }
}

float calcDistancia(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void myMouse(int button, int state, int x, int y){

    p paux;
    int md;

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        makePoint(x, y);
    }else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        md = menorDistancia(x, y);
        points.push_back(points.at(md));
        points.erase(points.begin()+md);
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

void myKeyboard(int key, int x, int y){

    p paux;

    switch(key){
        case GLUT_KEY_UP:
            cout << "up" << endl;
            paux.x = points.at(points.size()-1).x;
            paux.y = points.at(points.size()-1).y-5;
            points.pop_back();
            points.push_back(paux);
            cout << "&&&&&&&&" << endl;
            pListaPontos();
            cout << "&&&&&&&&" << endl;
            drawPoints();
            glFlush();
            break;

        case GLUT_KEY_DOWN:
            cout << "down" << endl;
            paux.x = points.at(points.size()-1).x;
            paux.y = points.at(points.size()-1).y+5;
            points.pop_back();
            points.push_back(paux);
            cout << "&&&&&&&&" << endl;
            pListaPontos();
            cout << "&&&&&&&&" << endl;
            drawPoints();
            glFlush();
            break;

        case GLUT_KEY_RIGHT:
            cout << "right" << endl;
            paux.x = points.at(points.size()-1).x+5;
            paux.y = points.at(points.size()-1).y;
            points.pop_back();
            points.push_back(paux);
            cout << "&&&&&&&&" << endl;
            pListaPontos();
            cout << "&&&&&&&&" << endl;
            drawPoints();
            glFlush();
            break;

        case GLUT_KEY_LEFT:
            cout << "left" << endl;
            paux.x = points.at(points.size()-1).x-5;
            paux.y = points.at(points.size()-1).y;
            points.pop_back();
            points.push_back(paux);
            cout << "&&&&&&&&" << endl;
            pListaPontos();
            cout << "&&&&&&&&" << endl;
            drawPoints();
            glFlush();
            break;

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
     glutCreateWindow("Exercicio 2");
     glutDisplayFunc(draw);
     glutMouseFunc(myMouse);
     glutSpecialFunc(myKeyboard);
     init();
     glutMainLoop();
}
