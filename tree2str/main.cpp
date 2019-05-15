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
    string tree2str(TreeNode* t) {
        string tmp = "";
        if(t == NULL)
            return "";
        tmp += to_string(t->val);
//        cout<<tmp<<endl;
        if (t->left != NULL && t->right != NULL) {
            tmp += "(" + tree2str(t->left)+")";
            tmp += "(" + tree2str(t->right)+")";
        }else if (t->left != NULL) {
            tmp += "(" + tree2str(t->left)+")";
        }else if (t->right != NULL) {
            if(t->left == NULL)
                tmp += "()(" + tree2str(t->right)+ ")";
            else {
                tmp += "(" + tree2str(t->right)+")";
            }
        }
//        cout<<tmp;
        return tmp;
    }
};

int main()
{
    cout << "Hello World!" << endl;


    TreeNode *root1 =new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);

    Solution test;
    cout<<test.tree2str(root1);

    return 0;
}
