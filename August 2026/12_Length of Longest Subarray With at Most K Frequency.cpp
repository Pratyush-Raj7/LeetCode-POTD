class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int i = 0, j = 0, result = 0;

        while(j < n){
            mp[nums[j]]++;

            while(i < j && mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};

// Approach: Sliding Window + HashMap
//
// - Maintain a window [i...j] where every element appears <= k times.
// - Use HashMap to store the frequency of each element in the window.
// - Move j forward to expand the window.
// - If nums[j] frequency becomes > k, move i forward and decrease
//   frequencies until the window becomes valid again.
// - Since both i and j only move forward, each element is processed
//   at most twice -> O(n) time.
// - Track the maximum valid window length using j - i + 1.
//
// Key pattern to remember:
// "Longest subarray + frequency constraint" -> Sliding Window + HashMap
//
// Time: O(n) average
// Space: O(n)