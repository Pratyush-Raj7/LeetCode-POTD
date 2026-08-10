class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> t(n + 1, false);

        t[0] = false;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                if (t[i - (k * k)] == false) {
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n];
    }
};

Winner Square Game — DP

Approach:
Use bottom-up Dynamic Programming.

Intuition:
For every number i, try removing each possible perfect square.
If any move leaves the opponent in a losing state, i is a winning state.

DP State:
t[i] = whether the current player can win with i stones.

Base Case:
t[0] = false
No stones → no move → lose.

Transition:
If t[i - k²] == false → t[i] = true.

Otherwise, if no such move exists → t[i] = false.

Complexity:
Time: O(n√n)
Space: O(n)

Key Pattern:
If you can move to a losing state → WIN.
If every move leads to a winning state → LOSS.