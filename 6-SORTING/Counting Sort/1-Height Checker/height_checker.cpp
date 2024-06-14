#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void countSort(vector<int> &expected)
    {
        vector<int> result(expected.size());
        int max = *max_element(expected.begin(), expected.end());
        vector<int> freq(max + 1, 0);

        for (int i = 0; i < expected.size(); i++)
            freq[expected[i]]++; // count freq

        for (int i = 1; i <= max; i++)
            freq[i] += freq[i - 1]; // cummulative freq

        for (int i = expected.size() - 1; i >= 0; i--)
        {
            result[freq[expected[i]] - 1] = expected[i];
            freq[expected[i]]--;
        }

        expected = result;
    }
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected(heights);
        countSort(expected); // 1 <= heights[i] <= 100
        int count = 0;

        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != expected[i])
                count++;

        return count;
    }
};