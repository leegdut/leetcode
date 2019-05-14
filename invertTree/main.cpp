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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        else {
            TreeNode * tmp;
            tmp  = root->left;
            root->left = root->right;
            root->right = tmp;

            invertTree(root->left);
            invertTree(root->right);
            return root;
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
    test.invertTree(root1);


    return 0;
}
