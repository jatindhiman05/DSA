// https://www.geeksforgeeks.org/problems/help-classmates--141631/1
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int> result(n);
        stack<int> st;
        st.push(-1);
        
        for(int i = n-1;i>=0;i--){
            int curr = arr[i];
            
            while(st.top() >= curr){
                st.pop();
            }
            
            result[i] = st.top();
            
            st.push(curr);
        }
        
        return result;
    } 
};