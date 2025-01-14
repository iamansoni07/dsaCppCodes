#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        // If we have fewer characters than k, we can't form k non-empty substrings
        if (n < k) {
            return false;
        }

        // If n == k, we can always form k substrings where each character is a separate substring
        if (n == k) {
            return true;
        }

        // Step 1: Count frequency of each character
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Count characters with odd frequency
        int oddFreqCharCount = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) { // If frequency is odd, it needs to be in its own palindrome
                oddFreqCharCount++;
            }
        }

        // Step 3: We can only form k palindromes if the number of odd-frequency characters <= k
        return oddFreqCharCount <= k;
    }
};

// Driver code for testing
int main() {
    Solution solution;
    
    // Example test cases
    string s1 = "aabbcc";
    int k1 = 3;
    cout << "Test 1: " << (solution.canConstruct(s1, k1) ? "True" : "False") << endl;

    string s2 = "aabb";
    int k2 = 1;
    cout << "Test 2: " << (solution.canConstruct(s2, k2) ? "True" : "False") << endl;

    string s3 = "leetcode";
    int k3 = 3;
    cout << "Test 3: " << (solution.canConstruct(s3, k3) ? "True" : "False") << endl;

    return 0;
}
