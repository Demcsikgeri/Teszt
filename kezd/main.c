
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <dos.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int x,y,sz,b,c,szin;
    randomize(); //random urit
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "D:\\TC\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   /* draw the circle */
   setcolor(LIGHTGREEN);
   circle(319,239,120);
   setfillstyle(1,YELLOW); //1=teli kit”lt‚s, ‚s ezzel a sz¡nnel tolt ki
   floodfill(319,239,LIGHTGREEN); //eddig a sz¡nig t”lts”n ki

   setcolor(LIGHTBLUE);
   circle(269,179,30);
   setfillstyle(1,BLUE);
   floodfill(269,179,LIGHTBLUE);

   setcolor(BLUE);
   ellipse(369,179,0,360,50,30);
   setfillstyle(1,BLUE);
   floodfill(369,179,BLUE);

   setcolor(RED);
   setlinestyle(1,1,3);
   arc(319,239,235,315,80);  //x,y,kezdoszog,vegszog,sugar

   setcolor(11);
   settextstyle(GOTHIC_FONT,0,4);
   outtextxy(10,50,"Nyomj egy gombot!");
   getch();

   sz=30;
   b=1;
   while(!kbhit())
   {
    if(b==1)
     setcolor(YELLOW);
     ellipse(369,179,0,360,50,sz);
     if (sz>0) sz=sz-1;
     else
     {
      b=0;
      szin=random(15)+1;
     }
    }
    else
    {
     setcolor(szin);
     ellipse(369,179,0,360,50,sz);
     if (sz<30) sz=sz+1;
     else b=1;
    }
   }

/*   sz=0;
   b=0;
   while(!kbhit())
   {
      if(b==0)
      {
       if(getmaxx()/2>sz) sz=sz+1;
       else b=1;
       setcolor(random(15)+1);
       circle(getmaxx()/2,getmaxy()/2,sz);
      }
      else
      {
       if(0<sz) sz=sz-1;
       else b=0;
	setcolor(random(15)+1);
	rectangle(getmaxx()/2-sz,getmaxy()/2-sz,getmaxx()/2+sz,getmaxy()/2+sz);
	delay(10);
      }
    //   setcolor(0);
     //  settextstyle(GOTHIC_FONT,0,5);
     //  outtextxy(10+sz*10,50+sz*10,"hello world");

   }*/


/*   sz=0;
   while(sz<360)
   {
       x=40*cos(sz*(M_PI/180));
       y=40*sin(sz*(M_PI/180));
       putpixel(200+x,80+y,13);
       sz=sz+1;
   }*/

   /* clean up */
   getch();
   closegraph();
   return 0;
}

