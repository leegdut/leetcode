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
    int max_depth = 1;
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        getDepth(root,1);
        return max_depth;
    }

    void getDepth(TreeNode* r_i,int depth)
    {
        if(r_i == NULL)
            return;
        max_depth = depth > max_depth?depth:max_depth;
        getDepth(r_i->left,depth +1);
        getDepth(r_i->right,depth +1);
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
    cout<<test.maxDepth(root1)<<endl;;

    return 0;
}
