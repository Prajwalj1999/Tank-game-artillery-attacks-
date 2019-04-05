void game();
void menu();
void saucer(double,double);
void morphsaucer(double,double);
double speedbar1(double);
void showspeedbar1(double);
double speedbar2(double);
void showspeedbar2(double);
void blast(double,double,double);
void battlefield(void);
int gettankcolor();
void tank(double,double,int);
void winner(double,double,double,double);
void winnersound(void);
void introsound(void);
void save(char [],char []);
void chooseweapon(int [],int [],char [],char []);
void displayweapon(int [],int []);
void show1(int [],int,char []);
void show2(int [],int,char []);
double mod(double);
void takescreenshot();
void LoadImg(char [],int,int);
void weaponinfo();
void help();
void credits();
void scorecard();

double speedbar1(double speed)
{
  setcolor(RED);
  rectangle(9,399,91,411);

for( ; ; )
{

setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
bar(10,400,90,410);
setcolor(LIGHTGREEN);
setfillstyle(SOLID_FILL,LIGHTGREEN);
bar(10,400,10+speed,410);

char key=getch();

if(speed>1)
 if(key==75)
  {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    bar(10,400,90,410);
    speed-=1;
  }

if(speed<80)
 if(key==77)
   speed+=1;

if(key=='x')
  return speed;

if(key==13)
  return speed;

}

/*  for(double i=1;i<=80;i++)
  {
  setcolor(RED);
  rectangle(9,399,91,411);
  setcolor(LIGHTGREEN);
  setfillstyle(SOLID_FILL,LIGHTGREEN);
  rectangle(10,400,10+i,410); delay(50);
  if(getch()==13)
  return i;
  }             */

return speed;

}

void showspeedbar1(double speed)
{
  setcolor(RED);
  rectangle(9,399,91,411);
setcolor(LIGHTGREEN);
setfillstyle(SOLID_FILL,LIGHTGREEN);
bar(10,400,10+speed,410);

}

double speedbar2(double speed)
{

setcolor(RED);
  rectangle(549,399,631,411);

for( ; ; )
{
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
bar(550,400,630,410);
setcolor(LIGHTGREEN);
setfillstyle(SOLID_FILL,LIGHTGREEN);
bar(550,400,550+speed,410);

char key=getch();

if(speed>1)
 if(key==75)
  {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    bar(550,400,630,410);
    speed-=1;
  }

if(speed<80)
 if(key==77)
   speed+=1;

if(key=='x')
  return speed;

if(key==13)
  return speed;

}


/*  for(double i=1;i<=80;i++)
  {
     setcolor(RED);
     rectangle(549,399,631,411);
     setcolor(LIGHTGREEN);
     setfillstyle(SOLID_FILL,LIGHTGREEN);
     rectangle(550,400,550+i,410); delay(50);
    if(getch()==13)
    return i;
  }              */
 return speed;

}

void showspeedbar2(double speed)
{
setcolor(RED);
  rectangle(549,399,631,411);
setcolor(LIGHTGREEN);
setfillstyle(SOLID_FILL,LIGHTGREEN);
bar(550,400,550+speed,410);

}

void blast(double o,double p,double r)
{  for(double i=0;i<=r;i+=0.1)
   {
      setcolor(YELLOW);
      circle(o,p,i); sound(1000);//sound(1-18) dosen't work,sound(19) works
      delay(1);
      setcolor(RED);
      circle(o,p,i); sound(1000);//sound(1-18) dosen't work,sound(19) works
      delay(1);
      setcolor(BLACK);
      circle(o,p,i); nosound();
   }

}//end of blast

void battlefield(void)
{
setbkcolor(BLACK);
setcolor(RED);
setfillstyle(SOLID_FILL,GREEN);
bar(0,286,640,349);
bar(300,281,340,286);


}//end of void battlefield

