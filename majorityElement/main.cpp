#include <iostream>
#include <vector>
#include<map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>record;
        for(int i =0;i<nums.size();i++)
            record[nums[i]]++;

        for(map<int,int>::iterator iter = record.begin();iter != record.end();iter++)
        {
            if(iter->second > nums.size()/2)
                return iter->first;
        }

    }
};

int main()
{
    cout << "Hello World!" << endl;

    Solution test;
    int nums[] = {2,2,1,1,1,2,2};
    vector<int>veci(nums,nums+sizeof(nums)/sizeof(int));
    cout<<test.majorityElement(veci);

    return 0;
}
