#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Function to check if freq2 is a subset of temp
    bool isSubset(vector<int>& freq2, vector<int>& temp) {
        for (int i = 0; i < 26; i++) { // Check for each letter a-z (O(1) constant time)
            if (temp[i] < freq2[i]) {
                return false; // If any character count is less, it's not a subset
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq2(26, 0); // Stores the max frequency of each letter in words2
        
        // Step 1: Build freq2 array - Find max frequency of each character across all words in words2
        for (string &word : words2) {  // O(n)
            int temp[26] = {0}; // Temporary frequency array for each word

            for (char &ch : word) { // O(l1) - Count occurrences of each letter in this word
                temp[ch - 'a']++;
                freq2[ch - 'a'] = max(freq2[ch - 'a'], temp[ch - 'a']); // Store max freq required
            }
        }

        // Step 2: Check each word in words1 against freq2
        for (string &word : words1) {  // O(m)
            vector<int> temp(26, 0); // Frequency array for the current word in words1

            for (char &ch : word) { // O(l2) - Count occurrences of each letter in this word
                temp[ch - 'a']++;
            }

            // Check if this word satisfies all conditions (i.e., contains required character counts)
            if (isSubset(freq2, temp)) { // O(1)
                result.push_back(word);
            }
        }

        return result;
    }
};

// Driver code to test the function
int main() {
    Solution solution;
    
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};

    vector<string> result = solution.wordSubsets(words1, words2);

    cout << "Universal words are: ";
    for (string &word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
