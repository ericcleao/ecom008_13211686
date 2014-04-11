#ifndef LINKEDLIST_H
#define LISTLINKED_H
#include "node.h"
#include <QDebug>
#include <QString>

template <typename E> class LinkedList// : public List
{
    Node<E> *head;
    Node<E> *tail;
    Node<E> *element;
    int location;
public:
    LinkedList(){
        this->head = new Node<E>;
        this->tail = new Node<E>;
        this->location = 0;
        this->element = new Node<E>;
        this->element = this->head;
    }

    ~LinkedList(){
        delete head;
        delete tail;
        delete element;
    }

    // Clear contents from the list, to make it empty.
    void clear(){
        this->head->setNext(0);
        this->tail->setNext(0);
        this->tail->setValue(0);
        this->location = 0;
        this->element = this->head;

    }
    // Insert an element at the current location.
    // item: The element to be inserted
    void insert(const E& item){
        ++this->location;
        this->tail->sum(1);
        this->element->createNext(this->element, item);
        this->element = this->element->getNext();
        if(this->element->getNext() == 0){
            this->tail->setNext(this->element);
        }
    }
    // Append an element at the end of the list.
    // item: The element to be appended.
   void append(const E& item){
       this->moveToEnd();
       ++this->location;
       this->tail->sum(1);
       this->element->createNext(this->element, item);
       this->element = this->element->getNext();
       if(this->element->getNext() == 0){
           this->tail->setNext(this->element);
       }
   }
    // Remove and return the current element.
    // Return: the element that was removed.
    E remove(){
        Node<E> aux;
        aux = *this->element;
        this->tail->sum(-1);
        if(this->element->getNext() != this->tail->getNext()){
            this->element->setNext(this->element->getNext()->getNext());
            return aux.getNext()->getValue();
        } else{
            this->element->setNext(0);
            return aux.getNext()->getValue();
        }
    }

    // Set the current position to the start of the list
    void moveToStart(){
        this->location = 0;
        this->element = this->head;
    }
    // Set the current position to the end of the list
    void moveToEnd(){
        for(int cont = this->location; this->element->getNext() != 0; ++cont){
            this->next();
        }
    }
    // Move the current position one step left. No change
    // if already at beginning.
    void prev(){
        --this->location;
        this->element = this->head;
        for(int cont = 0; cont < this->location; ++cont){
            this->element = this->element->getNext();
        }
    }
    // Move the current position one step right. No change
    // if already at end.
    void next(){
        if((Node<E>*)this->element->getNext() != 0){
            ++this->location;
            this->element = (Node<E>*)this->element->getNext();
        }
    }
    // Return: The number of elements in the list.
    int length() const{
        return this->tail->getValue();

    }
    // Return: The position of the current element.
    int currPos() const{
        return this->location + 1;
    }
    // Set current position.
    // pos: The position to make current.
    void moveToPos(int pos){
        moveToStart();
        for(int cont = 1; cont < pos; ++cont){
            this->next();
        }
    }
    // Return: The current element.
    const E& getValue() const{
        return this->element->getValue();
    }

    //Sort the list using the Bubble Sort algorithm
    void bubbleSort(){
        int finish = 0;
        int aux;
        moveToStart();
        next();
        for(int i = 1, j = this->tail->getValue() - 1; j > 0; ++i, this->next()){
            if(this->element->getValue() > this->element->getNext()->getValue()){
                aux = this->element->getValue();
                this->element->setValue(this->element->getNext()->getValue());
                this->element->getNext()->setValue(aux);
            } else{
                ++finish;
            }
            if(i == j){
                --j;
                i = 0;
                moveToStart();
            }
        }
    }

    //Sort the list using the Selection Sort algorithm
    void selectionSort(){
        for(int i = 1; i <= this->length(); ++ i){
            moveToPos(i+1);
            int menor = this->element->getValue();
            Node<E> *elementAux = element;
            for(int j = i; j <= this->length(); ++j, this->next()){
                if(this->element->getValue() < menor){
                    int aux = menor;
                    menor = this->element->getValue();
                    this->element->setValue(aux);
                }
            }
            elementAux->setValue(menor);
        }
    }

    //Sort the list using the Insertion Sort algorithm
    void insertionSort(){

    }

    // Return: The current list.
    QString toString(){
        Node<E> *aux = new Node<E>;
        aux = this->element;
        int atual = this->location;
        QString print = "";
        this->moveToStart();
        this->next();
        while(this->element->getNext() != 0){
            print += QString::number(this->element->getValue()) + " ";
            this->next();
        }
        print += QString::number(this->element->getValue());
        this->element = aux;
        this->location = atual;
        return print;
    }
};

#endif // LINKEDLIST_H
