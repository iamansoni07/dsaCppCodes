#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);  // Result vector to store the count of common elements for each prefix

        unordered_set<int> seen;  // Set to store elements encountered so far
        int count = 0;  // Variable to track common elements in prefixes

        // Iterate through each index and check for common elements in prefixes
        for (int i = 0; i < n; i++) {
            // Check if A[i] is already in the set (common element in both A and B)
            if (seen.count(A[i])) 
                count++;

            // Check if B[i] is already in the set (common element in both A and B)
            if (seen.count(B[i])) 
                count++;

            // Mark A[i] and B[i] as seen by inserting them into the set
            seen.insert(A[i]); 
            seen.insert(B[i]); 

            // Store the count of common elements up to index `i`
            result[i] = count;
        }

        return result;  // Return the result array with common prefix counts
    }
};

int main() {
    // Sample input
    vector<int> A = {1, 3, 2, 4, 6};
    vector<int> B = {3, 1, 2, 4, 5};

    Solution sol;
    vector<int> result = sol.findThePrefixCommonArray(A, B);

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
