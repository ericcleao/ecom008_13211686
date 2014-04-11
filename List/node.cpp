#include "node.h"

Node::Node()
{
    this->value = 0;
    this->next = 0;
}

Node::Node(Node *node, T value)
{
    this->value = value;
    this->next = node->getNext();
}

void Node::createNext(Node *node, T value){
    Node *next = new Node(node, value);
    this->setNext(next);
}

Node *Node::getNext(){
    return this->next;
}

void Node::setNext(Node *next){
    this->next = next;
}

T Node::getValue(){
    return this->value;
}

void Node::setValue(int value){
    this->value = value;
}
