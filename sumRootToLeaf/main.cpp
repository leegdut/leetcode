#include <iostream>
#include <vector>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    string s = "";
    int ans = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        s += root->val + '0';
        dfs(root);
        return ans;
    }

    void dfs(TreeNode * root)
    {
        if(root->left == NULL && root->right ==NULL)
        {
            int tmp = 0;
            for(int i = 0;i<s.size();i++)
            {
                   tmp = tmp*2 + s[i]-'0';
            }
            ans += tmp;
        }

        if(root->left)
        {
            s += root->left->val +'0';
            dfs(root->left);
            s.pop_back();       //delete left then run next round
        }
        if(root->right)
        {
             s += root->right->val + '0';
             dfs(root->right);
             s.pop_back();
        }
    }
};



int main()
{
    cout << "Hello World!" << endl;


    TreeNode *root =new TreeNode(1);
    TreeNode *l1 =new TreeNode(0);
    TreeNode *r1 =new TreeNode(1);
    TreeNode *l11 =new TreeNode(0);
    TreeNode *l12 =new TreeNode(1);
    TreeNode *r11 =new TreeNode(0);
    TreeNode *r12 =new TreeNode(1);


    root->left = l1;
    root->right = r1;
    l1->left = l11;
    l1->right = l12;
    r1->right = r11;
    r1->right = r12;

    Solution test;
    cout<<test.sumRootToLeaf(root);

//    cout<<" r  "<<root->val<<" l "<<root->left->val<<" r "<<root->right->val<<" l11 "<< root->left->left->val<<endl;

    return 0;
}
