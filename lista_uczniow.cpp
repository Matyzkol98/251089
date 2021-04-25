#include "lista_uczniow.h"
#include "ui_lista_uczniow.h"
#include <QMessageBox>
#include <QtSql>
#include <QDebug>

Lista_uczniow::Lista_uczniow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lista_uczniow)
{
    ui->setupUi(this);
}

Lista_uczniow::~Lista_uczniow()
{
    delete ui;
}

void Lista_uczniow::on_pushButton_clicked()
{
    close();
}

void Lista_uczniow::on_pushButton_2_clicked()
{
    qDebug()<<"Start";

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/matiz/Desktop/Roboczy Qt/Plan_lekcji/Baza_planu_zajec.db");

    if(!db.open())
        qDebug()<<"Problem z otwarciem bazy";
    else
        qDebug()<<"Połączono z bazą :)";

    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("Select * FROM Dane_osobowe");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}


void Lista_uczniow::on_pushButton_3_clicked()
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
    qry->prepare("Select * FROM Lista_zajec");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}
