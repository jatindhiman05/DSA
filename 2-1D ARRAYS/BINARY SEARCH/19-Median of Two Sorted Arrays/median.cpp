#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n) -> Space
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> temp(nums1.size() + nums2.size());

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                temp[k++] = nums1[i++];
            }
            else
            {
                temp[k++] = nums2[j++];
            }
        }

        while (i < nums1.size())
        {
            temp[k++] = nums1[i++];
        }

        while (j < nums2.size())
        {
            temp[k++] = nums2[j++];
        }

        if (temp.size() % 2 == 0)
        {
            int nby2 = temp.size() / 2;
            int nby2minus1 = (temp.size() / 2) - 1;

            return (temp[nby2] + temp[nby2minus1]) / 2.0;
        }
        else
        {
            return temp[temp.size() / 2];
        }

        return 0.0;
    }
};

// O(1) -> Space
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0;
        int j = 0;
        int size = nums1.size() + nums2.size();
        int k = 0;
        int n_by_2 = size / 2;
        int elem1 = -1;
        int n_by_2_minus_1 = (size / 2) - 1;
        int elem2 = -1;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                if (k == n_by_2)
                {
                    elem1 = nums1[i];
                }
                if (k == n_by_2_minus_1)
                {
                    elem2 = nums1[i];
                }
                i++;
            }
            else
            {
                if (k == n_by_2)
                {
                    elem1 = nums2[j];
                }
                if (k == n_by_2_minus_1)
                {
                    elem2 = nums2[j];
                }
                j++;
            }
            k++;
        }

        while (i < nums1.size())
        {
            if (k == n_by_2)
            {
                elem1 = nums1[i];
            }
            if (k == n_by_2_minus_1)
            {
                elem2 = nums1[i];
            }
            i++;
            k++;
        }

        while (j < nums2.size())
        {
            if (k == n_by_2)
            {
                elem1 = nums2[j];
            }
            if (k == n_by_2_minus_1)
            {
                elem2 = nums2[j];
            }
            j++;
            k++;
        }

        if (size % 2 == 0)
        {
            return (elem1 + elem2) / 2.0;
        }

        return elem1;
    }
};