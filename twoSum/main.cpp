#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> record;
        vector<int> res;
        map<int,int>::iterator iter;
        for(int i = 0;i<nums.size();i++)
        {
            iter = record.find(target-nums[i]);
            if(iter != record.end())
            {
                res.push_back(iter->second);
                res.push_back(i);
                return res;
            }else {
                record[nums[i]] = i;
            }
        }
        return res;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    int nums[] = {2, 7, 11, 15};

    vector<int> vec_in(nums,nums + sizeof(nums)/sizeof(int));

    Solution test;
    cout<<test.twoSum(vec_in,9)[0]<<" "<< test.twoSum(vec_in,9)[1];
    return 0;
}
