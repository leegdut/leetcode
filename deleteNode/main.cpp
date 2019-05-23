#include <iostream>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main()
{
    cout << "Hello World!" << endl;

    ListNode *l1  =new ListNode(1);
    l1->next  = new ListNode(2);
    l1->next->next =  new ListNode(4);
    l1->next->next->next =  new ListNode(3);

//    l1->next->next->next = l1;
    return 0;
}