void tank(double x,double y,int color)
{
setcolor(color);
setfillstyle(SOLID_FILL,color);
bar(x-15,y-4,x+15,y+4);        //lower body
bar(x-10,y-8,x+10,y-4);        //upper body

setcolor(RED);
setfillstyle(SOLID_FILL,BLUE);
circle(x-13,y+6,2);  /*wheel*/    floodfill(x-13,y+6,RED);
circle(x-9,y+6,2);                floodfill(x-9,y+6,RED);
circle(x-5,y+6,2);                floodfill(x-5,y+6,RED);
circle(x-1,y+6,2);                floodfill(x-1,y+6,RED);
circle(x+3,y+6,2);                floodfill(x+3,y+6,RED);
circle(x+7,y+6,2);                floodfill(x+7,y+6,RED);
circle(x+11,y+6,2);               floodfill(x+11,y+6,RED);
circle(x+15,y+6,2);               floodfill(x+15,y+6,RED);

}

void saucer(double c,double d)
{
   int color;

   if( ((int)c/50)%2==0  )
     color=0;
   else
     color=15;

   setfillstyle(SOLID_FILL,CYAN);
   bar(c-5,d-3,c+5,d);
   bar(c-4,d-6,c+4,d);
   bar(c-3,d-9,c+3,d);
   putpixel(c-2,d-1,color);
   putpixel(c+2,d-1,color);

}
void morphsaucer(double c,double d)
{
   setfillstyle(SOLID_FILL,BLACK);
   bar(c-5,d-3,c+5,d);
   bar(c-4,d-6,c+4,d);
   bar(c-3,d-9,c+3,d);
 /*  putpixel(c-2,d-1,BLACK);
   putpixel(c+2,d-1,BLACK);   */ //useless as it gets morphed already

}

void winnersound()
{
 sound(523);
 delay(250);
 sound(587);
 delay(250);
 sound(659);
 delay(250);
 sound(698);
 delay(250);
 sound(784);
 delay(250);
 nosound();

}

int gettankcolor()
{
 int x=20,y=400;
 char lock;

 for(int i=1;i<=14;i++)
 {
  setfillstyle(SOLID_FILL,i);
  bar(x,y,x+10,y+10);
  x+=20;
 }

 x=20;
 for( ; ; )
 {
  setcolor(YELLOW);
  rectangle(x-2,y-2,x+10+2,y+10+2);
  lock=getch();
  if(x>20)
    if(lock==75)
      {
	setcolor(BLACK);
	rectangle(x-2,y-2,x+10+2,y+10+2);
	x-=20;
      }
  if(x<280)
    if(lock==77)
      {
	setcolor(BLACK);
	rectangle(x-2,y-2,x+10+2,y+10+2);
	x+=20;
      }
  if(lock==13)
  {
    setcolor(BLACK);
    rectangle(x-2,y-2,x+10+2,y+10+2);
    return x/20;
  }

 }//end of for( ; ; )

return i;
}

void introsound()
{
sound(300);
delay(100);
sound(200);
delay(100);
sound(100);
delay(100);
sound(300);
delay(100);
sound(300);
delay(100);
sound(100);
delay(100);
sound(200);
delay(100);
sound(300);
delay(100);

sound(400);
delay(100);
sound(300);
delay(100);
sound(200);
delay(100);
sound(100);
delay(100);
sound(200);
delay(100);
sound(300);
delay(100);
sound(400);
delay(100);
sound(500);
delay(100);

sound(400);
delay(100);
sound(350);
delay(100);
sound(300);
delay(100);
sound(250);
delay(100);
sound(250);
delay(100);
sound(300);
delay(100);
sound(350);
delay(100);
sound(400);
delay(100);

nosound();

}

double mod(double a)
{
 if(a>0)
   return 1;
 else if(a<0)
   return -1;
 else if(a==0)
   return 0;

return a;
}

void takescreenshot(void)
{

int i,j;   //i is for x axis and j for y axis
fstream file;
file.open("D:screen.dat",ios::app | ios::binary);

 for(i=1;i<=640;i++)
 {
  for(j=1;j<=480;j++)
  {
    int color=getpixel(i,j);
    file<<color;
  }
 }

file.close();


}//void takescreenshot(void)

