#include <iostream>
#include <vector>
#include <queue>
#include <utility>  // for pair

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Directions for BFS traversal

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1)); // Initialize heights with -1
        queue<P> que;

        // Initialize water cells with height 0 and push them to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        // Perform multi-source BFS to calculate heights
        while (!que.empty()) {
            P curr = que.front();
            que.pop();

            int i = curr.first;
            int j = curr.second;

            for (auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1) {
                    height[i_][j_] = height[i][j] + 1; // Increment height for neighboring cells
                    que.push({i_, j_}); // Add the cell to the queue
                }
            }
        }

        return height;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> isWater = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 1}
    };

    // Get the result from the highestPeak function
    vector<vector<int>> result = sol.highestPeak(isWater);

    // Print the result
    for (auto& row : result) {
        for (auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
