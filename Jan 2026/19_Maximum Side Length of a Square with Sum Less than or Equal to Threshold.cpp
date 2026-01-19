class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Build prefix sum
        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = mat[i][j]
                             + (i > 0 ? prefix[i - 1][j] : 0)
                             + (j > 0 ? prefix[i][j - 1] : 0)
                             - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        // Sum of square (r1,c1) -> (r2,c2)
        auto sumSquare = [&](int r1, int c1, int r2, int c2) {
            int sum = prefix[r2][c2];
            if (r1 > 0) sum -= prefix[r1 - 1][c2];
            if (c1 > 0) sum -= prefix[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) sum += prefix[r1 - 1][c1 - 1];
            return sum;
        };

        // Check function
        auto check = [&](int side) {
            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {
                    if (sumSquare(i, j,  i + side - 1,  j + side - 1) <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };

        // Binary search on side length
        int lo = 1, hi = min(rows, cols);
        int result = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                result = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
   return result;
    }
};