void putscreenshot(void)
{

int i,j,color; //i is for y axis and j for x axis
fstream file;
file.open("D:screen.dat",ios::in | ios::binary);

 for(i=1;i<=640;i++)
 {
  for(j=1;j<=480;j++)
  {
    file>>color;
    putpixel(i,j,color);
  }

 }

file.close();



}//void putscreenshot(void)

void chooseweapon(int weapon1[],int weapon2[],char name1[],char name2[])
{
int weapons[16],used[16]={0},x1=200,y1,x2=200,y2=0,temp;
int add=50; //add is for increasing space between x-axis and weapon depot
  for(int i=0;i<16;i++)
     weapons[i]=random(10)+1;

  for(i=0;i<16;i++)
  {
   //displayweapon(weapons,used);
   if(i%2==0)
   {
     cleardevice();
     for(int j=0;j<16;j++)
      if(used[j]==0)
	{
	 y1=20*j; temp=j;
	 break;
	}
     for( ; ; )
     {
       displayweapon(weapons,used);
       setcolor(GREEN);
       rectangle(x1,y1+add,x1+105,y1+15+add);
       show1(weapon1,i/2-1,name1);
       show2(weapon2,i/2-1,name2);
       char key=getch();
       if(key==75)
       {
	setcolor(BLACK);
	rectangle(x1,y1+add,x1+105,y1+15+add);
	 if(temp>0)
	 {
	  int temp1=temp;
	  for(j=temp-1;j>=0;j--)
	  {
	    if(used[j]==0)
	     { temp1=j;
	       break;
	     }

	  }
	  temp=temp1;
	  y1=temp*20;
	 }

       }//if(key==75)

       if(key==77)
       {
	setcolor(BLACK);
	rectangle(x1,y1+add,x1+105,y1+15+add);
	 if(temp<16)
	 {
	  int temp1;
	  for(j=temp+1;j<16;j++)
	  {
	    if(used[j]==0)
	    {  temp1=j;
	       break;
	    }

	  }//end of for(j=temp...
	  temp=temp1;
	  y1=temp*20;
	 }

       }//if(key==77)

       if(key==13)
	{
	  weapon1[i/2]=weapons[temp];
	  used[temp]=1;
	  break;
	}

     }//for( ; ; )

   }//if(i%2==0)
   else
   {
     cleardevice();
     for(int j=0;j<16;j++)
      if(used[j]==0)
	{
	 y2=20*j; temp=j;
	 break;
	}
     for( ; ; )
     {
       displayweapon(weapons,used);
       setcolor(GREEN);
       rectangle(x2,y2+add,x2+105,y2+15+add);
       show1(weapon1,i/2,name1);
       show2(weapon2,i/2-1,name2);
       char key=getch();
       if(key==75)
       {
	setcolor(BLACK);
	rectangle(x2,y2+add,x2+105,y2+15+add);
	 if(temp>0)
	 {
	  int temp1=temp;
	  for(j=temp-1;j>=0;j--)
	  {
	    if(used[j]==0)
	     { temp1=j;
	       break;
	     }

	  }
	  temp=temp1;
	  y2=temp*20;
	 }

       }//if(key==75)

       if(key==77)
       {
	setcolor(BLACK);
	rectangle(x2,y2+add,x2+105,y2+15+add);
	 if(temp<16)
	 {
	  int temp1=temp;
	  for(j=temp+1;j<16;j++)
	  {
	    if(used[j]==0)
	    {  temp1=j;
	       break;
	    }

	  }//end of for(j=temp...
	  temp=temp1;
	  y2=temp*20;
	 }

       }//if(key==77)

       if(key==13)
	{
	  weapon2[i/2]=weapons[temp];
	  used[temp]=1;
	  break;
	}

     }//for( ; ; )


   }//else

  }//for(i=0;i<20;i++)

cleardevice();
show1(weapon1,7,name1);
show2(weapon2,7,name2);
delay(1000);//to see the last weapon choosed

}//end of chooseweapon(int weapon1[],int weapon2[])

