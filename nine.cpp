#include <iostream>
using namespace std;

int main() {
  int ret = 0;
  for (int b = 2; b < 500; b++) {
    int num = 1000 * (500 - b);
    int denom = 1000 - b;

    if (num % denom == 0) {
      int a = num / denom;
      int c = 1000 - a - b;
      if (a * a + b * b == c * c) {
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        ret = a * b * c;
        break;
      }
    }
  }
  cout << ret << endl;
  return 0;
}
