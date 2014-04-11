#include<QDebug>
#include "item.h"


Item::Item()
{
    this->name = "";
    this->price = 0.0;
}

Item::Item(QString name, double price){
    this->name = name;
    this->price = price;
}

void Item::print(){
    qDebug() << "= Item ================";
    qDebug() << "name:" << qPrintable(this->name);
    qDebug() << "price:" << this->price;
    qDebug() << "=======================";
}

Item *Item::averangeItem(Item *p){
    return new Item("Testando",(this->price+ p->price)/2);
}