void displayweapon(int weapons[],int used[])
{
int x=200,y=0,add=50; //add is for increasing space between x-axis and weapon depot
setcolor(MAGENTA);
rectangle(295,45,210,370);
 for(int i=0;i<16;i++)
 {
   if(used[i]==0)
   {
    setfillstyle(SOLID_FILL,BLUE);
    bar(x,y+add,x+105,y+10+add);
    setcolor(YELLOW);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
     switch(weapons[i])
     {
       case 1: outtextxy(x+2,y+1+add,"RED BALL");
	       break;
       case 2: outtextxy(x+2,y+1+add,"ROD");
	       break;
       case 3: outtextxy(x+2,y+1+add,"SINE LASER");
	       break;
       case 4: outtextxy(x+2,y+1+add,"SCATTER SHOT");
	       break;
       case 5: outtextxy(x+2,y+1+add,"SPACE CANNON");
	       break;
       case 6: outtextxy(x+2,y+1+add,"SAUCER ATTACK");
	       break;
       case 7: outtextxy(x+2,y+1+add,"COLOR BOMB");
	       break;
       case 8: outtextxy(x+2,y+1+add,"SQUARE BOMB");
	       break;
       case 9: outtextxy(x+2,y+1+add,"BOUNCY BALL");
	       break;
       case 10: outtextxy(x+2,y+1+add,"CRUISER");
	       break;
     }//end of switch

   }//if(used[i]==0)

   y+=20;

 }//for(int i=0;i<20;i++)

}//end of displayweapon(int weapons[],int used[])

void show1(int weapons[],int t,char name1[])
{
setcolor(YELLOW);
outtextxy(10,10,name1);
setcolor(RED);
rectangle(0,28,110,240);
int x=0,y=0;
setcolor(LIGHTGREEN);
  for(int i=0;i<=t;i++)
  {
     switch(weapons[i])
     {
       case 1: outtextxy(x+4,y+30,"RED BALL");
	       break;
       case 2: outtextxy(x+4,y+30,"ROD");
	       break;
       case 3: outtextxy(x+4,y+30,"SINE LASER");
	       break;
       case 4: outtextxy(x+4,y+30,"SCATTER SHOT");
	       break;
       case 5: outtextxy(x+4,y+30,"SPACE CANNON");
	       break;
       case 6: outtextxy(x+4,y+30,"SAUCER ATTACK");
	       break;
       case 7: outtextxy(x+4,y+30,"COLOR BOMB");
	       break;
       case 8: outtextxy(x+4,y+30,"SQUARE BOMB");
	       break;
       case 9: outtextxy(x+4,y+30,"BOUNCY BALL");
	       break;
       case 10: outtextxy(x+4,y+30,"CRUISER");
	       break;
     }//end of switch

    y+=20;
  }//end of for


}//end of show1(...
void show2(int weapons[],int t,char name2[])
{
setcolor(YELLOW);
outtextxy(510,10,name2);
setcolor(RED);
rectangle(500,28,610,240);
int x=500,y=0;
setcolor(LIGHTGREEN);
  for(int i=0;i<=t;i++)
  {
     switch(weapons[i])
     {
       case 1: outtextxy(x+4,y+30,"RED BALL");
	       break;
       case 2: outtextxy(x+4,y+30,"ROD");
	       break;
       case 3: outtextxy(x+4,y+30,"SINE LASER");
	       break;
       case 4: outtextxy(x+4,y+30,"SCATTER SHOT");
	       break;
       case 5: outtextxy(x+4,y+30,"SPACE CANNON");
	       break;
       case 6: outtextxy(x+4,y+30,"SAUCER ATTACK");
	       break;
       case 7: outtextxy(x+4,y+30,"COLOR BOMB");
	       break;
       case 8: outtextxy(x+4,y+30,"SQUARE BOMB");
	       break;
       case 9: outtextxy(x+4,y+30,"BOUNCY BALL");
	       break;
       case 10: outtextxy(x+4,y+30,"CRUISER");
	       break;
     }//end of switch

    y+=20;
  }//end of for


}//end of show2(...

void menu()
{

int gd=DETECT,gm,errorcode;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(0); /* terminate with an error code */
   }

LoadImg("D:tank17.txt",0,50);
delay(1000);

