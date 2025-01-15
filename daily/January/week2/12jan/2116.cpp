#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        // If the length is odd, it's impossible to form a valid parentheses string
        if (n % 2 != 0) {
            return false;
        }

        stack<int> open;      // Stack to store indices of '(' which are locked
        stack<int> openClose; // Stack to store indices of flexible (unlocked) characters

        // Step 1: Iterate through the string
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {  
                openClose.push(i);  // Unlocked characters can be either '(' or ')'
            } 
            else if (s[i] == '(') {  
                open.push(i);  // Store index of locked '('
            } 
            else {  // s[i] == ')'
                if (!open.empty()) {  
                    open.pop();  // Match a locked '(' with a locked ')'
                } 
                else if (!openClose.empty()) {  
                    openClose.pop();  // Use an unlocked character to balance ')'
                } 
                else {  
                    return false;  // No way to balance the ')', return false
                }
            }
        }

        // Step 2: Balancing leftover '(' with unlocked characters
        while (!open.empty() && !openClose.empty() && open.top() < openClose.top()) {
            open.pop();
            openClose.pop();
        }

        // If all locked '(' are balanced, return true
        return open.empty();
    }
};

// Driver code to test the function
int main() {
    Solution solution;

    string s1 = "(()))";
    string locked1 = "01010";
    cout << "Test 1: " << (solution.canBeValid(s1, locked1) ? "True" : "False") << endl;

    string s2 = "())";
    string locked2 = "110";
    cout << "Test 2: " << (solution.canBeValid(s2, locked2) ? "True" : "False") << endl;

    string s3 = "())(()";
    string locked3 = "000000";
    cout << "Test 3: " << (solution.canBeValid(s3, locked3) ? "True" : "False") << endl;

    return 0;
}
