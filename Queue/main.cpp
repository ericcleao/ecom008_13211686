#include "fila.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Fila<int> test;

    test.enqueue(1);
    test.enqueue(3);
    test.enqueue(5);
    test.enqueue(7);
    test.enqueue(9);
    test.enqueue(11);
    test.enqueue(13);
    test.enqueue(15);
    test.enqueue(17);
    test.enqueue(19);
    test.enqueue(21);
    qDebug() << test.dequeue();
    qDebug() << test.dequeue();
    qDebug() << test.dequeue();
    qDebug() << test.frontValue();

    return 0;
}