int op=1;
char key;
 for( ; ; )
 {
   cleardevice();
   settextstyle(DEFAULT_FONT,0,1);
   if(op==1)
   {
	    setcolor(WHITE);
	    setfillstyle(SOLID_FILL,LIGHTBLUE);
	    bar(310,100,410,120);
	    rectangle(308,98,412,122);
	    bar(300,140,400,160);
	    rectangle(298,138,402,162);
	    bar(300,180,400,200);
	    rectangle(298,178,402,202);
	    bar(300,220,400,240);
	    rectangle(298,218,402,242);
	    bar(300,260,400,280);
	    rectangle(298,258,402,282);
	    setcolor(YELLOW);
	    outtextxy(311,110,"START");
	    outtextxy(301,150,"CREDITS");
	    outtextxy(301,190,"HELP");
	    outtextxy(301,230,"WEAPON-INFO");
	    outtextxy(301,270,"EXIT");

   }
   if(op==2)
   {
	    setcolor(WHITE);
	    setfillstyle(SOLID_FILL,LIGHTBLUE);
	    bar(300,100,400,120);
	    rectangle(298,98,402,122);
	    bar(310,140,410,160);
	    rectangle(308,138,412,162);
	    bar(300,180,400,200);
	    rectangle(298,178,402,202);
	    bar(300,220,400,240);
	    rectangle(298,218,402,242);
	    bar(300,260,400,280);
	    rectangle(298,258,402,282);
	    setcolor(YELLOW);
	    outtextxy(301,110,"START");
	    outtextxy(311,150,"CREDITS");
	    outtextxy(301,190,"HELP");
	    outtextxy(301,230,"WEAPON-INFO");
	    outtextxy(301,270,"EXIT");

   }
   if(op==3)
   {
	    setcolor(WHITE);
	    setfillstyle(SOLID_FILL,LIGHTBLUE);
	    bar(300,100,400,120);
	    rectangle(298,98,402,122);
	    bar(300,140,400,160);
	    rectangle(298,138,402,162);
	    bar(310,180,410,200);
	    rectangle(308,178,412,202);
	    bar(300,220,400,240);
	    rectangle(298,218,402,242);
	    bar(300,260,400,280);
	    rectangle(298,258,402,282);
	    setcolor(YELLOW);
	    outtextxy(301,110,"START");
	    outtextxy(301,150,"CREDITS");
	    outtextxy(311,190,"HELP");
	    outtextxy(301,230,"WEAPON-INFO");
	    outtextxy(301,270,"EXIT");

   }
   if(op==4)
   {
	    setcolor(WHITE);
	    setfillstyle(SOLID_FILL,LIGHTBLUE);
	    bar(300,100,400,120);
	    rectangle(298,98,402,122);
	    bar(300,140,400,160);
	    rectangle(298,138,402,162);
	    bar(300,180,400,200);
	    rectangle(298,178,402,202);
	    bar(310,220,410,240);
	    rectangle(308,218,412,242);
	    bar(300,260,400,280);
	    rectangle(298,258,402,282);
	    setcolor(YELLOW);
	    outtextxy(301,110,"START");
	    outtextxy(301,150,"CREDITS");
	    outtextxy(301,190,"HELP");
	    outtextxy(311,230,"WEAPON-INFO");
	    outtextxy(301,270,"EXIT");

   }

   if(op==5)
   {
	    setcolor(WHITE);
	    setfillstyle(SOLID_FILL,LIGHTBLUE);
	    bar(300,100,400,120);
	    rectangle(298,98,402,122);
	    bar(300,140,400,160);
	    rectangle(298,138,402,162);
	    bar(300,180,400,200);
	    rectangle(298,178,402,202);
	    bar(300,220,402,240);
	    rectangle(298,218,402,242);
	    bar(310,260,410,280);
	    rectangle(308,258,412,282);
	    setcolor(YELLOW);
	    outtextxy(301,110,"START");
	    outtextxy(301,150,"CREDITS");
	    outtextxy(301,190,"HELP");
	    outtextxy(301,230,"WEAPON-INFO");
	    outtextxy(311,270,"EXIT");


   }

   key=getch();
   if(op>1)
    if(key==75)
      op--;

   if(op<5)
    if(key==77)
      op++;

   if(key==13)
   {
    switch(op)
    {
     case 1:
	    game();
	    break;
     case 2:credits();
	    break;
     case 3:help();
	    break;
     case 4:weaponinfo();
	    break;
     case 5:exit(0);
    }
   }

 }//for

}//end of menu

