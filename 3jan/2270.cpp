#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        
        // Compute prefix sum array
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int validSplits = 0;
        
        // Check each possible split point
        for (int i = 0; i < n - 1; i++) {
            long long leftSum = prefixSum[i];
            long long rightSum = prefixSum[n - 1] - prefixSum[i];

            if (leftSum >= rightSum) {
                validSplits++;
            }
        }

        return validSplits;
    }
};

// Driver function to test the code
int main() {
    Solution solution;
    vector<int> nums = {10, 4, -8, 7}; // Example input
    int result = solution.waysToSplitArray(nums);

    cout << "Number of valid splits: " << result << endl;

    return 0;
}
