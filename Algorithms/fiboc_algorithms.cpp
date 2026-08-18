#include <iostream>
#include <vector>

// Recursive Fibonacci function
long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int numTerms = 10; // Number of Fibonacci numbers to generate
    std::vector<long long> fibSequence;

    for (int i = 0; i < numTerms; ++i) {
        fibSequence.push_back(fibonacci(i));
    }

    std::cout << "Fibonacci Sequence: ";
    for (long long num : fibSequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}