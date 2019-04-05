//points are not shown because at the end of 8th volley the points2 are not morphed properly
#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<iomanip.h>
#include<fstream.h>
#include<math.h>
#include<string.h>
#include<alloc.h>
#include "c:\\turboc3\\bin\\function.cpp"
void menu();
void saucer(double,double);
void morphsaucer(double,double);
void shoot1(double,double,double,double,double,double,double,double,double,double,int);
void shoot2(double,double,double,double,double,double,double,double,double,double,int);
double speedbar1(double);
void showspeedbar1(double);
double speedbar2(double);
void showspeedbar2(double);
void blast(double,double,double);
void battlefield(void);
int points1=0; //for points
int points2=0;
int gettankcolor();
void tank(double,double,int);
void winner(double,double,double,double);
void winnersound(void);
void introsound(void);
void save(char [],char []);
double mod(double);

struct profile
{
char name[50];
int points;
};
struct depot
{
char name[8][20];
int weapons[8],used[8],availableweapons;

	depot(int weap[8])
	{
	 for(int j=0;j<8;j++)
	 {
	  used[j]=0;
	  weapons[j]=weap[j];
	  switch(weap[j])
	  {
	   case 1:strcpy(name[j],"RED BALL");
		  break;
	   case 2:strcpy(name[j],"ROD");
		  break;
	   case 3:strcpy(name[j],"SINE LASER");
		  break;
	   case 4:strcpy(name[j],"SCATTER SHOT");
		  break;
	   case 5:strcpy(name[j],"SPACE CANNON");
		  break;
	   case 6:strcpy(name[j],"SAUCER ATTACK");
		  break;
	   case 7:strcpy(name[j],"COLOR BOMB");
		  break;
	   case 8:strcpy(name[j],"SQUARE BOMB");
		  break;
	   case 9:strcpy(name[j],"BOUNCY BALL");
		  break;
	   case 10:strcpy(name[j],"CRUISER");
		  break;
	  }//end of switch

	 }//end of for
	 availableweapons=8;

	}//end of depot constructor

     void update()
     {  int i,j,temporary;
	char temp[20];
	for(i=0;i<8;i++)
	{
	  if(used[i]==1)
	  {
	    for(j=i;j<8;j++) //j<7 because we compare
	    {
	      if(used[j+1]==0)
	      {
	      strcpy(temp,name[j]);
	      strcpy(name[j],name[j+1]);
	      strcpy(name[j+1],temp);
	      used[j]=0;      used[j+1]=1;
	      temporary=weapons[j];
	      weapons[j]=weapons[j+1];
	      weapons[j+1]=temporary;
	      }
	    }

	  //if(i<7)
	   // i--; //to use it again when many 1's are present in a row

	  }//end of if(used[i]==1)

	}//end of for

	availableweapons=0;
	for(i=0;i<8;i++)
	  if(used[i]==0)
	    availableweapons++;

     }//end of update

     int defaulted()
     {
      for(int i=0;i<8;i++)
       if(used[i]==0)
	 return (i+1);

      return (i+1);
     }

};

void main()
{
int a=1;
 while(a==1)
 {
 menu();
 }

}



