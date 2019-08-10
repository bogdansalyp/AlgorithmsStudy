#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProductHard(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * (long long)numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int index_1;
    int index_2;
    if (numbers[0] > numbers[1]) {
        index_1 = 0;
        index_2 = 1;
    } else {
        index_2 = 0;
        index_1 = 1;
    }

    for (int i = 2; i < n; i++) {
        if (numbers[i] > numbers[index_1]) {
            index_2 = index_1;
            index_1 = i;
        } else if (numbers[i] > numbers[index_2]) {
            index_2 = i;
        }
    }

    max_product = (long long)numbers[index_1] * (long long)numbers[index_2];

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // while (true) {
    //     long long result_1;
    //     long long result_2;

    //     int n = rand() % 10 + 2;
    //     std::vector<int> a;
    //     for (int i = 0; i < n; i++) {
    //         a.push_back(rand() % 10000);
    //     }

    //     for (int i = 0; i < n; i++) {
    //         std::cout << a[i] << " ";
    //     }
    //     std::cout << "\n";

    //     result_1 = MaxPairwiseProductHard(a);
    //     result_2 = MaxPairwiseProduct(a);

    //     if (result_1 != result_2) {
    //         std::cout << "Wrong answer: " << result_1 << " " << result_2 << "\n";
    //         return 0;
    //     }
        
    //     std::cout << "OK\n";
    // }
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
