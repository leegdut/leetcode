#include <iostream>
#include <vector>
#include <algorithm>


//dp_max[0] = nums[0] , dp_min[0] = nums[0] ,
using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp_max[nums.size()] = {nums[0]};
        int dp_min[nums.size()] = {nums[0]};


        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] >0 )
            {
                dp_max[i] = max(nums[i]*dp_max[i-1],nums[i]);
                dp_min[i] = min(nums[i]*dp_min[i-1],nums[i]);
            }
            else if(nums[i] == 0)
            {
                dp_max[i] = 0;
                dp_min[i] = 0;
            }else {
                dp_max[i] = max(nums[i]*dp_min[i-1],nums[i]);
                dp_min[i] = min(nums[i]*dp_max[i-1],nums[i]);
            }
        }

        int max = *max_element(dp_max,dp_max + sizeof(dp_max)/sizeof(int));
        return max;
//        cout<<"";
    }
};


int main()
{
    cout << "Hello World!" << endl;

    int nums[] = {2,3,-2,4};

    vector<int> veci = {-2,0,-1};

    Solution test;
    cout<<test.maxProduct(veci);
    return 0;
}
