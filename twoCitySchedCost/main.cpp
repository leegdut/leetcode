#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//学习使用sort的第三参数，函数

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        sort(costs.begin(),costs.end(),compp);        //this one is ok try to use lambda
/*        sort(costs.begin(),costs.end(),[](vector<int> A,vector<int> B){        if(A[0]-A[1] < B[0]-B[1])
            {
                return true;
            }
            else {
                return false;
            }}); */                         //format [](parameter){}  no need ;
        for(int i = 0;i<costs.size();i++)
        {
            if(i<costs.size()/2)
                res += costs[i][0];
            else {
                res += costs[i][1];
            }
        }
        return res;
    }

    static bool compp(vector<int> A,vector<int> B)      //have to use static ??
    {
//        if(A[0]-A[1] < B[0]-B[1])
//        {
//            return true;
//        }
//        else {
//            return false;
//        }
        return (A[0]-A[1] < B[0]-B[1]);
    }

};


int main()
{
    cout << "Hello World!" << endl;

    int num[][2]= {{10,20},{30,200},{400,50},{30,20}};
    vector<vector<int>> t_in;
    for(int i =0;i<sizeof(num)/sizeof(int)/2;i++)
    {
        vector<int>in;
        in.push_back(num[i][0]);
        in.push_back(num[i][1]);
        t_in.push_back(in);
    }

    Solution test;
    cout<<"res" <<test.twoCitySchedCost(t_in);
    return 0;
}
