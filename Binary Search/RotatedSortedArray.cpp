#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;  // Found the target
            }

            // Check if left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;  // Search in left half
                } else {
                    low = mid + 1;  // Search in right half
                }
            }
            // Otherwise, right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Search in right half
                } else {
                    high = mid - 1;  // Search in left half
                }
            }
        }

        return -1;  // Target not found
    }
};
