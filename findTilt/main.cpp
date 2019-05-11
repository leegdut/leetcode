#include <iostream>

using namespace std;


using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    int sum = 0;
    int findTilt(TreeNode* root) {
        if(root == NULL)
            return sum;

        if(root->left  == NULL && root->right == NULL)
        {

        }
        else if (root->left  == NULL || root->right == NULL) {
            if(root->left  == NULL)
                sum += root->right->val;
            else {
                sum += root->left->val;
            }
        }else{
            sum += abs(root->right->val - root->left->val);
        }
        findTilt(root->left);
        findTilt(root->right);

        return sum;
    }
};




class Solution {
public:
    int ans=0;
    int findTilt(TreeNode* root) {
        count(root);
        return ans;
    }
    int count(TreeNode* root) {//返回当前分支的节点之和
        if(root==NULL) return 0;
        int l=count(root->left), r=count(root->right);
        ans+=abs(l-r);
        return l+r+root->val;
    }
};      //dont know


int main()
{
    cout << "Hello World!" << endl;

    TreeNode *root1 =new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
//    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(5);


    Solution test;
    cout<<test.findTilt(root1);

    return 0;
}
