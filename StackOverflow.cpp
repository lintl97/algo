//=============================================================================
// Simulate a Stack Overflow and show how to properly handle it via exceptions
//=============================================================================

#include "Stack.hpp" // Stack implementation safely guarded against overflow
#include <iostream>
using std::cout;

int main() {

  // Guard stack push against overflow
  try {
    Stack<int> stack{5};
    cout << " Created stack of max size: " << stack.MaxSize() << '\n';

    // Keep pushing until the stack overflows...
    while (true) {
      cout << " Trying: stack.Push(64); ...";
      stack.Push(64);
      cout << "OK.\n";
    }
  } catch (const StackOverflowException& e) {
    cout << "\n *** Stack Overflow detected ***\n\n";    
  }
}

