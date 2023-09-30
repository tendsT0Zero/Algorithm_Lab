#include<bits/stdc++.h>
using namespace std;


void swapWithoutThirdVariable(int &a, int &b) {
    a = a + b;
    b = a - (2 * b);
    a = (a - b) / 2;
}

// Function to partition the array into two sub-arrays.
// Elements smaller than the pivot will be on the left,
// and elements greater than the pivot will be on the right.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) { // increasing / decreasing matter here
            i++; // Increment index of the smaller element
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

  //swapWithoutThirdVariable(arr[i+1],arr[high]);
    return (i + 1);
}

// Function to perform quick sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}