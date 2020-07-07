#include "Stack1.hpp"
#include <cassert>
#include <iostream>
using std::cout;

int main() {
  Stack<int> stack{10};
  assert(stack.IsEmpty());
  assert(stack.MaxSize() == 10);

  cout << " Stack created:\n";
  cout << stack;

  cout << " Pushing some elements:\n";
  cout << " stack.Push(10)\n";
  cout << " stack.Push(20)\n";
  cout << " stack.Push(64)\n";
  stack.Push(10);
  stack.Push(20);
  stack.Push(64);
  assert(stack.Size() == 3);
  cout << stack;

  cout << " stack.Pop(): " << stack.Pop() << '\n';
  cout << " stack.Pop(): " << stack.Pop() << '\n';
  assert(stack.Size() == 1);
  assert(!stack.IsEmpty());

  cout << " stack.Top(): " << stack.Top() << '\n';
  assert(stack.Size() == 1);

  cout << " Current stack:\n";
  cout << stack;
}