void LoadImg(char path[50],int x=0,int y=0)
{  fstream file;  char ch;
  file.open(path,ios::in  | ios::binary);
  if(file)
  {  file.get(ch);
     int i=x,j=y,l,b;
     while(!file.eof())  {
       if(ch=='%')  {
	 j++;
	 i=x;
	 file.get(ch);
	 continue;
	 }
       putpixel(i,j,(int)(ch));
       file.get(ch);
       i++;
       }   }
      else  {
      cout<<"FILE NOT FOUND!";
      }
      file.close();
}//end of loadimg

void weaponinfo()
{
int y=0;
while(y<1000)
{
cleardevice();
setfillstyle(SOLID_FILL,RED);
settextstyle(DEFAULT_FONT,0,1);
 bar(9,39-y,74,48-y);
 outtextxy(10,40-y,"RED BALL: This bomb will blast if it hits only tanks.");
 outtextxy(10,50-y,"The bomb won't blast if it hits the terrain.");
 outtextxy(10,60-y,"It will award you 5 points if it hits the enemy tank.");
 outtextxy(10,70-y,"It will take your 3 points if it hits your tank.");
 outtextxy(10,80-y,"No points are awarded if it hits the terrain.");

 bar(9,99-y,33,108-y);
 outtextxy(10,100-y,"ROD: It takes a curved path and hits only tanks.");
 outtextxy(10,110-y,"The bomb won't blast if it hits the terrain.");
 outtextxy(10,120-y,"It will award you 8 points if it hits the enemy tank.");
 outtextxy(10,130-y,"It will take your 4 points if it hits your tank.");
 outtextxy(10,140-y,"No points are awarded if it hits the terrain.");

 bar(9,159-y,90,168-y);
 outtextxy(10,160-y,"SINE LASER:It goes in a straight line with sine curves on it.");
 outtextxy(10,170-y,"The laser won't blast if it hits the terrain.");
 outtextxy(10,180-y,"It will award you 10 points if it hits the enemy tank.");
 outtextxy(10,190-y,"It will take your 6 points if it hits your tank.");
 outtextxy(10,200-y,"No points are awarded if it hits the terrain.");

 bar(9,219-y,105,228-y);
 outtextxy(10,220-y,"SCATTER SHOT:Initially like the red ball but after hitting any part of terrain");
 outtextxy(10,230-y,"it splits in to 4 balls.The bomb won't blast if it hits the terrain.");
 outtextxy(10,240-y,"It will award you 8 points if it hits the enemy tank directly.");
 outtextxy(10,250-y,"It will award you 5 points if it hits the enemy tank with smaller balls.");
 outtextxy(10,260-y,"It will take your 4 points if it hits your tank directly.");
 outtextxy(10,270-y,"It will take your 2 points if it hits your tank with smaller balls.");
 outtextxy(10,280-y,"No points are awarded if it hits the terrain.");

 bar(9,299-y,105,308-y);
 outtextxy(10,300-y,"SPACE CANNON:Initially takes a curved path and lands on any part of");
 outtextxy(10,310-y,"the terrain.It sends a signal to the sky and then a laser beam destroys");
 outtextxy(10,320-y,"the region where it landed.The laser won't blast if it hits the terrain.");
 outtextxy(10,330-y,"It will award you 15 points if it hits the enemy tank.");
 outtextxy(10,340-y,"It will take your 5 points if it hits your tank.");
 outtextxy(10,350-y,"No points are awarded if it hits the terrain.");

 bar(9,369-y,113,378-y);
 outtextxy(10,370-y,"SAUCER ATTACK:Initially takes a curved path and lands on any part of");
 outtextxy(10,380-y,"the terrain.It sends a signal to the sky and then a flying saucer destroys");
 outtextxy(10,390-y,"the area where it landed.The laser won't blast if it hits the terrain.");
 outtextxy(10,400-y,"It will award you 20 points if it hits the enemy tank.");
 outtextxy(10,410-y,"It will take your 10 points if it hits your tank.");
 outtextxy(10,420-y,"No points are awarded if it hits the terrain.");

 bar(9,439-y,90,448-y);
 outtextxy(10,440-y,"COLOR BOMB:The bomb changes its color during its flight and");
 outtextxy(10,450-y,"hits only tanks.The bomb won't blast if it hits the terrain.");
 outtextxy(10,460-y,"It will award you 6 points if it hits the enemy tank.");
 outtextxy(10,470-y,"It will take your 2 points if it hits your tank.");
 outtextxy(10,480-y,"No points are awarded if it hits the terrain.");

 bar(9,499-y,98,508-y);
 outtextxy(10,500-y,"SQUARE BOMB:The bomb traces the path similar to red ball and it hits");
 outtextxy(10,510-y,"only tanks.The bomb won't blast if it hits the terrain.");
 outtextxy(10,520-y,"It will award you 7 points if it hits the enemy tank.");
 outtextxy(10,530-y,"It will take your 3 points if it hits your tank.");
 outtextxy(10,540-y,"No points are awarded if it hits the terrain.");

 bar(9,559-y,98,568-y);
 outtextxy(10,560-y,"BOUNCY BALL:The bomb traces the path similar to red ball and it bounces");
 outtextxy(10,570-y," 2 times with decreasing power,The bomb won't blast if it hits the terrain.");
 outtextxy(10,580-y,"It will award you 5 points if it hits the enemy tank.");
 outtextxy(10,590-y,"It will take your 3 points if it hits your tank.");
 outtextxy(10,600-y,"No points are awarded if it hits the terrain.");

 bar(9,619-y,66,628-y);
 outtextxy(10,620-y,"CRUISER:The bomb traces the path similar to red ball and it hits");
 outtextxy(10,630-y,"only tanks after moving for a certain distance on the terrain.The bomb won't");
 outtextxy(10,640-y,"blast if it hits the terrain.The bomb won't blast if it hits the terrain.");
 outtextxy(10,650-y,"It will award you 5 points if it hits the enemy tank directly.");
 outtextxy(10,660-y,"It will award you 3 points if it hits the enemy tank on moving on the terrain.");
 outtextxy(10,670-y,"It will take your 3 points if it hits your tank directly.");
 outtextxy(10,680-y,"It will take your 2 points if it hits your tank on moving on the terrain.");
 outtextxy(10,690-y,"No points are awarded if it hits the terrain.");

settextstyle(DEFAULT_FONT,0,8);
outtextxy(10,800-y,"GOOD LUCK");

char ch=getch();
if(y>0)
 if(ch==72)
   y-=50;

if(y<650)
 if(ch==80)
   y+=50;

if(ch==13 || ch==27)
 break;

}//while

}//end of weaponinfo()

