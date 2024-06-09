#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// brute force
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int result = 0;
        // cummulative sum
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int sum = (i == 0) ? nums[j] : nums[j] - nums[i - 1]; // i to j sum

                if (sum % k == 0)
                {
                    result++;
                }
            }
        }

        return result;
    }
};

// optimal

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // if s1%k = x, s2%k = x ==> (s2-s1)%k = 0 
        unordered_map<int,int> map; // remain <-> count
        int sum = 0;

        map[0] = 1;
        int result = 0;

        for(int i =0;i<nums.size();i++){
            sum += nums[i];

            int remain = sum % k;

            if(remain < 0){
                //handle -ve remain
                remain += k;
            }

            if(map.find(remain) != map.end()){
                result += map[remain];
            }

            map[remain]++;
        }

        return result;
    }
};