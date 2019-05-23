#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();

        vector<vector<unsigned long long>> dp(m,vector<unsigned long long>(n,1));

        for(int i =0;i<m;i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                for(int j =i;j<m;j++)
                {
                    dp[j][0] = 0;
                }
            }
//                dp[i][0] = 0;
        }

        for(int i =0;i<n;i++)
        {
            if(obstacleGrid[0][i] == 1)
            {
                for(int j =i;j<n;j++)
                {
                    dp[0][j] = 0;
                }
            }
//                dp[i][0] = 0;
        }

        for(int i = 1;i<m;i++)
        {
            for (int j = 1;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
//        cout<<dp[m-1][n-1]<<endl;
        return dp[m-1][n-1];
    }
};

int main()
{
    cout << "Hello World!" << endl;
    int nums[][3] = {
            {0,0,0},
            {0,1,0},
            {0,0,0}
          };


    Solution test;

    vector<vector<int>>veci = {
        {1}
//        {0,1,0},
//        {0,0,0}
      };
//    for(int i = 0;i<3;i++)
//    {
//        vector<int>tmp(nums + i*3,nums+i*3 + sizeof(nums)/sizeof(int)/3);
//        veci.push_back(tmp);
//    }
    test.uniquePathsWithObstacles(veci);
    return 0;
}
