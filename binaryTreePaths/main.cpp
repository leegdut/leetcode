#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>  res;
        string str = "";
        findPath(root,res,str);
        return res;
    }

    void findPath(TreeNode* root,vector<string> & v,string str)
    {
        if(root == NULL)
            return;
        else if(root->left == NULL && root->right == NULL)
        {
            str  = str + to_string (root->val);
            v.push_back(str);
        }else {
            str = str + to_string (root->val) +  "->" ;
            findPath(root->left,v,str);
            findPath(root->right,v,str);
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
    test.binaryTreePaths(root1);

    return 0;
}
