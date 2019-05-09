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
    int x_pos = -1;
    int y_pos = -1;
    int x_par = -1;
    int y_par = -1;

    vector<vector<TreeNode*>> total_res;
    bool isCousins(TreeNode* root, int x, int y) {
        traversal(root,x,y,1,root->val);

        if(y_pos == x_pos && x_par != y_par)
            return true;
        else {
            return false;
        }
    }

    void traversal(TreeNode* root, int x, int y,int deep,int parent_val)
    {
        if(root == NULL)
            return;

        if(root->val== x)
        {
            x_pos = deep;
            x_par = parent_val;
        }else if(root->val == y)
        {
            y_pos = deep;
            y_par = parent_val;
        }
        traversal(root->left,x,y,deep+1,root->val);
        traversal(root->right,x,y,deep+1,root->val);
    }

};

int main()
{
    cout << "Hello World!" << endl;

    int num[] = {1,2,3,NULL,4,NULL,5};
    int run =0;
    int counter = 1;
    vector<TreeNode*>res;
    vector<vector<TreeNode*>> total_res;

    TreeNode* root = new TreeNode(1);
    res.push_back(root);
    total_res.push_back(res);
    while(counter < sizeof(num)/sizeof(int))
    {
        vector<TreeNode*> tmp;
//        for(int i=0;i<pow(2,total_res.size());i++)       //before have build n floor,next to build n+1 floor
//        {
            for(int j =0;j < total_res[total_res.size()-1].size();j++)
            {
                TreeNode* tmp_root;
                if(total_res[total_res.size()-1][j] != NULL)
                {
                    if(num[counter] != NULL)
                    {
                        tmp_root = new TreeNode(num[counter]);
                        counter++;
                        tmp.push_back(tmp_root);
                    }
                    else {
                        tmp_root = NULL;
                        counter++;
                        tmp.push_back(tmp_root);
                    }
                    if(num[counter] != NULL)
                    {
                        tmp_root = new TreeNode(num[counter]);
                        counter++;
                        tmp.push_back(tmp_root);
                    }
                    else {
                        tmp_root = NULL;
                        counter++;
                        tmp.push_back(tmp_root);
                    }
                }else{
                     tmp_root = NULL;
                     tmp.push_back(tmp_root);
                     tmp.push_back(tmp_root);
                }

            }

        total_res.push_back(tmp);
    }

    for(int i = 0;i< total_res.size()-1;i++)
    {
         for(int j = 0;j<total_res[i].size();j++)
        {
            if(total_res[i][j] != NULL)
            {
                total_res[i][j]->left = total_res[i+1][j*2];
                total_res[i][j]->right = total_res[i+1][j*2+1];
            }
        }
    }

    Solution test;
    cout<<test.isCousins(root,5,4);

    return 0;
}
