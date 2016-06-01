#include <conio.h>
#include <stdio.h>
#include "Szinek.h"

void ugras(FILE *f,int x, int y)
{
    fprintf(f,"U%i;%i\r\n",x,y);
}

void f_vonal(FILE *f,int xk, int yk,int xv,int yv)
{
    ugras(f,xk,yk);

    if (yk<yv)
    {
        //lefele
        int y;
        for (y=yk; y<=yv; y+=1 )
        {
            fprintf(f,"*\r\n");
            fprintf(f,"L\r\n");
        }
    }
    else
    {
        //felfele
        int y;
        for (y=yk; y>=yv; y-=1 )
        {
            fprintf(f,"*\r\n");
            fprintf(f,"F\r\n");
        }
    }
}

void v_vonal(FILE *f,int xk, int yk,int xv,int yv)
{
    ugras(f,xk,yk);

    if (xk<xv)
    {
        //jobbra
        int x;
        for (x=xk; x<=xv; x+=1 )
        {
            fprintf(f,"*\r\n");
            fprintf(f,"J\r\n");
        }
    }
    else
    {
        //balra
        int x;
        for (x=xk; x>=xv; x-=1 )
        {
            fprintf(f,"*\r\n");
            fprintf(f,"B\r\n");
        }
    }
}


void szinez(FILE *f,int kod)
{
 fprintf(f,"S%c\r\n",kod+48);
}

int main()
{
    FILE * f=fopen("smiley.S13","w");

    //buksi
    szinez(f,kek);
    v_vonal(f,1,1,15,1);
    f_vonal(f,15,1,15,13);
    v_vonal(f,15,13,1,13);
    f_vonal(f,1,13,1,1);

    //bal szem
    szinez(f,piros);
    v_vonal(f, 4,4, 6,4);
    f_vonal(f, 6,4, 6,6);
    v_vonal(f, 6,6, 4,6);
    f_vonal(f, 4,6, 4,4);

    //jobb szem
    szinez(f,zod);
    v_vonal(f, 10,4, 12,4);
    f_vonal(f, 12,4, 12,6);
    v_vonal(f, 12,6, 10,6);
    f_vonal(f, 10,6, 10,4);

    //száj
    szinez(f,feher);
    f_vonal(f, 4,9, 4,10);
    v_vonal(f, 4,10, 12,10);
    f_vonal(f, 12,10, 12,9);

    fclose(f);

    return 0;
}
