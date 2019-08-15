#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  for(int i = 0; i < values.size(); i++) {
    if (capacity == 0) {
      return value;
    }

    // Select a most valuable one
    int max_index = 0;
    for(int j = 0; j < values.size(); j++) {
      if (weights[j] > 0) {
        if (((float)values[j] / (float)weights[j]) > ((float)values[max_index] / (float)weights[max_index])) {
          max_index = j;
        }
      }
    }

    // Determine weight
    int a = (capacity > weights[max_index]) ? weights[max_index] : capacity;
    capacity -= a;
    value += a * (float)values[max_index] / (float)weights[max_index];
    weights[max_index] -= a;
    
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
