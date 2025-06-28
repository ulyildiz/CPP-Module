#include <iostream>
#include <vector>
#include <algorithm>

// Recursive helper for inserting elements in optimal order
void insertRecursively(std::vector<int>& sorted, const std::vector<int>& insertList, int start, int end) {
    if (start > end) return;

    int mid = (start + end) / 2;
    int val = insertList[mid];

    // Binary insert
    auto it = std::lower_bound(sorted.begin(), sorted.end(), val);
    sorted.insert(it, val);

    // Recurse left and right
    insertRecursively(sorted, insertList, start, mid - 1);
    insertRecursively(sorted, insertList, mid + 1, end);
}

std::vector<int> mergeInsertionSort(const std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return arr;

    std::vector<int> largerHalf;
    std::vector<int> smallerHalf;

    // Step 1: Pairing and comparing
    for (int i = 0; i + 1 < n; i += 2) {
        if (arr[i] < arr[i + 1]) {
            smallerHalf.push_back(arr[i]);
            largerHalf.push_back(arr[i + 1]);
        } else {
            smallerHalf.push_back(arr[i + 1]);
            largerHalf.push_back(arr[i]);
        }
    }

    // Handle odd count
    if (n % 2 != 0) {
        smallerHalf.push_back(arr[n - 1]);
    }

    // Step 2: Recursively sort larger elements
    std::vector<int> sorted = mergeInsertionSort(largerHalf);

    // Step 3: Recursively insert smaller elements
    insertRecursively(sorted, smallerHalf, 0, smallerHalf.size() - 1);

    return sorted;
}

int main() {
    std::vector<int> data = {7, 10, 2, 9, 4, 1, 18, 5, 3, 6, 8};
    std::vector<int> sorted = mergeInsertionSort(data);

    std::cout << "Sorted: ";
    for (int x : sorted)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
