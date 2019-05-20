#include <iostream>
#include <stack>

using namespace std;

//stack last in first out
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>record;


    MinStack() {

    }

    void push(int x) {
        record.push(x);
    }

    void pop() {
        record.pop();
    }

    int top() {
        return record.top();
    }

    int getMin() {
        stack<int>tmp(record);
        int min  = tmp.top();
        for(int i = 0;i<record.size();i++)
        {
            min = min < tmp.top()?min:tmp.top();
            tmp.pop();
        }
        return min;
    }
};



int main()
{
    cout << "Hello World!" << endl;

    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout<<minStack->getMin()<<endl;;  /* --> 返回 -3.*/
    minStack->pop();
    cout<<minStack->top()<<endl;     /* --> 返回 0.*/
    cout<<minStack->getMin()<<endl;  /* --> 返回 -2.*/
    return 0;
}
