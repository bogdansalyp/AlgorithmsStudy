#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (long long i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long fibonacci_fast(long long n) {
    std::vector<long long> arr;
    arr.reserve(n + 1);

    arr[0] = 0;
    arr[1] = 1;
    for (long long i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long new_n = n % get_pisano_period(m);
    std::vector<long long> arr;
    arr.reserve(new_n + 1);

    arr[0] = 0;
    arr[1] = 1;
    for (long long i = 2; i <= new_n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] % m;
    }

    long long result = arr[new_n] % m;
    return result;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
