#include<GL/freeglut.h>
#ifndef genb && gena
#include "general.h"
#endif
#define genc 0

float ws_i1=00,ws_i2=00,ws_i3=0,ws_i4=0,car1=00,car2=200,car3=400,car4=600;

float car_x1=-375,car1_x1=-375,car2_x1=-375,car3_x1=-375,car4_x1=-375,speed=0.2;


void white_line(int x1,int x2);
void draw_car(float c_x1,float c_y1,int c_type);
void car_game();
void car_game_ui();
void side_grass_road();
void move_car_left();
void move_car_right();
void draw_oppo_car();
void car_game_reset();
void car_game_speed_up();

void car_game_speed_up()
{
level=GAME_SCORE/50;
 if(GAME_SCORE%50==0){
        speed=0.3;

   for(int i=0;i<=GAME_SCORE/50;i++){
        speed+=0.1;
    if(GAME_SCORE/50==i)
    break;
   }
}

}

void car_game_printing()
{
     char score_line[]="Score :";
     char level_line[]="Level :";
     char str[100],str1[100];

     char game1_name[]="C A R   R A C E ";
     drawText(game1_name, -150, 290, 0,0);
     itoa (GAME_SCORE,str,10);
     itoa (level,str1,10);

     drawText(strcat(score_line,str), 400, 300, 0,2);
     drawText(strcat(level_line,str1), 400, 250, 0,2);
     drawText("Press Esc to exit ", 400, 200, 0,5);
     drawText("Press F1 for main menu ", 400, 100, 0,5);
     drawText("use Left & Right  ", 400, 00, 0,5);
     drawText("arrow keys to move car ", 400, -50, 0,5);
     if(GAME_OVER==1)
        {

        game_over_func(-375);

        }
}
void car_game_reset()
{
 car_x1=-375;car1_x1=-375;car2_x1=-375;car3_x1=-375;car4_x1=-375;
 ws_i1=00;ws_i2=00;ws_i3=0;ws_i4=0;car1=00;car2=200;car3=400,car4=600;
  level=0;
}



void draw_oppo_car()
{

    draw_car(car1_x1,car1,2);
    car1-=speed;
    if(car1<-375)
        {
        car1=225;
        car1_x1=car_x1;

        GAME_SCORE+=10;

        }

 if(( car_x1==car1_x1&&car1<-200)&&car1>-280-80)
     GAME_OVER=1;


    draw_car(car2_x1,car2,2);

    car2-=speed;
    if(car2<-375)
    {
      car2=225;
      car2_x1=car_x1;GAME_SCORE+=10;
    }
     if( (car_x1==car2_x1&&car2<-200)&&car2>-280-80)
     GAME_OVER=1;


draw_car(car3_x1,car3,2);
 car3-=speed;
    if(car3<-375)
    {
      car3=225;
      car3_x1=car_x1;GAME_SCORE+=10;
    }
 if( (car_x1==car3_x1&&car3<-200)&&car3>-280-80)
     GAME_OVER=1;


draw_car(car4_x1,car4,2);
 car4-=speed;
    if(car4<-375)
    {
      car4=225;
      car4_x1=car_x1;GAME_SCORE+=10;
    }
 if( (car_x1==car4_x1&&car4<-200)&&car4>-280-80)
     GAME_OVER=1;

car_game_speed_up();
}
void move_car_left()
{
   if(car_x1==-375)
        car_x1=-375;
    else
        car_x1-=90;
}


void move_car_right()
{
   if(car_x1==75)
        car_x1=75;
    else
        car_x1+=90;
}


