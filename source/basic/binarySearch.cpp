#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearch(arr, target, mid + 1, end);
    else return binarySearch(arr, target, start, mid - 1);
}

int main() {
    vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    int target = 7;
    int start = 0;
    int end = arr.size() - 1;

    cout << binarySearch(arr, target, start, end) << endl;

    return 0;
}
