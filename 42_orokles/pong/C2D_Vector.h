#ifndef C2D_VECTOR_H_INCLUDED
#define C2D_VECTOR_H_INCLUDED

//#define log

class C2D_Vector
{
private:

    double x;
    double y;

public:

    double Get_x()
    {
        return x;
    }

    double Get_y()
    {
        return y;
    }

    C2D_Vector() // (alapértelmezett) default constructor
    {
#ifdef log
        printf("C2D_Vector(0x%x)::C2D_Vector()\r\n",this);
#endif

        x=0;
        y=0;
    }

    C2D_Vector(/* C2D_Vector *this, */ double Fx, double Fy)//: // constructor overload / redefine
    /* x(Fx),
     y(Fy)*/
    {
#ifdef log
        printf("C2D_Vector(0x%x)::C2D_Vector(double,double)\r\n",this);
#endif
        /*this->*/x=Fx;
        /*this->*/y=Fy;
    }

    C2D_Vector mul(/* C2D_Vector *this, */double FScalar)
    {
#ifdef log
        printf("C2D_Vector(0x%x)::mul(double)\r\n",this);
#endif

        return C2D_Vector(/*this->*/x*FScalar,this->y*FScalar);
    }

    C2D_Vector add(/* C2D_Vector *this, */ const C2D_Vector &FVector)
    {
#ifdef log
        printf("C2D_Vector(0x%x)::add(C2D_Vector)\r\n",this);
#endif

        return C2D_Vector(this->x+FVector.x,this->y+FVector.y);
    }

    void kiir(/* C2D_Vector *this, */)
    {
#ifdef log
        printf("C2D_Vector(0x%x)::kiir()\r\n",this);
#endif

        printf("x=%f\r\n",this->x);
        printf("y=%f\r\n",/*this->*/y);
    }
};

#endif // C2D_VECTOR_H_INCLUDED