void game()
{
cleardevice();


double x=100,y=280,x1,y1,ang1=0,x2,y2,speed1=40,a=550,b=280,a1,b1,ang2=M_PI,a2,b2,speed2=40;
int i,weapon1[8],weapon2[8],tankcolor1,tankcolor2;
char player1[50]="player1",player2[50]="player2";
//introsound();

i=6;
setcolor(YELLOW);
settextstyle(3, HORIZ_DIR, 3);
setbkcolor(BLACK);//as background is white when game() is invoked as cleardevice() is invoked in last function
outtextxy(100,100,"ENTER FIRST PLAYER NAME:");
//cout<<"\n\n\n\n\n\n\n\t\t\t\t\t";
//gets(player1);
for( ; ; )
{
 setcolor(YELLOW);
 settextstyle(3, HORIZ_DIR,3);
 outtextxy(400,100,player1);
 char leg;
 leg=getch();
 setcolor(BLACK);
 settextstyle(3, HORIZ_DIR,3);
 outtextxy(400,100,player1);
 if(leg==13)
 {
    setcolor(YELLOW);
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(400,100,player1);
    player1[i+1]='\0';
    break;
 }
 else if(leg=='\b')
 {
     player1[i]='\0';
   if(i>=0)    //i>=0 and not i>0 because if '\b' is given till name has no characters then we can't type it again
     i--;
 }
 else
 {
   player1[i+1]=leg;
   i++;
 }
setcolor(YELLOW);
settextstyle(3, HORIZ_DIR, 3);
outtextxy(400,100,player1);
}

if(strlen(player1)==0)
  strcpy(player1,"player1");

tankcolor1=gettankcolor();

clrscr();
cleardevice();

i=6;
setcolor(YELLOW);
settextstyle(3, HORIZ_DIR, 3);
outtextxy(100,100,"ENTER SECOND PLAYER NAME:");
//cout<<"\n\n\n\n\n\n\n\t\t\t\t\t";
//gets(player2);
for( ; ; )
{
 setcolor(YELLOW);
 settextstyle(3, HORIZ_DIR, 3);
 outtextxy(430,100,player2);
 char leg;
 leg=getch();
 setcolor(BLACK);
 settextstyle(3, HORIZ_DIR, 3);
 outtextxy(430,100,player2);
 if(leg==13)
 {
    setcolor(YELLOW);
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(430,100,player2);
    player2[i+1]='\0';
    break;
 }
 else if(leg=='\b')
 {
     player2[i]='\0';
   if(i>=0)    //i>=0 and not i>0 because if '\b' is given till name has no characters then we can't type it again
     i--;
 }
 else
 {
   player2[i+1]=leg;
   i++;
 }
setcolor(YELLOW);
settextstyle(3, HORIZ_DIR, 3);
outtextxy(430,100,player2);
}

if(strlen(player2)==0)
  strcpy(player2,"player2");

tankcolor2=gettankcolor();
randomize();
//tankcolor1=random(14)+1;
//tankcolor2=random(14)+1;

chooseweapon(weapon1,weapon2,player1,player2);
/*
 for(int temp=0;temp<8;temp++)
 {
  weapon1[temp]=random(10)+1;
  weapon2[temp]=random(10)+1;
 }
*/
depot weapondepot1(weapon1),weapondepot2(weapon2);
char cnt[5],displaypoints1[5],displaypoints2[5];  //displaying volleys
int temp1=1,temp2=1,defaulttemp1=1,defaulttemp2=1;

settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
for(i=0;i<16;i++) //8 volleys
{

   if(i%2==0)
   {
     defaulttemp1=weapondepot1.defaulted();
     temp1=defaulttemp1;
     for( ; ; )
      {
      clrscr();
      cleardevice();
      battlefield();
      tank(x,y,tankcolor1);
     tank(a,b,tankcolor2);
     x1=20*cos(ang1);   a1=20*cos(ang2);    x2=30*cos(ang1);  a2=30*cos(ang2);
     y1=20*sin(ang1);   b1=20*sin(ang2);    y2=30*sin(ang1);  b2=20*sin(ang2);
     line(x,y-8,x+x1,y-8-y1);    //pipe of first tank
     line(a,b-8,a+a1,b-8-b1);    //pipe of second tank

     showspeedbar1(speed1);

     setcolor(YELLOW);
     sprintf(displaypoints1,"%i",points1);
     outtextxy(10,0,player1);
     outtextxy(10,10,displaypoints1);
     sprintf(displaypoints2,"%i",points2);
     outtextxy(550,0,player2);
     outtextxy(550,10,displaypoints2);

     setcolor(LIGHTCYAN);
     sprintf(cnt,"%i",i/2+1);
     outtextxy(200,0,cnt);
     outtextxy(210,0,"volley");
     //cout<<cnt<<"volley";
      outtextxy(50,450,weapondepot1.name[temp1-1]);

      char key=getch();

      if(key=='a' && x>10) x-=5;
      if(x<275)   if(key=='d') x+=5;

      if(ang1>=0-M_PI/72 && ang1<=M_PI+M_PI/72)
	{
	if(ang1>0) if(key==77) ang1-=M_PI/72;
	if(ang1<M_PI) if(key==75)  ang1+=M_PI/72;
	}

      //for first tank
      if(key=='x')
     {
       setcolor(YELLOW);
       rectangle(8,398,92,412);
       speed1=speedbar1(speed1);
     }//key='x'

     if(key=='j')
     {    if(temp1>1)
	    temp1--;
     }
     if(key=='l')
     {    if(temp1<weapondepot1.availableweapons)
	    temp1++;
     }


     if(key=='s')
     {
       defaulttemp1=temp1;
       shoot1(x+x2,y2,speed1,ang1,x,y,x1,y1,a,b,weapondepot1.weapons[defaulttemp1-1]); //earlier it was weapondepot1.weapons[i/2]
       weapondepot1.used[temp1-1]=1;
       weapondepot1.update();
      /* if(o>x-20 && o<x+20)   //to blaxt if it hits the tank
       { blast(o,y,5);
	 blast(o,y,10);
	 blast(o,y,15);
	 erg1-=10;    //lose points if tank hits

       }
       if(o>a-20 && o<a+20)   //to blaxt if it hits the tank
	{ blast(o,b,5);
	  blast(o,b,10);
	  blast(o,b,15);
	  erg2-=10;    //lose points if tank hits
	}
	delay(500);//to see the projectile
		 */
	break;

     }

     if(key=='e' || key==27) exit(0);

      }


   }//end of if

   else
   {
     defaulttemp2=weapondepot2.defaulted();
     temp2=defaulttemp2;
    for( ; ; )
     {
      clrscr();
      cleardevice();
      battlefield();

      tank(x,y,tankcolor1);
      tank(a,b,tankcolor2);
      x1=20*cos(ang1);   a1=20*cos(ang2);    x2=30*cos(ang1);  a2=30*cos(ang2);
      y1=20*sin(ang1);   b1=20*sin(ang2);    y2=30*sin(ang1);  b2=20*sin(ang2);
      line(x,y-8,x+x1,y-8-y1);    //pipe of first tank
      line(a,b-8,a+a1,b-8-b1);    //pipe of second tank
      showspeedbar2(speed2);

     setcolor(YELLOW);
     sprintf(displaypoints1,"%i",points1);
     outtextxy(10,0,player1);
     outtextxy(10,10,displaypoints1);
     sprintf(displaypoints2,"%i",points2);
     outtextxy(550,0,player2);
     outtextxy(550,10,displaypoints2);

      setcolor(LIGHTCYAN);
      sprintf(cnt,"%i",i/2+1);
      outtextxy(200,0,cnt);
      outtextxy(210,0,"volley");
      //cout<<cnt<<"volley";
      outtextxy(500,450,weapondepot2.name[temp2-1]);

      char key=getch();
      if(a>360)   if(key=='a') a-=5;
      if(key=='d' && a<630) a+=5;

	if(ang2>=0-M_PI/72 && ang2<=M_PI+M_PI/72)
	{
	if(ang2>0) if(key==77) ang2-=M_PI/72;
	if(ang2<M_PI) if(key==75)  ang2+=M_PI/72;
	}

      //for second tank
      if(key=='x')
      {
	setcolor(YELLOW);
	rectangle(548,398,632,412);
	speed2=speedbar2(speed2);
      }

     if(key=='j')
     {    if(temp2>1)
	    temp2--;
     }
     if(key=='l')
     {    if(temp2<weapondepot2.availableweapons)
	    temp2++;
     }


      if(key=='s')
      {
	defaulttemp2=temp2;
	shoot2(a+a2,b2,speed2,ang2,a,b,a1,b1,x,y,weapondepot2.weapons[defaulttemp2-1]); //earlier it was weapondepot2.weapons[i/2]
	weapondepot2.used[temp2-1]=1;
	weapondepot2.update();
       /* if(o>a-20 && o<a+20)   //to blaxt if it hits the tank
       { blast(o,b,5);
	blast(o,b,10);
	blast(o,b,15);
	erg2-=10;    //lose points if tank hits
       }
       if(o>x-20 && o<x+20)   //to blaxt if it hits the tank
       { blast(o,y,5);
	blast(o,y,10);
	blast(o,y,15);
	erg1-=10;    //lose points if tank hits
       }
       delay(500);//to see the projectile
		*/
       break;

      }


      if(key=='e'|| key==27) exit(0);





     }

   } //end of else


}//end of for(i=0;i<20;i++)
setcolor(YELLOW);
sprintf(displaypoints1,"%i",points1);
outtextxy(10,0,player1);
outtextxy(10,10,displaypoints1);
sprintf(displaypoints2,"%i",points2);
outtextxy(550,0,player2);
outtextxy(550,10,displaypoints2);
save(player1,player2);
winner(x,y,a,b);
getch();

}//end of void game()



