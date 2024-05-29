// https://www.geeksforgeeks.org/problems/find-unique-element2632/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class solution
{
    int findUnique(int a[], int n, int k)
    {
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            map[a[i]]++;
        }

        int i;
        for (i = 0; i < n; i++)
        {
            if (map[a[i]] % k != 0)
            {
                break;
            }
        }

        return a[i];
    }
};
