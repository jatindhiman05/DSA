#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &nums, int k, int x)
    {
        sort(nums.begin(), nums.end(), [x](int a, int b)
             {
            int diffA = abs(a - x);
            int diffB = abs(b - x);

            if(diffA != diffB){
                return diffA < diffB;
            }else{
                return a < b;
            } });

        nums.resize(k);

        sort(nums.begin(), nums.end());
        return nums;
    }
};

// two pointer
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int low = 0;
        int high = arr.size() - 1;

        while ((high - low) >= k)
        {
            // decreasing windowsize
            if (x - arr[low] > arr[high] - x)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return vector<int>(arr.begin() + low ,arr.begin() + high + 1);
    }
};
