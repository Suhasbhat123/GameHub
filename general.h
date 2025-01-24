
#include <GL/glut.h>
#include<math.h>



int GAME_OVER=0,GAME_SCORE=0;
int SCENE = -1,flag=0;
int level=0;



 typedef float  xy[3];
 xy p[]={{-670,350,0},{670,350,0},{670,-350,0},{-670,-350,0},
             {-600,350,0},{-600,-350,0},{400,-350,0},{400,350,0},
             {-600,-300,0},{-600,275,0},{-575,275,0},{-575,-300,0},
             {375,-300,0},{375,275,0},{400,275,0},{400,-300,0},
             { 375,250,0},{-575,250,0},{400,250,0}
};

typedef struct stColor {
    double red, green, blue;
    double alpha;
} RgbColor;


RgbColor createColor(int red, int green, int blue, double alpha) {
    RgbColor color;
    color.red = (double)red / 256;
    color.green = (double)green / 256;
    color.blue = (double)blue / 256;
    color.alpha = (double)alpha;
    return color;
}

RgbColor color;

int CURRENT_WINDOW=1;

void reshape(int width, int height);
void initGL(int width, int height);
void idle();
void draw_box( int i,int j,int k,int l,RgbColor color1,RgbColor color2);
void ui(RgbColor color1,RgbColor color2,RgbColor color3);

void game_over_func(int x);

void ui(RgbColor color1,RgbColor color2,RgbColor color3)
{
    glPushMatrix();

//up
     draw_box(10,15,8,5,color2,color2);
//down
    draw_box(9,16,7,6,color2,color2);
//left
    draw_box(1,4,6,5,color1,color2);
//right
    draw_box(8,7,3,2,color2,color1);
//u1
    draw_box(11,15,19,18,color2,color3);
//u2
    draw_box(10,9,12,11,color2,color2);
//u3
    draw_box(13,14,15,16,color2,color2);
 //game place


    glPopMatrix();
}
//general function
void draw_box( int i,int j,int k,int l,RgbColor color1,RgbColor color2)
{
    glColor3f(color1.red, color1.green, color1.blue);
    glBegin(GL_POLYGON);
    glVertex3f(p[i-1][0], p[i-1][1], p[i-1][2]);
    glVertex3f(p[j-1][0], p[j-1][1], p[j-1][2]);
    glColor3f(color2.red, color2.green, color2.blue);
    glVertex3f(p[k-1][0], p[k-1][1], p[k-1][2]);
    glVertex3f(p[l-1][0], p[l-1][1], p[l-1][2]);
    glEnd();
}

//generalfunction
void drawText(char text[], int x, int y, int z,int font)
{



// The color
    glColor3f(1, 1, 1);
// Position of the text to be printer
    glRasterPos3f(x, y, z);
    for (int i = 0; text[i] != '\0'; i++)
        {

        switch(font)
        {
            case 1:  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, text[i]);
                        break;
            case 2:    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
                        break;

            case 3:  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, text[i]);
                        break;
            case 4:  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
                        break;
             case 5:  glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
                        break;

            default: glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);

        }

        }
}


void idle()
 {
    glutPostRedisplay();
 }
void reshape(int width, int height)
 {
    GLfloat fieldOfView = 90.0f;
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-662, 662, -350, 350, -450, 450);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initGL(int width, int height)
{
    reshape(width, height);
    glClearColor(0.2f, 0.8f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}



void game_over_func(int x)
{
    char game_over_score[20];
    char str[]=" Your Score is  :";
    drawText("  Game over ", x, 00, 0,0);
    drawText("  press R to restart game ", x, -30, 0,0);
    itoa (GAME_SCORE,game_over_score,10);
    drawText(strcat(str,game_over_score), x, -60, 0,0);
}
