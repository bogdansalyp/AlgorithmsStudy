#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int current_amount = 0;
  while(n > 0) {
    current_amount++;
    if (n - current_amount < current_amount + 1) {
      summands.push_back(n);
      return summands;
    } else {
      summands.push_back(current_amount);
    }
    n -= current_amount;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
