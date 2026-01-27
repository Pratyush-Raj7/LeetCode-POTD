/*
Intuition:
After sorting, the best k scores will always form a consecutive window.
Checking all such windows gives the minimum possible max-min difference.

Approach:
- Sort the array
- Slide a window of size k
- Track minimum (nums[i]) and maximum (nums[i+k-1])

Time: O(n log n)
Space: O(1)
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int minDiff = INT_MAX;

        int i = 0;
        int j = i+k-1;
        while(j < n) {
            int minElement = nums[i];
            int maxElement = nums[j];

            minDiff = min(minDiff, maxElement - minElement);
            i++;
            j++;
        }

        return minDiff;
    }
};