#include <iostream>
#include <vector>
#include <algorithm>

void mergeSort(std::vector<double>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    int mid = arr.size() / 2;
    std::vector<double> left(arr.begin(), arr.begin() + mid);
    std::vector<double> right(arr.begin() + mid, arr.end());

    mergeSort(left);
    mergeSort(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size()) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size()) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void quickSort(std::vector<double>& arr, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int partition(std::vector<double>& arr, int low, int high) {
    double pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}