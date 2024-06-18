#include <iostream>
using namespace std;

class queue
{
    int *arr;
    int size;
    int rear;
    int front;

public:
    queue(int sizz)
    {
        this->size = size;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    void push(int val)
    {
        if (rear == size - 1)
        {
            cout << "OverFlow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            rear++;
            front++;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Under flow" << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
