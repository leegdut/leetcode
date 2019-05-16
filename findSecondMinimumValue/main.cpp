#include <iostream>
#include<set>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> res;
        getSet(root,res);
        if(res.size()<2)
            return -1;
        else {
            set<int>::iterator iter = res.begin();
//            iter--;
            return *(++iter);
        }
    }

    void getSet(TreeNode* r,set<int> & set_in)
    {
        if(r == NULL)
            return;
        set_in.insert(r->val);
        getSet(r->left,set_in);
        getSet(r->right,set_in);
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

    cout<<test.findSecondMinimumValue(root1);
    return 0;
}
