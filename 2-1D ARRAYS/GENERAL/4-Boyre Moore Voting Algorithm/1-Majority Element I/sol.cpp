// https://www.naukri.com/code360/problems/majority-element_6783241
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> v)
{
    int count = 0;
    int candidate = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (count == 0)
        {
            candidate = v[i];
        }
        if (v[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return candidate;
}