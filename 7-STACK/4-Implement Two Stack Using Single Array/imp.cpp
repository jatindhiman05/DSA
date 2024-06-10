#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size)
    {
        this->size = size;
        this->arr = new int[size];

        this->top1 = -1;
        this->top2 = size;
    }
    void push1(int data)
    {
        top1++;
        if (abs(top2 - top1) == 1)
        {
            cout << "Stack OverFlow!" << endl;
            return;
        }

        arr[top1] = data;
    }
    void push2(int data)
    {
        top2--;
        if (abs(top2 - top1) == 1)
        {
            cout << "Stack OverFlow!" << endl;
            return;
        }

        arr[top2] = data;
    }
    void pop1()
    {
        if (arr[top1] == -1)
        {
            cout << "Stack underFlow!" << endl;
            return;
        }
        arr[top1] = 0;
        top1--;
    }
    void pop2()
    {
        if (arr[top2] == size)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        arr[top2] = 0;
        top2++;
    }
    int getTop1()
    {
        return arr[top1];
    }
    int getTop2()
    {
        return arr[top1];
    }
};