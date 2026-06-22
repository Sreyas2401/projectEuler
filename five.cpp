#include <iostream>
using namespace std;

// Euclidean Algorithm for GCD(a, b)
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  while (b != 0) {
    unsigned long long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

unsigned long long find_smallest_multiple(int n) {
  unsigned long long running_lcm = 1;
  for (int i = 2; i <= n; i++) {
    running_lcm = (running_lcm * i) / gcd(running_lcm, i);
  }
  return running_lcm;
}

int main() {
  cout << find_smallest_multiple(20) << endl;
  return 0;
}
