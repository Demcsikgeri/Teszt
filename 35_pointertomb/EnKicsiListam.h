#ifndef ENKICSILISTAM_H_INCLUDED
#define ENKICSILISTAM_H_INCLUDED

extern PSMacska *L;
extern int L_elemszam;

void Add(PSMacska FMacska);
void Del(int idx);
PSMacska Remove(int idx);
void Insert(int idx,PSMacska FMacska);
void Replace(int idx_a,int idx_b);

#endif // ENKICSILISTAM_H_INCLUDED
