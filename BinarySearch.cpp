#include <iostream>
#include <vector>
using namespace std;

constexpr int kNotFound = -1;

int BinarySearch(int element, const int* v, int size) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int middle = (left + right) / 2;
    
    if (v[middle] == element) {
      // Element found
      return middle;

    } else if (v[middle] < element) {
      // Search in the right-half: (middle+1..right)
      left = middle + 1;      

    } else if (v[middle] > element) {
      // Search in the left-half: (left..middle-1)
      right = middle - 1;
    } 
  }

  return kNotFound; // Element not found
}


void Print(const vector<int>& v) {
  cout << "[ ";
  for (int x : v) {
    cout << x << ' ';
  }
  cout << "]\n";
}

int main() {
  vector<int> v{11, 22, 33, 44, 55};
  Print(v);

  cout << "Element to search? ";
  int x;
  cin >> x;
  
  int pos = BinarySearch(x, v.data(), v.size());
  if (pos == kNotFound) {
    cout << " Element not found.\n";
  } else {
    cout << " Element found at index " << pos << ".\n";
  }
}

