#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fp; //1
   int x=0;

   fp = fopen ("d:\\temp\\file.txt", "a+"); //2
   if(fp!=NULL)
   {
     printf("Sikerult megnyitni\n");
     //fprintf(fp, "%s %s %s %d", "We", "are", "in", 2015); //3
     fprintf(fp, "%d",-79); //3
     fseek(fp,0,SEEK_SET);
     //fseek(fp,-3,SEEK_CUR);
     fscanf(fp, "%d",&x); //3
     printf("Fajlbol olvasva: %d",x);
     fclose(fp); //4
   }
   else
   {
       printf("Nem Sikerült megnyitni");
   }

   return(0);
}