void shoot1(double f1,double f2,double v,double ang,double f3,double f4,double f5,double f6,double f7,double f8,int weapon)
{      //shoot1(x+x2,y2,speed1,ang1,x,y,x1,y1,a,b,weapondepot1.weapons[i/2] )

/*   double g=9.8,x=0,y=0;
    for(double p=0; x<=640 && y>=-f2;p+=0.01 )
	{
	   //y>=-f2 is for making projectile reach the floor of the tank
	y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(weapon);
	setfillstyle(SOLID_FILL,weapon);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,weapon);
	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);

	}
	setcolor(weapon);
	setfillstyle(SOLID_FILL,weapon);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,weapon);    */

 double g=9.8,p,x=0,y=0,slope,stangle,x1,y1,x2,y2,x3,y3,x4,y4,nlang,r;
 double ang1=M_PI/6,ang2=M_PI/3,ang3=M_PI/4;
 int dir;

     //to morph when the the points are not right at last
     char displaypoints1[5],displaypoints2[5];
     setcolor(BLACK);
     sprintf(displaypoints1,"%i",points1);
     outtextxy(10,10,displaypoints1);
     sprintf(displaypoints2,"%i",points2);
     outtextxy(550,10,displaypoints2);

switch(weapon)
{
case 1:
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>3)
		 points1-=3;
		else
		 points1=0;

		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}



	break; //end of case 1

case 2:
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{
	//slope=( ((v*sin(ang)*(p+1))-(0.5*g*(p+1)*(p+1)) ) - (v*sin(ang)*p)-(0.5*g*p*p) )/( v*cos(ang)*(p+1) - v*cos(ang)*p );

	slope= (v*sin(ang)-g*p)/(v*cos(ang) );
	y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	stangle=atan(slope);
	x1=10*cos(stangle);
	y1=10*sin(stangle);
	setcolor(WHITE);
	line(x+x1+f1,280-y-y1-f2,x-x1+f1,280-y+y1-f2);
		if(x+x1+f1>f7-15 && x+x1+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=8;
		break;
	       }
	       if(x+x1+f1>f3-15 && x+x1+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>4)
		 points1-=4;
		else
		 points1=0;
		break;
	       }
	delay(3);
	setcolor(BLACK);
	line(x+x1+f1,280-y-y1-f2,x-x1+f1,280-y+y1-f2);

	}
	setcolor(WHITE);
	line(x+x1+f1,280-y-y1-f2,x-x1+f1,280-y+y1-f2);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}

	//to see the line properly after drawing the curve
	setcolor(WHITE);
	line(x+x1+f1,280-y-y1-f2,x-x1+f1,280-y+y1-f2);


	break; //end of case 2

case 3: p=0;
	do
	{
	nlang=atan( -1.0/tan(ang) );

	x1=p*cos(ang);
	y1=p*sin(ang);
	r=5*sin(p/5);

	x2=r*cos(nlang);
	y2=r*sin(nlang);

	setcolor(MAGENTA);
	line(x+f1,280-y-f2,x+x1+f1,280-y-y1-f2);
	putpixel(x+x1+x2+f1,280-y-y1-y2-f2,BLUE);

		if(x+x1+x2+f1>f7-15 && x+x1+x2+f1<f7+15 && 280-y-y1-y2-f2>f8)   //to blaxt if it hits the tank
	       { blast(x+x1+x2+f1,280-y-y1-y2-f2,5);
		blast(x+x1+x2+f1,280-y-y1-y2-f2,10);
		blast(x+x1+x2+f1,280-y-y1-y2-f2,15);
		points1+=10;
		break;
	       }
	       if(x+x1+x2+f1>f3-15 && x+f1<f3+15 && 280-y-y1-y2-f2>f4)   //to blaxt if it hits the tank
	       { blast(x+x1+x2+f1,280-y-y1-y2-f2,5);
		blast(x+x1+x2+f1,280-y-y1-y2-f2,10);
		blast(x+x1+x2+f1,280-y-y1-y2-f2,15);
		if(points1>6)
		 points1-=6;
		else
		 points1=0;
		break;
	       }

	p++;
	delay(5);
	}while(x+x1+f1>0 && x+x1+f1<640 && 240-y-y1-f2>0 && 240-y-y1-f2<480);

	break; //end of case 3

