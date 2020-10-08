#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pilha.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int t;
void MainWindow::on_pushButton_Inicio_clicked()
{
    ui->pushButton_P1_P2->setEnabled(true);
    ui->pushButton_P1_P3->setEnabled(true);
    ui->pushButton_P2_P1->setEnabled(true);
    ui->pushButton_P2_P3->setEnabled(true);
    ui->pushButton_P3_P1->setEnabled(true);
    ui->pushButton_P3_P2->setEnabled(true);

    int x=0;
    switch(ui->comboBox_Tamanho->currentIndex()){
    case 1:
        ui->textEdit_Pilha1->setGeometry(50,120,21,65);
        ui->textEdit_Pilha2->setGeometry(170,120,21,65);
        ui->textEdit_Pilha3->setGeometry(300,120,21,65);
        x=3;
        ui->lineEdit->setText("minimo de jogadas = "+QString::number(pow(2,x)-1));
        break;
    case 2:
        ui->textEdit_Pilha1->setGeometry(50,120,21,78);
        ui->textEdit_Pilha2->setGeometry(170,120,21,78);
        ui->textEdit_Pilha3->setGeometry(300,120,21,78);
        x=4;
        ui->lineEdit->setText("minimo de jogadas = "+QString::number(pow(2,x)-1));
        break;
    case 3:
        ui->textEdit_Pilha1->setGeometry(50,120,21,95);
        ui->textEdit_Pilha2->setGeometry(170,120,21,95);
        ui->textEdit_Pilha3->setGeometry(300,120,21,95);
        x=5;
        ui->lineEdit->setText("minimo de jogadas = "+QString::number(pow(2,x)-1));
        break;
    case 4:
        ui->textEdit_Pilha1->setGeometry(50,120,21,115);
        ui->textEdit_Pilha2->setGeometry(170,120,21,115);
        ui->textEdit_Pilha3->setGeometry(300,120,21,115);
        x=6;
        ui->lineEdit->setText("minimo de jogadas = "+QString::number(pow(2,x)-1));
        break;
    case 5:
        ui->textEdit_Pilha1->setGeometry(50,120,21,130);
        ui->textEdit_Pilha2->setGeometry(170,120,21,130);
        ui->textEdit_Pilha3->setGeometry(300,120,21,130);
        x=7;
        ui->lineEdit->setText("minimo de jogadas = "+QString::number(pow(2,x)-1));
        break;
    }
    t=x;
    if(x!=0){
        T=new Jogo(x);
        QString S;
        Node<int>* aux=T->torres[0]->getTopo();
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha1->setText(S);
    }
}

void MainWindow::on_pushButton_P1_P2_clicked()
{
    T->mover(T->torres[0],T->torres[1]);
    QString S;
    Node<int>* aux;
    aux=T->torres[0]->getTopo();
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha1->setText(S);
    aux=T->torres[1]->getTopo();
    S="";
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha2->setText(S);
    aux=T->torres[2]->getTopo();
    S="";
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha3->setText(S);
    ui->lineEdit->setText(QString::number(T->getJogadas())+" jogada(s)");
}

void MainWindow::on_pushButton_P2_P1_clicked()
{
    T->mover(T->torres[1],T->torres[0]);
    QString S;
    Node<int>* aux;
    aux=T->torres[0]->getTopo();
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha1->setText(S);
    aux=T->torres[1]->getTopo();
    S="";
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha2->setText(S);
    aux=T->torres[2]->getTopo();
    S="";
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha3->setText(S);
    ui->lineEdit->setText(QString::number(T->getJogadas())+" jogada(s)");
}

