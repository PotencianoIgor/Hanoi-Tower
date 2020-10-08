#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "jogo.h"
#include <QKeyEvent>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *);
    ~MainWindow();

private slots:

    void on_pushButton_P1_P2_clicked();

    void on_pushButton_P2_P1_clicked();

    void on_pushButton_P2_P3_clicked();

    void on_pushButton_P3_P2_clicked();

    void on_pushButton_P3_P1_clicked();

    void on_pushButton_P1_P3_clicked();

    void on_pushButton_Inicio_clicked();

private:
    Ui::MainWindow *ui;
    Jogo* T;
};

#endif // MAINWINDOW_H
