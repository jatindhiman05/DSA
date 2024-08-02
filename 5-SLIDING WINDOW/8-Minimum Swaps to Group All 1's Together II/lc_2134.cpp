#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        // The window(of size totalOnes) with maxOnes results in min Swaps
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int i = 0;
        int j = 0;
        int currOnes = 0;
        int maxOnes = 0;

        while (j < 2 * n)
        {
            if (nums[j % n] == 1)
            {
                currOnes++;
            }

            if (j - i + 1 == totalOnes)
            {
                maxOnes = max(maxOnes, currOnes);

                currOnes -= nums[i % n];
                i++;
            }

            j++;
        }

        return totalOnes - maxOnes;
    }
};