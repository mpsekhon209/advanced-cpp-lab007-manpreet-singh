#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

namespace {
int factorialRecursive(int n) {
    // Base case: factorial(0) and factorial(1) are both 1.
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case: multiply the current value by the factorial of n - 1.
    return n * factorialRecursive(n - 1);
}

int fibonacciRecursive(int n) {
    // Base case: fib(0) = 0 and fib(1) = 1.
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Recursive case: sum of the previous two Fibonacci numbers.
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int binarySearchRecursive(const std::vector<int>& array, int left, int right, int target) {
    // Base case: the search interval is empty, so the target is not found.
    if (left > right) {
        return -1;
    }

    const int mid = left + (right - left) / 2;
    if (array[mid] == target) {
        return mid;
    }

    // Recursive case: narrow the search to the correct half of the array.
    if (array[mid] > target) {
        return binarySearchRecursive(array, left, mid - 1, target);
    }
    return binarySearchRecursive(array, mid + 1, right, target);
}

int arraySumRecursive(const std::vector<int>& array, std::size_t index) {
    // Base case: when the index reaches the end, the remaining sum is 0.
    if (index >= array.size()) {
        return 0;
    }

    // Recursive case: add the current element to the sum of the rest of the array.
    return static_cast<int>(array[index]) + arraySumRecursive(array, index + 1);
}

void reverseArrayRecursive(std::vector<int>& array, std::size_t left, std::size_t right) {
    // Base case: an empty or single-element array is already reversed.
    if (left >= right) {
        return;
    }

    // Recursive case: swap the ends and continue with the inner portion.
    std::swap(array[left], array[right]);
    reverseArrayRecursive(array, left + 1, right - 1);
}
}  // namespace

// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    if (n < 0) {
        throw std::logic_error("factorial input must be non-negative");
    }
    return factorialRecursive(n);
}

int factorialIterative(int n) {
    if (n < 0) {
        throw std::logic_error("factorial input must be non-negative");
    }

    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    if (n < 0) {
        throw std::logic_error("fibonacci input must be non-negative");
    }
    return fibonacciRecursive(n);
}

int fibonacciIterative(int n) {
    if (n < 0) {
        throw std::logic_error("fibonacci input must be non-negative");
    }

    if (n == 0) {
        return 0;
    }

    int previous = 0;
    int current = 1;
    for (int i = 2; i <= n; ++i) {
        const int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

// Base case: target not found or left > right.
// Recursive case: compare the middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
    if (array.empty()) {
        return -1;
    }

    return binarySearchRecursive(array, 0, static_cast<int>(array.size()) - 1, target);
}

int binarySearchIterative(const std::vector<int>& array, int target) {
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    return arraySumRecursive(array, 0);
}

int arraySumIterative(const std::vector<int>& array) {
    int total = 0;
    for (const int value : array) {
        total += value;
    }
    return total;
}

// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
    if (array.empty()) {
        return;
    }
    reverseArrayRecursive(array, 0, array.size() - 1);
}

void reverseArrayIterative(std::vector<int>& array) {
    std::size_t left = 0;
    std::size_t right = array.size();

    if (right == 0) {
        return;
    }

    --right;
    while (left < right) {
        std::swap(array[left], array[right]);
        ++left;
        --right;
    }
}
