#include <iostream>


using namespace std;

//利用与操作，若一个数n是2的幂次方，则2进制表达式一定为某一位为1，其余为0。则n-1则会变成后面的数全部变成1，原来1的位置变成0

//class Solution {
//public:
//    bool isPowerOfTwo(int n) {
//        if(n== 1)
//            return 1;
//        if(n%2 == 1 || n == 0)
//            return 0;
//        if(n<0)
//        {
//            long long in  = n;
//            return getRes(-in);
//        }
//        else {
//            return getRes(n);
//        }
//    }

//    bool getRes(int n)
//    {
//        int yu = n%2;
//        n = n/2;

//        if(yu == 1)
//            return 0;
//        if( n== 1 && yu ==0)
//            return 1;
//        return getRes(n);
//    }
//};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n== 0 || n == 1)
            return n;
        if(n<=0)
            return 0;
        return (n&(n-1)) == 0;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    Solution test;
    cout<<test.isPowerOfTwo(8);
    return 0;
}
