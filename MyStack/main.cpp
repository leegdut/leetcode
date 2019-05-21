#include <iostream>
#include <queue>

using namespace std;

//队列（queue）是一种先入先出的数据结构（FIFO）

//栈（stack）是一种后入先出的数据结构（LIFO）

// push是一样的，pop的话队列是弹最旧，stack是最新那个，用两个队列，将队列的n-1个导出到另外一个队列，最后一个元素就是最旧的元素


class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if(!que1.empty())
            que1.push(x);
        else {
            que2.push(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!que1.empty())
        {
            int que_size = que1.size();
            for(int i =0;i<que_size-1;i++)
            {
                que2.push(que1.front());
                que1.pop();
            }
            int res = que1.front();
            que1.pop();
            return res;
        }else {
            int que_size = que2.size();
            for(int i =0;i<que_size-1;i++)
            {
                que1.push(que2.front());
                que2.pop();
            }
            int res = que2.front();
            que2.pop();
            return res;
        }
    }

    /** Get the top element. */
    int top() {
        if(!que1.empty())
        {
            int que_size = que1.size();
            for(int i =0;i<que_size-1;i++)
            {
                que2.push(que1.front());
                que1.pop();
            }
            int res = que1.front();
            que2.push(que1.front());
            que1.pop();
            return res;
        }else {
            int que_size = que2.size();
            for(int i =0;i<que_size-1;i++)
            {
                que1.push(que2.front());
                que2.pop();
            }
            int res = que2.front();
            que1.push(que2.front());
            que2.pop();
            return res;
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty()&&que2.empty();
        //        if(que1.empty() && que2.empty())
//            return true;
//        else {
//            return false;
//        }
    }
};


int main()
{
    cout << "Hello World!" << endl;

     MyStack obj = new MyStack();
     obj->push(5);
     int param_2 = obj->pop();
     int param_3 = obj->top();
     bool param_4 = obj->empty();

     cout<<"";
    return 0;
}
