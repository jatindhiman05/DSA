// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

// 1st - approach using sorting

#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {

        sort(arr, arr + (r - l + 1));

        return arr[k - 1];
    }
};

// Second approach -> priority queue
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        
        for(int i = 0;i<(r - l + 1);i++){
            pq.push(arr[i]);
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
};