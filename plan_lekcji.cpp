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
    QMessageBox::about(this, "O programie", "Wersja 1.1.0\nUtworzył Mateusz Kołodziejski\nNr albumu 251089");
}

void Plan_lekcji::on_pushButton_2_clicked()
{
    dodaj_ucznia.show();
}

void Plan_lekcji::on_pushButton_5_clicked()
{
    lista_uczniow.show();
}

void Plan_lekcji::on_tableView_activated(const QModelIndex &index)
{

}

/* nad tym pracuję */
void Plan_lekcji::on_pushButton_3_clicked()
{
    qDebug()<<"Start";

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/matiz/Desktop/Roboczy Qt/Plan_lekcji3/Baza_planu_zajec.db");
    if(!db.open()){
        qDebug()<<"Problem z otwarciem bazy";
    }
    else
        qDebug()<<"Połączono z bazą :)";

    QString str=ui->lineEdit->text();
    qDebug()<<str;

    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQueryModel* modal2 = new QSqlQueryModel();
    QSqlQueryModel* modal3 = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);
    QSqlQuery *qry2 = new QSqlQuery(db);
    QSqlQuery *qry3 = new QSqlQuery(db);

    qry->prepare("Select Imie FROM Dane_osobowe WHERE ID_Ucznia = '"+str+"'");
    qry->exec();
    modal->setQuery(*qry);

    qry2->prepare("Select Nazwisko FROM Dane_osobowe WHERE ID_Ucznia = '"+str+"'");
    qry2->exec();
    modal2->setQuery(*qry2);

    qry3->prepare("SELECT * FROM Dane_osobowe INNER JOIN Lista_kursow ON Dane_osobowe.ID_Ucznia = Lista_kursow.Dane_osobowe_ID_"+str+"");
    qry3->exec();
    modal3->setQuery(*qry3);

    ui->listView_Uczen_Imie->setModel(modal);
    ui->listView_Uczen_Nazwisko->setModel(modal2);
    ui->tableView_plan_zajec->setModel(modal3);

    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
    if(!db.open())
        qDebug()<<"Zamknięto bazę :)";
    else
        qDebug()<<"Problem z zamknięciem bazy";
}

void Plan_lekcji::on_pushButton_4_clicked()
{
    qDebug()<<"Start";

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/matiz/Desktop/Roboczy Qt/Plan_lekcji3/Baza_planu_zajec.db");
    if(!db.open()){
        qDebug()<<"Problem z otwarciem bazy";
    }
    else
        qDebug()<<"Połączono z bazą :)";

    QString str=ui->lineEdit_2->text();
    qDebug()<<str;

    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);

    qry->prepare("SELECT * FROM Lista_kursow WHERE Przedmiot = '"+str+"'");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView_plan_zajec->setModel(modal);

    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
    if(!db.open())
        qDebug()<<"Zamknięto bazę :)";
    else
        qDebug()<<"Problem z zamknięciem bazy";
}
