#include <iostream>
#include <vector>
using namespace std;


//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。


//等同于去到每间房子时的最优值，每间房子只有偷和不偷两种情况，如果偷了，得到的钱就是本房子的钱+ n-2房子时的最优解，如果不偷，得到的钱就是n-1房子的最优解，所以n 房子的最优解就是 偷和不偷的最大值


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() ==1){
            return nums[0];
        }
        else if (nums.size() == 2) {
            return max(nums[0],nums[1]);
        }

        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = nums[0]>nums[1]?nums[0]:nums[1];
        for(int i = 2;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
    }
};


int main()
{
    cout << "Hello World!" << endl;
    int nums[]  = {2,7,9,3,1};
    return 0;
}
