#include <iostream>
#include <vector>
using namespace std;

constexpr int kNotFound = -1;

int Search(int element, const int* v, int size) {
  // For each item in the input array,
  // compare it with the search element
  for (int i = 0; i < size; i++) {
    if (v[i] == element) {
      // Element found!
      // Return its position to the caller
      return i;
    }
  }

  // Element not found
  return kNotFound;
}

void Print(const vector<int>& v) {
  cout << "[ ";
  for (int x : v) {
    cout << x << ' ';
  }
  cout << "]\n";
}

int main() {
  vector<int> v{33, 44, 55, 11, 22};
  Print(v);

  cout << "Element to search? ";
  int x;
  cin >> x;

  cout << '\n';

  int pos = Search(x, v.data(), v.size());
  if (pos == kNotFound) {
    cout << "Element not found.\n";
  } else {
    cout << "Element found at index " << pos << ".\n";
  }
} 

