#include <iostream>
#include <vector>
using namespace std;

//dp[0][0] = 0;  //dp[0][n] = 1 dp[0][m] = 1  dp[1][1] = 2    // dp[m][n] = dp[m-1][n] + dp[m][n-1]

class Solution {
public:
    int uniquePaths(int m, int n) {
//        int dp[m][n] = {{0}};
//        for(int i = 0;i<m;i++)
//        {
//            dp[i][0] = 1;
//        }
//        for(int i = 0;i<n;i++)
//        {
//            dp[0][i] = 1;
//        }

        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i = 1;i<m;i++)
        {
            for (int j = 1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
//        cout<<dp[m-1][n-1]<<endl;
        return dp[m-1][n-1];
    }
};

int main()
{
    cout << "Hello World!" << endl;
    Solution test;
    test.uniquePaths(3,7);
    return 0;
}
