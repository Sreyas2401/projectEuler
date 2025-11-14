#include <iostream>

std::string toString128(unsigned __int128 x) {
    if (x == 0) return "0";
    std::string s;
    while (x > 0) {
        int digit = x % 10;
        s.push_back('0' + digit);
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

int main(){
  const int N = 1000-1;
  unsigned long long M = N/3;
  unsigned long long K = N/5;
  unsigned long long J = N/15;

  unsigned __int128 sum_3 = 3*((__int128)M*(M+1))/2;

  unsigned __int128 sum_5 = 5*((__int128)K*(K+1))/2;

  unsigned __int128 sum_15 = 15*((__int128)J*(J+1))/2;

  unsigned __int128 total = sum_3 + sum_5 - sum_15;  

  std::cout << toString128(total) << std::endl;
  return 0;
}
