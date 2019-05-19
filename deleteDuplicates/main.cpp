#include <iostream>
#include <set>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int>record;
        ListNode * now = head;
        ListNode * prev = head;
        while(now != NULL)
        {
            set<int>::iterator iter=  record.find(now->val);
            if(iter != record.end())    //find val
            {
//                cout<<"hh"<<endl;
                prev->next = now->next;
                now = now->next;
            }else {     //not find val
//            cout<<"vv"<<endl;
                record.insert(now->val);
                prev = now;
                now = now->next;
            }
        }
        return head;
    }
};

int main()
{
    cout << "Hello World!" << endl;

//    1->1->2->3->3;
    ListNode *l = new ListNode(1);
    l->next = new ListNode(1);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(3);

    Solution test;
    test.deleteDuplicates(l);

    return 0;
}
