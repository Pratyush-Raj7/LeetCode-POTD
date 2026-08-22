class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int x = n;

        while (x) {
            int digit = x % 10;
            sum += digit;
            product *= digit;
            x /= 10;
        }

        return n % (sum + product) == 0;
    }
};

// Approach:
// 1. Traverse through all digits of n using modulo (%) and integer division (/).
// 2. For each digit, add it to the running sum and multiply it with the
//    running product.
// 3. A temporary variable is used for digit extraction so that the original
//    value of n remains unchanged.
// 4. After processing all digits, calculate (sum + product) and check whether
//    n is divisible by this value.
// 5. Return true if the remainder is 0; otherwise, return false.
//
// Time Complexity: O(log10(n))
//   - A number n has approximately log10(n) + 1 digits.
//   - Each digit is processed exactly once.
//
// Space Complexity: O(1)
//   - Only a constant number of variables are used, regardless of the size of n.