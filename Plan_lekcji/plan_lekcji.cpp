#include "plan_lekcji.h"
#include "ui_plan_lekcji.h"
#include <QMessageBox>

Plan_lekcji::Plan_lekcji(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Plan_lekcji)
{
    ui->setupUi(this);
}

Plan_lekcji::~Plan_lekcji()
{
    delete ui;
}


void Plan_lekcji::on_pushButton_clicked()
{
   close();
}

void Plan_lekcji::on_pushButton_1_clicked()
{
    QMessageBox::about(this, "O programie", "Wersja 1.0.0\nUtworzył Mateusz Kołodziejski\nNr albumu 251089");
}

/*void Plan_lekcji::on_actionDodawanie_triggered()
{

}*/
