
#include<math.h>
#include<graphics.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<direct.h>

using namespace std;

int width=800,height=600,page =0,r=6,boun=30, leftscore=0,rightscore=0,speed = 18,paddlespeed=17,nol=0,nor=0;//r=radius //speed = 15,paddlespeed=20;

    void end()
    {
        initwindow(width,height,"");
    setfillstyle(1,12);
    bar(0,0,width,boun);
     bar(0,0,boun,height);
     bar(0,height,width,height-boun);
     bar(width-boun,boun,width,height+boun);
    if(leftscore>rightscore)
    {
        settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
        outtextxy(100,height/2-100,"Player 1 wins");
    }
    else if(leftscore<rightscore){

            settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
        outtextxy(100,height/2-100,"Player 2 wins");


    }
        delay(2000);
        exit(1);
    }

void setup()
{


    initwindow(width,height,"");
    //boundary
    setfillstyle(1,14);
     bar(0,0,width,boun);
     bar(0,0,boun,height);
     bar(0,height,width,height-boun);
     bar(width-boun,boun,width,height+boun);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
     outtextxy(100,height/2-60,"LETS BEGIN:");
     delay(2000);
     srand(NULL);

}

//paddle

class Paddle
{
    public:
    float x=10,y=height/2-60,w=x+10,h=height/2+60;

    Paddle(boolean left)
    {
        if(left)
        {
            x = 5;
        }
        else{x=width;}


    }


    void move(float steps)
    {
        int dif = h-y;
        y+=2*steps;
        h+=2*steps;

        if(h <= dif-boun)
        {
         y= y-(2*steps);
        h= h-(2*steps);
        }
        else if(h > height)
        {
         y= y- (2*steps);
        h= h-(2*steps);
        }
    }
    void show()
    {
        setfillstyle(1,8);
        bar(x,y,w,h);

    }
    void show1()
    {
        setfillstyle(1,8);
        int r1=width-20;

        bar(r1,y,r1+15,h);

    }


};

int random(int min ,int max)
{
    int distance,anyRandom,x;
    distance = max-min;
    anyRandom = rand();

    x = anyRandom % distance;
    return(x+min);
}
//puck
class Puck  {
    public:

float x=width/2,y=height/2,xspeed,yspeed;

Puck()
{
    reset();


}
void update()
{
    x=x+xspeed;
    y=y+yspeed;
}


void reset()
{
    x=width/2;
    y=height/2;

    float e =random(45,-135);
    float angle= 0.017453*e;
    if( e == 180 || e == 0)
    {
    float e =random(45,-135);
    float angle= 0.017453*e;
    }
    xspeed=speed*cos(angle);
    yspeed= speed* sin (angle);


}


void edges()
{
    if(y-r-5<5|| y+r+r>height-5)
    {

        yspeed *= -1;
    }

    if(x+r> width )
    {
        leftscore++;
        reset();
    }
    if(x-r<0)
    {
        rightscore++;
        reset();
    }


}
void show()
{
    setfillstyle(1,15);
    fillellipse(x,y,r*2,r*2);
     delay(20);
}

};


//main
int main()
{


 setup();
srand(time(NULL));
Puck puck;
//Paddle object;
Paddle left(true);
Paddle right(false);



int flag=0;
  for(;;)
  {


setactivepage(page);
     setvisualpage(1-page);


  cleardevice();
 //centre bar
       setfillstyle(2,7);
       bar(width/2-10,0,width/2+10,height);

left.show();
right.show1();



char arr[50];
sprintf(arr,"player 1 : %d/11",leftscore);
char arr1[50];
sprintf(arr1,"player 2 : %d/11",rightscore);
setfillstyle(1,2);
settextstyle(DEFAULT_FONT,HORIZ_DIR,-1);
outtextxy(50,50,arr);

outtextxy(width-200,50,arr1);
settextstyle(DEFAULT_FONT,HORIZ_DIR,8);
char w1[50],w2[50];
sprintf(w1,"%d",leftscore);
outtextxy(width/4-10,height/2,w1);
sprintf(w2,"%d",rightscore);
outtextxy(width/4+width/2+10,height/2,w2);

        puck.update();
        puck.edges();
      puck.show();




      if(GetAsyncKeyState('A'))
      {
          left.move(-paddlespeed);
      }
      else if (GetAsyncKeyState('Z'))
      {
          left.move(paddlespeed);
      }


      if(GetAsyncKeyState(VK_UP))
      {
          right.move(-paddlespeed);
      }
      else if (GetAsyncKeyState(VK_DOWN))
      {
          right.move(paddlespeed);
      }


//right seg
  for(int n=0;n<8;n++)
        {
            int seg=0;

            int diff = right.h-right.y;//diff = peddle ki height
            int q = diff/8;

            int a = puck.y;
            int b = right.y + (n*q);
            int c = right.y + ((n+1)*q);
            if( (puck.x >=width-40) && ((a>=b)&&(a<=c)))
            {

                seg=n+1;
                int t=0;
                if (seg ==1 ) {t = 135;}
                else if (seg == 2) {t = 150;}
                 else if (seg == 3) {t = 165;}
                  else if (seg == 4) {t = 180;}
                   else if (seg == 5) {t = 180;}
                    else if (seg == 6) {t = -165;}
                     else if (seg == 7) {t = 170;}
                      else if (seg == 8) {t = -145;}//- ka farak
                int angle = 0.017453 *t;

 puck.xspeed=(-1)*speed*cos(angle);
    puck.yspeed= speed* sin (angle);
                puck.xspeed *= -1;
                nor++;
                break;
            }}
//left seg
  for(int n=0;n<8;n++)
        {
            int seg=0;
            int diff = left.h-left.y;
            int q = diff/8;

            int a = puck.y;
            int b = left.y + (n*q);
            int c = left.y + ((n+1)*q);
            if( (puck.x <= 40) && ((a>=b)&&(a<=c)))
            {

                seg=n+1;
                int t=0;
                if (seg ==1 ) {t = -135;}
                else if (seg == 2) {t = -150;}
                 else if (seg == 3) {t = -165;}
                  else if (seg == 4) {t = 180;}
                   else if (seg == 5) {t = 180;}
                    else if (seg == 6) {t = 165;}
                     else if (seg == 7) {t = 150;}
                      else if (seg == 8) {t = 135;}
                int angle = 0.017453 *t;

 puck.xspeed=speed*cos(angle);
    puck.yspeed= speed* sin (angle);
                puck.xspeed *= -1;
                nol++;
                break;
            }}
//
//for(int i=1;i<5;i++)
//{
//    if(nor> 5*i)
//{
//    speed=speed+5;
//    cout<<speed;
//    break;
//}
//}

if((puck.x>=width/2-20 )&& (puck.x <=  width/2+20)&&(puck.y<0))

{

      int angle = 0.017453 *150;

 puck.xspeed=speed*cos(angle);
    puck.yspeed= speed* sin (angle);
                puck.xspeed *= -1;

}if((puck.x>=width/2-20 )&& (puck.x <= width/2+20)&&(puck.y> height))

{

      int angle = 0.017453 *(-150);

 puck.xspeed=speed*cos(angle);
    puck.yspeed= speed* sin (angle);
                puck.xspeed *= -1;

}
            if((leftscore==11) || (rightscore ==11))
{
    cleardevice();

end();

}
            page = 1 - page;
//delay(20);

  }

exit(1);}


