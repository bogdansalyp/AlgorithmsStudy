#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    if (from == 0) {
        return fibonacci_sum_fast(to);
    }
    long long from_sum = fibonacci_sum_fast(from - 1);
    long long to_sum = fibonacci_sum_fast(to);

    if (to_sum < from_sum) {
        to_sum += 10;
    } 
    long long sum = to_sum - from_sum;

    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
