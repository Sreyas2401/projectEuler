#include <iostream>
using namespace std;

unsigned long long largest_prime_factor(unsigned long long n) {
  unsigned long long largest = 0;

  while (n % 2 == 0) {
    largest = 2;
    n /= 2;
  }

  for (unsigned long long i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      largest = i;
      n /= i;
    }
  }

  if (n > 2)
    largest = n;

  return largest;
}

int main() {
  unsigned long long num = 600851475143ULL;
  cout << largest_prime_factor(num) << endl;
}
