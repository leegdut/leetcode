#include <iostream>
#include <vector>

using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




//前序遍历 preorder = [3,9,20,15,7]     root left right
//中序遍历 inorder = [9,3,15,20,7]      left root left    ->   left tree,

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return NULL;

        vector<int>left_tree_pre;
        vector<int>right_tree_pre;
        vector<int>left_tree_in;
        vector<int>right_tree_in;

        int root_index = 0;
        while(inorder[root_index] != preorder[0])
        {
            root_index++;
        }

        left_tree_in.assign(inorder.begin(),inorder.begin()+root_index);
        right_tree_in.assign(inorder.begin()+root_index+1,inorder.end());

        left_tree_pre.assign(preorder.begin()+1,preorder.begin()+1+left_tree_in.size());
        right_tree_pre.assign(preorder.begin()+left_tree_in.size()+1,preorder.end());


        TreeNode* root = new TreeNode(preorder[0]);
        root->left = buildTree(left_tree_pre,left_tree_in);

        root->right = buildTree(right_tree_pre,right_tree_in);

        return root;
    }
};

int main()
{
    cout << "Hello World!" << endl;



    TreeNode *root1 =new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
//    root1->left->left = new TreeNode(3);
//    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};
    Solution test;
    test.buildTree(preorder,inorder);


    return 0;
}
