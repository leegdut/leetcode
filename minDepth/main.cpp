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
    int min_depth = 1;
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        getDepth(root,1);
        return min_depth;
    }

    void getDepth(TreeNode * r_i ,int depth)
    {
        if(r_i == NULL)
            return;
        if(r_i->left == NULL && r_i->right == NULL)
        {
            if(min_depth>1)
                min_depth = min_depth<depth?min_depth:depth;
            else {
                min_depth = depth;
            }
        }
        if(depth < min_depth || min_depth == 1)
        {
            getDepth(r_i->left,depth+1);
            getDepth(r_i->right,depth+1);
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
    cout<<test.minDepth(root1);
    return 0;
}