case 4:  //scatter shot
	ang1=M_PI/6;  ang2=M_PI/3;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,1);
	floodfill(x+f1,280-y-f2,RED);

		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=8;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>4)
		 points1-=4;
		else
		 points1=0;
		break;
	       }
	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,1);
	floodfill(x+f1,280-y-f2,BLACK);
	}

	int disable1=0,disable2=0,disable3=0,disable4=0;
	x1=0; y1=0;//sometimes x1 and y1 takes junk values and this for loop dosen't happen
	double v1=30.0;
	double v2=v1/sqrt(3.0);
	for(p=0; x1<=640 && y1>=-f2;p+=0.01 )
	{
	//  T=2usin(theta)/g
	//  T60 degrees=2*u(60 degrees)*sin(60 degrees)/g
	//  T30 degrees=2*u(30 degrees)*sin(30 degrees)/g
	//  T60 degrees=T30 degrees
	//  2*u(60 degrees)*sin(60 degrees)/g=2*u(30 degrees)*sin(30 degrees)/g
	//  sqrt(3.0)*u(60 degrees)=u(30 degrees)

	    y1=(v1*sin(ang1)*p)-(0.5*g*p*p);
	    x1=v1*cos(ang1)*p;
	   if(disable1==0)
	   {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(f1+x-x1,280-y1-f2,1);
	    floodfill(f1+x-x1,280-y1-f2,RED);

		if(f1+x-x1>f7-15 && f1+x-x1<f7+15 && 280-y1-f2>f8)   //to blaxt if it hits the tank
	       { blast(f1+x-x1,280-y1-f2,5);
		blast(f1+x-x1,280-y1-f2,10);
		blast(f1+x-x1,280-y1-f2,15);
		points1+=5;
		disable1=1;
	       }
	       if(f1+x-x1>f3-15 && f1+x-x1<f3+15 && 280-y1-f2>f4)   //to blaxt if it hits the tank
	       { blast(f1+x-x1,280-y1-f2,5);
		blast(f1+x-x1,280-y1-f2,10);
		blast(f1+x-x1,280-y1-f2,15);
		if(points1>2)
		 points1-=2;
		else
		 points1=0;
		disable1=1;
	       }
	   }//if(disable1==0)

	    y2=(v2*sin(ang2)*p)-(0.5*g*p*p);
	    x2=v2*cos(ang2)*p;
	   if(disable2==0)
	   {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(f1+x-x2,280-y2-f2,1);
	    floodfill(f1+x-x2,280-y2-f2,RED);

		if(f1+x-x2>f7-15 && f1+x-x2<f7+15 && 280-y2-f2>f8)   //to blaxt if it hits the tank
	       { blast(f1+x-x2,280-y2-f2,5);
		blast(f1+x-x2,280-y2-f2,10);
		blast(f1+x-x2,280-y2-f2,15);
		points1+=5;
		disable2=1;
	       }
	       if(f1+x-x2>f3-15 && f1+x-x2<f3+15 && 280-y2-f2>f4)   //to blaxt if it hits the tank
	       { blast(f1+x-x2,280-y2-f2,5);
		blast(f1+x-x2,280-y2-f2,10);
		blast(f1+x-x2,280-y2-f2,15);
		if(points1>2)
		 points1-=2;
		else
		 points1=0;
		disable2=1;
	       }
	   }//if(disable2==0)

	    y3=(v1*sin(ang1)*p)-(0.5*g*p*p);
	    x3=v1*cos(ang1)*p;
	   if(disable3==0)
	   {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(f1+x+x3,280-y3-f2,1);
	    floodfill(f1+x+x3,280-y3-f2,RED);

		if(f1+x+x3>f7-15 && f1+x+x3<f7+15 && 280-y3-f2>f8)   //to blaxt if it hits the tank
	       { blast(f1+x+x3,280-y3-f2,5);
		blast(f1+x+x3,280-y3-f2,10);
		blast(f1+x+x3,280-y3-f2,15);
		points1+=5;
		disable3=1;
	       }
	       if(f1+x+x3>f3-15 && f1+x+x3<f3+15 && 280-y3-f2>f4)   //to blaxt if it hits the tank
	       { blast(f1+x+x3,280-y3-f2,5);
		blast(f1+x+x3,280-y3-f2,10);
		blast(f1+x+x3,280-y3-f2,15);
		if(points1>2)
		 points1-=2;
		else
		 points1=0;
		disable3=1;
	       }
	   }//if(disable3==0)


	    y4=(v2*sin(ang2)*p)-(0.5*g*p*p);
	    x4=v2*cos(ang2)*p;

	   if(disable4==0)
	   {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(f1+x+x4,280-y4-f2,1);
	    floodfill(f1+x+x4,280-y4-f2,RED);

		if(f1+x+x4>f7-15 && f1+x+x4<f7+15 && 280-y4-f2>f8)   //to blaxt if it hits the tank
	       { blast(f1+x+x4,280-y4-f2,5);
		blast(f1+x+x4,280-y4-f2,10);
		blast(f1+x+x4,280-y4-f2,15);
		points1+=5;
		disable4=1;
	       }
	       if(f1+x+x4>f3-15 && f1+x+x4<f3+15 && 280-y3-f2>f4)   //to blaxt if it hits the tank
	       { blast(f1+x+x4,280-y4-f2,5);
		blast(f1+x+x4,280-y4-f2,10);
		blast(f1+x+x4,280-y4-f2,15);
		if(points1>2)
		 points1-=2;
		else
		 points1=0;
		disable4=1;
	       }
	   }//if(disable4==0);
	delay(3);

	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(f1+x-x1,280-y1-f2,1);
	floodfill(f1+x-x1,280-y1-f2,BLACK);
	circle(f1+x-x2,280-y2-f2,1);
	floodfill(f1+x-x2,280-y2-f2,BLACK);
	circle(f1+x+x3,280-y3-f2,1);
	floodfill(f1+x+x3,280-y3-f2,BLACK);
	circle(f1+x+x4,280-y4-f2,1);
	floodfill(f1+x+x4,280-y4-f2,BLACK);
	}
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}
	break; //end of case 4

