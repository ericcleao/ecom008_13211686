#ifndef ITEM_H
#define ITEM_H
//#include <QString>

class Item
{
    QString name;
    double price;
public:
    Item();
    Item(QString name, double price);
    void print();
    Item *averangeItem(Item *p);
};

//int soma(int a, int b);
template<class T>
T soma(T a, T b){
    return a + b;
}

#endif // ITEM_H
