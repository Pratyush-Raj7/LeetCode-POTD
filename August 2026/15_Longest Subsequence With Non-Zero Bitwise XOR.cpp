class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resultXor = 0;
        bool allZero = true;

        for(int &x : nums) {
            resultXor ^= x;
            if(x != 0)
                allZero = false;
        }

        if(allZero)
            return 0;

        return resultXor == 0 ? n-1 : n;
    }
};


/*
    Approach:

    1. Calculate the XOR of all elements in the array.

    2. If all elements are 0:
       - XOR of every possible subsequence will be 0.
       - Therefore, no valid non-empty subsequence exists.
       - Return 0.

    3. If the total XOR is non-zero:
       - The entire array itself is a valid subsequence.
       - Return n.

    4. If the total XOR is 0:
       - Since the array is not all zeros, there is at least one non-zero element.
       - Remove any one non-zero element.
       - The XOR of the remaining elements becomes non-zero.
       - Therefore, answer = n - 1.

    Key XOR Properties:
       - x ^ x = 0
       - x ^ 0 = x
       - a ^ a ^ b = b

    Complexity:
       Time  : O(n)
       Space : O(1)
*/