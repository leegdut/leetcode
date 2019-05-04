#include <iostream>
#include <vector>
#include <list>
using namespace std;


//1018. 可被 5 整除的二进制前缀



class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int tmp  = 0;
        for(int i = 0;i<A.size();i++)
        {
            tmp = tmp<<1;
            tmp = tmp + A[i];
            res.push_back(!(tmp%5));
        }
        return res;
    }
};


int main()
{
    cout << "test!" << endl;
    int v[] = {0,1,1};
    vector<int> a(v,v+(sizeof(v)/sizeof(int)));
    Solution test;
    vector<bool> res = test.prefixesDivBy5(a);
    cout << "finish";
    return 0;
}
