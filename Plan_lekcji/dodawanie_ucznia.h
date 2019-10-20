#ifndef DODAWANIE_UCZNIA_H
#define DODAWANIE_UCZNIA_H

#include <QWidget>

namespace Ui {
class Dodawanie_ucznia;
}

class Dodawanie_ucznia : public QWidget
{
    Q_OBJECT

public:
    explicit Dodawanie_ucznia(QWidget *parent = nullptr);
    ~Dodawanie_ucznia();

private:
    Ui::Dodawanie_ucznia *ui;
};

#endif // DODAWANIE_UCZNIA_H
