#include <windows.h>
#include <gl/glut.h>

//com base no algoritimo da professora

int pixel_size = 10;
int size_x = 450;
int size_y = 450;

float toRGBf(int x){
    return (float)x/255;
}

void makeGrid(){

    for(int i = 0; i<=size_x; i+=pixel_size){
        glBegin(GL_LINES);
            glVertex2i(0, 0+i);
            glVertex2i(size_x, 1+i );
            glVertex2i(0+i, 0);
            glVertex2i(1+i, size_y);
        glEnd();
    }
}


void makeLine(int x0, int x1, int y0){

    glBegin(GL_QUAD_STRIP);
        glVertex2i(x0*pixel_size, y0*pixel_size);
        glVertex2i(x0*pixel_size, (y0+1)*pixel_size);
        glVertex2i(x1*pixel_size, y0*pixel_size);
        glVertex2i(x1*pixel_size, (y0+1)*pixel_size);
    glEnd();
}

void makePixel(int x0, int y0){

    glBegin(GL_QUADS);
        glVertex2i(x0*pixel_size, y0*pixel_size);
        glVertex2i(x0*pixel_size, (y0+1)*pixel_size);
        glVertex2i((x0+1)*pixel_size, (y0+1)*pixel_size);
        glVertex2i((x0+1)*pixel_size, y0*pixel_size);
    glEnd();

}

