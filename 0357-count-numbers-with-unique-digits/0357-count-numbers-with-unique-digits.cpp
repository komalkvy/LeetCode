class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int total = 10; // counts for 0 and 1-digit numbers
        int current = 9; // starts from 9 for the first digit (1-9)
        for (int i = 2; i <= n; ++i) {
            current *= (10 - (i - 1)); // multiply by the remaining choices
            total += current;
        }
        return total;
    }
};