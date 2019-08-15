#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

vector<int> bubble_sort(vector<int> arr) {
  for(int i = 0; i < arr.size() - 1; i++) {
    for(int j = i; j < arr.size(); j++) {
      if(arr[i] < arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  return arr;
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  a = bubble_sort(a);
  b = bubble_sort(b);
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
