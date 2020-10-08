#include "refazer.h"

NodeP::PNode(Pilha* x){
    prox=NULL;
    this->x=x;
}

void Refazer::push(Pilha* x){
    Node* aux=new Node(x);
    aux->prox=topo;
    topo=aux;
}

Pilha* Refazer::pop(){
    pilha=topo;
    topo=topo->prox;
    Pilha x=pilha->x;
    delete pilha;
    return x;
}

void Desfazer::push(Pilha* x){
    Node* aux=new Node(x);
    aux->prox=topo;
    topo=aux;
}

Pilha* Desfazer::pop(){
    pilha=topo;
    topo=topo->prox;
    Pilha x=pilha->x;
    delete pilha;
    return x;
}
