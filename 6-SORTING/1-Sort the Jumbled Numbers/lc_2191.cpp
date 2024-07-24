#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<int> temp(nums.begin(), nums.end());
        vector<pair<int, int>> result;

        for (int i = 0; i < temp.size(); i++)
        {
            int newNum = 0;
            int factor = 1;

            if (temp[i] == 0)
            {
                // explicitly handle temp[i] = 0
                newNum = mapping[0];
            }
            else
            {
                while (temp[i] > 0)
                {
                    int digit = temp[i] % 10;
                    newNum += mapping[digit] * factor;
                    factor *= 10;
                    temp[i] /= 10;
                }
            }

            result.push_back({newNum, i});
        }

        sort(result.begin(), result.end());

        vector<int> finalRes;

        for (auto &i : result)
        {
            finalRes.push_back(nums[i.second]);
        }

        return finalRes;
    }
};
