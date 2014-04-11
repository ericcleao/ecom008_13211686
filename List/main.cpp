#include "LinkedList.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    LinkedList<int> lista;

    lista.insert(10);
    lista.insert(20);
    lista.moveToStart();
    lista.insert(17);
    lista.insert(9);
    lista.insert(40);
    lista.moveToPos(3);
    lista.insert(30);
    lista.insert(46);
    qDebug() << lista.getValue();
    lista.append(41);
    lista.insert(12);
    lista.moveToPos(3);

    qDebug() << lista.currPos() << lista.getValue();

    lista.moveToEnd();
    qDebug() << qPrintable(lista.toString());
    lista.bubbleSort();
    qDebug() << qPrintable(lista.toString());
    lista.moveToStart();
    qDebug() << lista.remove();

    qDebug() << qPrintable(lista.toString());

    qDebug() << lista.currPos();
    qDebug() << lista.length();

    return 0;
}
