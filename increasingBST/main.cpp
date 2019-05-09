#include <iostream>
#include <math.h>
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
    vector<TreeNode *> res;

    TreeNode* increasingBST(TreeNode* root) {
        inordertra(root);
    for(int i = 0;i<res.size()-1;i++)
    {
        res[i]->left = NULL;
        res[i]->right = res[i+1];
    }
        res[res.size()-1]->left=NULL;
        res[res.size()-1]->right = NULL;
//        return res;
        return res[0];
}

    TreeNode* inordertra(TreeNode* root) {
    if(root == NULL)
        return NULL;

     inordertra(root->left);      //keep run to lefest the output the root
//     cout<<"  "<<root->val<<endl;
     res.push_back(root);
     inordertra(root->right);
     return NULL;
    }


};


int main()
{
    cout << "Hello World!" << endl;
    int num[] = {5,3,6,2,4,NULL,8,1,NULL,NULL,NULL,7,9};
    int run =0;
    int counter = 1;
    vector<TreeNode*>res;
    vector<vector<TreeNode*>> total_res;

    TreeNode* root = new TreeNode(5);
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
    test.increasingBST(root);

    return 0;
}
