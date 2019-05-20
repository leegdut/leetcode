#include <iostream>
#include <unordered_set>

using namespace std;

//set基于红黑树实现，红黑树具有自动排序的功能，因此map内部所有的数据，在任何时候，都是有序的。
//unordered_set基于哈希表，数据插入和查找的时间复杂度很低，几乎是常数时间，而代价是消耗比较多的内存，无自动排序功能。

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * tmp = head;
        unordered_set<ListNode *>record;
        unordered_set<ListNode *>::iterator iter;
        while(tmp != NULL)
        {
            iter = record.find(tmp);
            if(iter != record.end())
                return true;
            else {
                record.insert(tmp);
                tmp = tmp->next;
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello World!" << endl;

    ListNode *l1  =new ListNode(1);
    l1->next  = new ListNode(2);
    l1->next->next =  new ListNode(4);
//    l1->next->next->next = l1;
    Solution test;
    cout<<test.hasCycle(l1);
    return 0;
}
