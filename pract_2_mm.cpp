#include <iostream>
#include <vector>
using namespace std;

struct Pair {
    int max;
    int min;
};

Pair getMinMax(const vector<int>& arr, int low, int high) {
    Pair minmax, leftPair, rightPair;
    int mid;

    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    mid = (low + high) / 2;
    leftPair = getMinMax(arr, low, mid);
    rightPair = getMinMax(arr, mid + 1, high);

    if (leftPair.max > rightPair.max)
        minmax.max = leftPair.max;
    else
        minmax.max = rightPair.max;

    if (leftPair.min < rightPair.min)
        minmax.min = leftPair.min;
    else
        minmax.min = rightPair.min;

    return minmax;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Pair result = getMinMax(arr, 0, n - 1);

    cout << "\n--- Results ---" << endl;
    cout << "Maximum element: " << result.max << endl;
    cout << "Minimum element: " << result.min << endl;

    return 0;
}