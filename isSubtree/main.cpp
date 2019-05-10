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
//    TreeNode* sameRoot;
    bool same_flag = 1;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t== NULL)
            return true;
        else if (s==NULL || t ==NULL) {
            return false;
        }
        if(isEqual(s,t))
            return true;

        return isSubtree(s->left,t)||isSubtree(s->right,t);

    }
    bool isEqual(TreeNode* s,TreeNode* t)
    {
        if(s == NULL && t == NULL)
            return true;
        else if (s==NULL || t == NULL) {
            return false;
        }
        if(s->val == t->val)
        {
            return isEqual(s->left,t->left)&& isEqual(s->right,t->right);
        }else {
            return false;
        }
    }

};


int main()
{
    cout << "Hello World!" << endl;

    TreeNode *root1 =new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);

    TreeNode *root2 =new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);

    return 0;
}
