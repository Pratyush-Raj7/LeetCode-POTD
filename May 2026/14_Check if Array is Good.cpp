class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i = 0; i <= n-2; i++) {
            if(nums[i] != i+1)
                return false;
        }

        return nums[n-1] == n-1;
    }
};