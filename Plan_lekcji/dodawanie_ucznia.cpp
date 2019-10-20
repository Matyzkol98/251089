#include "dodawanie_ucznia.h"
#include "ui_dodawanie_ucznia.h"

Dodawanie_ucznia::Dodawanie_ucznia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dodawanie_ucznia)
{
    ui->setupUi(this);
}

Dodawanie_ucznia::~Dodawanie_ucznia()
{
    delete ui;
}
