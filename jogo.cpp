#include "jogo.h"

Jogo::Jogo(int x)
{
    torres=new Pilha*[3];
    torres[0]=new Pilha(x);
    torres[1]=new Pilha;
    torres[2]=new Pilha;
    jogadas=0;
}

void Jogo::mover(Pilha *ori, Pilha *des){
    if(ori->getTopo()){
        if(des->getTopo()==NULL){
            des->push(ori->pop());
            desfaz.push(des);
            desfaz.push(ori);
            jogadas++;
        }
        else
        {
            if(des->getTopo()->x>ori->getTopo()->x){
                 des->push(ori->pop());
                 desfaz.push(des);
                 desfaz.push(ori);
                 jogadas++;
            }
        }
    }
}

void Jogo::desfazer(){
    if(desfaz.getTopo()){
        Pilha* ori,*des;
        ori=desfaz.pop();
        des=desfaz.pop();
        ori->push(des->pop());
        refaz.push(ori);
        refaz.push(des);

    }
}

void Jogo::refazer(){
    if(refaz.getTopo()){
        Pilha* ori,*des;
        ori=refaz.pop();
        des=refaz.pop();
        ori->push(des->pop());
        jogadas++;
    }
}