void makeTirion(int i){

    glColor3f(0.0, 0.0, 0.0);
        makeLine(6, 10, 1);
        makeLine(12, 17, 1);
        makePixel(5, 2);
        makePixel(7, 2);
        makeLine(10, 12, 2);
        makePixel(14, 2);
        makeLine(16, 21, 2);
        makePixel(5, 3);
        makePixel(7, 3);
        makeLine(14, 16, 3);
        makePixel(20, 3);
        makeLine(5, 9, 4);
        makeLine(12, 17, 4);
        makePixel(19, 4);
        makeLine(4, 6, 5);
        makePixel(7, 5);
        makePixel(14, 5);
        makePixel(16, 5);
        makePixel(18, 5);
        makeLine(3, 5, 6);
        makePixel(7, 6);
        makePixel(14, 6);
        makeLine(17, 19, 6);
        makePixel(3, 7);
        makeLine(5, 8, 7);
        makeLine(14, 17, 7);
        makePixel(18, 7);
        makePixel(2,8);
        makePixel(8, 8);
        makePixel(13, 8);
        makePixel(19, 8);
        makePixel(2, 9);
        makeLine(7, 15, 9);
        makePixel(19, 9);
        makePixel(3, 10);
        makeLine(5, 7, 10);
        makeLine(15, 17, 10);
        makePixel(18, 10);
        makePixel(2, 11);
        makePixel(5, 11);
        makePixel(16, 11);
        makePixel(19, 11);
        makePixel(2, 12);
        makeLine(4, 6, 12);
        makeLine(9, 12, 12);
        makeLine(16, 18, 12);
        makePixel(19, 12);
        makePixel(3, 13);
        makePixel(5, 13);
        makePixel(16, 13);
        makePixel(18, 13);
        makeLine(1, 3, 14);
        makeLine(4, 6, 14);
        makePixel(8, 14);
        makePixel(12, 14);
        makePixel(16, 14);
        makePixel(1, 15);
        makePixel(3, 15);
        makePixel(5, 15);
        makePixel(16, 15);
        makeLine(1, 4, 16);
        makePixel(5, 16);
        makePixel(16, 16);
        makePixel(6, 17);
        makePixel(15, 17);
        makeLine(6, 16, 18);

    glColor3f(toRGBf(100), toRGBf(100), toRGBf(100));
        makeLine(7, 14, 17);
        makeLine(6, 8, 16);
        makePixel(11, 16);
        makePixel(6, 15);
        makePixel(14, 15);
        makePixel(6, 14);
        makePixel(14, 14);
        makeLine(9, 11, 13);
        makePixel(14, 13);
        makePixel(8, 12);
        makePixel(8, 11);
        makeLine(8, 10, 10);
        makePixel(6, 6);
        makePixel(15, 6);
        makeLine(16, 20, 3);
        makePixel(9, 2);
        makePixel(13, 2);

    glColor3f(toRGBf(130), toRGBf(130), toRGBf(130));
        makePixel(14, 17);
        makeLine(8, 10, 16);
        makeLine(12, 16, 16);
        makePixel(15, 15);
        makePixel(14, 15);
        makePixel(15, 14);
        makePixel(15, 13);
        makePixel(11, 13);
        makePixel(12, 12);
        makePixel(15, 12);
        makePixel(10, 11);
        makePixel(12, 11);
        makePixel(15, 11);
        makeLine(10, 13, 10);
        makePixel(17, 5);
        makeLine(17, 19, 4);

    glColor3f(toRGBf(255), toRGBf(153), toRGBf(102));
        makePixel(10, 16);
        makeLine(7, 14, 15);
        makePixel(7, 14);
        makeLine(9, 12, 14);
        makePixel(13, 14);
        makeLine(6, 9, 13);
        makeLine(12, 14, 13);
        makeLine(6, 8, 12);
        makeLine(13, 15, 12);
        makeLine(6, 8, 11);
        makeLine(13, 15, 11);
        makePixel(9, 11);
        makePixel(11, 11);
        makePixel(7, 10);
        makeLine(13, 15, 10);

    glColor3f(toRGBf(255), toRGBf(189), toRGBf(2));
        makePixel(3, 12);
        makePixel(18, 12);
        makeLine(3, 5, 11);
        makeLine(17, 19, 11);
        makePixel(4, 10);
        makePixel(17, 10);
        makeLine(3, 6, 9);
        makeLine(16, 19, 9);
        makePixel(10, 4);

    glColor3f(toRGBf(173), toRGBf(123), toRGBf(2));
        makePixel(2, 15);
        makePixel(6, 9);
        makePixel(15, 9);
        makeLine(3, 8, 8);
        makeLine(14, 19, 8);
        makePixel(10, 8);
        makePixel(4, 7);
        makeLine(9, 12, 7);
        makePixel(17, 7);
        makePixel(5, 6);
        makePixel(10, 6);
        makePixel(16, 6);
        makePixel(9, 4);
        makePixel(11, 4);
        makePixel(8, 3);
        makePixel(12, 3);

    glColor3f(toRGBf(51), toRGBf(52), toRGBf(47));
        makePixel(9, 8);
        makeLine(11, 13, 8);
        makePixel(8, 7);
        makeLine(12, 14, 7);
        makeLine(8, 10, 6);
        makeLine(11, 13, 6);
        makeLine(9, 12, 5);
        makePixel(10, 3);
        makePixel(8, 2);
        makePixel(12, 2);

    glColor3f(toRGBf(0), toRGBf(52), toRGBf(104));
        makePixel(6, 5);
        makePixel(15, 5);
        makePixel(6, 3);
        makePixel(13, 3);
        makePixel(6, 2);
        makePixel(15, 2);

    glColor3f(toRGBf(160), toRGBf(0), toRGBf(3));
        makePixel(3, 14);
        makePixel(4, 13);

    glColor3f(toRGBf(180), toRGBf(183), toRGBf(252));
        makePixel(13, 6);
        makePixel(8, 5);
        makeLine(12, 14, 5);
        makePixel(9, 3);
        makePixel(11, 3);

    if(i)
        makeGrid();

}

void draw(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    makeTirion(1);
    //glColor3f(1.0, 1.0, 1.0);
    //makeGrid();
    glutSwapBuffers();
    glFlush();
}

void init(){

    glClearColor(toRGBf(85), toRGBf(125), toRGBf(145), 1.0f);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){

    if(h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
    else
        gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(void){

     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(size_x,size_y);
     glutInitWindowPosition(400,200);
     glutCreateWindow("TIRION FORDRING");

     glutDisplayFunc(draw);
     glutReshapeFunc(AlteraTamanhoJanela);

     init();

     glutMainLoop();

}
