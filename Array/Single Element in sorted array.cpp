#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();

        if (n == 1) return A[0];

        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

           
            if (mid == 0 && A[0] != A[1]) return A[mid];
            if (mid == n - 1 && A[n - 1] != A[n - 2]) return A[mid];

      
            if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1]) return A[mid];

     
            if (mid % 2 == 0) {
                if (A[mid] == A[mid + 1]) {
                    st = mid + 2;
                } else {
                    end = mid - 1;
                }
            } else {
                if (A[mid] == A[mid - 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1; 
    }
};

int main() {
    int n;
    cout << "Enter the number of elements (odd number, since only one is unique): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Invalid input. Number of elements must be odd.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements (pairs + one unique): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.singleNonDuplicate(arr);

    if (result != -1) {
        cout << "The single non-duplicate element is: " << result << endl;
    } else {
        cout << "No unique element found or input is invalid." << endl;
    }

    return 0;
}
