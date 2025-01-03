#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Check if a char is a vowel
    bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    // Answer the queries
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int numQueries = queries.size();                 // Number of queries
        int numWords = words.size();                     // Number of words
        vector<int> result(numQueries);                  // To store the results

        vector<int> cumulativeVowelCount(numWords);      // Count of vowel words up to index
        int validVowelWordCount = 0;                     // Count of words with vowels at both ends

        // Build cumulative count array
        for(int i = 0; i < numWords; i++) {
            if(isVowel(words[i][0]) && isVowel(words[i].back())) {
                validVowelWordCount++;                  // Increment if both ends are vowels
            }
            cumulativeVowelCount[i] = validVowelWordCount; // Save the cumulative count
        }

        // Answer each query
        for(int i = 0; i < numQueries; i++) {
            int leftIndex = queries[i][0];                // Start of range
            int rightIndex = queries[i][1];               // End of range

            // Calculate result for the query
            result[i] = cumulativeVowelCount[rightIndex] - (leftIndex > 0 ? cumulativeVowelCount[leftIndex - 1] : 0);
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<string> words = {"apple", "banana", "orange", "umbrella", "aqua"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {0, 4}};
    
    // Get the result
    vector<int> result = sol.vowelStrings(words, queries);
    
    // Print the result
    for(int res : result) {
        cout << res << " ";
    }
    cout << endl;
    
    return 0;
}
