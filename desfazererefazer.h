#ifndef DESFAZEREREFAZER_H
#define DESFAZEREREFAZER_H

#include "pilha.h"
class RefazerDesfazer
{
public:
    Pilha* refazer;
    Pilha* desfazer;
    RefazerDesfazer();
    void desfazerJogada(Pilha*,Pilha*);
    void refazerJogada(Pilha*,Pilha*);
};

#endif // DESFAZEREREFAZER_H
