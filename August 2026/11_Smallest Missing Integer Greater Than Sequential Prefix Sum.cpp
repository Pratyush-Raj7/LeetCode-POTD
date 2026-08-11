class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};

/*

Approach:
1. Find the sum of the longest sequential prefix.
   - Keep adding while nums[i] == nums[i-1] + 1.
   - Stop at the first break.

2. Store all elements in unordered_set.

3. Starting from prefixSum, keep checking:
   - If present -> prefixSum++
   - If missing -> answer.

Example:
nums = [3,4,5,1,12,14,13]

Prefix = [3,4,5]
sum = 12

12 -> present
13 -> present
14 -> present
15 -> missing

Answer = 15

Time: O(n) expected
Space: O(n)
*/