#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions,
                                      vector<int> &healths, string directions)
    {
        vector<pair<int, int>> actual_idx;

        for (int i = 0; i < positions.size(); i++)
        {
            actual_idx.push_back({positions[i], i});
        }

        sort(actual_idx.begin(), actual_idx.end());

        // for(auto &p: actual_idx){
        //     cout<<"{"<<p.first<<","<<p.second<<"}";
        // }

        stack<int> st;

        for (int i = 0; i < actual_idx.size(); i++)
        {
            int curr = actual_idx[i].second;
            if (directions[curr] == 'R')
            {
                st.push(curr);
            }
            else
            {
                while (!st.empty() && healths[curr] > 0)
                {
                    int top = st.top();
                    st.pop();

                    if (healths[top] > healths[curr])
                    {
                        healths[curr] = 0;
                        healths[top]--;
                        st.push(top);
                    }
                    else if (healths[top] < healths[curr])
                    {
                        healths[top] = 0;
                        healths[curr]--;
                    }
                    else
                    {
                        healths[top] = 0;
                        healths[curr] = 0;
                    }
                }
            }
        }

        vector<int> result;

        for (int i = 0; i < healths.size(); i++)
        {
            if (healths[i] > 0)
            {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};