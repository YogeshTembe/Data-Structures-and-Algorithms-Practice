// calc.cpp
#include <iostream>
using namespace std;
#include "calc.h"

int add(int op1, int op2) {
    return op1 + op2;
}

int sub(int op1, int op2) {
    return op1 - op2;
}

template <typename E> Queue<E>::Queue(){
    cout<<"Queue constr"<<endl;
}

template <typename E> void Queue<E>::Enqueue(E element){
    this->q.push(element);
}

template <typename E> E Queue<E>::Dequeue(){
    int val = this->q.front();
    this->q.pop();
    return val;
}

template <typename E> int Queue<E>::size() const{
    return this->q.size();
}

template class Queue<int>;//explicit instantiation is necessary here otherwise we get linker errors