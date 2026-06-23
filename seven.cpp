#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int n, const vector<int> &primes) {
  for (int p : primes) {
    if (p * p > n)
      break;
    if (n % p == 0)
      return false;
  }
  return true;
}

int main() {
  vector<int> primes = {2};

  int cur = 3;

  while (primes.size() < 10001) {
    if (is_prime(cur, primes)) {
      primes.push_back(cur);
    }
    cur += 2;
  }

  cout << primes.back() << endl;
  return 0;
}
