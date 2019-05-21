#include <iostream>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;

        while (head->val == val) {
            if(head->next != NULL)
                head = head->next;
            else {
                return NULL;
            }
        }
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            if(tmp->next != NULL)
            {
                if(tmp->next->val == val)
                {
                    if(tmp->next->next != NULL)
                        tmp->next = tmp->next->next;
                    else {
                        tmp->next = NULL;
                    }
                }
                else {
                    tmp = tmp->next;
                }
            }else {
                tmp = tmp->next;
            }
        }
        return head;
    }
};

int main()
{
    cout << "Hello World!" << endl;



    TreeNode *root1 =new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    Solution test;
    test.removeElements(root1,2);
    return 0;
}
