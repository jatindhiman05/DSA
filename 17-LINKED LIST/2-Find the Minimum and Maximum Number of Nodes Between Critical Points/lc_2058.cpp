// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        // not possible to have critical point with less than 3 nodes
        if (!head || !head->next || !head->next->next)
        {
            return {-1, -1};
        }

        ListNode *prev = head;
        ListNode *current = head->next;
        ListNode *forward = current->next;

        vector<int> criticalNodesNum;
        int count = 1;

        while (forward)
        {
            count++;
            if ((current->val > prev->val && current->val > forward->val) ||
                (current->val < prev->val && current->val < forward->val))
            {
                criticalNodesNum.push_back(count);
            }
            prev = current;
            current = forward;
            forward = forward->next;
        }

        if (criticalNodesNum.size() == 0 || criticalNodesNum.size() == 1)
        {
            return {-1, -1};
        }

        int maxi = criticalNodesNum.back() - criticalNodesNum.front();
        int mini = INT_MAX;

        for (int i = 0; i < criticalNodesNum.size() - 1; i++)
        {
            mini = min(mini, criticalNodesNum[i + 1] - criticalNodesNum[i]);
        }

        return {mini, maxi};
    }
};
