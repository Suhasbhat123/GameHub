#include<GL/freeglut.h>
#include "general.h"
#define genb 0

 GLfloat ballRadius=25,ballX=0.0,ballY=0.0,ballXMax=350,ballXMin=-550,ballYMin=-225,ballYMax=225;

float xSpeed=0.4f,ySpeed=0.45f;

 int xmin=-575,xmax=375,ymin=-300,ymax=250;
 int bb_i=0;


//game 1 func
void bouncing_ball_game_printing();
void bouncing_ball_game_move_tail();
void bouncing_ball_game_draw_sphere();
void bouncing_ball_game_ui();
void bouncing_ball_game() ;
bool bouncing_ball_game_tail_within_boundary();
void bouncing_ball_game_ball_within_boundary();
void bouncing_ball_game_reset();

void bouncing_ball_game_move_tail_left();
void bouncing_ball_game_move_tail_right();
void bouncing_ball_game_ball_speed_up();


// game 2

void bouncing_ball_game_move_tail_left()
{

if(bb_i==0)
    {;}
    else
    {
        if(bouncing_ball_game_tail_within_boundary())
            {
                    bb_i-=95;
            }
    }


}

void bouncing_ball_game_move_tail_right()
{
    if(bb_i+95==950)
        {;}
    else
    {
        if(bouncing_ball_game_tail_within_boundary())
          {
               bb_i+=95;//tail,brick
          }
     }
}




void bouncing_ball_game_printing()
{
     char score_line[]="Score :";
     char str[100];
     char game1_name[]="Bouncing Ball game";
     drawText(game1_name, -150, 290, 0,0);
     itoa (GAME_SCORE,str,10);
     drawText(strcat(score_line,str), 400, 300, 0,2);
     drawText("Press Esc to exit ", 400, 200, 0,5);
     drawText("Press F1 for main menu ", 400, 100, 0,5);
     drawText("use Left & Right  ", 400, 00, 0,5);
     drawText("arrow keys to move tile ", 400, -50, 0,5);
     if(GAME_OVER==1)
        {
        game_over_func(-180);
        bouncing_ball_game_reset();
        }
}
//general func

 void bouncing_ball_game_move_tail()
  {
    //to draw tail game 1 bouncing ball
    glBegin(GL_POLYGON); //body
    color = createColor(174, 147, 138, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(xmin+95 + bb_i, -250, 0);
    glVertex3f(xmin+ bb_i, -250, 0);
    color = createColor(1, 14, 1, 0);
    glColor3f(color.red, color.green, color.blue);
    glVertex3f(xmin+ bb_i, -275, 0);
    glVertex3f(xmin+95 + bb_i, -275, 0);
    glEnd();
}

void bouncing_ball_game_draw_sphere()
{
   // bouncing_ball_game_ball_speed_up();
        int numseg=255;
        glTranslatef(ballX,ballY,0);
        glBegin(GL_POLYGON);
        GLfloat an;
        glColor3f(color.red, color.green, color.blue);
        for(int i=0;i<numseg;i++)
            {
                an=i*2.0f *3.141 /numseg;
                if(an<256)
                color = createColor(i,i,i, 1);
                glColor3f(color.red, color.green, color.blue);
                glVertex3f(cos(an)*ballRadius,sin(an)*ballRadius,0);
            }
        glEnd();
        bouncing_ball_game_ball_within_boundary();

}


void bouncing_ball_game_ui()
 {
    RgbColor color1,color2,color3;
    color1 =createColor(109, 200, 241, 0);
    color2 = createColor(0, 0, 0, 1);
    color3=createColor(101,67,33,1);


    ui(color1,color2,color3);

    glPushMatrix();
    color1 =createColor(145, 110, 10, 1);
    color2 = createColor(60, 62, 60, 1);
    draw_box(12,13,17,18,color1,color2);

    glBegin(GL_LINES);
    glVertex3f(-575, -275, 0);
    glVertex3f(375, -275, 0);
    glEnd();

//user functions


//drawing drawing sphere
    if(GAME_OVER==0)
    {
      bouncing_ball_game_move_tail();
      bouncing_ball_game_draw_sphere();

    }
    glPopMatrix();
}

void bouncing_ball_game()
{

    glPushMatrix();

    bouncing_ball_game_ui();
    bouncing_ball_game_printing();

    glPopMatrix();

}



bool bouncing_ball_game_tail_within_boundary()
{
    if((bb_i >=0&& bb_i+95<=950))
        {
        return true;
        }
    return false;
}

void bouncing_ball_game_ball_within_boundary(){

 ballX+=xSpeed;
 ballY+=ySpeed;
 if(ballX>ballXMax)
    {
        ballX=ballXMax;
        xSpeed=-(xSpeed);
    }
 else
 if(ballX<ballXMin)
    {
        ballX=ballXMin;
        xSpeed= -(xSpeed);
    }
 if(ballY>ballYMax)
    {
        ballY=ballYMax;
        ySpeed=-(ySpeed);
    }
 else
 if(ballY<ballYMin)
    {
        ballY=ballYMin;
        ySpeed= -(ySpeed);
        if(!(bb_i+xmin-25<=ballX && ballX<=bb_i+95+25+xmin ))
            {
                GAME_OVER=1;

            }
        else
            {
                GAME_SCORE+=10;

            }

    }
}


void bouncing_ball_game_reset()
{
    ballRadius=25;ballX=0.0;ballY=0.0;ballXMax=350;ballXMin=-550;ballYMin=-225;ballYMax=225;

    xSpeed=0.4f;ySpeed=0.45f;


    xmin=-575;xmax=375;ymin=-300;ymax=250;
    bb_i=0;

}


