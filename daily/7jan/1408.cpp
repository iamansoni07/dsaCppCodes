#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> result;
        int n = words.size();

        // Sort words based on length (shorter words first)
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        // Check if the current word is a substring of any longer word
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; // Avoid duplicates
                }
            }
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution solution;
    vector<string> words = {"mass", "as", "hero", "superhero"};

    vector<string> result = solution.stringMatching(words);

    cout << "Substrings found: ";
    for (const string &word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
