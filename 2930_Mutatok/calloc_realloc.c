int main()
{
    int t_meret=10;
    int *t=(int*)calloc(t_meret,sizeof(int));
    printf("%x\r\n",t);

    int i;
    for (i=0;i<t_meret;i+=1)
        t[i]=i;

    for (i=0;i<t_meret;i+=1)
        printf("%i,",*(t+i));

    printf("\r\n");

    int *tmp=(int*)realloc(t,200000*sizeof(int));
    if (tmp==NULL)
    {
        printf("Hiba van");
        free(t);
        exit(1);
    }
    t=tmp;
    t_meret=200000;

    printf("%x\r\n",t);
        for (i=0;i<10;i+=1)
        printf("%i,",*(t+i));





    getch();
    return 0;
}
