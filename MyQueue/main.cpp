#include <iostream>
#include <stack>

using namespace std;


class MyQueue {
public:

    stack<int> stack1;
    stack<int> stack2;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if(!stack1.empty())
        {
            stack2.push(x);
            int len = stack1.size();
            for(int i = 0;i<len;i++)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        else {
            stack1.push(x);
            int len = stack2.size();
            for(int i = 0;i<len;i++)
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!stack1.empty())
            stack1.pop();
        else {
            stack2.pop();
        }
        return NULL;
    }

    /** Get the front element. */
    int peek() {
        if(!stack1.empty())
            return stack1.top();
        else {
            return stack2.top();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
