#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> unique_letters;
        
        // Get all unique characters from the string
        for (char &ch : s) {
            unique_letters.insert(ch);
        }
        
        int result = 0;
        
        // Check for each unique letter
        for (char letter : unique_letters) {
            int first_idx = -1, last_idx = -1;
            
            // Find the first and last occurrence of the letter
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (first_idx == -1) first_idx = i; // Store first occurrence
                    last_idx = i; // Update last occurrence
                }
            }
            
            unordered_set<char> middle_chars;
            
            // Collect unique characters between first and last occurrence
            for (int middle = first_idx + 1; middle <= last_idx - 1; middle++) {
                middle_chars.insert(s[middle]);
            }

            // The number of unique middle characters contributes to the count
            result += middle_chars.size();
        }
        
        return result;
    }
};

// Driver function to test the code
int main() {
    Solution solution;
    
    string s = "aabca"; // Example input
    int result = solution.countPalindromicSubsequence(s);
    
    cout << "Number of unique palindromic subsequences: " << result << endl;
    
    return 0;
}
