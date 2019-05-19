#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       queue< TreeNode*> que;
       vector<vector<int>> res;
       if(root == NULL)
           return res;
       que.push(root);
       while(!que.empty())
       {
            int que_size = que.size();
            vector<int> tmp;
            for(int i = 0;i<que_size;i++)
            {
                tmp.push_back(que.front()->val);
                if(que.front()->left!= NULL)
                    que.push(que.front()->left);
                if(que.front()->right!= NULL)
                    que.push(que.front()->right);
                que.pop();
            }
            res.insert(res.begin(),tmp);
       }
       return res;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
