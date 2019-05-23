#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for(int i = 0;i<triangle.size();i++)
            {
            vector<int> tmp(i+1);
            dp.push_back(tmp);
        }
        dp[0][0] = triangle[0][0];

        for(int i = 1;i<triangle.size();i++)
        {
            for(int j = 0;j<triangle[i].size();j++)
            {
                if(j == 0)
                    dp[i][j] = dp[i-1][j]+ triangle[i][j];
                else if(j == triangle[i].size() - 1)
                    dp[i][j] = dp[i-1][triangle[i-1].size() - 1]+ triangle[i][j];
                else {
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+ triangle[i][j];
                }
            }
        }
        int min = *min_element(dp[triangle.size()-1].begin(),dp[triangle.size()-1].end());
//        cout<<""<<min<<endl;
        return min;
    }
};

int main()
{
    cout << "Hello World!" << endl;

    vector<vector<int>>veci = {
            {2},
           {3,4},
          {6,5,7},
         {4,1,8,3}
       };
    Solution test;
    test.minimumTotal(veci);

    return 0;
}
