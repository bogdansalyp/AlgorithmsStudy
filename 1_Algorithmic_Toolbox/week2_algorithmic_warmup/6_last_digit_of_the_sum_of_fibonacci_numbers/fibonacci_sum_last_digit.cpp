#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    long long numbers_to_count = n % 60;
    if (numbers_to_count == 0) {
        return 0;
    }
    std::vector<int> arr(numbers_to_count + 1, 0);
    arr[0] = 0;
    arr[1] = 1;
    long long sum = 1;
    for (long long i = 2; i <= numbers_to_count; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
        sum = (sum + arr[i]) % 10;
    }
    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
