#include "plan_lekcji.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Plan_lekcji w;
    w.show();
    return a.exec();
}
