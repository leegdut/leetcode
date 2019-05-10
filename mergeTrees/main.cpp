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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL)
            return t2;
        else if (t2 == NULL) {
            return t1;
        }else {
            t1->val = t1->val + t2->val;
        }
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;

    TreeNode *root1 =new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode *root2 =new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

}
