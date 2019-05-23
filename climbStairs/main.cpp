#include <iostream>
#include <math.h>

using namespace std;


//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

//第一级楼梯是1，第二级是 1+1 或2；
//第n级可以是第n-1级+1 或者 第n-2级 +2，所以 第n级的方法为n-1级 与 n-2级的方法和则 dp[n] = dp[n-1] + dp[n-2]



class Solution {
public:
    int climbStairs(int n) {

        if(n <3)
            return n;

        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        for(int i =2;i<n;i++)
        {
            dp[i] = dp[i-2] + dp[i-1];
        }

        return dp[n-1];

    }
};

int main()
{
    cout << "Hello World!" << endl;
    Solution test;
    cout<<test.climbStairs(3);
    return 0;
}
