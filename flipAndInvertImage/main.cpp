#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i =0;i<A.size();i++)
        {
            reverse(A[i].begin(),A[i].end());
            for(int j = 0;j<A[i].size();j++)
            {
                A[i][j] = 1- A[i][j];
            }
        }
        return A;
//        cout<<""<<endl;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    int num[][4] = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    int size = sizeof(num)/sizeof(int)/4;
    vector<vector<int>>in;
    for(int i = 0;i<size;i++)
    {
        vector<int> tmp(num[i],num[i]+4);
        in.push_back(tmp);
    }
    Solution test;
    test.flipAndInvertImage(in);
    return 0;
}
