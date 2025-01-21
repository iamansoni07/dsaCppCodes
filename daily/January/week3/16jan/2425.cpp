#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, long> mp; // Frequency count of XOR contributions

        // Occurrences of each number in nums1 (each appears `n` times in XOR sum)
        for (int &num : nums1) {
            mp[num] += n;
        }

        // Occurrences of each number in nums2 (each appears `m` times in XOR sum)
        for (int &num : nums2) {
            mp[num] += m;
        }

        int result = 0;

        // Final XOR result
        for (auto &it : mp) {
            int num = it.first;
            int freq = it.second;

            if (freq % 2 != 0) { // Only include numbers appearing an odd number of times
                result ^= num;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {6, 5};

    // Function call
    int result = solution.xorAllNums(nums1, nums2);

    // Output result
    cout << "Result: " << result << endl;

    return 0;
}
