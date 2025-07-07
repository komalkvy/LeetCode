class Solution {
public:
    int integerBreak(int n) {
        // Base cases: for n = 2 and 3, best product is n - 1
        if (n == 2 || n == 3)
            return n - 1;

        // If n is divisible by 3, best to use all 3s
        if (n % 3 == 0) {
            return pow(3, n / 3);
        }
        // If remainder is 1, it's better to use one 4 instead of 3 + 1
        else if (n % 3 == 1) {
            return pow(3, (n / 3) - 1) * 4;
        }
        // If remainder is 2, just multiply with 2
        else {
            return pow(3, n / 3) * 2;
        }
    }
};