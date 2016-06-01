#ifndef SMACSKA_H_INCLUDED
#define SMACSKA_H_INCLUDED

typedef struct
{
    char nev[20];
    int suly;
    int kor;
} SMacska;

typedef SMacska *PSMacska;

void kiir(PSMacska FMacska);
PSMacska beker();

#endif // SMACSKA_H_INCLUDED
