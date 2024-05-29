// Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/ -> lc- 215

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 1st - approach using sorting
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k - 1];
    }
};

// Second approach -> priority queue
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};

// Third approach -> using Quick Select

class Solution
{
public:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low + 1;
        int j = high;

        while (i <= j)
        {
            if (nums[i] < pivot && nums[j] > pivot)
            {
                swap(nums[i++], nums[j--]);
            }
            if (nums[i] >= pivot)
            {
                i++;
            }
            if (nums[j] <= pivot)
            {
                j--;
            }
        }

        swap(nums[low], nums[j]);

        return j;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int pivot_idx = 0;
        int low = 0;
        int high = nums.size() - 1;

        while (true)
        {
            pivot_idx = partition(nums, low, high);

            if (pivot_idx == k - 1)
            {
                break;
            }
            else if (pivot_idx > k - 1)
            {
                high = pivot_idx - 1;
            }
            else
            {
                low = pivot_idx + 1;
            }
        }

        return nums[pivot_idx];
    }
};