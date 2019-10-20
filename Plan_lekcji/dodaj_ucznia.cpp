#include "dodaj_ucznia.h"
#include "ui_dodaj_ucznia.h"

dodaj_ucznia::dodaj_ucznia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dodaj_ucznia)
{
    ui->setupUi(this);
}

dodaj_ucznia::~dodaj_ucznia()
{
    delete ui;
}

void dodaj_ucznia::on_pushButton_2_clicked()
{
     close();
}
