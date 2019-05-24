#include <iostream>
#include <vector>

using namespace std;


//中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3]

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() ==0 )
            return NULL;

        int root_index = 0;

        while(inorder[root_index] != postorder[postorder.size()-1])
            root_index++;

        vector<int>left_inorder;
        vector<int>right_inorder;
        vector<int>left_postorder;
        vector<int>right_postorder;

        left_inorder.assign(inorder.begin(),inorder.begin()+root_index);
        right_inorder.assign(inorder.begin()+root_index+1,inorder.end());

        left_postorder.assign(postorder.begin(),postorder.begin() + left_inorder.size());
        right_postorder.assign(postorder.begin() + left_inorder.size(),postorder.end()-1);

        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);

        root->left = buildTree(left_inorder,left_postorder);
        root->right = buildTree(right_inorder,right_postorder);

        return root;

//        cout<<"";
    }
};


int main()
{
    cout << "Hello World!" << endl;
    Solution test;
    vector<int>in = {9,3,15,20,7};
    vector<int>post = {9,15,7,20,3};


    test.buildTree(in , post);
    return 0;
}
