#include <iostream>
#include <stdio.h>
#include <conio.h>

class Eloleny // absztrakt oszt�ly
{
public:

    void cimki()
    {
        printf("%x\r\n",this);
    }

    virtual void koszon()=0; //abstract method / pure method
                                // pure virtual function
};

class Kutya: public Eloleny
{
public:

    virtual void koszon()
    {

    }

    virtual void koszones()
    {
        cimki();
        printf("Vau\r\n");
    }
};

class Ember: public Eloleny
{
public:
    virtual void koszon()
    {
        cimki();
        printf("Helosziaszevasz\r\n");
    }
};

class MorcosEmber: public Ember
{
public:
    virtual void koszon()
    {
        cimki();
        printf("Egyszart\r\n");
    }
};

int main()
{
   /* Eloleny el;
    el.koszon();
    NEM hozhat� l�tre mert absztrakt oszt�ly
    */

    Kutya k;
    k.koszon();

    ((Eloleny*)&k)->koszon();

    MorcosEmber me;

    me.koszon();
    ((Ember*)&me)->koszon();
    ((Eloleny*)&me)->koszon();

    me.Ember::koszon();



    getch();
}
