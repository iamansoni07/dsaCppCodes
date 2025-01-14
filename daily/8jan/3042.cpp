#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Check if string 'check' is both prefix and suffix of string 's'
    bool isPrefixAndSuffix(string &check, string &s) {
        int n = check.length();
        
        // Get the first and last 'n' characters of string 's'
        string s1 = s.substr(0, n);
        string s2 = s.substr(s.length() - n, n);
        
        return s1 == check && s2 == check;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        
        // Compare all pairs of words
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                // Only check pairs where the length of word[i] <= word[j]
                if (words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

// Driver code
int main() {
    Solution solution;
    vector<string> words = {"abc", "abcabc", "a", "abca", "cabc"};

    int result = solution.countPrefixSuffixPairs(words);

    cout << "Prefix-Suffix Pairs Count: " << result << endl;
    return 0;
}
