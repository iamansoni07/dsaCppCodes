#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Map to store the value-to-cell coordinate mapping
        unordered_map<int, pair<int, int>> mp; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }

        // Arrays to track painted count in rows and columns
        vector<int> rowCountPaint(m, 0);
        vector<int> colCountPaint(n, 0);

        // Process elements in `arr` and update paint counts
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            auto [row, col] = mp[val];

            rowCountPaint[row]++;
            colCountPaint[col]++;

            // Check if a row or column is fully painted
            if (rowCountPaint[row] == n || colCountPaint[col] == m) {
                return i;
            }
        }

        return -1; // No row or column fully painted
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> arr = {1, 3, 4, 2};
    vector<vector<int>> mat = {
        {1, 4},
        {2, 3}
    };

    // Function call
    int result = solution.firstCompleteIndex(arr, mat);

    // Output the result
    cout << "First index where a row or column is fully painted: " << result << endl;

    return 0;
}
