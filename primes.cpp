#include <cstddef>
#include <cmath>
#include <stdexcept>
#include <vector>

bool is_prime(int n, const std::vector<int> &primes) {
  if (n < 2) {
    return false;
  }

  for (int p : primes) {
    if (p > n / p) {
      break;
    }
    if (n % p == 0) {
      return false;
    }
  }

  return true;
}

std::vector<int> primes_up_to(int limit) {
  if (limit < 2) {
    return {};
  }

  std::vector<bool> is_prime_number(limit + 1, true);
  is_prime_number[0] = false;
  is_prime_number[1] = false;

  for (int p = 2; p <= limit / p; ++p) {
    if (!is_prime_number[p]) {
      continue;
    }

    for (int multiple = p * p; multiple <= limit; multiple += p) {
      is_prime_number[multiple] = false;
    }
  }

  std::vector<int> primes;
  for (int n = 2; n <= limit; ++n) {
    if (is_prime_number[n]) {
      primes.push_back(n);
    }
  }

  return primes;
}

int nth_prime(std::size_t n) {
  if (n == 0) {
    throw std::invalid_argument("n must be at least 1");
  }

  if (n <= 5) {
    constexpr int first_primes[] = {2, 3, 5, 7, 11};
    return first_primes[n - 1];
  }

  const double value = static_cast<double>(n);
  int limit =
      static_cast<int>(value * (std::log(value) + std::log(std::log(value)))) +
      1;

  while (true) {
    const std::vector<int> primes = primes_up_to(limit);
    if (primes.size() >= n) {
      return primes[n - 1];
    }
    limit *= 2;
  }
}

long long sum_primes_below(int limit) {
  long long sum = 0;

  for (int prime : primes_up_to(limit - 1)) {
    sum += prime;
  }

  return sum;
}
