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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if (p== NULL || q == NULL) {
            return false;
        }

        if(p->val != q->val)
            return false;

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

int main()
{
    cout << "Hello World!" << endl;

    TreeNode *root1 =new TreeNode(1);
    root1->left = new TreeNode(2);
//    root1->right = new TreeNode(5);
//    root1->left->left = new TreeNode(1);
//    root1->left->right = new TreeNode(2);

    TreeNode *root2=new TreeNode(1);
    root2->right = new TreeNode(2);

    Solution test;
    test.isSameTree(root1,root2);

    return 0;
}