void help()
{
cleardevice();
settextstyle(DEFAULT_FONT,0,4);
setcolor(CYAN);
outtextxy(200,50,"CONTROLS");
setcolor(RED);
rectangle(190,40,455,90);
settextstyle(DEFAULT_FONT,0,1);
setcolor(YELLOW);
outtextxy(10,100,"to move the tank to the right press 'd' key");
outtextxy(10,120,"to move the tank to the left press 'a' key");
outtextxy(10,140,"to move the turret to the left press '<'-left arrow key");
outtextxy(10,160,"to move the turret to the right press '>'-right arrow key");
outtextxy(10,180,"to change the weapon press 'j' or 'l' key");
outtextxy(10,200,"to select the power press 'x' key");
outtextxy(10,210,"to increase the power press '<'-left arrow key");
outtextxy(10,220,"to increase the power press '>'-right arrow key");
outtextxy(10,230,"to quit power select option press 'x' key again or press enter key");
outtextxy(10,260,"to exit the game press 'e' key(it erases your data in the game)");

getch();
}

void credits()
{
cleardevice();
settextstyle(DEFAULT_FONT,0,2);
while(!kbhit() )
{
setcolor( random(15)+1);
outtextxy(100,40,"BY");
setcolor( random(15)+1);
outtextxy(100,80,"ARJUN GANESH NAYAK");
setcolor( random(15)+1);
outtextxy(100,120,"AND");
setcolor( random(15)+1);
outtextxy(100,160,"PRAJWAL J");
delay(50);
}//while
cleardevice();
}//end of credits

