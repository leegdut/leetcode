#include <iostream>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode *curA = headA;
        ListNode *curB = headB;
        int A_size = 0;
        int B_size = 0;

        while(curA != NULL)
        {
            A_size++;
            curA = curA->next;
        }


        while(curB != NULL)
        {
            B_size++;
            curB = curB->next;
        }

        curA = A_size>=B_size?headA:headB;
        curB = A_size<B_size?headA:headB;

        int offset = abs(A_size - B_size);

        while(offset != 0)
        {
            curA = curA->next;
            offset--;
        }

        while (curA != curB){
            curA = curA->next;
            curB = curB->next;
        }
        return curA;

//        while(1)
//        {
//            if(curA == NULL || curB == NULL)
//                return NULL;
//            else if(curA->val != curB->val)
//            {
//                curA = curA->next;
//                curB = curB->next;
//            }else {
//                 ListNode * tmp = curA;
//                while(curA->val != curB->val)
//                {
//                    if(curA->next!= NULL)
//                    {
//                        curA = curA->next;
//                        curB = curB->next;
//                    }else {
//                        return tmp;
//                    }
//                }
//            }
//        }
    }
};


int main()
{
    cout << "Hello World!" << endl;

    ListNode *l1  =new ListNode(1);
    l1->next  = new ListNode(2);
    l1->next->next =  new ListNode(4);

    ListNode *l2  =new ListNode(2);
    l2->next  = new ListNode(4);
//    l1->next->next =  new ListNode(4);


    Solution test;
    cout<<test.getIntersectionNode(l1,l2);

    return 0;
}
