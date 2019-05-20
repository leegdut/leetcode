#include <iostream>
#include <vector>
using namespace std;


//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> res;
//        for(int i =0;i<numRows;i++)
//        {
//            if(i <2)
//            {
//                vector<int>  tmp;
//                for(int j =0;j<i+1;j++)
//                {
//                    tmp.push_back(1);
//                }
////                res.insert(res.begin(),tmp);
//                res.push_back(tmp);
//            }else {
//                vector<int>  tmp;
//                tmp.push_back(1);
//                for(int j =1;j<i;j++)
//                {
//                    tmp.push_back(res[i-1][j-1] + res[i-1][j]);
//                }
//                tmp.push_back(1);
////                res.insert(res.begin(),tmp);
//                res.push_back(tmp);
//            }
//        }
//        return res;
//    }
//};



class Solution {
public:
    vector<int> getRow(int rowIndex) {
                vector<vector<int>> res;
                for(int i =0;i<=rowIndex;i++)
                {
                    if(i <2)
                    {
                        vector<int>  tmp;
                        for(int j =0;j<i+1;j++)
                        {
                            tmp.push_back(1);
                        }
        //                res.insert(res.begin(),tmp);
                        res.push_back(tmp);
                    }else {
                        vector<int>  tmp;
                        tmp.push_back(1);
                        for(int j =1;j<i;j++)
                        {
                            tmp.push_back(res[i-1][j-1] + res[i-1][j]);
                        }
                        tmp.push_back(1);
        //                res.insert(res.begin(),tmp);
                        res.push_back(tmp);
                    }
                }
                return res[rowIndex];
    }
};

int main()
{
    cout << "Hello World!" << endl;

    Solution test;
    test.generate(5);
    return 0;
}
