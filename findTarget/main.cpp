#include <iostream>
#include <set>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> record;
        get_record(root,record);

        for(set<int>::iterator iter = record.begin();iter != record.end();iter++)
        {
            set<int>::iterator iter2 = iter;
            for(++iter2;iter2 != record.end();iter2++)
            {
                if(*iter + *iter2 == k)
                    return true;
                else if (*iter + *iter2 > k) {
                    break;
                }
            }
        }
        return false;
    }

    void get_record(TreeNode* root1 , set<int> & rec)
    {
        if(root1 == NULL)
            return;
        rec.insert(root1->val);
        get_record(root1->left,rec);
        get_record(root1->right,rec);
    }
};

int main()
{
    cout << "Hello World!" << endl;

    TreeNode *root1 =new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);

    Solution test;
    cout<<test.findTarget(root1,30);
    return 0;
}
