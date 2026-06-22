#include <algorithm>
#include <iostream>
using namespace std;

unsigned int largest_palindrome() {
  int max_val = 0;
  for (int i = 999; i >= 100; i--) {
    for (int j = 999; j >= 100; j--) {
      int prod = i * j;
      int t = prod;
      int rev = 0;
      while (t > 0) {
        int dig = t % 10;
        rev = rev * 10 + dig;
        t /= 10;
      }
      if (prod == rev) {
        max_val = max(max_val, prod);
      }
    }
  }
  return max_val;
}

int main() {
  cout << largest_palindrome() << endl;
  return 0;
}
