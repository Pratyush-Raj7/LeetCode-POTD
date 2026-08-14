class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;

        int l = 0;
        int ans = 0;

        for(int r = 0; r < s.size(); r++){
            freq[s[r]]++;

            while(freq[s[r]] > 2){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// Approach: Sliding Window / Two Pointers
//
// Intuition:
// We need the longest substring where every character appears at most 2 times.
//
// Maintain a window [l...r]:
// - r expands the window by adding s[r].
// - freq stores the frequency of each character inside the window.
// - If the frequency of s[r] becomes > 2, the window is invalid.
// - Move l forward and remove characters until the window becomes valid again.
// - After the window is valid, update the maximum length.
//
// Why does this work?
// Before adding s[r], the window was already valid.
// Adding one character can only make s[r] exceed the allowed frequency.
// Therefore, we only need to check freq[s[r]] > 2.
//
// Window length = r - l + 1
//
// Example:
// s = "aaaa"
//
// r=0 -> "a"     valid
// r=1 -> "aa"    valid, ans=2
// r=2 -> "aaa"   invalid
//        remove left 'a' -> "aa"
// r=3 -> "aaa"   invalid
//        remove left 'a' -> "aa"
//
// Answer = 2
//
// Complexity:
// Time: O(n)
// Space: O(k), where k = number of distinct characters.
// Since there are only 26 lowercase letters, space is effectively O(1).
