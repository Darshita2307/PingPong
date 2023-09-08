// step1: We are including all the libraries and initializing the variables like on line 18
//STEP2: Calling setup//in this we are making boundary of the initial window and greeting the player

#include<math.h> // header file declares a set of functions to perform mathematical operations such as: sqrt() to calculate the square root, All the functions available in this library take double as an argument and return double as the result.

#include<graphics.h> // In C graphics, the graphics. h functions are used to draw different shapes like circles, rectangles, etc, display text(any message) in a different format (different fonts and colors). By using the functions in the header graphics. h, programs, animations, and different games can also be made.

#include<time.h> //contains definitions of functions to get and manipulate date and time information.

#include<windows.h> //used to access the Win32 API functions and it makes it easier for the user to use the in-built functionality. 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<direct.h> // C/C++ header file provided by Microsoft Windows, which contains functions for manipulating file system directories. 

using namespace std;

int width=800,height=600,page =0,r=6,boun=30, leftscore=0,rightscore=0,speed = 18,paddlespeed=17,nol=0,nor=0;//r=radius //speed = 15,paddlespeed=20;

    void end()
    {
        initwindow(width,height,""); //https://home.cs.colorado.edu/~main/bgi/doc/initwindow.html
    setfillstyle(1,12); //sets the current fill pattern and fill color. https://www.geeksforgeeks.org/setfillstyle-floodfill-c/
    bar(0,0,width,boun); //makes a rect// left,top,ri,bott
     bar(0,0,boun,height);
     bar(0,height,width,height-boun);
     bar(width-boun,boun,width,height+boun);
    if(leftscore>rightscore)
    {
        settextstyle(DEFAULT_FONT,HORIZ_DIR,4); //change the way in which text appears. Using it we can modify the size of text, change direction of text and change the font of text. 
        
        outtextxy(100,height/2-100,"Player 1 wins"); //displays the text or string at a specified point (x, y) on the screen.
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

    Paddle(boolean left) //constructor
    {
        if(left)
        {
            
            x = 5;
        }
        else{x=width;}


    }


    void move(float steps)
    {
        int dif = h-y; //height of paddle
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
    //The setup() function is run once, when the program starts. It's used to define initial environment properties such as screen size and to load media such as images and fonts as the program starts. There can only be one setup() function for each program, and it shouldn't be called again after its initial execution.

srand(time(NULL));
// makes use of the computer's internal clock to control the choice of the seed.  Since time is continually changing, the seed is forever changing.  Remember, if the seed number remains the same, the sequence of numbers will be repeated for each run of the program.

//What is normally called a random number sequence in reality is a "pseudo-random" number sequence because the values are computed using a deterministic algorithm and probability plays no real role.
The "seed" is a starting point for the sequence and the guarantee is that if you start from the same seed you will get the same sequence of numbers. This is very useful for example for debugging (when you are looking for an error in a program you need to be able to reproduce the problem and study it, a non-deterministic program would be much harder to debug because every run would be different).
If you need just a random sequence of numbers and don't need to reproduce it then simply use current time as seed... for example with:

    // srand(10); seed=10 here.

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


