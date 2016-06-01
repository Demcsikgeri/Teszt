#include <iostream>
#include <stdio.h>
#include <conio.h>

class Aru //abstract class
{
protected:
    static double afa;

public:

    static void Set_afa(double Fafa)
    {
        afa=Fafa;
        kiir();
    }

    virtual char * Get_Name()=0; // abstract method
    virtual double Get_Price()=0; // abstract method

    void kiir(/*this*/)
    {
        printf("%s=%f\r\n",Get_Name(),Get_Price());
    }
};

double Aru::afa=27;

class Banan: public Aru
{
    virtual char * Get_Name()
    {
        return "Banan";
    }
    virtual double Get_Price()
    {
        return 349.0*(1.0+afa/100.0);
    }
};

class Alma: public Aru
{
    virtual char * Get_Name()
    {
        return "Alma";
    }
    virtual double Get_Price()
    {
        return 200.0*(1.0+afa/100.0);
    }
};

int main()
{
    // Aru a; // abstract class

    Banan b;
    b.kiir();

    Alma a;
    a.kiir();

    Aru::Set_afa(0);

    b.kiir();
    a.kiir();

    getch();

    return 0;
}
