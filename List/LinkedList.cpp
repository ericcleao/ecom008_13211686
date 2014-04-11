#include "list.h"
#include <QString>
#include <QDebug>

List::List(){
    this->location = 0;
    element = new Node;
    this->element = &head;
}

void List::clear(){
    moveToStart();
    this->next();
    while(element->getNext() != 0){
        this->element->setValue(0);
        this->next();
    }
}

void List::insert(int item){
    ++this->location;
    this->element->createNext(this->element, item);
    element = element->getNext();
    if(element->getNext() == 0){
        tail.setNext(element);
    }
}

void List::append(int item){
    this->moveToEnd();
    ++this->location;
    this->element->createNext(this->element, item);
    element = element->getNext();
    if(element->getNext() == 0){
        tail.setNext(element);
    }
}

//int List::remove(){}

void List::moveToStart(){
    this->location = 0;
    element = &head;
}

void List::moveToEnd(){
    for(int cont = this->location; this->element->getNext() != 0; ++cont){
        this->next();
    }
}

void List::prev(){
    --location;
    this->element = &head;
    for(int cont = 0; cont < location; ++cont){
        this->element = this->element->getNext();
    }
}

void List::next(){
    if((Node*)element->getNext() != 0){
        ++this->location;
        this->element = (Node*)element->getNext();
    }
}

//int List::length() const{}

//int List::currPos() const{}

void List::moveToPos(int pos){
    moveToStart();
    for(int cont = 1; cont < pos; ++cont){
        this->next();
    }
}

//const int List::getValue(){}

QString List::toString(){
    QString print = "";
    this->moveToStart();
    this->next();
    while(element->getNext() != 0){
        print += QString::number(element->getValue()) + " ";
        this->next();
    }
    print += QString::number(element->getValue());
    return print;
}

