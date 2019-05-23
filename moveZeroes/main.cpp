#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i =0;i<nums.size()-1;i++)
        {
                if(nums[i] == 0)
                {
                    int j = i+1;
                    while(nums[j]==0 && j < nums.size()-1)
                    {
                        j++;
    //                    if(j == nums.size())
    //                        j = nums.size() - 1;
    //                    break;
                    }
    //                int tmp = nums[i]
                    nums[i] = nums[j];
                    nums[j] = 0;
    //                i = j;
                }
        }
    }
};



int main()
{
    cout << "Hello World!" << endl;

    int nums[] = {0,1,0,3,12};
    Solution test;
    vector<int> veci(nums,nums+sizeof(nums)/sizeof(int));
    test.moveZeroes(veci);

    return 0;
}
