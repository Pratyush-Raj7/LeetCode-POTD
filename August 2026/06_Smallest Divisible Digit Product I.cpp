class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int x = n;
            int product = 1;

            while (x > 0) {
                product *= (x % 10);
                x /= 10;
            }

            if (product % t == 0)
                return n;

            n++;
        }
    }
};


/*
Approach (Brute Force)

- Start checking from n itself.
- For every number:
    1. Copy it into x (x = n).
    2. Find the product of all its digits.
    3. If product % t == 0, this is the smallest valid number, so return it.
    4. Otherwise, check the next number (n++).

Why x = n?
- We need to extract digits by doing x /= 10.
- If we do this on n directly, n becomes 0 after the loop.
- Then n++ becomes 1 instead of the next number, giving the wrong answer (and can even cause TLE).
- So always use a temporary variable (x) and keep n unchanged.

Example:
n = 15
15 -> product = 1 * 5 = 5 (not divisible)
16 -> product = 1 * 6 = 6 (divisible)
Answer = 16

Time Complexity: O((answer - n) * no. of digits)
Space Complexity: O(1)
*/