#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
//    static int r;
//    static int c;
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
//        r = r0;
//        c = c0;
        for(int i = 0;i<R;i++)
        {
            for(int j = 0;j<C;j++)
            {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                res.push_back(tmp);
            }
        }
//        sort(res.begin(),res.end(),comp);
        sort(res.begin(),res.end(),[r0,c0](vector<int> A,vector<int> B){            // lambda : [capture list] (params list) mutable exception-> return type { function body }
            return  abs(A[0]-r0) + abs(A[1]-c0) < abs(B[0]-r0) + abs(B[1]-c0);  //capture list：捕获外部变量列表
        });                                                                                 //[=] 意味着，lambda 表达式以传值的形式捕获同范围内的变量。[&] 表明，lambda 表达式以传引用的方式捕获外部变量

        return res;
    }

//    static bool comp(vector<int> A,vector<int> B)
//    {
//        return  (pow(B[0]-r,2) + pow(B[1]-c,2)) - (pow(A[0]-r,2) + pow(A[1]-c,2));
//    }
};

int main()
{
    cout << "Hello World!" << endl;
//    R = 2, C = 3, r0 = 1, c0 = 2
    Solution test;
//    test.allCellsDistOrder(2,3,1,2);
    test.allCellsDistOrder(1,2,0,0);


    return 0;
}
