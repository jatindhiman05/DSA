// https://www.geeksforgeeks.org/problems/sort-a-stack/0
#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int element)
{
    if (st.empty() || element > st.top())
    {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    insertSorted(st, element);

    st.push(temp);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, temp);
}