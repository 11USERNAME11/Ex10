// Copyright 2020 Mikhail Bogomazov
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <climits>
#include <iostream>
template<class Typ>
class MyStack {
 private:
    int amountOfElements = 0;
    int stackSize;
    Typ* stackArray;

 public:
    MyStack() {
        stackSize = 999999;
        stackArray = new Typ[stackSize];
    }
    explicit MyStack(int size) {
        stackSize = size;
        stackArray = new Typ[stackSize];
    }
    MyStack(const MyStack &stack):
        amountOfElements(stack.amountOfElements),
        stackSize(stack.stackSize), stackArray(stack.stackArray) {}

    ~MyStack() {
        delete[] stackArray;
        stackSize = 0;
    }
    void push(Typ el) {
        stackArray[amountOfElements++] = el;
    }
    Typ pop() {
        return stackArray[amountOfElements--];
        }
    Typ get() const {
        return stackArray[amountOfElements-1];
    }
    bool isFull() const {
        return amountOfElements == stackSize;
    }
    bool isEmpty() const {
        return amountOfElements == 0;
    }
};

#endif  // INCLUDE_MYSTACK_H_
