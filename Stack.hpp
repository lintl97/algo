#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <ostream>
#include "Array.hpp"

template <typename T>
class Stack {

 private:
  Array<T> m_array; // Stack elements are stored in this array
  int      m_top;   // Index of the top element (-1 for empty stack)

 public:

  explicit Stack(int maxStackSize)
    : m_array{maxStackSize}
    , m_top{-1}             // Empty stack
  {}

  void Push(const T& element) {
    // Push element on top of the stack
    m_top++;
    m_array[m_top] = element;
  }

  T Pop() {
    T topElement = m_array[m_top];
    m_top--;
    return topElement;
  }

  const T& Top() const {
    return m_array[m_top];  
  }

  int Size() const {
    return (m_top + 1);
  }

  bool IsEmpty() const {
    return Size() == 0;
  }

  int MaxSize() const {
    return m_array.Size();
  }

  void Clear() {
    m_top = -1;
  }


  // Dump stack content to output stream
  friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
    if (stack.IsEmpty()) {
      os << "  [*** Empty Stack ***]\n\n";
      return os;
    }

    os << "  [Stack]\n";
    // Print stack content from top to bottom
    for (int i = stack.m_top; i >= 0; i--) {
      os << "    " << stack.m_array[i] << '\n';
    }
    os << '\n';

    return os;
  }
};

#endif // STACK_HPP_INCLUDED

