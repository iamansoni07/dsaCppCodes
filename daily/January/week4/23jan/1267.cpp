#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int resultServers = 0;

        // Traverse through the grid
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) { // Check if there's a server at the current cell
                    bool canCommunicate = false;

                    // Check for another server in the same row
                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // If no communication in the row, check the same column
                    if (!canCommunicate) {
                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }
                    }

                    // If the server can communicate, count it
                    if (canCommunicate) {
                        resultServers++;
                    }
                }
            }
        }

        return resultServers;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1},
        {1, 1}
    };

    // Get the result from the countServers function
    int result = sol.countServers(grid);

    // Print the result
    cout << "Number of servers that can communicate: " << result << endl;

    return 0;
}
