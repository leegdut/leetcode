#include <iostream>
#include <vector>

using namespace std;


//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

//说明：每次只能向下或者向右移动一步。

//示例:

//输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7


//dp[0][n] = dp[0][n-1] + nums[n]  dp[m][n] = min(dp[m-1][n],dp[m][n-1]) + nums[m][n];

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for(int i =1;i<dp.size();i++)
        {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int i =1;i<dp[0].size();i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for(int i = 1;i<dp.size();i++)
        {
            for(int j = 1;j<dp[0].size();j++)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
//        cout<<""<<endl;
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main()
{
    cout << "Hello World!" << endl;
    vector<vector<int>>veci = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
      };


    Solution test;
    test.minPathSum(veci);

    return 0;
}
