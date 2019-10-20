#ifndef PLAN_LEKCJI_H
#define PLAN_LEKCJI_H

#include <QMainWindow>
#include <dodaj_ucznia.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Plan_lekcji; }
QT_END_NAMESPACE

class Plan_lekcji : public QMainWindow
{
    Q_OBJECT

public:
    Plan_lekcji(QWidget *parent = nullptr);
    ~Plan_lekcji();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Plan_lekcji *ui;

    dodaj_ucznia dodaj_ucznia;

};
#endif // PLAN_LEKCJI_H