case 5: //space cannon
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(WHITE);
	putpixel(x+f1,280-y-f2,WHITE);
	delay(3);
	setcolor(BLACK);
	putpixel(x+f1,280-y-f2,BLACK);
	}
	setcolor(WHITE);
	putpixel(x+f1,280-y-f2,WHITE);

	for(p=1;p<=2;p++)
	{
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 3);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 3);
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 6);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 6);
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 9);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 9);
	}

	for(p=x-15;p<=x+15;p++)
	{
	 setfillstyle(SOLID_FILL,RED);
	 bar(p+f1,0,p+5+f1,280-y-f2);
		if(p+f1>f7-15 && p+f1<f7+15)   //to blaxt if it hits the tank
	       { blast(p+f1,280-y-f2,5);
		blast(p+f1,280-y-f2,10);
		blast(p+f1,280-y-f2,15);
		points1+=15;
		break;
	       }
	       if(p+f1>f3-15 && p+f1<f3+15)   //to blaxt if it hits the tank
	       { blast(p+f1,280-y-f2,5);
		blast(p+f1,280-y-f2,10);
		blast(p+f1,280-y-f2,15);
		if(points1>5)
		 points1-=5;
		else
		 points1=0;
		break;
	       }

	 delay(50);
	 setfillstyle(SOLID_FILL,BLACK);
	 bar(p+f1,0,p+5+f1,280-y-f2);

	}

	break; //end of case 5

case 6: //saucer attack
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(YELLOW);
	putpixel(x+f1,280-y-f2,YELLOW);
	delay(3);
	setcolor(BLACK);
	putpixel(x+f1,280-y-f2,BLACK);
	}
	setcolor(YELLOW);
	putpixel(x+f1,280-y-f2,YELLOW);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}

	for(p=1;p<=2;p++)
	{
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 3);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 3);
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 6);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 6);
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 9);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 9);
	}

	for(p=0;p<=x+f1;p++)//coming from left
	{
	 saucer(p,100);
	 delay(10);
	 if( (int)p==(int)(x+f1) ) //here float values are converted to (int) because we can't test equality values with float values
	 {  setcolor(RED);
	  setfillstyle(SOLID_FILL,RED);
	  bar(p-2,100,p+2,280-y-f2);
		if(p>f7-15 && p<f7+15)   //to blaxt if it hits the tank
	       { blast(p,280-y-f2,5);
		blast(p,280-y-f2,10);
		blast(p,280-y-f2,15);
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		delay(10);
		bar(p-2,100,p+2,280-y-f2);
		points1+=20;
		break;
	       }
	       if(p>f3-15 && p<f3+15)   //to blaxt if it hits the tank
	       { blast(p,280-y-f2,5);
		blast(p,280-y-f2,10);
		blast(p,280-y-f2,15);
		delay(10);
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		bar(p-2,100,p+2,280-y-f2);
		if(points1>10)
		 points1-=10;
		else
		 points1=0;
		break;
	       }

	  delay(100);
	  setcolor(BLACK);
	  setfillstyle(SOLID_FILL,BLACK);
	  bar(p-2,100,p+2,280-y-f2);

	 }

	 morphsaucer(p,100);
	}

	for(p=x+f1;p>=0;p--)  //going back to left
	{
	 saucer(p,100);
	 delay(10);
	 morphsaucer(p,100);
	}

	break; //end of case 6
case 7:
	int color;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{
	color=random(14)+1;
	y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(color);
	setfillstyle(SOLID_FILL,color);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,color);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=6;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>2)
		 points1-=2;
		else
		 points1=0;
		break;
	       }
	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}
	setcolor(color);
	setfillstyle(SOLID_FILL,color);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,color);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}
	break; //end of case 7
case 8:
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	bar(x+f1-2,278-y-f2,x+f1+2,282-y-f2);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=7;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>3)
		 points1-=3;
		else
		 points1=0;
		break;
	       }
	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar(x+f1-2,278-y-f2,x+f1+2,282-y-f2);
	floodfill(x+f1,280-y-f2,BLACK);
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	bar(x+f1-2,278-y-f2,x+f1+2,282-y-f2);
	floodfill(x+f1,280-y-f2,RED);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}
	break; //end of case 8

case 9: //bouncy ball
	//1st bounce
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>3)
		 points1-=3;
		else
		 points1=0;

		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}

	//2nd bounce
	x1=x;
	x=0; y=0;
	v=v/2.0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p + x1;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>3)
		 points1-=3;
		else
		 points1=0;

		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}

	//3rd bounce
	x1=x;
	x=0; y=0;
	v=v/2.0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p + x1;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>3)
		 points1-=3;
		else
		 points1=0;

		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);

	break; //end of case 9

case 10://cruiser
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points1+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points1>3)
		 points1-=3;
		else
		 points1=0;

		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}

	x1=x+f1;

	dir=mod( cos(ang) );
	if(dir==0)
	{
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
	delay(100);
	}
	else
	{
	  x=0;
	  while(x+x1>0 && x+x1<640 && x>-150 && x<150)
	  {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(x+x1,280-y-f2,3);
	    floodfill(x+x1,280-y-f2,RED);
	    delay(10);
	    setcolor(BLACK);
	    setfillstyle(SOLID_FILL,BLACK);
	    circle(x+x1,280-y-f2,3);
	    floodfill(x+x1,280-y-f2,BLACK);
		if(x+x1>f7-15 && x+x1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+x1,280,5);
		blast(x+x1,280,10);
		blast(x+x1,280,15);
		points1+=3;
		break;
	       }
	       if(x+x1>f3-15 && x+x1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+x1,280,5);
		blast(x+x1,280,10);
		blast(x+x1,280,15);
		if(points1>2)
		 points1-=2;
		else
		 points1=0;

		break;
	       }
	    x+=dir;
	  }

	}

	break; //end of case 10


}//end of switch



}//end of  shoot1





