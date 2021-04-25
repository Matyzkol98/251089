#include "dodaj_ucznia.h"
#include "ui_dodaj_ucznia.h"
#include <QMessageBox>
#include <QtSql>
#include <QDebug>

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

void dodaj_ucznia::on_pushButton_clicked()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/matiz/Desktop/Roboczy Qt/Plan_lekcji/Baza_planu_zajec.db");

    QString ID,Imie,Nazwisko;
    ID=ui->lineEdit_ID->text();
    Imie=ui->lineEdit_Imie->text();
    Nazwisko=ui->lineEdit_Nazwisko->text();

    db.open();
    QSqlQuery qry;
    qry.prepare("insert into Dane_osobowe (ID,Imie,Nazwisko) values ('"+ID+"','"+Imie+"','"+Nazwisko+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Zapisz"),tr("Zapisano"));
        db.close();
    }
    else
        QMessageBox::critical(this,tr("Błąd!!!"),qry.lastError().text());
}
