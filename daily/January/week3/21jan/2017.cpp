#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int gridGame(vector<vector<int>>& grid) {
        int firstRowRemainSum = accumulate(begin(grid[0]), end(grid[0]), 0); // Total sum of the first row
        int secondRowRemainSum = 0;
        int minimizedRobot2Sum = INT_MAX;

        // Simulate Robot1's strategies
        for (int Robot1Col = 0; Robot1Col < grid[0].size(); Robot1Col++) {
            firstRowRemainSum -= grid[0][Robot1Col]; // Update remaining sum for the first row
            int bestOfRobot2 = max(firstRowRemainSum, secondRowRemainSum); // Robot2's best option
            minimizedRobot2Sum = min(minimizedRobot2Sum, bestOfRobot2); // Minimize Robot2's maximum score
            secondRowRemainSum += grid[1][Robot1Col]; // Update accumulated sum for the second row
        }

        return minimizedRobot2Sum;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<vector<int>> grid = {
        {2, 5, 4},
        {1, 5, 1}
    };

    // Function call
    int result = solution.gridGame(grid);

    // Output the result
    cout << "Minimized maximum score Robot2 can achieve: " << result << endl;

    return 0;
}
