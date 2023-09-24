
#ifndef BINARY_TREE_QUEUE_H
#define BINARY_TREE_QUEUE_H
#include <iostream>
class Node
{
public:
    Node *lchild;
    Node *rchild;
    int data;
};
class Queue {
private:
    int front;
    int rear;
    int size;
    Node **A;
public:
    Queue(int size) {
        this->size = size;
        front = rear = 0;
        A = new Node *[size];
    }

    void enqueue(Node *x) {
        if ((rear+1)%size == front ) {
            std::cout << "Queue is full\n";
        } else {
            rear = (rear + 1) % size;
            A[rear] = x;
        }
    }

    Node *dequeue() {
        Node *x = NULL;
        if (rear == front) std::cout << "Queue is empty\n";
        else {
            front = (front + 1) % size;
            x = A[front];
        }
        return x;
    }

    bool isEmpty(){return rear == front;}
};


#endif //BINARY_TREE_QUEUE_H
