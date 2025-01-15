//1st question of 2025 - Maximum Score After Splitting a String

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int ans = INT_MIN;
        int n = s.length();
        for (int i = 0; i <= n - 2; i++) {
            int z = 0; 
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') {
                    z++;
                }
            }
            int o = 0; 
            for (int k = i + 1; k < n; k++) { 
                if (s[k] == '1') {
                    o++;
                }
            }
            int ekAns = o + z; 
            ans = max(ans, ekAns);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter the binary string: ";
    cin >> input;

    int result = sol.maxScore(input);
    cout << "Maximum score: " << result << endl;

    return 0;
}
