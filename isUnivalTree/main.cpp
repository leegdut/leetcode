#include <iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
//    bool res = 1;
public:
    bool isUnivalTree(TreeNode* root) {
       return traversal(root,root->val);
//        return res;
    }

    bool traversal(TreeNode * root,int val)
    {
        if(root == NULL)
            return true;
        if(root->val == val)
        {
            return traversal(root->left,val)&&traversal(root->right,val);
;
        }else {
            return false;
        }
    }
};



int main()
{
    cout << "Hello World!" << endl;
    TreeNode *root =new TreeNode(1);
    TreeNode *l1 =new TreeNode(1);
    TreeNode *r1 =new TreeNode(1);
    TreeNode *l11 =new TreeNode(1);
    TreeNode *l12 =new TreeNode(1);
    TreeNode *r11 =new TreeNode(1);
    TreeNode *r12 =new TreeNode(1);


    root->left = l1;
    root->right = r1;
    l1->left = l11;
    l1->right = l12;
    r1->right = r11;
    r1->right = r12;

    Solution test;
    cout<<test.isUnivalTree(root);
    return 0;
}