void scorecard()
{
clrscr();
cleardevice();
struct profile
{
char name[50];
int points;
};

profile p,p1,p2;
fstream file;
int count=0;


file.open("D:profile.txt",ios::in | ios::binary);
if(file)
{
file.read( (char*)&p,sizeof(p) );
while(!file.eof())
{
count++;
/*cout<<p.name<<"---"<<p.points<<'\n';
file.read( (char*)&p,sizeof(p) );     */
}
}//if(file)
getch();
file.close();

clrscr();
file.open("D:profile.txt",ios::in | ios::out | ios::binary);
for(int j=1;j<=count;j++)
{
file.open("D:profile.txt",ios::in | ios::out | ios::binary);
 for(int i=1;i<=count;i++)
 {
   file.read( (char*)&p1,sizeof(p1) );
   file.read( (char*)&p2,sizeof(p2) );
   if(p2.points>p1.points)
   {
   file.seekp(file.tellg()-2*sizeof(profile) );
   file.write( (char*)&p2,sizeof(p2) );
   file.write( (char*)&p1,sizeof(p1) );
   }

file.seekg(file.tellg()-sizeof(profile) );
 }
file.close();
}
getch();

clrscr();
cleardevice();
int x=30,y=60,x1=30,y1=30;
char displaypoints[5],ch;
for( ; ; )
{
//cleardevice();
x=30;
y=60;
x1=30;
file.open("D:profile.txt",ios::in | ios::binary);
file.read( (char*)&p,sizeof(p) );
while(!file.eof())
{
setcolor(YELLOW);
outtextxy(500,100,"HIGH SCORE");
setcolor(LIGHTRED);
setlinestyle(DOTTED_LINE,1 ,1);
rectangle(480,80,600,120);
setlinestyle(DASHED_LINE,10 ,1);
rectangle(470,70,610,130);

setcolor(CYAN);
outtextxy(x,y-y1,p.name);
sprintf(displaypoints,"%i",p.points);
setcolor(LIGHTCYAN);
outtextxy(400,y-y1,displaypoints);
y+=30;
file.read( (char*)&p,sizeof(p) );
}

ch=getch();
cleardevice();
 if(ch==77 && y1<=30*count)
   y1+=30;
 if(ch==75 && y1>30)
   y1-=30;
 if(ch==27)
   exit(0);
 if(ch=='e')
   exit(0);
 if(ch==13) //to show top 10
   break;

file.close();
}

//top 10
clrscr();
cleardevice();
x=30,y=60,x1=30,y1=30;
int i=1;
setcolor(YELLOW);
outtextxy(500,100,"TOP 10");
setcolor(LIGHTRED);
setlinestyle(DOTTED_LINE,1 ,1);
rectangle(480,80,600,120);
setlinestyle(DASHED_LINE,10 ,1);
rectangle(470,70,610,130);

fstream file1;
file1.open("D:profile.txt",ios::in | ios::binary);
file1.read( (char*)&p,sizeof(p) );
while(i<=10 && !file1.eof())
{
setcolor(CYAN);
outtextxy(x,y-y1,p.name);
sprintf(displaypoints,"%i",p.points);
setcolor(LIGHTCYAN);
outtextxy(400,y-y1,displaypoints);
y+=30;
file1.read( (char*)&p,sizeof(p) );
i++;
}

ch=getch();
 if(ch==27)
   exit(0);
 if(ch=='e')
   exit(0);

file1.close();

//showing screenshots
// putscreenshot();

getch();
}