#include <iostream> 
#include <cmath>
#include <iomanip>
using namespace std;

long double phi = (1 + std::sqrt(5))/2.0L;
long double psi = (1 - std::sqrt(5))/2.0L;

long double fib_closed(long double n){
  long double a = pow(phi, n);
  long double b = pow(psi, n);
  return (a-b)/sqrt(5.0L);
}

long double inverse_fib(long double fn){
  long double A = fn * sqrt(5.0L);
  long double B = sqrt(5.0L * fn * fn - 4.0L);
  long double x = (A+B)/2.0L;
  return log(x)/log(phi);
}

int main(){
  long double upper = 4000000;
  long double n_est = inverse_fib(upper);
  long double k = floor(n_est/3.0L);
  long double A = (1-pow(pow(phi, 3), k))/(1-pow(phi, 3));
  long double B = (1-pow(pow(psi, 3), k))/(1-pow(psi, 3));
  long double sum = 1/sqrt(5)*(pow(phi, 3)*A - pow(psi, 3)*B);
  cout << sum << endl;
  return 0;
}
