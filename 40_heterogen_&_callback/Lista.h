#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

void hozzaad(void* FElem);
void beszur(int FIndex, void * FElem);
void torol(int FIndex);
void cserel(int FA_Index,int FB_Index);

typedef void (*PFenkicsicallbackem)(void *FElem);

void bejar(PFenkicsicallbackem Fenkicsicallbackem);

#endif // LISTA_H_INCLUDED
