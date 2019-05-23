#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;


//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

//示例 1:

//输入: [2,3,2]
//输出: 3
//解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。



//普通节点，dp[n] = max(dp[n-1],dp[n-2] + nums[n])
//头尾节点
//分两种情况，开始时就决定偷第一件房子，不偷的话，dp[0] = 0，dp[last] = max(dp[last*-1],dp[last2]+nums[last]；//偷的话dp[0] = nums[0] ,dp[last] = dp[last-1];


class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        if(nums.size()<3)
            return *max_element(nums.begin(),nums.end());

        int dp_rob[nums.size()];
        int dp_no_rob[nums.size()];

        dp_rob[0] = nums[0];
        dp_rob[1] = dp_rob[0];

        dp_no_rob[0] = 0;
        dp_no_rob[1] = nums[1];

        for(int i = 2;i<nums.size()-1;i++)
        {
            dp_rob[i] = max(dp_rob[i-1],dp_rob[i-2] + nums[i]);
            dp_no_rob[i] = max(dp_no_rob[i-1],dp_no_rob[i-2] + nums[i]);
        }

        dp_rob[nums.size()-1] = dp_rob[nums.size()-2];
        dp_no_rob[nums.size()-1] = max(dp_no_rob[nums.size()-1-1],dp_no_rob[nums.size()-1-2] + nums[nums.size()-1]);
        int max = *max_element(dp_rob,dp_rob + sizeof(dp_rob)/sizeof(int));
        int max_2 = *max_element(dp_no_rob,dp_no_rob + sizeof(dp_no_rob)/sizeof(int));

        max = max>max_2?max:max_2;

        return max;
//        cout<<"";
    }
};

int main()
{
    cout << "Hello World!" << endl;



    vector<int> veci = {2,3,2};


    Solution test;
    cout<<test.rob(veci);


    return 0;
}

