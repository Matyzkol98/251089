#include "plan_lekcji.h"
#include "ui_plan_lekcji.h"
#include <QMessageBox>
#include <QtSql>
#include <QDebug>

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
    QMessageBox::about(this, "O programie", "Wersja 1.0.1\nUtworzył Mateusz Kołodziejski\nNr albumu 251089");
}

void Plan_lekcji::on_pushButton_2_clicked()
{
    qDebug()<<"Start";

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/matiz/Desktop/Roboczy Qt/Plan_lekcji/Baza_planu_zajec.db");

    if(!db.open()){
        qDebug()<<"Problem z otwarciem bazy";
 //     return false;
    }
    else
        qDebug()<<"Połączono z bazą :)";
 //     return true;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("Select * FROM Dane_osobowe");

    dodaj_ucznia.show();
}

void Plan_lekcji::on_pushButton_5_clicked()
{
    lista_uczniow.show();
}

void Plan_lekcji::on_tableView_activated(const QModelIndex &index)
{

}

