#include "pilha.h"
Temp

Node<type>::Node(type x){
    prox=NULL;
    this->x=x;
}

Pilha::Pilha(int x)
{
    topo=new Node<int>(1);
    pilha=topo;
    for(int i=2;i<=x;i++){
        pilha->prox=new Node<int>(i);
        pilha=pilha->prox;
    }
    size=x;
}

Pilha::Pilha(){
    topo=pilha=NULL;
    size=0;
}

Desfazer::Desfazer(){
    topo=pilha=NULL;
}

Refazer::Refazer(){
    topo=pilha=NULL;
}

void Pilha::push(int x){
    Node<int>* aux=new Node<int>(x);
    aux->prox=topo;
    topo=aux;
    size++;
}


int Pilha::pop(){
    size--;
    pilha=topo;
    topo=topo->prox;
    int x=pilha->x;
    delete pilha;
    return x;
}

void Refazer::push(Pilha *x){
    Node<Pilha*>* aux=new Node<Pilha*>(x);
    aux->prox=topo;
    topo=aux;
}

Pilha* Refazer::pop(){
    pilha=topo;
    topo=topo->prox;
    Pilha* x=pilha->x;
    delete pilha;
    return x;
}

void Desfazer::push(Pilha *x){
    Node<Pilha*>* aux=new Node<Pilha*>(x);
    aux->prox=topo;
    topo=aux;
}

Pilha* Desfazer::pop(){
    pilha=topo;
    topo=topo->prox;
    Pilha* x=pilha->x;
    delete pilha;
    return x;
}
