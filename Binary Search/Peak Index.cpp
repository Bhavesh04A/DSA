#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int st = 1, end = A.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
                return mid; 
            }
            else if (A[mid - 1] < A[mid]) {
                st = mid + 1; 
            }
            else {
                end = mid - 1; 
            }
        }
        return -1; 
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the mountain array: ";
    cin >> n;

    if (n < 3) {
        cout << "A mountain array must have at least 3 elements.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements (in mountain shape): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    int peakIndex = sol.peakIndexInMountainArray(arr);

    if (peakIndex != -1) {
        cout << "Peak index: " << peakIndex << endl;
        cout << "Peak element: " << arr[peakIndex] << endl;
    } else {
        cout << "Invalid mountain array." << endl;
    }

    return 0;
}
