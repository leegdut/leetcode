#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;

        int max = INT_MIN;
        int tmp = -1;
        for(int i =0;i<nums.size();i++)
        {
            tmp  = nums[i] > tmp + nums[i]?nums[i]: tmp + nums[i];
            max = max>tmp?max:tmp;
        }
        return max;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    int nums[]  = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> veci(nums,nums+sizeof(nums)/sizeof(int));
    Solution test;
    cout<<test.maxSubArray(veci);
    return 0;
}
