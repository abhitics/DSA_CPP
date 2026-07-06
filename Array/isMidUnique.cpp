#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        if (nums.empty()) return false; 
        return count(nums.begin(), nums.end(), nums[nums.size() / 2]) == 1;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1: Middle element (3) is unique
    vector<int> test1 = {1, 2, 3, 4, 5}; 
    cout << "Test 1 (Expected 1/True): " << solver.isMiddleElementUnique(test1) << endl;

    // Test Case 2: Middle element (2) is repeated
    vector<int> test2 = {1, 2, 2, 2, 5}; 
    cout << "Test 2 (Expected 0/False): " << solver.isMiddleElementUnique(test2) << endl;

    return 0;
}
