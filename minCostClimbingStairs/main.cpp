#include <iostream>
#include <vector>

using namespace std;


//数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。

//每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

//您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。


//输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//输出: 6
//解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。


//求取每个点的最优解，第一级的值为第一级，第二级的值为cost[1] + dp[1] 或 nums[2]，则第三级可以为 第一级的dp 加上第三级的dp 或 第二级的dp + 第三级的值
//则 dp[n] = min ( dp[i-1] + nums[n] , dp[i-2] + nums[n])


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()];
        if(cost.size() < 3)
            return 0;
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i<cost.size();i++)
            dp[i] = min(dp[i-1] + cost[i],dp[i-2] + cost[i]);

        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
