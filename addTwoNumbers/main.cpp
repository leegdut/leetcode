#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
        vector<int> v2;
        ListNode  * res_l = NULL;
        ListNode * head;
        head = l1;
        while(l1 != NULL)
        {
            v1.push_back(l1->val);
            l1 = l1->next;
//            head = l1->next;
        }
//        head = l2;
        while(l2 != NULL)
        {
            v2.push_back(l2->val);
            l2 = l2->next;
//            head = l2->next;
        }
        long tmp1=0;
        long tmp2=0;
        long tmp3=0;

        for(int i = v1.size()-1;i>=0;i--)
            tmp1 = tmp1 *10 + v1[i];

        for(int i = v2.size()-1;i>=0;i--)
            tmp2 = tmp2 *10 + v2[i];

        tmp3 = tmp1 + tmp2;

//        cout<<tmp3<<endl;
//        v1.clear();

        ListNode *tmp;
        while(1)
        {
            cout<<" "<<endl;
            int res = tmp3%10;
            tmp3 = tmp3/10;
            if(res == 0 && tmp3 == 0)
                break;
//            v1.push_back(res);
            else {
                if(res_l == NULL)
                {
                    res_l = new ListNode(res);
                    tmp = res_l;
                }else {
                    tmp->next = new ListNode(res);
                    tmp = tmp->next;
                }
            }
        }

//        res_l = new ListNode(v1[v1.size()-1]);
//        ListNode *tmp = res_l;
//        for(int i = v1.size() - 2;i>=0;i--)
//        {
//            tmp->next = new ListNode(v1[i]);
//            tmp  = tmp->next;
//        }
        return res_l;
//        cout<<" "<<endl;
    }
};

int main()
{
    cout << "Hello World!" << endl;

    ListNode *l1  =new ListNode(2);
    l1->next  = new ListNode(4);
    l1->next->next =  new ListNode(3);

    ListNode *l2  =new ListNode(5);
    l2->next  = new ListNode(6);
    l2->next->next =  new ListNode(4);

    Solution test;
    test.addTwoNumbers(l1,l2);
    return 0;
}
