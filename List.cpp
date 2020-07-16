#include "List.hpp"
#include <iostream>
using std::cout;

int main() {
  List<int> l{};
  cout << " Created an empty list: " << l << "\n\n";

  cout << " Inserting some elements...\n";
  l.InsertHead(10);
  l.InsertHead(64);
  l.InsertHead(80);
  l.InsertHead(77);  
  cout << " Current list: " << l << "\n\n";

  cout << " Inserting a new element (500) after node with value 64.\n";
  auto pos = l.Find(64);
  l.InsertAfter(pos, 500);
  cout << " Current list: " << l << "\n\n";

  cout << " Removing current head.\n";
  l.RemoveHead();
  cout << " Current list: " << l << "\n\n";

  cout << " Clearing the whole list.\n";
  l.Clear();
  cout << " Current list: " << l << "\n\n";
}

