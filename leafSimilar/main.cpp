#include <iostream>
#include <list>


using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       list<TreeNode*> l1,l2;
        traverse(root1,l1);
        traverse(root2,l2);
        if(l1.size() != l2.size())
            return false;
        else {
            list<TreeNode*>::iterator iter = l1.begin();
            list<TreeNode*>::iterator iter2 = l2.begin();

            for(;iter != l1.end();iter++,iter2++)
            {
                if((*iter)->val != (*iter2)->val)
                    return false;
            }
        }
        return true;
    }
    void traverse(TreeNode * root , list<TreeNode*> & list_in)
    {
        if(root == NULL)
            return;
        else if (root->left == NULL && root->right ==NULL) {
            list_in.push_back(root);
        }else {
            traverse(root->left,list_in);
            traverse(root->right,list_in);
        }
    }
};


int main()
{
    cout << "Hello World!" << endl;
    Solution test;

    TreeNode *root1 =new TreeNode(1);
    root1->left = new TreeNode(2);
//    root1->right = new TreeNode(5);
//    root1->left->left = new TreeNode(1);
//    root1->left->right = new TreeNode(2);

    TreeNode *root2=new TreeNode(1);
    root2->right = new TreeNode(2);

    cout<<test.leafSimilar(root1,root2);

    return 0;
}
