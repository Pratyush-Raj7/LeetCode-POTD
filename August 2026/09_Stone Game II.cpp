class Solution {
public:
    
    int n;
    int t[2][101][101]; //t[2][n+1][n+1] - 2*(n+1)*(n+1) ~n^2 * n ~ O(n^3)
    int solveForAlice(vector<int>& piles, int person, int i, int M) {
        
        if(i >= n)
            return 0;
        
        if(t[person][i][M] != -1)
            return t[person][i][M];
        
        int result = (person == 1) ? -1 : INT_MAX;
        
        int stones = 0;
        
        for(int x = 1; x <= min(2*M, n-i); x++) {
            
            stones += piles[i+x-1];
            
            if(person == 1) { //Alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            } else { //Bob
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x)));
            }
            
        }
        
        return t[person][i][M] = result;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        
        memset(t, -1, sizeof(t));
        
        return solveForAlice(piles, 1, 0, 1);
    }
};


/*
    Stone Game II
    Approach: Top-Down DP + Memoization (Minimax)

    DP State:
        t[person][i][M]
        -> Maximum stones Alice can get from index i
           with current M and player's turn.

    person:
        1 -> Alice -> MAX
        0 -> Bob   -> MIN

    Transition:
        Take x piles, where 1 <= x <= 2*M
        next state = (i + x, max(M, x))

    Alice:
        maximize(stones_taken + future_Alice_score)

    Bob:
        minimize(future_Alice_score)
        (Bob's stones aren't added since DP tracks Alice's score)

    Base Case:
        i >= n -> 0

    Initial State:
        Alice, i = 0, M = 1

    Complexity:
        Time  -> O(n^3)
        Space -> O(n^2)

    Key Pattern:
        Two-player optimal game -> Minimax DP
*/