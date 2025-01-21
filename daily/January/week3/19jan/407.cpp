#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Directions: right, left, down, up

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // Min-heap for Dijkstra
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));         // Store the minimum cost to reach each cell

        pq.push({0, 0, 0});         // Start from (0, 0) with cost 0
        result[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();               // Pop the cell with the smallest cost

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if (result[i][j] < currCost) {
                continue;           // Skip if the current cost is not optimal
            }

            for (int dir_i = 0; dir_i <= 3; dir_i++) {
                int i_ = i + dir[dir_i][0];
                int j_ = j + dir[dir_i][1];

                if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir - 1 != dir_i) ? 1 : 0); // Cost to change direction

                    int newCost = currCost + dirCost;

                    if (newCost < result[i_][j_]) {
                        result[i_][j_] = newCost;               // Update cost if we found a cheaper path
                        pq.push({newCost, i_, j_});             // Push the new cell into the priority queue
                    }
                }
            }
        }

        return result[m - 1][n - 1];
    }
};

int main() {
    Solution solution;

    // Example input
    vector<vector<int>> grid = {
        {1, 1, 3},
        {3, 2, 2},
        {1, 1, 4}
    };

    // Function call
    int result = solution.minCost(grid);

    // Output the result
    cout << "Minimum cost to make at least one valid path in the grid: " << result << endl;

    return 0;
}
