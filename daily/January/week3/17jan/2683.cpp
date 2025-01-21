#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorVal = 0;

        // Compute XOR of all elements in the derived array
        for (auto el : derived) {
            xorVal ^= el;
        }

        // If the final XOR is 0, a valid original array exists
        return (xorVal == 0);
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> derived = {1, 1, 0};

    // Function call
    bool result = solution.doesValidArrayExist(derived);

    // Output result
    if (result) {
        cout << "A valid original array exists." << endl;
    } else {
        cout << "No valid original array exists." << endl;
    }

    return 0;
}
