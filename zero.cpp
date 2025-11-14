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
  long long total_cnt = 507000LL;

  unsigned long long odd_cnt = (total_cnt)/2;

  unsigned __int128 m = odd_cnt;

  unsigned __int128 sum_k = m * (m+1)/2;

  unsigned __int128 sum_k2 = m * (m+1) * (2*m+1)/6;

  unsigned __int128 total_sum = 4*sum_k2 - 4*sum_k + m;

  std::cout << toString128(total_sum) << std::endl;
  return 0;
}



