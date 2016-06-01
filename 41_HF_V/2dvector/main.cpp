#include <stdio.h>
#include <conio.h>

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

		C2D_Vector(double Fx=0.0, double Fy=0.0)
		{
			x=Fx;
			y=Fy;
		}

		C2D_Vector(const C2D_Vector& F2D_Vector)
		{
			x=F2D_Vector.x;
			y=F2D_Vector.y;
		}

		void add(C2D_Vector F2D_Vector)
		{
			x+=F2D_Vector.x;
			y+=F2D_Vector.y;
		}

		void mul(double FScalar)
		{
		    x*=FScalar;
		    y*=FScalar;
		}

		void print()
		{
		    printf("C2D_Vector.x=%f\r\n",x);
		    printf("C2D_Vector.y=%f\r\n",y);
		}
};

int main()
{
    double t=2.5;  // másodperc

    C2D_Vector v(+1.0,0); // sebesség(velocity)
    printf("*** Sebesseg ***\r\n");
    v.print();

    C2D_Vector g(0,+9.80665); // gravitációs gyorsulás
    printf("\r\n*** Gravitacio ***\r\n");
    g.print();

    // s=v*t+g*t^2;

    C2D_Vector s(v);
    s.mul(t);

    C2D_Vector tmp(g);
    tmp.mul(t*t);

    s.add(tmp);

    printf("\r\n*** Elmozdulas ***\r\n");
    s.print();

    getch();

    return 0;
}
