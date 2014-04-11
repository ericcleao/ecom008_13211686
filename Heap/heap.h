#ifndef HEAP_H
#define HEAP_H
#include <stdlib.h>

template <typename E>
class Heap
{
    E* Heap; // Pointer to the heap array
    int maxsize; // Maximum size of the heap
    int n; // Number of elements now in the heap
public:
    // Constructor
    heap(E* h = 0, int num = 0, int max = 0){
        this->maxsize = max;
        Heap = (E*)calloc(this->maxsize, sizeof(E));
        this->n = num;
        for(int cont = 0; cont < n; ++cont){
            Heap[cont] = h[cont];
        }

    }

    // Return current heap size
    int size() const{
        return n;
    }

    // True if pos is a leaf
    bool isLeaf(int pos) const = 0;

    // Return leftchild position
    int leftchild(int pos) const{
        return 2*pos;
    }

    // Return rightchild position
    int rightchild(int pos) const{
        return 2*pos + 1;
    }

    // Return parent position
    int parent(int pos) const{
        return pos/2;
    }

    // Heapify contents of Heap
    void buildHeap(){
        int siftdown = n/2;
    }

    // Insert "it" into the heap
    void insert(const E& it) = 0;
};

#endif // HEAP_H
