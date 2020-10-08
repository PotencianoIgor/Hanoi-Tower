#ifndef PILHA_H
#define PILHA_H
#include <iostream>
using namespace std;
#define Temp template<typename type>
Temp

class Node{
public:
    Node(type);
    Node* prox;
    type x;
};


class Pilha
{
private:
    Node<int>* pilha;
    Node<int>* topo;
    int size;
public:
    Pilha(int x);
    Pilha();
    Node<int>* getTopo(){return topo;}
    int pop();
    void push(int);
    int getSize(){return size;}
};

class Refazer{
private:
    Node<Pilha*>* topo;
    Node<Pilha*>* pilha;
public:
    Refazer();
    Pilha* pop();
    void push(Pilha *);
    Node<Pilha*>* getTopo(){return topo;}
};

class Desfazer{
private:
    Node<Pilha*>* topo;
    Node<Pilha*>* pilha;
public:
    Desfazer();
    Pilha *pop();
    void push(Pilha *);
    Node<Pilha*>* getTopo(){return topo;}
};

#endif // PILHA_H
