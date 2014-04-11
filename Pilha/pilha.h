#ifndef PILHA_H
#define PILHA_H
#include <stack.h>
#include <stdlib.h>
#include <QDebug>

template <typename E>
class Pilha
{
    E *stack;
    int top;
public:
    Pilha(){
        this->stack = (E*)calloc(10,sizeof(E));
        this->top = -1;
    }
    virtual ~Pilha(){
        delete stack;
    }              // Base destructor

    // Reinitialize the stack.  The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void clear(){
        free(stack);
        this->stack = (E*)calloc(10,sizeof(E));
        this->top = -1;

    }

    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(const E& it){
        ++top;
        if((top+1)%10 == 0){
            this->stack = (E*)realloc(stack, (top+10) * sizeof(E));
        }
        this->stack[top] = it;
    }

    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual E pop(){
        if(top != -1){
            --top;
        } else{
            return 0;
        }
        return stack[top+1];

    }

    // Return: A copy of the top element.
    virtual const E& topValue() const{
        if(top != -1){
            return stack[top];
        } else{
        }

    }

    // Return: The number of elements in the stack.
    virtual int length() const{
        return top + 1;
    }
};

#endif // PILHA_H
