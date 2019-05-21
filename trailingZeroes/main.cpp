#include <iostream>

using namespace std;


//给定一个整数 n，返回 n! 结果尾数中零的数量。

//示例 1:

//输入: 3
//输出: 0
//解释: 3! = 6, 尾数中没有零。
//示例 2:

//输入: 5
//输出: 1
//解释: 5! = 120, 尾数中有 1 个零.

//末尾为0 则为5*2，阶乘里面 4== 2*2；所以2肯定比5多，数5的个数即可


class Solution {
public:
    int trailingZeroes(int n) {

        if(n<5)
            return 0;
        return n/5 + trailingZeroes(n/5);

    }
};


//class Solution {
//public:
//    int trailingZeroes(int n) {
////        cout<<factorial(5)<<endl;;
//        long long tmp = factorial(n);
//        string str = to_string(tmp);
//        int res = 0;
//        cout<<str<<endl;
//        for(int i = 0;i<str.length();i++)
//        {
//           if(str[i]== '0')
//               res++;
//        }
//        return res;
//    }

//    long long factorial(int n)
//    {
//        if(n == 1)
//            return 1;
//        else if(n == 0)
//            return 0;
//        return n * factorial(n-1);
//    }

//};


int main()
{
    cout << "Hello World!" << endl;

    Solution test;
    cout<<test.trailingZeroes(13);
    return 0;
}
