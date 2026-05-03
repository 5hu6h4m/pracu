#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> data(n);
    cout << "Enter " << n << " integers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    cout << "\nSorted array: ";
    for (int num : data) cout << num << " ";
    cout << "\n\nEnter the element to search for: ";
    cin >> target;
    int result = binarySearch(data, target);
    if (result != -1) {
        cout << "Element found at index " << result << " (in the sorted array)." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}