/*
 * Problem: LeetCode 3754 - Concatenate Non-Zero Digits and Multiply by Sum I
 * 
 * Description:
 * Given a positive integer 'n', this program extracts all of its non-zero digits 
 * while maintaining their original relative order to form a new integer 'x'. 
 * It also calculates the sum of these non-zero digits. The final result returned 
 * is the mathematical product of 'x' and the 'sum' (x * sum).
 * 
 * Approach: 
 * Iterates through the number from right to left using the modulo operator (`% 10`). 
 * To preserve the original left-to-right order without needing string conversion or 
 * array reversals, it uses a scaling `multiplier` variable to dynamically prepend 
 * each non-zero digit to the front of 'x'.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long multiplier = 1; // Tracks the place value from right to left

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit != 0) {
                sum += digit;
                x = digit * multiplier + x; // Place the digit at the correct left-most position
                multiplier *= 10;           // Shift position for the next non-zero digit
            }
        }
        
        return x * sum;
    }
};

int main() {
    // Instantiate the Solution class
    Solution solver;

    // Sample input containing internal and trailing zeros
    int n = 10203004;

    // Call the function and capture the result
    long long result = solver.sumAndMultiply(n);

    // Print the output to the VS Code terminal
    cout << "Input: " << n << endl;
    cout << "Result (x * sum): " << result << endl;

    return 0;
}
