#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length() - 1;  // Two pointers from both ends

        // Continue while characters match
        while (l < r && s[l] == s[r]) { 
            char ch = s[l];  // Store the current character being removed
            
            // Move `l` forward while it still matches `ch`
            while (l <= r && s[l] == ch) {
                l++;
            }

            // Move `r` backward while it still matches `ch`
            while (r >= l && s[r] == ch) {
                r--;
            }
        }

        // Remaining length of the valid substring
        return r - l + 1;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;  // Input string
    cout << sol.minimumLength(s) << endl;  // Output the result
    return 0;
}
