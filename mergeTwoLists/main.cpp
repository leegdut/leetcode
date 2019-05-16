#include <iostream>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* now_l = l;
        ListNode* now_l1 = l1;
        ListNode* now_l2 = l2;

        if(l1 == NULL)
        {
            return l2;
        }else if (l2 == NULL) {
            return l1;
        }

        while(now_l1 != NULL || now_l2 != NULL)
        {
            if(now_l1 == NULL)
            {
                now_l->next = now_l2;
                now_l = now_l->next;
                now_l2 = now_l2->next;
            }else if (now_l2 == NULL) {
                now_l->next =now_l1;
                now_l =now_l->next;
                now_l1 = now_l1->next;
            }else {
                if(now_l1->val<now_l2->val)
                {
                    now_l->next =now_l1;
                    now_l =now_l->next;
                    now_l1 = now_l1->next;
                }else {
                    now_l->next = now_l2;
                    now_l = now_l->next;
                    now_l2 = now_l2->next;
                }
            }
        }

        return l->next;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    ListNode *l1  =new ListNode(1);
    l1->next  = new ListNode(2);
    l1->next->next =  new ListNode(4);

    ListNode *l2  =new ListNode(1);
    l2->next  = new ListNode(3);
    l2->next->next =  new ListNode(4);

    Solution test;
    test.mergeTwoLists(l1,l2);


    return 0;
}
