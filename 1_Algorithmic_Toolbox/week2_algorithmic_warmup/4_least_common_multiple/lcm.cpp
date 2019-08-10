#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
  if (a < b) {
    int temp = a;
    a = b;
    b = temp;
  }
  int remainder = a % b;
  if (remainder == 0) {
    return b;
  } else {
    return gcd_fast(b, remainder);
  }
}

long long lcm_fast(int a, int b) {
  if ((a == 0) || (b == 0)) {
    return 0;
  }
  int gcd = gcd_fast(a, b);
  int a_prime = a / gcd;
  int b_prime = b / gcd;
  return (long long) gcd * a_prime * b_prime;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
