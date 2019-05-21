#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;


//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        map<int,int>record;
////        if(k>nums.size())
////            return false;

//        for(int i = 0;i<nums.size();i++)
//        {
////            if(nums.)
////            cout<<i<<" "<<record[nums[i]]<<endl;
//            if(record[nums[i]] != 0)
//            {
//                if(i+1 - record[nums[i]]<=k)
//                {
//                    return true;
//                }
//            }
//            record[nums[i]] = i+1;
//        }
//        return false;
//    }
//};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        map<int,int>record;
        if(k <=0 )
            return false;
        int run_times = nums.size()>k?nums.size()-k:1;

        for(int i = 0;i<run_times;i++)
        {
            if(run_times == 1)
            {
                set<int>record(nums.begin()+i,nums.begin()+nums.size());
                if(record.size() != nums.size())
                    return true;
            }else {
                set<int>record(nums.begin()+i,nums.begin()+i+k+1);
                if(record.size() != k + 1)
                    return true;
            }

        }
        return false;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Solution test;
    int nums[] = {1,2,3,1,2,3};
    vector<int>veci(nums,nums+sizeof(nums)/sizeof(int));
    cout<<test.containsNearbyDuplicate(veci,2);
//    set<int>record(veci.begin(),veci.begin()+3);
    return 0;
}
