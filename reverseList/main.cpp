#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    ListNode *l1  =new ListNode(1);
    l1->next  = new ListNode(2);
    l1->next->next =  new ListNode(4);

    Solution test;
    test.reverseList(l1);

    return 0;
}
