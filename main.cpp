#include <stdio.h>
#include "bouncingball.h"
#include "about.h"
#include "car.h"

void drawMainScene();
void draw();
void keyboardDown(unsigned char key, int x, int y);
void specialKey(int key,int x,int y);
void  drawcertificate();
void draw();

void timer(int);


int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1244, 700);
    glutInitWindowPosition(100, 0);
    glutCreateWindow("Vehicles");

    // register glut call backs
    glutKeyboardFunc(keyboardDown);
    glutReshapeFunc(reshape);
    glutDisplayFunc(draw);
    glutIdleFunc(idle);
    glutIgnoreKeyRepeat(1); // ignore keys held down
    glutSpecialFunc(specialKey);
    glutTimerFunc(100,timer,0);
    initGL(1244, 700);
    glutMainLoop();
    return 0;
}

 void drawcertificate()
 {

      glBegin(GL_QUADS);
    color = createColor(120, 120, 65, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(-670.0, 350.0);

    color = createColor(25, 20, 30, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(670.0, 350.0);

    color = createColor(0, 0, 0, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(670.0, -350.0);

    color = createColor(120, 120, 65, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(-670.0, -350.0);
    glEnd();

    glClearColor(1.0, 1.0, 1.0, 1.0);
    char h1[] = "  Project  Title  :  G A M E  H U B    ";
    char message1[] = "Developed by   : ";
    char message2[] = "Suhas Bhat  (4MW20CS093) ";
    char message3[] = "Sri Harsha Upadhya P  (4MW20CS090) ";

    drawText(h1, -500, 60, 0,2);

    drawText(message1, -480, -60, 0,0);
    drawText(message2, -320, -60, 0,5);
    drawText(message3, -320, -90, 0,5);
    drawText("Press  F1 to Enter Main Menu ", -480, -300, 0,4);



 }

void drawMainScene()
{
    glBegin(GL_QUADS);
    color = createColor(0, 0, 0, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(-670.0, 350.0);

    color = createColor(25, 20, 30, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(670.0, 350.0);

    color = createColor(0, 0, 0, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(670.0, -350.0);

    color = createColor(125, 120, 130, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex2f(-670.0, -350.0);
    glEnd();

    glClearColor(1.0, 1.0, 1.0, 1.0);
    char h1[] = " Computer Graphics Project";
    char h2[] = " <-- G A M E   H U B -->";


    char message1[] = "Press 1 for Bouncing Ball Game ";
    char message2[] = "Press 2 for  Car Race ";

    drawText(h1, -160, 200, 0,2);
    drawText(h2, -150, 120, 0,0);

    drawText(message1, -120, -150, 0,5);
    drawText(message2, -120, -200, 0,5);


}


void keyboardDown(unsigned char key, int x, int y) {

    switch (key) {

       case 48: if(flag==0)
                        {
                            SCENE=0;
                            GAME_OVER=0;
                            flag=1;
                            GAME_SCORE=0;

                        }
    case 49: //enter 1
                if(CURRENT_WINDOW==0)
                {
                    SCENE = 1;//game1
                    GAME_OVER=0;
                    GAME_SCORE=0;
                }
                break;
    case 50:    if(CURRENT_WINDOW==0)
                {
                    SCENE = 2;//game2
                    GAME_OVER=0;
                    GAME_SCORE=0;

                }
                break;

    case 'R':
    case 'r':
              if(GAME_OVER==1)
                {
                     bouncing_ball_game_reset();
                     car_game_reset();
                }
                GAME_OVER=0;
                GAME_SCORE=0;

                break;
    case 'Q':
    case 'q':
    case  27:   // ESC
                exit(0);//about developer
                break;
    case  57: if(CURRENT_WINDOW==0)
                 SCENE=9;
               break;

    }
}

void specialKey(int key,int x,int y)
{
    switch(key)
    {
        case GLUT_KEY_F1:
                        SCENE=0;
                        GAME_OVER=1;
                        bouncing_ball_game_reset();
                        car_game_reset();
                        break;

        case GLUT_KEY_LEFT :
        case GLUT_KEY_UP   :if(CURRENT_WINDOW==1)
                                bouncing_ball_game_move_tail_left();
                            if(CURRENT_WINDOW==2)
                                move_car_left();

                            glutPostRedisplay();
                            break;
        case GLUT_KEY_RIGHT :
        case GLUT_KEY_DOWN  :if(CURRENT_WINDOW==1)
                                bouncing_ball_game_move_tail_right();
                             if(CURRENT_WINDOW==2)
                                move_car_right();

                            glutPostRedisplay();
                            break;
    }
}


void timer(int){
    glutPostRedisplay();
    glutTimerFunc(100,timer,0);
}
void draw()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
// render the scene here
    switch (SCENE)
    {
        case -1:CURRENT_WINDOW=-1;
                drawcertificate();




                break;
        case 0: CURRENT_WINDOW=0;
                drawMainScene();
                break;

        case 1: CURRENT_WINDOW=1;
                bouncing_ball_game();
                break;
        case 2: CURRENT_WINDOW=2;

                car_game();
                break;

    }
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}