void MainWindow::on_pushButton_P2_P3_clicked()
{
    T->mover(T->torres[1],T->torres[2]);
    if(T->torres[2]->getSize()<t){
        QString S;
        Node<int>* aux;
        aux=T->torres[0]->getTopo();
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha1->setText(S);
        aux=T->torres[1]->getTopo();
        S="";
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha2->setText(S);
        aux=T->torres[2]->getTopo();
        S="";
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha3->setText(S);
        ui->lineEdit->setText(QString::number(T->getJogadas())+" jogada(s)");
    }
    else{
        ui->lineEdit->setText("Fim de Jogo - "+QString::number(T->getJogadas())+" jogada(s)");
        ui->textEdit_Pilha1->close();
        ui->textEdit_Pilha2->close();
        ui->textEdit_Pilha3->close();
        ui->pushButton_P1_P2->close();
        ui->pushButton_P1_P3->close();
        ui->pushButton_P2_P1->close();
        ui->pushButton_P2_P3->close();
        ui->pushButton_P3_P1->close();
        ui->pushButton_P3_P2->close();
    }
}

void MainWindow::on_pushButton_P3_P2_clicked()
{
    T->mover(T->torres[2],T->torres[1]);
    QString S;
    Node<int>* aux;
    aux=T->torres[0]->getTopo();
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha1->setText(S);
    aux=T->torres[1]->getTopo();
    S="";
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha2->setText(S);
    aux=T->torres[2]->getTopo();
    S="";
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha3->setText(S);
    ui->lineEdit->setText(QString::number(T->getJogadas())+" jogada(s)");
}

void MainWindow::on_pushButton_P3_P1_clicked()
{
    T->mover(T->torres[2],T->torres[0]);
    QString S;
    Node<int>* aux;
    aux=T->torres[0]->getTopo();
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha1->setText(S);
    aux=T->torres[1]->getTopo();
    S="";
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha2->setText(S);
    aux=T->torres[2]->getTopo();
    S="";
    while(aux){
        S+=QString::number(aux->x);
        aux=aux->prox;
    }
    ui->textEdit_Pilha3->setText(S);
    ui->lineEdit->setText(QString::number(T->getJogadas())+" jogada(s)");
}

void MainWindow::on_pushButton_P1_P3_clicked()
{
    T->mover(T->torres[0],T->torres[2]);
    if(T->torres[2]->getSize()<t){
        Node<int>* aux;
        QString S;
        aux=T->torres[0]->getTopo();
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha1->setText(S);
        aux=T->torres[1]->getTopo();
        S="";
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha2->setText(S);
        aux=T->torres[2]->getTopo();
        S="";
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha3->setText(S);
        ui->lineEdit->setText(QString::number(T->getJogadas())+" jogada(s)");
    }
    else{
        ui->lineEdit->setText("Fim de Jogo - "+QString::number(T->getJogadas())+" jogada(s)");
        ui->textEdit_Pilha1->close();
        ui->textEdit_Pilha2->close();
        ui->textEdit_Pilha3->close();
        ui->pushButton_P1_P2->close();
        ui->pushButton_P1_P3->close();
        ui->pushButton_P2_P1->close();
        ui->pushButton_P2_P3->close();
        ui->pushButton_P3_P1->close();
        ui->pushButton_P3_P2->close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent * k){
    if(k->key()==Qt::Key_D){
        T->desfazer();
        Node<int>* aux;
        QString S;
        aux=T->torres[0]->getTopo();
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha1->setText(S);
        aux=T->torres[1]->getTopo();
        S="";
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha2->setText(S);
        aux=T->torres[2]->getTopo();
        S="";
        while(aux){
            S+=QString::number(aux->x);
            aux=aux->prox;
        }
        ui->textEdit_Pilha3->setText(S);
    }
    else{
        if(k->key()==Qt::Key_R){
            T->refazer();
            Node<int>* aux;
            QString S;
            aux=T->torres[0]->getTopo();
            while(aux){
                S+=QString::number(aux->x);
                aux=aux->prox;
            }
            ui->textEdit_Pilha1->setText(S);
            aux=T->torres[1]->getTopo();
            S="";
            while(aux){
                S+=QString::number(aux->x);
                aux=aux->prox;
            }
            ui->textEdit_Pilha2->setText(S);
            aux=T->torres[2]->getTopo();
            S="";
            while(aux){
                S+=QString::number(aux->x);
                aux=aux->prox;
            }
            ui->textEdit_Pilha3->setText(S);
            ui->lineEdit->setText(QString::number(T->getJogadas())+" jogada(s)");
        }
    }
}
