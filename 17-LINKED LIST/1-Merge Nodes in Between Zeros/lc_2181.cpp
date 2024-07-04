#include <iostream>
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
    ListNode *mergeNodes(ListNode *head)
    {
        if (!head)
            return NULL;

        if (!head->next)
            return head;

        ListNode *temp = head->next;
        int sum = 0;

        while (temp->val != 0)
        {
            sum += temp->val;
            temp = temp->next;
        }

        ListNode *root = new ListNode(sum);

        if (temp->next != NULL)
        {
            root->next = mergeNodes(temp);
        }
        else
        {
            root->next = NULL;
        }

        return root;
    }
};