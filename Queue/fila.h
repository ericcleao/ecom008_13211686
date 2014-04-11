#ifndef FILA_H
#define FILA_H
#include "LinkedList.h"

template<typename E> class Fila// : public Queue
{
public:
    LinkedList<E> *fila;
    Fila() {
        this->fila = new LinkedList<E>;
    }
    ~Fila(){
        delete fila;
    } // Base destructor

    // Reinitialize the queue.  The user is responsible for
    // reclaiming the storage used by the queue elements.
//    virtual void clear() = 0;

    // Place an element at the rear of the queue.
    // it: The element being enqueued.
    void enqueue(const E& item){
        fila->append(item);
    }

    // Remove and return element at the front of the queue.
    // Return: The element at the front of the queue.
    E dequeue(){
        fila->moveToStart();
        return fila->remove();
    }

    // Return: A copy of the front element.
    const E& frontValue() const{
        this->fila->moveToStart();
        return fila->getValue();
    }

    // Return: The number of elements in the queue.
    int length() const{
        return fila->length();
    }
};

#endif // FILA_H
