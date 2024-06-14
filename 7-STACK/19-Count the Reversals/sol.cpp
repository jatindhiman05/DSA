// https://www.geeksforgeeks.org/problems/count-the-reversals0401/1
#include<iostream>
#include<stack>
using namespace std;

int countRev (string s)
{
    // if odd sized string then impossible to make string
    int n = s.length();
    
    if(n%2 != 0) return -1;
    
    int count = 0;
    stack<char> st;
    
    for(char &ch: s){
        if(ch == '{'){
            st.push(ch);
        }else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }
    
    // if stack is not empty, lets count reversals
    
    while(!st.empty()){
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        
        if(a == b){
            count += 1;
        }else{
            count += 2;
        }
    }
    
    return count;
}