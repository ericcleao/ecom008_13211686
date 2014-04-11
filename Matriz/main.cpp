#include <QDebug>
#include "matriz.h"

int main(int argc, char *argv[])
{
    Q_UNUSED (argc);
    Q_UNUSED (argv);
/*
    Matriz a, b;
    a.create(2,3);

    a.setElementAt(0,0,1);
    a.setElementAt(0,1,2);
    a.setElementAt(0,2,3);
    a.setElementAt(1,0,4);
    a.setElementAt(1,1,5);
    a.setElementAt(1,2,6);

    b.create(5,5);

    b.setElementAt(0,0,1);
    b.setElementAt(0,1,2);
    b.setElementAt(0,2,3);
    b.setElementAt(0,3,4);
    b.setElementAt(0,4,5);
    b.setElementAt(1,0,1);
    b.setElementAt(1,1,0);
    b.setElementAt(1,2,2);
    b.setElementAt(1,3,0);
    b.setElementAt(1,4,9);
    b.setElementAt(2,0,0);
    b.setElementAt(2,1,1);
    b.setElementAt(2,2,2);
    b.setElementAt(2,3,3);
    b.setElementAt(2,4,13);
    b.setElementAt(3,0,2);
    b.setElementAt(3,1,3);
    b.setElementAt(3,2,0);
    b.setElementAt(3,3,0);
    b.setElementAt(3,4,2);
    b.setElementAt(4,0,3);
    b.setElementAt(4,1,0);
    b.setElementAt(4,2,5);
    b.setElementAt(4,3,1);
    b.setElementAt(4,4,12);

    qDebug() << qPrintable(b.toString());
    qDebug() << b.determinant() << endl;
    b.multiplyBy(2);
    qDebug() << b.transpose()->determinant() << endl;

    MatrixADT * c = a.transpose();
    qDebug() << qPrintable(a.toString());
    qDebug() << qPrintable(c->toString());
*/
    Matriz x;
    x.square(5);
    qDebug() << qPrintable(x.toString());
    qDebug() << x.determinant();
    return 0;
}
