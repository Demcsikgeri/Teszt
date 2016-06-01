int main()
{
    int z=1111;

    printf("z valtozo cime:%x\r\n",&z);
    printf("z valtozo erteke:%i\r\n",z);

    int *p; // p mutato deklarálása

    p=NULL; // p mutató inicializálása null értékkel (érvénytelen)

    p=0; // == p=NULL

    printf("p pointer erteke:%x\r\n",p);

    p=&z; // z változó címének berakása p mutatóba

    printf("p pointer erteke:%x\r\n",p);
    printf("p mutato indirekcioja/feloldasa:%i\r\n", *p);

    short int t[5] = {0x1122,0x3344,0x5566,0x7788,0x99AA};
                    //2211443366558877AA99
                    // ->

    printf("t tomb kezdocime:%x\r\n",t);
    printf("t tomb kezdocime:%x\r\n",&t[0]); // t == &t[0]

    printf("t tomb 3. elemenek erteke:%x\r\n",t[3]);
    printf("t tomb 3. elemenek erteke:%x\r\n",*((&t[0])+3));
    printf("t tomb 3. elemenek erteke:%x\r\n",*(t+3));
    printf("sizeof(short int)=%i\r\n",sizeof(short int));
    printf("t tomb 3. elemenek cime:%x\r\n",&t[3]);
    printf("t tomb 3. elemenek szamitott cime:%x\r\n",  ((int)t + 3*sizeof(short int)) );
    printf("t tomb 3. elemenek erteke:%x\r\n",*(short int *)((int)t + 3*sizeof(short int)));

    printf("t tomb 1. elemenek ROSSZ erteke:%x\r\n",*(int *)((int)t + 1*sizeof(int)));
                                                //22,11 44,33 66,55 88,77 AA,99
                                                //^
                                                //** ** ** ** 66,55 88,77 -> 0x77885566

    char azennevem[30]="Kalcsu Attila";
    printf("Nevem 7. karakterenek ASCII kodja:%i\r\n",azennevem[7]);
    printf("Nevem 7. karakterenek ASCII kodja:%i\r\n",*(azennevem+7));

    int i;

    // i=i+1 <-> i+=1   C++-> i++    C -> C++

    char *pc=azennevem;
    for (i=0;i<30;i+=1,pc+=1)
        (*pc)+=1;

    printf("Az en nevem kodolva:%s\r\n", azennevem);

    short int *pi=t;
    for (i=0;i<5;i+=1,pi+=1)
        (*pi)+=1;
    printf("t tomb 3. elemenek erteke:%x\r\n",t[3]);

    getch();
    return 0;
}
