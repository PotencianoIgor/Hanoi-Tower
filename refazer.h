#ifndef REFAZER_H
#define REFAZER_H
#include "pilha.h"

class NodeP{
public:
    NodeP* prox;
    Pilha* x;
    NodeP(Pilha* x);
};

class Refazer
{
    NodeP* topo;
    NodeP* pilha;
public:
    Refazer();
    Pilha *pop();
    void push(Pilha*);
    Pilha* getTopo(){return topo;}
};

class Desfazer
{
    NodeP* topo;
    NodeP* pilha;
public:
    Desfazer();
    Pilha* pop();
    void push(Pilha*);
    NodeP* getTopo(){return topo;}
};
#endif // REFAZER_H
