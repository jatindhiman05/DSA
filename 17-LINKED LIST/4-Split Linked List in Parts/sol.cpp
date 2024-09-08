#include<iostream>
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
    int getLen(ListNode *head)
    {
        ListNode *it = head;
        int len = 0;
        while (it)
        {
            len++;
            it = it->next;
        }
        return len;
    }

public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int len = getLen(head);
        int totalSets = len / k;
        int remainNodes = len % k;

        vector<ListNode *> result(k, NULL);
        ListNode *curr = head;
        ListNode *prev = NULL;
        int i = 0;

        while (curr && i < k)
        {
            result[i] = curr;
            int count = 1;
            while (count <= totalSets + (remainNodes > 0 ? 1 : 0))
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            prev->next = NULL;
            remainNodes--;
            i++;
        }

        return result;
    }
};
