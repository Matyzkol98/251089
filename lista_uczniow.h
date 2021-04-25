#ifndef LISTA_UCZNIOW_H
#define LISTA_UCZNIOW_H

#include <QWidget>

namespace Ui {
class Lista_uczniow;
}

class Lista_uczniow : public QWidget
{
    Q_OBJECT

public:
    explicit Lista_uczniow(QWidget *parent = nullptr);
    ~Lista_uczniow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Lista_uczniow *ui;
};

#endif // LISTA_UCZNIOW_H
