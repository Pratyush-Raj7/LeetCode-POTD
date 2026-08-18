class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;

        for (int x : nums) {
            int count = 0;

            for (int i = 0; i <= nums.size() - k; i++) {
                for (int j = i; j < i + k; j++) {
                    if (nums[j] == x) {
                        count++;
                        break;
                    }
                }
            }

            if (count == 1)
                ans = max(ans, x);
        }

        return ans;
    }
};



// Approach:
// - Traverse through each number in nums.
// - For every number, check all possible subarrays of size k.
// - Count how many different subarrays contain that number.
// - A number is "almost missing" if it appears in exactly one subarray.
// - Keep the maximum value that satisfies this condition.
// - If no such value exists, return -1.
//
// Note:
// We break after finding the number in a subarray,
// so multiple occurrences inside the same subarray are counted only once.
//
// Time Complexity: O(n² * k)
// Space Complexity: O(1)