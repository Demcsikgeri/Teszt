#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "C2D_Vector.h"
#include "MyConsole.h"

C2D_Vector g(0,9.81);

class CBall
{
protected:
    C2D_Vector p;
    C2D_Vector v;

public:

    CBall(const C2D_Vector &Fp,const C2D_Vector &Fv):
        p(Fp),
        v(Fv)
    {
        /* p=Fp;
         v=Fv;*/
    }

    void elmozdul(double t)
    {
        p=p.add(v.mul(t));
        fal_ellenorzo();
    }

    void y_pattan()
    {
        v=C2D_Vector(v.Get_x(),-1.0*v.Get_y());
    }

    void x_pattan()
    {
        v=C2D_Vector(-1.0*v.Get_x(),v.Get_y());
    }

    void fal_ellenorzo()
    {
        if (p.Get_x()<0)
            x_pattan();

        if (p.Get_x()>50)
            x_pattan();

        if (p.Get_y()<0)
            y_pattan();

        if (p.Get_y()>24)
            y_pattan();
    }

    void kirajzol()
    {
        Write_To_Console_Buffer(p.Get_x(),p.Get_y(),FCIG|BCIG,' ');
    }
};

class CGravity_Ball:public CBall
{
public:
    CGravity_Ball(const C2D_Vector &Fp,const C2D_Vector &Fv):CBall(Fp,Fv)
    {
    }

    void elmozdul(double t)
    {
        v=v.add(g.mul(t));
        /*
            s= v*t + g*t*t
            p = p + s

                     tmp1           tmp2
        p = p  +   v  *  t   +   g  *  t*t                               */
        p = p.add( v.mul(t).add( g.mul(t*t) ));
        /*      p = p  +     tmp1    +      tmp2
                p = p  +     tmp1  .add(    tmp2)
                p = p  +          tmp3
                p = p.add(        tmp3               )
                p = tmp4*/

        fal_ellenorzo();
    }

};

int main()
{
    Init_Console();
    Set_Console_Buffer_Sizes(80,25);

    CBall b(C2D_Vector(0,0),C2D_Vector(25,0));
    CGravity_Ball gb1(C2D_Vector(0,0),C2D_Vector(25,0));
    CGravity_Ball gb2(C2D_Vector(0,0),C2D_Vector(0,0));

    b.kirajzol();
    gb1.kirajzol();
    gb2.kirajzol();

    while(1)
    {
        b.elmozdul(0.005);
        gb1.elmozdul(0.005);
        gb2.elmozdul(0.005);

        Clear_Console_Buffer();

        b.kirajzol();
        gb1.kirajzol();
        gb2.kirajzol();

        Write_Buffer_To_Console();

        MySleep(1);

    }
    getch();
}
