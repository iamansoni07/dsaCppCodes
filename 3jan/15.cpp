// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     // To find two numbers that sum up to 'target'
//     void twoSum(vector<int>& nums, int start, vector<vector<int>>& result, int target) {
//         int left = start, right = nums.size() - 1;

//         while (left < right) {
//             int sum = nums[left] + nums[right];

//             if (sum > target) {
//                 right--;
//             } else if (sum < target) {
//                 left++;
//             } else {
//                 result.push_back({-target, nums[left], nums[right]});

//                 // Skip duplicate elements to avoid repeated triplets
//                 while (left < right && nums[left] == nums[left + 1]) left++;
//                 while (left < right && nums[right] == nums[right - 1]) right--;

//                 left++;
//                 right--;
//             }
//         }
//     }

//     vector<vector<int>> threeSum(vector<int>& nums) {
//         if (nums.size() < 3) return {};                     // Edge case: If less than 3 elements, no triplet possible

//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end());                     // Sorting is necessary for two-pointer technique

//         for (int i = 0; i < nums.size() - 2; i++) {
//             if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates

//             twoSum(nums, i + 1, result, -nums[i]);          // Find pairs that sum to -nums[i]
//         }

//         return result;
//     }
// };

// // Driver function to test the code
// int main() {
//     Solution solution;
//     vector<int> nums = {-1, 0, 1, 2, -1, -4};  // Example input
//     vector<vector<int>> result = solution.threeSum(nums);

//     // Print the output
//     cout << "Triplets that sum to zero:" << endl;
//     for (const auto& triplet : result) {
//         cout << "[";
//         for (int i = 0; i < triplet.size(); i++) {
//             cout << triplet[i];
//             if (i < triplet.size() - 1) cout << ", ";
//         }
//         cout << "]" << endl;
//     }

//     return 0;
// }




#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        if (n < 3) return {}; // Edge case
        
        sort(nums.begin(), nums.end()); // Sorting helps avoid duplicate triplets

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate elements
            
            unordered_set<int> seen; // Hash set to track pairs
            for (int j = i + 1; j < n; j++) {
                int complement = -nums[i] - nums[j]; // Find the third element
                
                if (seen.count(complement)) {
                    result.push_back({nums[i], nums[j], complement});

                    // Skip duplicate values for nums[j] to avoid repeated triplets
                    while (j + 1 < n && nums[j] == nums[j + 1]) j++;
                }
                seen.insert(nums[j]); // Store the number in the set
            }
        }

        return result;
    }
};

// Driver function for testing
int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Example input
    vector<vector<int>> result = solution.threeSum(nums);

    // Printing the output
    cout << "Triplets that sum to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}

