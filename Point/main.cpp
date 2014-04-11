#include <QDebug>
#include <QList>
#include "item.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Item p("Eric", 5.3);
    Item *p1 = new Item;
    p.print();
    p1->print();
    Item *p2 = p.averangeItem(p1);
    p2->print();


    return 0;
}
