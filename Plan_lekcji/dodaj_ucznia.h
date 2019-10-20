#ifndef DODAJ_UCZNIA_H
#define DODAJ_UCZNIA_H

#include <QWidget>

namespace Ui {
class dodaj_ucznia;
}

class dodaj_ucznia : public QWidget
{
    Q_OBJECT

public:
    explicit dodaj_ucznia(QWidget *parent = nullptr);
    ~dodaj_ucznia();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::dodaj_ucznia *ui;
};

#endif // DODAJ_UCZNIA_H
