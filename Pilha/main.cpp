#include "pilha.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Pilha<int> teste;

    teste.push(11);
    teste.push(22);
    teste.push(11);
    teste.push(22);
    teste.push(11);
    teste.push(22);
    teste.push(11);
    teste.push(22);
    teste.push(11);
    teste.push(22);
    teste.push(11);
    teste.push(22);
    teste.push(11);
    teste.push(22);




    qDebug() << teste.length();
    qDebug() << teste.pop();
    qDebug() << teste.length();
    qDebug() << teste.topValue();

    return 0;
}
