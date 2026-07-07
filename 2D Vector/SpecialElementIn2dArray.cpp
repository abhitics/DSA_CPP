/*
 * Problem: LeetCode 1582 - Special Positions in a Binary Matrix
 * 
 * Description:
 * Given an m x n binary matrix 'mat' (containing only 0s and 1s), this program 
 * counts the number of "special positions". A position (r, c) is considered 
 * special if mat[r][c] == 1 and all other elements in row 'r' and column 'c' 
 * are 0 (meaning it is the only 1 in its respective row and column).
 * 
 * Approach: Precompute the count of 1s in each row and column using frequency arrays
 * to achieve an optimal O(m * n) time complexity.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rCount(m, 0);
        vector<int> cCount(n, 0);
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1) {
                    rCount[r]++;
                    cCount[c]++;
                }
            }
        }
        
        int pos = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1 && rCount[r] == 1 && cCount[c] == 1) {
                    pos++;
                }
            }
        }
        return pos;
    }
};

int main() {
    // Instantiate the Solution class
    Solution solver;

    // Create a sample 2D grid matrix for testing
    vector<vector<int>> mat = {
        {1, 0, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    // Call the function and capture the result
    int result = solver.numSpecial(mat);

    // Print the output to the VS Code terminal
    cout << "Number of Special Positions: " << result << endl;

    return 0;
}
