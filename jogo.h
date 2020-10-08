#ifndef JOGO_H
#define JOGO_H
#include "pilha.h"

class Jogo
{
    int jogadas;
    Refazer refaz;
    Desfazer desfaz;
public:

    Pilha** torres;
    Jogo(int);
    void mover(Pilha*,Pilha*);
    int getJogadas(){return jogadas;}
    void desfazer();
    void refazer();
};

#endif // JOGO_H
