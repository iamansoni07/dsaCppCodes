#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);

        for(int i = 0; i < numRows; i++) {
            result[i] = vector<int>(i + 1, 1);

            for(int j = 1; j < i; j++) {
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    int numRows;

    cout << "Enter the number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = sol.generate(numRows);

    cout << "Pascal's Triangle: " << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
