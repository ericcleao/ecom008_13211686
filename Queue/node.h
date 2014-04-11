#ifndef NODE_H
#define NODE_H

template <typename E> class Node
{
    E value;
    Node *next;
public:
    Node(){
        this->value = 0;
        this->next = 0;
    }
    Node(Node *node, E value)
    {
        this->value = value;
        this->next = node->getNext();
    }
    void createNext(Node *node, E value){
        Node *next = new Node<E>(node, value);
        this->setNext(next);
    }
    Node *getNext(){
        return this->next;
    }
    void setNext(Node *next){
        this->next = next;
    }
    const E& getValue(){
        return this->value;
    }
    void setValue(E value){
        this->value = value;
    }

    void sum(int value){
        this->value += value;
    }
};

#endif // NODE_H
