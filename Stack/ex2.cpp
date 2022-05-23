// Define a struct called MyStack which will provide you with the functionality of stack (LIFO).
// The MyStack object will accept only int numbers and it 
// will be limited in size 0-10 (can hold maximum 10 integers)
// Struct must have user defined special member functions
// Also you should provide the following functionality:
// Implement pop() member function that will give you the last inserted integer
// value and will remove it, if there is no such print message “There is no value in stack” and terminate the program. 
// Implement push(int) member function that will insert int value, if the limit is reached print “There is no space left” and terminate program.
// Implement size() member function that will give you correct size in real time (how many elements object holds)
// Implement clear() member function that will clear content. After this call there will be no elements left in struct

#include <iostream>
#include "stack.h"
int main()
{
    myStack obj;
    obj.push(5);
    obj.push(15);
    if(!obj.isEmpty())
    {obj.printStack();}
    obj.pop();
    obj.printStack();
    std::cout << obj.size() << std::endl;
}
myStack::myStack()
{
    array = new int[maxCapacity];
}
myStack::~myStack()
{
    delete[] array;
    array = nullptr;
}
void myStack::push(int value)
{
    if(begin != maxCapacity)
    {
        begin++;
        array[begin] = value;
    }
    else
    {
        std::cerr << "Stack is FULL !" << std::endl;
        exit(0);
    }
}

void myStack::pop()
{
    if(begin != -1)
    {
        begin--;
    }
    else
    {
        std::cerr << "Stack is EMPTY !" << std::endl;
        exit(0);
    }
}
int myStack::top()
{
    if(!isEmpty())
    {
        array[begin];
    }
    else
    {
        std::cerr << "Error !" << std::endl;
        exit(0);
    }

}
bool myStack::isEmpty()
{
    return (begin == -1);
}
const int myStack::size()
{
    return begin + 1;
}
void myStack::clear()
{
    if(begin <= 0)
    {return;}
    else
    {
        do
        {
            pop();
        } while (begin < -1);
        
    }
}
void myStack::printStack()
{
    if(begin == -1)
    {
        std::cout << "Nothing to print :) !";
    }
    else
    {
        std::cout << "\nYour stack is :";
        for(int i = 0; i <= begin; i++)
        {
            std::cout << "\t" << array[i];            
        }
        std::cout << std::endl;
    }
}