void shoot2(double f1,double f2,double v,double ang,double f3,double f4,double f5,double f6,double f7,double f8,int weapon)
{      //shoot2(a+a2,b2,speed2,ang2,a,b,a1,b1,x,y,weapondepot2.weapons[i/2])

/*   double g=9.8,x=0,y=0;
    for(double p=0; x<=640 && y>=-f2;p+=0.01 )
	{
	   //y>=-f2 is for making projectile reach the floor of the tank
	y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(weapon);
	setfillstyle(SOLID_FILL,weapon);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,weapon);
	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);

	}
	setcolor(weapon);
	setfillstyle(SOLID_FILL,weapon);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,weapon);    */

 double g=9.8,p,x=0,y=0,slope,stangle,x1,y1,x2,y2,x3,y3,x4,y4,nlang,r;
 double ang1=M_PI/6,ang2=M_PI/3,ang3=M_PI/4;
 int dir;

     //to morph when the the points are not right at last
     char displaypoints1[5],displaypoints2[5];
     setcolor(BLACK);
     sprintf(displaypoints1,"%i",points1);
     outtextxy(10,10,displaypoints1);
     sprintf(displaypoints2,"%i",points2);
     outtextxy(550,10,displaypoints2);

switch(weapon)
{
case 1:
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points2+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points2>3)
		 points2-=3;
		else
		 points2=0;
		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}



	break; //end of case 1

case 2:
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{
	//slope=( ((v*sin(ang)*(p+1))-(0.5*g*(p+1)*(p+1)) ) - (v*sin(ang)*p)-(0.5*g*p*p) )/( v*cos(ang)*(p+1) - v*cos(ang)*p );

	slope= (v*sin(ang)-g*p)/(v*cos(ang) );
	y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	stangle=atan(slope);
	x1=10*cos(stangle);
	y1=10*sin(stangle);
	setcolor(WHITE);
	line(x+x1+f1,280-y-y1-f2,x-x1+f1,280-y+y1-f2);
		if(x+x1+f1>f7-15 && x+x1+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280,5);
		blast(x+f1,280,10);
		blast(x+f1,280,15);
		points2+=8;
		break;
	       }
	       if(x+x1+f1>f3-15 && x+x1+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280,5);
		blast(x+f1,280,10);
		blast(x+f1,280,15);
		if(points2>4)
		 points2-=4;
		else
		 points2=0;
		break;
	       }
	delay(3);
	setcolor(BLACK);
	line(x+x1+f1,280-y-y1-f2,x-x1+f1,280-y+y1-f2);

	}
	setcolor(WHITE);
	line(x+x1+f1,280-y-y1-f2,x-x1+f1,280-y+y1-f2);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}

	//to see the line properly after drawing the curve
	setcolor(WHITE);
	line(x+x1+f1,280-y-y1-f2,x-x1+f1,280-y+y1-f2);


	break; //end of case 2

case 3: p=0;
	do
	{
	nlang=atan( -1.0/tan(ang) );

	x1=p*cos(ang);
	y1=p*sin(ang);
	r=5*sin(p/5);

	x2=r*cos(nlang);
	y2=r*sin(nlang);

	setcolor(MAGENTA);
	line(x+f1,280-y-f2,x+x1+f1,280-y-y1-f2);
	putpixel(x+x1+x2+f1,280-y-y1-y2-f2,BLUE);

		if(x+x1+x2+f1>f7-15 && x+x1+x2+f1<f7+15 && 280-y-y1-y2-f2>f8)   //to blaxt if it hits the tank
	       { blast(x+x1+x2+f1,280-y-y1-y2-f2,5);
		blast(x+x1+x2+f1,280-y-y1-y2-f2,10);
		blast(x+x1+x2+f1,280-y-y1-y2-f2,15);
		points2+=10;
		break;
	       }
	       if(x+x1+x2+f1>f3-15 && x+x1+f1<f3+15 && 280-y-y1-y2-f2>f4)   //to blaxt if it hits the tank
	       { blast(x+x1+x2+f1,280-y-y1-y2-f2,5);
		blast(x+x1+x2+f1,280-y-y1-y2-f2,10);
		blast(x+x1+x2+f1,280-y-y1-y2-f2,15);
		if(points2>6)
		 points2-=6;
		else
		 points2=0;
		break;
	       }

	p++;
	delay(5);
	}while(x+x1+f1>0 && x+x1+f1<640 && 240-y-y1-f2>0 && 240-y-y1-f2<480);

	break; //end of case 3

