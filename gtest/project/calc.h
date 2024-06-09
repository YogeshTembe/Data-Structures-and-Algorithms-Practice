// calc.hpp
#ifndef CALC_HPP_
#define CALC_HPP_
#include <queue>
using namespace std;

int add(int op1, int op2);
int sub(int op1, int op2);

template <typename E>  // E is the element type.
class Queue {
 public:
    queue<E>q;
  Queue();
  void Enqueue(E element);
  E Dequeue();  // Returns NULL if the queue is empty.
  int size() const;
};

#endif // CALC_HPP_