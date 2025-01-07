#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> answer(n, 0);

        int leftCount = 0, rightCount = 0; // Number of '1's seen from left and right
        int leftOps = 0, rightOps = 0;     // Operations needed to move all left and right '1's

        // Pass 1: Left to Right
        for (int i = 0; i < n; i++) {
            answer[i] += leftOps; // Store operations needed from the left side
            if (boxes[i] == '1') leftCount++; // Update left count
            leftOps += leftCount; // Increase operation count
        }

        // Pass 2: Right to Left
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += rightOps; // Add operations needed from the right side
            if (boxes[i] == '1') rightCount++; // Update right count
            rightOps += rightCount; // Increase operation count
        }

        return answer;
    }
};

// Driver code
int main() {
    Solution solution;
    string boxes = "110"; 
    vector<int> result = solution.minOperations(boxes);

    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
