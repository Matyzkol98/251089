#ifndef PLAN_LEKCJI_H
#define PLAN_LEKCJI_H

#include <QMainWindow>

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

    void on_actionDodawanie_triggered();

private:
    Ui::Plan_lekcji *ui;

//    void loadSubWindow(QWidget *widget);
};
#endif // PLAN_LEKCJI_H
