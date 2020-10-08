#include "desfazererefazer.h"

RefazerDesfazer::RefazerDesfazer()
{
    refazer=new Pilha;
    desfazer=new Pilha;
}

RefazerDesfazer::RefazerJogada(Pilha *ori, Pilha *des){
    ori->push(refazer->pop());
    des->push(refazer->pop());
}

RefazerDesfazer::desfazerJogada(Pilha *ori, Pilha *des){
    ori->push(desfazer->pop());
    des->push(desfazer->pop());
}
