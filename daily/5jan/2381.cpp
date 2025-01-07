#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0); // Difference array to efficiently apply shifts

        // Step 1: Process all shifts
        for (auto &shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1; // 1 means forward shift, 0 means backward shift
            
            diff[start] += direction; // Apply shift at start index
            diff[end + 1] -= direction; // Remove shift after end index
        }

        // Step 2: Compute prefix sum to apply shifts correctly
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1];
        }

        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = diff[i] % 26; // Ensure shift is within [0, 25]
            if (shift < 0)
                shift += 26; // Handle negative shifts properly
            
            // Apply shift to the character
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';

            /*
                Explanation:
                - s[i] - 'a' → Converts char to number (0 to 25)
                - + shift   → Adds the shift amount
                - % 26      → Ensures it stays within 'a' to 'z'
                - + 'a'     → Converts back to character
            */
        }

        return s;
    }
};

// Driver code
int main() {
    Solution solution;
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 1}, {1, 2, 1}, {0, 2, 0}}; 

    string result = solution.shiftingLetters(s, shifts);
    cout << "Shifted String: " << result << endl;

    return 0;
}
