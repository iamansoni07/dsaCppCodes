// T.C: O(log(n)), since we iterate through bits (at most 32 for int)
// S.C: O(1), no extra space used

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution
{
public:
    // Function to check if a bit is set at a given position
    bool isSet(int &x, int bit)
    {
        return x & (1 << bit);
    }

    // Function to set a bit at a given position
    bool setBit(int &x, int bit)
    {
        return x |= (1 << bit);
    }

    // Function to unset a bit at a given position
    bool unsetBit(int &x, int bit)
    {
        return x &= ~(1 << bit);
    }

    int minimizeXor(int num1, int num2)
    {
        int x = num1;

        // Count the number of set bits in num2 (this is the number we want in x)
        int requiredSetBitCount = __builtin_popcount(num2);
        int currSetBitCount = __builtin_popcount(x);

        int bit = 0; // Bit position tracker

        // If we need more set bits, turn on unset bits from LSB
        if (currSetBitCount < requiredSetBitCount)
        {
            while (currSetBitCount < requiredSetBitCount)
            {
                if (!isSet(x, bit))
                { // If bit is 0, turn it on
                    setBit(x, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        }
        // If we have extra set bits, turn off bits from LSB
        else if (currSetBitCount > requiredSetBitCount)
        {
            while (currSetBitCount > requiredSetBitCount)
            {
                if (isSet(x, bit))
                { // If bit is 1, turn it off
                    unsetBit(x, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }

        return x;
    }
};

// Driver Code
int main()
{
    Solution sol;

    int num1, num2;
    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;

    int result = sol.minimizeXor(num1, num2);
    cout << "Minimum XOR Value: " << result << endl;

    return 0;
}
