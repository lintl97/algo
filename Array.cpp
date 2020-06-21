// Array9.cpp -- Fixes subtle copy bug adding proper copy constructor

#include <cassert>
#include <ostream>
#include <iostream>

class IndexOutOfBoundsException{};

class IntArray {
 private:
  int* m_ptr{nullptr};
  int  m_size{0};

  bool IsValidIndex(int index) const {
    return (index >= 0) && (index < m_size);
  }

 public:
  IntArray() = default;

  explicit IntArray(int size) {
    assert(size >= 0);
    if (size != 0) {
      m_ptr = new int[size]{};
      m_size = size;
    }
  }

  IntArray(const IntArray& source) {
    if (! source.IsEmpty()) {
      m_size = source.m_size;

      m_ptr = new int[m_size]{};
    
      for (int i = 0; i < m_size; i++) {
        m_ptr[i] = source.m_ptr[i];
      }
    }
  }

  ~IntArray() {
    delete[] m_ptr;
  }

  int Size() const {
    return m_size;
  }

  bool IsEmpty() const {
    return (m_size == 0);
  }

  int& operator[](int index) {
    if (!IsValidIndex(index)) {
      throw IndexOutOfBoundsException{};
    }

    return m_ptr[index];
  }

  int operator[](int index) const {
    if (!IsValidIndex(index)) {
      throw IndexOutOfBoundsException{};
    }

    return m_ptr[index];
  }
};

std::ostream& operator<<(std::ostream& os, const IntArray& a) {
  os << "[ ";
  for (int i = 0; i < a.Size(); i++) {
    os << a[i] << ' ';
  }
  os << ']';

  return os;
}

int main() {
  using std::cout;

  IntArray a{3};
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;

  IntArray b = a;
    
  cout << " a = " << a << '\n';
  cout << " b = " << b << '\n';

  b[1] = 100;
  cout << "\n b[1] = 100; \n\n";

  cout << " a = " << a << '\n';
  cout << " b = " << b << '\n';
}


