#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i =0; i<nums.size();i++)
        {
            if(nums[i]== target)
                return i;
            else if (nums[i]<target) {
                if(i==(nums.size()-1))
                {
//                    nums.push_back(target);
                    return i+1;
                }else if (nums[i+1]>target) {
                    return i+1;
                }
            }
        }
        return 0;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    Solution test;
    int nums[] = {1,3,5,6};
    vector<int> veci(nums,nums+sizeof(nums)/sizeof(int));

    test.searchInsert(veci,2);
    return 0;
}