case 4:  //scatter shot
	int disable1=0,disable2=0,disable3=0,disable4=0;
	ang1=M_PI/6;  ang2=M_PI/3;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,1);
	floodfill(x+f1,280-y-f2,RED);

		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points2+=8;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points2>4)
		 points2-=4;
		else
		 points2=0;
		break;
	       }
	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,1);
	floodfill(x+f1,280-y-f2,BLACK);
	}

	x1=0; y1=0;//sometimes x1 and y1 takes junk values and this for loop dosen't happen
	double v1=30.0;
	double v2=v1/sqrt(3.0);
	for(p=0; x1<=640 && y1>=-f2;p+=0.01 )
	{
	//  T=2usin(theta)/g
	//  T60 degrees=2*u(60 degrees)*sin(60 degrees)/g
	//  T30 degrees=2*u(30 degrees)*sin(30 degrees)/g
	//  T60 degrees=T30 degrees
	//  2*u(60 degrees)*sin(60 degrees)/g=2*u(30 degrees)*sin(30 degrees)/g
	//  sqrt(3.0)*u(60 degrees)=u(30 degrees)

	    y1=(v1*sin(ang1)*p)-(0.5*g*p*p);
	    x1=v1*cos(ang1)*p;
	   if(disable1==0)
	   {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(f1+x-x1,280-y1-f2,1);
	    floodfill(f1+x-x1,280-y1-f2,RED);

		if(f1+x-x1>f7-15 && f1+x-x1<f7+15 && 280-y1-f2>f8)   //to blaxt if it hits the tank
	       { blast(f1+x-x1,280-y1-f2,5);
		blast(f1+x-x1,280-y1-f2,10);
		blast(f1+x-x1,280-y1-f2,15);
		points2+=5;
		disable1=1;
	       }
	       if(f1+x-x1>f3-15 && f1+x-x1<f3+15 && 280-y1-f2>f4)   //to blaxt if it hits the tank
	       { blast(f1+x-x1,280-y1-f2,5);
		blast(f1+x-x1,280-y1-f2,10);
		blast(f1+x-x1,280-y1-f2,15);
		if(points2>2)
		 points2-=2;
		else
		 points2=0;
		disable1=1;
	       }
	   }//if(disable1==0)

	    y2=(v2*sin(ang2)*p)-(0.5*g*p*p);
	    x2=v2*cos(ang2)*p;
	   if(disable2==0)
	   {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(f1+x-x2,280-y2-f2,1);
	    floodfill(f1+x-x2,280-y2-f2,RED);

		if(f1+x-x2>f7-15 && f1+x-x2<f7+15 && 280-y2-f2>f8)   //to blaxt if it hits the tank
	       { blast(f1+x-x2,280-y2-f2,5);
		blast(f1+x-x2,280-y2-f2,10);
		blast(f1+x-x2,280-y2-f2,15);
		points2+=5;
		disable2=1;
	       }
	       if(f1+x-x2>f3-15 && f1+x-x2<f3+15 && 280-y2-f2>f4)   //to blaxt if it hits the tank
	       { blast(f1+x-x2,280-y2-f2,5);
		blast(f1+x-x2,280-y2-f2,10);
		blast(f1+x-x2,280-y2-f2,15);
		if(points2>2)
		 points2-=2;
		else
		 points2=0;
		disable2=1;
	       }
	   }//if(disable2==0)

	    y3=(v1*sin(ang1)*p)-(0.5*g*p*p);
	    x3=v1*cos(ang1)*p;
	   if(disable3==0)
	   {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(f1+x+x3,280-y3-f2,1);
	    floodfill(f1+x+x3,280-y3-f2,RED);

		if(f1+x+x3>f7-15 && f1+x+x3<f7+15 && 280-y3-f2>f8)   //to blaxt if it hits the tank
	       { blast(f1+x+x3,280-y3-f2,5);
		blast(f1+x+x3,280-y3-f2,10);
		blast(f1+x+x3,280-y3-f2,15);
		points2+=5;
		disable3=1;
	       }
	       if(f1+x+x3>f3-15 && f1+x+x3<f3+15 && 280-y3-f2>f4)   //to blaxt if it hits the tank
	       { blast(f1+x+x3,280-y3-f2,5);
		blast(f1+x+x3,280-y3-f2,10);
		blast(f1+x+x3,280-y3-f2,15);
		if(points2>2)
		 points2-=2;
		else
		 points2=0;
		disable3=1;
	       }
	   }//if(disable3==0)


	    y4=(v2*sin(ang2)*p)-(0.5*g*p*p);
	    x4=v2*cos(ang2)*p;

	   if(disable4==0)
	   {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(f1+x+x4,280-y4-f2,1);
	    floodfill(f1+x+x4,280-y4-f2,RED);

		if(f1+x+x4>f7-15 && f1+x+x4<f7+15 && 280-y4-f2>f8)   //to blaxt if it hits the tank
	       { blast(f1+x+x4,280-y4-f2,5);
		blast(f1+x+x4,280-y4-f2,10);
		blast(f1+x+x4,280-y4-f2,15);
		points2+=5;
		disable4=1;
	       }
	       if(f1+x+x4>f3-15 && f1+x+x4<f3+15 && 280-y3-f2>f4)   //to blaxt if it hits the tank
	       { blast(f1+x+x4,280-y4-f2,5);
		blast(f1+x+x4,280-y4-f2,10);
		blast(f1+x+x4,280-y4-f2,15);
		if(points2>2)
		 points2-=2;
		else
		 points2=0;
		disable4=1;
	       }
	   }//if(disable4==0);

	delay(3);

	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(f1+x-x1,280-y1-f2,1);
	floodfill(f1+x-x1,280-y1-f2,BLACK);
	circle(f1+x-x2,280-y2-f2,1);
	floodfill(f1+x-x2,280-y2-f2,BLACK);
	circle(f1+x+x3,280-y3-f2,1);
	floodfill(f1+x+x3,280-y3-f2,BLACK);
	circle(f1+x+x4,280-y4-f2,1);
	floodfill(f1+x+x4,280-y4-f2,BLACK);
	}
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}
	break; //end of case 4

case 5: //space cannon
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(WHITE);
	putpixel(x+f1,280-y-f2,WHITE);
	delay(3);
	setcolor(BLACK);
	putpixel(x+f1,280-y-f2,BLACK);
	}
	setcolor(WHITE);
	putpixel(x+f1,280-y-f2,WHITE);

	for(p=1;p<=2;p++)
	{
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 3);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 3);
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 6);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 6);
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 9);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 9);
	}

	for(p=x-15;p<=x+15;p++)
	{
	 setfillstyle(SOLID_FILL,RED);
	 bar(p+f1,0,p+5+f1,280-y-f2);

		if(p+f1>f7-15 && p+f1<f7+15)   //to blaxt if it hits the tank
	       { blast(p+f1,280-y-f2,5);
		blast(p+f1,280-y-f2,10);
		blast(p+f1,280-y-f2,15);
		points2+=15;
		break;
	       }
	       if(p+f1>f3-15 && p+f1<f3+15)   //to blaxt if it hits the tank
	       { blast(p+f1,280-y-f2,5);
		blast(p+f1,280-y-f2,10);
		blast(p+f1,280-y-f2,15);
		if(points2>5)
		 points2-=5;
		else
		 points2=0;
		break;
	       }
	 delay(50);
	 setfillstyle(SOLID_FILL,BLACK);
	 bar(p+f1,0,p+5+f1,280-y-f2);

	}

	break; //end of case 5

