#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> record;

        ListNode* tmp = head;
        while(tmp != NULL)
        {
            record.push(tmp);
            tmp = tmp->next;
        }

        int len = record.size();
        tmp = head;
        for(int i =0;i<len/2;i++)
        {
            if(tmp->val != record.top()->val)
                return false;
            tmp = tmp->next;
            record.pop();
        }
        return true;
    }
};

int main()
{
    cout << "Hello World!" << endl;


    ListNode *l1  =new ListNode(1);
    l1->next  = new ListNode(2);
//    l1->next->next =  new ListNode(2);
//    l1->next->next->next =  new ListNode(1);

    Solution test;
    cout<<test.isPalindrome(l1);
    return 0;
}
