#include <iostream>
using namespace std;

int main() {
  int input = 100;

  auto formula = [](int n) { return n * (n + 1) * (3 * n + 2) * (n - 1) / 12; };

  cout << formula(input) << endl;

  return 0;
}
