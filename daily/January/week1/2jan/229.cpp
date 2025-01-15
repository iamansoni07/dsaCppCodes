#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int firstMaj = -1;  // Use -1 as a placeholder for uninitialized value
        int firstCount = 0;

        int secondMaj = -1; // Use -1 as a placeholder for uninitialized value
        int secondCount = 0;
        int threshold = n / 3;
        
        // First pass: Find the two potential majority elements
        for(int i = 0; i < n; i++) {
            if(nums[i] == firstMaj) {
                firstCount++;
            } else if(nums[i] == secondMaj) {
                secondCount++;
            } else if(firstCount == 0) {
                firstMaj = nums[i];
                firstCount = 1;
            } else if(secondCount == 0) {
                secondMaj = nums[i];
                secondCount = 1;
            } else {
                firstCount--;
                secondCount--;
            }
        }
        
        vector<int> result; // To store the final result
        firstCount = 0;
        secondCount = 0;
        
        // Second pass: Count actual occurrences of the candidates
        for(int num : nums) {
            if(num == firstMaj) firstCount++;
            else if(num == secondMaj) secondCount++;
        }
        
        // Add the majority elements to the result if they appear more than n / 3 times
        if(firstCount > threshold) result.push_back(firstMaj);
        if(secondCount > threshold) result.push_back(secondMaj);
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Sample input
    vector<int> nums = {3, 2, 3};
    
    // Get the result
    vector<int> result = solution.majorityElement(nums);
    
    // Print the result
    cout << "Majority elements are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
