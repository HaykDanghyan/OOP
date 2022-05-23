#ifndef STACK_H
#define STACK_H
#include <iostream>
class myStack
{
    private:
    int* array = nullptr;
    int begin = -1;
    const int maxCapacity = 10;
    public:
    myStack();
    ~myStack();
    void pop();
    void push(int);
    int top();
    bool isEmpty();
    void clear();
    void printStack();
    const int size();

};
#endif