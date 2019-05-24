#include <iostream>
#include <set>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());

        vector<int> res;

        for(set<int>::iterator iter = s1.begin();iter != s1.end();iter++)
        {
            if(s2.find(*iter) != s2.end())
            {
                res.push_back(*iter);
            }
        }

        return res;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    vector<int>nums1 = {4,9,5};
    vector<int>nums2 = {9,4,9,8,4};
    Solution test;
    test.intersection(nums1,nums2);
    return 0;
}
