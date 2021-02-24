#include <bits/stdc++.h>
using namespace std;

// T.C => O(log n)
// S.C => O(log n)
void heapify(int* arr, int node, int n) {
    // in order to heapify the ith node
    // we have to check both right and left
    // nodes that they should follow the heap property
    int parent = node;
    int left = 2*node+1;
    int right = 2*node+2;
    int largest = node;
    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != node) {
        swap(arr[node], arr[largest]);
        heapify(arr, largest, n);
    }
}

// T.C => O(n)
// S.C => O(log n)
void buildHeap(int* arr, int n) {
    // take array and length of array
    // and build heap from it
    // we already know that range of internal nodes
    // and leaves nodes so, only need to heapify the internal
    // nodes bcoz leaves nodes always follow the heap property
    int start = n/2 - 1;
    // range of internal nodes
    // 0 to ceil(arr.length)/2 - 1
    for (int i = start; i>=0; i--) {
        heapify(arr, i, n);
    }
}

void printHeap(int* arr, int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int extractMax(int* arr, int n) {
    // extract maximum element form array
    // max value will be at root or 0th index
    // bcoz of heap property
    int maxValue = arr[0];
    arr[0] = arr[n-1];
    n = n-1;
    heapify(arr, 0, n);
    return maxValue;
}

int main() {
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, n);
    printHeap(arr, n);
    cout << endl;
    cout << extractMax(arr, n) << endl;
    printHeap(arr, n);
	return 0;
}
