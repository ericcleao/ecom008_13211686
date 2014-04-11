#ifndef CONTA_H
#define CONTA_H
#include <QList>

class Conta
{
    QList<QString> list;
public:
    Conta();
    void pedido(item i){
        add.list(i);
    }
};

#endif // CONTA_H
