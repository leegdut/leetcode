#include <iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return 1;
        return isMirror(root->left,root->right);
    }

    bool isMirror(TreeNode* root1,TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if (root1 == NULL || root2 == NULL) {
            return false;
        }else if(root1->val == root2->val){
            return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
        }else {
            return false;
        }
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
    cout<<test.isSymmetric(root1);

    return 0;
}