case 6: //saucer attack
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(YELLOW);
	putpixel(x+f1,280-y-f2,YELLOW);
	delay(3);
	setcolor(BLACK);
	putpixel(x+f1,280-y-f2,BLACK);
	}
	setcolor(YELLOW);
	putpixel(x+f1,280-y-f2,YELLOW);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}

	for(p=1;p<=2;p++)
	{
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 3);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 3);
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 6);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 6);
	setcolor(WHITE);
	arc(x+f1, 280-y-f2, 30, 150, 9);
	delay(300);
	setcolor(BLACK);
	arc(x+f1, 280-y-f2, 30, 150, 9);
	}

	for(p=0;p<=x+f1;p++)//coming from left
	{
	 saucer(p,100);
	 if( (int)p==(int)(x+f1) ) //here float values are converted to (int) because we can't test equality values with float values
	 {  setcolor(RED);
	  setfillstyle(SOLID_FILL,RED);
	  bar(p-2,100,p+2,280-y-f2);
		if(p>f7-15 && p<f7+15)   //to blaxt if it hits the tank
	       { blast(p,280-y-f2,5);
		blast(p,280-y-f2,10);
		blast(p,280-y-f2,15);
		delay(10);
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		bar(p-2,100,p+2,280-y-f2);
		points2+=20;
		break;
	       }
	       if(p>f3-15 && p<f3+15)   //to blaxt if it hits the tank
	       { blast(p,280-y-f2,5);
		blast(p,280-y-f2,10);
		blast(p,280-y-f2,15);
		delay(10);
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		bar(p-2,100,p+2,280-y-f2);
		if(points2>10)
		 points2-=10;
		else
		 points2=0;
		break;
	       }
	 delay(100);
	 setcolor(BLACK);
	 setfillstyle(SOLID_FILL,BLACK);
	 bar(p-2,100,p+2,280-y-f2);
	 }
	 delay(10);
	 morphsaucer(p,100);
	}


	for(p=x+f1;p>=0;p--)  //going back to left
	{
	 saucer(p,100);
	 delay(10);
	 morphsaucer(p,100);
	}

	break; //end of case 6
case 7:
	int color;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{
	color=random(14)+1;
	y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(color);
	setfillstyle(SOLID_FILL,color);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,color);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points2+=6;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points2>2)
		 points2-=2;
		else
		 points2=0;
		break;
	       }
	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}
	setcolor(color);
	setfillstyle(SOLID_FILL,color);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,color);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}
	break; //end of case 7
case 8:
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	bar(x+f1-2,278-y-f2,x+f1+2,282-y-f2);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points2+=7;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points2>3)
		 points2-=3;
		else
		 points2=0;
		break;
	       }
	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar(x+f1-2,278-y-f2,x+f1+2,282-y-f2);
	floodfill(x+f1,280-y-f2,BLACK);
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	bar(x+f1-2,278-y-f2,x+f1+2,282-y-f2);
	floodfill(x+f1,280-y-f2,RED);
	x=0; y=0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	putpixel(x+f1,280-y-f2,GREEN);
	}
	break; //end of case 8

case 9: //bouncy ball
	//1st bounce
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points2+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points2>3)
		 points2-=3;
		else
		 points2=0;
		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}

	//2nd bounce
	x1=x;
	x=0; y=0;
	v=v/2.0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p + x1;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points2+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points2>3)
		 points2-=3;
		else
		 points2=0;
		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}

	//3rd bounce
	x1=x;
	x=0; y=0;
	v=v/2.0;
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p + x1;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points2+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points2>3)
		 points2-=3;
		else
		 points2=0;
		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);

	break; //end of case 9

case 10://cruiser
	for(p=0; x<=640 && y>=-f2;p+=0.01 )
	{ y=(v*sin(ang)*p)-(0.5*g*p*p);
	x=v*cos(ang)*p;
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);

		if(x+f1>f7-15 && x+f1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		points2+=5;
		break;
	       }
	       if(x+f1>f3-15 && x+f1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+f1,280-y,5);
		blast(x+f1,280-y,10);
		blast(x+f1,280-y,15);
		if(points2>3)
		 points2-=3;
		else
		 points2=0;
		break;
	       }

	delay(3);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,BLACK);
	}

	x1=x+f1;

	dir=mod( cos(ang) );
	if(dir==0)
	{
	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	circle(x+f1,280-y-f2,3);
	floodfill(x+f1,280-y-f2,RED);
	delay(100);
	}
	else
	{
	  x=0;
	  while(x+x1>0 && x+x1<640 && x>-150 && x<150)
	  {
	    setcolor(RED);
	    setfillstyle(SOLID_FILL,RED);
	    circle(x+x1,280-y-f2,3);
	    floodfill(x+x1,280-y-f2,RED);
	    delay(10);
	    setcolor(BLACK);
	    setfillstyle(SOLID_FILL,BLACK);
	    circle(x+x1,280-y-f2,3);
	    floodfill(x+x1,280-y-f2,BLACK);
		if(x+x1>f7-15 && x+x1<f7+15 && 280-y>f8)   //to blaxt if it hits the tank
	       { blast(x+x1,280,5);
		blast(x+x1,280,10);
		blast(x+x1,280,15);
		points2+=3;
		break;
	       }
	       if(x+x1>f3-15 && x+x1<f3+15 && 280-y>f4)   //to blaxt if it hits the tank
	       { blast(x+x1,280,5);
		blast(x+x1,280,10);
		blast(x+x1,280,15);
		if(points2>2)
		 points2-=2;
		else
		 points2=0;
		break;
	       }
	    x+=dir;
	  }

	}

	break; //end of case 10

}//end of switch



}//end of  projectile

void winner(double x,double y,double a,double b)
{
 setcolor(YELLOW);
 if(points1>points2)
 {
  outtextxy(x-10,y-30,"winner");
   while(!kbhit())
   winnersound();
 }
 else if(points2>points1)
 {
  outtextxy(a-10,b-30,"winner");
   while(!kbhit())
   winnersound();
 }
 else
 {
  outtextxy(320,400,"no one won");
 }

}

void save(char player1[],char player2[])
{
profile p1,p2;
fstream file;
file.open("H:profile.txt",ios::app | ios::binary);
strcpy(p1.name,player1);
strcpy(p2.name,player2);
p1.points=points1;
p2.points=points2;
file.write( (char*)&p1,sizeof(p1) );
file.write( (char*)&p2,sizeof(p2) );
file.close();
}

