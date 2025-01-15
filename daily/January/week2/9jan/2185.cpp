#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        // Iterate through each word in the list
        for (string& word : words) {
            // Check if the word starts with the given prefix
            if (word.find(pref) == 0) {  // find() returns 0 if the prefix matches from the start
                count++;
            }
        }
        return count;
    }
};

// Driver Code to test the function
int main() {
    Solution solution;
    
    vector<string> words = {"apple", "app", "apricot", "banana", "apply"};
    string prefix = "app";

    int result = solution.prefixCount(words, prefix);

    cout << "Words starting with prefix '" << prefix << "': " << result << endl;

    return 0;
}
