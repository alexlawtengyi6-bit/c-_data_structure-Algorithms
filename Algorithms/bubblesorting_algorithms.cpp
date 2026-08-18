#include <iostream>
#include <vector>
#include <algorithm> // For std::swap (more efficient)

void bubbleSort(std::vector<double>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in inner loop, the array is sorted
        if (swapped == false)
            break;
    }
}

int main() {
    std::vector<double> topUps = {5.5, 2.1, 8.9, 1.3, 9.7};

    std::cout << "Before sorting: ";
    for (double val : topUps) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    bubbleSort(topUps);

    std::cout << "After sorting: ";
    for (double val : topUps) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}