void draw_car(float c_x1,float c_y1,int c_type)
{
     RgbColor color1;
     color1 =createColor(255,255, 255, 0);
     if(c_type==1)
        {
            //body
             color1 =createColor(20,100, 155, 0);
            glColor3f(color1.red, color1.green, color1.blue);
             glBegin(GL_POLYGON);
            glVertex3f(c_x1+30,c_y1,-1);
            glVertex3f(c_x1+70,c_y1,-1);
             color1 =createColor(250,200, 250, 0);
             glColor3f(color1.red, color1.green, color1.blue);

            glVertex3f(c_x1+70,c_y1+60,-1);
            glVertex3f(c_x1+30,c_y1+60,-1);
            glEnd();
            //triangle
            color1 =createColor(200,100, 155, 0);
            glColor3f(color1.red, color1.green, color1.blue);
            glBegin(GL_POLYGON);
            glVertex3f(c_x1+50,c_y1+80,-1);
            color1 =createColor(20,100, 155, 0);
            glColor3f(color1.red, color1.green, color1.blue);
            glVertex3f(c_x1+30,c_y1+60,-1);
            glVertex3f(c_x1+70,c_y1+60,-1);

            glEnd();
            //wheel
            color1 =createColor(20,25, 25, 0);
            glColor3f(color1.red, color1.green, color1.blue);

            glBegin(GL_POLYGON);
            glVertex3f(c_x1+20,c_y1+5,-1);
            glVertex3f(c_x1+30,c_y1+5,-1);
            glVertex3f(c_x1+30,c_y1+20,-1);
            glVertex3f(c_x1+20,c_y1+20,-1);

            glEnd();

            glBegin(GL_POLYGON);
            glVertex3f(c_x1+70,c_y1+5,-1);
            glVertex3f(c_x1+80,c_y1+5,-1);
            glVertex3f(c_x1+80,c_y1+20,-1);
            glVertex3f(c_x1+70,c_y1+20,-1);

            glEnd();
            //front wheel
             glBegin(GL_POLYGON);
            glVertex3f(c_x1+20,c_y1+45,-1);
            glVertex3f(c_x1+30,c_y1+45,-1);
            glVertex3f(c_x1+30,c_y1+60,-1);
            glVertex3f(c_x1+20,c_y1+60,-1);

            glEnd();

            glBegin(GL_POLYGON);
            glVertex3f(c_x1+70,c_y1+45,-1);
            glVertex3f(c_x1+80,c_y1+45,-1);
            glVertex3f(c_x1+80,c_y1+60,-1);
            glVertex3f(c_x1+70,c_y1+60,-1);

            glEnd();



        }
        else

        {

//triangle
             color1 =createColor(200,100, 155, 0);
            glColor3f(color1.red, color1.green, color1.blue);
            glBegin(GL_POLYGON);
            glVertex3f(c_x1+50,c_y1,-1);
            color1 =createColor(20,100, 155, 0);
            glColor3f(color1.red, color1.green, color1.blue);
            glVertex3f(c_x1+30,c_y1+20,-1);
            glVertex3f(c_x1+70,c_y1+20,-1);

            glEnd();

            //box
             color1 =createColor(200,100, 155, 0);
            glColor3f(color1.red, color1.green, color1.blue);
            glBegin(GL_POLYGON);
            glVertex3f(c_x1+30,c_y1+20,-1);
            glVertex3f(c_x1+70,c_y1+20,-1);
            glVertex3f(c_x1+70,c_y1+80,-1);
            glVertex3f(c_x1+30,c_y1+80,-1);

            glEnd();
            //wheel
              color1 =createColor(0,0, 0, 0);
            glColor3f(color1.red, color1.green, color1.blue);
            glBegin(GL_POLYGON);
            glVertex3f(c_x1+20,c_y1+35,-1);
            glVertex3f(c_x1+30,c_y1+35,-1);
            glVertex3f(c_x1+30,c_y1+20,-1);
            glVertex3f(c_x1+20,c_y1+20,-1);

            glEnd();
             glBegin(GL_POLYGON);
            glVertex3f(c_x1+70,c_y1+35,-1);
            glVertex3f(c_x1+80,c_y1+35,-1);
            glVertex3f(c_x1+80,c_y1+20,-1);
            glVertex3f(c_x1+70,c_y1+20,-1);

            glEnd();
  // front wheel
              color1 =createColor(0,0, 0, 0);
            glColor3f(color1.red, color1.green, color1.blue);
            glBegin(GL_POLYGON);
            glVertex3f(c_x1+20,c_y1+75,-1);
            glVertex3f(c_x1+30,c_y1+75,-1);
            glVertex3f(c_x1+30,c_y1+60,-1);
            glVertex3f(c_x1+20,c_y1+60,-1);

            glEnd();
             glBegin(GL_POLYGON);
            glVertex3f(c_x1+70,c_y1+75,-1);
            glVertex3f(c_x1+80,c_y1+75,-1);
            glVertex3f(c_x1+80,c_y1+60,-1);
            glVertex3f(c_x1+70,c_y1+60,-1);

            glEnd();



        }
}


