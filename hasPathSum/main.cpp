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
    bool hasPathSum(TreeNode* root, int sum) {
        return getSum(root,0,sum);
    }

    bool getSum(TreeNode* root, int counter,int sum)
    {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == counter + root->val)
                return true;
            else {
                return false;
            }
        }
        counter += root->val;
        return getSum(root->left, counter,sum) || getSum(root->right, counter,sum);
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

    cout<<test.hasPathSum(root1,10);

    return 0;
}
