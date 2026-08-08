class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> rightHandSideMatchLength(n, 0);

        int rightMatched = 0;
        int i = n-1;
        int j = m-1;
        while(i >= 0) {
            if(j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }

            rightHandSideMatchLength[i] = rightMatched;
            i--;
        }

        vector<int> seq;
        bool changePower = true; 
        i = 0;
        j = 0;
        while(i < n && j < m) {
            if(word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if(changePower == true && i+1 < n && rightHandSideMatchLength[i+1] >= m-j-1) {
                seq.push_back(i);
                j++;
                changePower = false;
            }

            i++;
        }

        return j == m ? seq : vector<int>();
    }
};

/*
Approach:
- Need to form word2 as a subsequence of word1 with at most 1 mismatch.
- First traverse from RIGHT -> LEFT and store suffix matching information.
- rightHandSideMatchLength[i] = number of characters of word2 that can
  be matched from word1[i...n-1].
- Then traverse word1 from LEFT -> RIGHT:
    1. If word1[i] == word2[j], take index i normally.
    2. If mismatch, use the one allowed change only if the remaining
       characters of word2 can still be matched.
- Condition:
      rightHandSideMatchLength[i+1] >= m-j-1
  ensures that after using the current index as the mismatch,
  the remaining word2 can still be completed.
- changePower makes sure we use the mismatch only once.
- If j reaches m, return the selected indices; otherwise return empty.

Key idea:
  Precompute suffix feasibility from the right, then greedily build
  the answer from the left.

Time: O(n)
Space: O(n)
*/