void white_line(int x1,int x2)
{


    RgbColor color1;
    color1 =createColor(255,255, 255, 0);
    glColor3f(color1.red, color1.green, color1.blue);
    glBegin(GL_POLYGON);
    glVertex3f(x1,350+ws_i1,-1);
    glVertex3f(x2,350+ws_i1,-1);
    glVertex3f(x2,250+ws_i1,-1);
    glVertex3f(x1,250+ws_i1,-1);
    glEnd();
    ws_i1-=0.1;
    if(ws_i1<-200)
        {
            ws_i1 =00;
        }



    glColor3f(color1.red, color1.green, color1.blue);
    glBegin(GL_POLYGON);
    glVertex3f(x1,150+ws_i2,-1);
    glVertex3f(x2,150+ws_i2,-1);
    glVertex3f(x2,50+ws_i2,-1);
    glVertex3f(x1,50+ws_i2,-1);
    glEnd();
    ws_i2-=0.1;
    if(ws_i2<-200)
        {
            ws_i2 =0;
        }



    glColor3f(color1.red, color1.green, color1.blue);
    glBegin(GL_POLYGON);
    glVertex3f(x1,-50+ws_i3,-1);
    glVertex3f(x2,-50+ws_i3,-1);
    glVertex3f(x2,-150+ws_i3,-1);
    glVertex3f(x1,-150+ws_i3,-1);
    glEnd();
    ws_i3-=0.1;
    if(ws_i3<-200)
        {
            ws_i3 =0;
        }



    glColor3f(color1.red, color1.green, color1.blue);
    glBegin(GL_POLYGON);
    glVertex3f(x1,-250+ws_i4,-1);
    glVertex3f(x2,-250+ws_i4,-1);
    glVertex3f(x2,-350+ws_i4,-1);
    glVertex3f(x1,-350+ws_i4,-1);
    glEnd();
    ws_i4-=0.1;
    if(ws_i4<-200)
        {
            ws_i4 =00;
        }

}


void side_grass_road()
{//grass
     RgbColor color1,color2,color3;
    color1 =createColor(0, 211, 10, 0);
    color2 = createColor(10, 0, 10, 1);
    color3=createColor(100,120,33,1);

    glBegin(GL_POLYGON);
    glColor3f(color1.red, color1.green, color1.blue);
    glVertex3f(-575, -300, -2);
    glVertex3f(-500, -300, -2);
    glColor3f(color2.red, color2.green, color2.blue);
    glVertex3f(-500, 250, -2);
    glVertex3f(-575, 250, -2);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(color1.red, color1.green, color1.blue);
    glVertex3f(300, -300, -2);
    glVertex3f(375, -300, -2);
    glColor3f(color2.red, color2.green, color2.blue);
    glVertex3f(375, 250, -2);
    glVertex3f(300, 250, -2);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(color1.red, color1.green, color1.blue);
    glVertex3f(-400, -300, -2);
    glVertex3f(-500, -300, -2);
    glColor3f(color2.red, color2.green, color2.blue);
    glVertex3f(-500, 250, -2);
    glVertex3f(-400, 250, -2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(color1.red, color1.green, color1.blue);
    glVertex3f(300, -300, -2);
    glVertex3f(200, -300, -2);
    glColor3f(color2.red, color2.green, color2.blue);
    glVertex3f(200, 250, -2);
    glVertex3f(300, 250, -2);
    glEnd();


    //road
    color1 =createColor(175, 192, 190, 0);

    glBegin(GL_POLYGON);
    glColor3f(color1.red, color1.green, color1.blue);
    glVertex3f(-400, -300, -2);
    glVertex3f(200, -300, -2);

    glVertex3f(200, 250, -2);
    glVertex3f(-400, 250, -2);
    glEnd();
//white strip
     color1 =createColor(255, 255, 255, 0);

    glBegin(GL_POLYGON);
    glColor3f(color1.red, color1.green, color1.blue);
    glVertex3f(-120, -300, -2);
    glVertex3f(-80, -300, -2);

    glVertex3f(-80, 250, -2);
    glVertex3f(-120, 250, -2);
    glEnd();
    color1 =createColor(0, 0, 0, 0);
     glBegin(GL_POLYGON);
    glColor3f(color1.red, color1.green, color1.blue);
    glVertex3f(-105, -300, -2);
    glVertex3f(-95, -300, -2);

    glVertex3f(-95, 250, -2);
    glVertex3f(-105, 250, -2);
    glEnd();

}

//game 2
void car_game()
{

    glPushMatrix();

    car_game_ui();
//printing
    car_game_printing();

    glPopMatrix();


}





void car_game_ui(){
   RgbColor color1,color2,color3;
    color1 =createColor(211, 211, 211, 0);
    color2 = createColor(10, 0, 10, 1);
    color3=createColor(100,120,33,1);



    ui(color1,color2,color3);

    glPushMatrix();
    color1 = createColor(255, 255, 200, 1);
    color2 =createColor(135,206, 235, 1);
     color = createColor(81, 81, 81, 0);



    glBegin(GL_POLYGON);
    glColor3f(color1.red, color1.green, color1.blue);
    glVertex3f(-575, -300, -2);
    glVertex3f(375, -300, -2);
    glColor3f(color2.red, color2.green, color2.blue);
    glVertex3f(375, 250, -2);
    glVertex3f(-575, 250, -2);
    glEnd();
      //road


//user functions

 side_grass_road();


 if(GAME_OVER==0)
 {
      white_line(-260,-240);
      white_line(40,60);
      draw_car(car_x1,-280,1);
      draw_oppo_car();
 }
  glPopMatrix();


}
