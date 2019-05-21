#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + len);
        reverse(nums.begin()+len,nums.end());
    }
};


int main()
{
    cout << "Hello World!" << endl;
    int nums[] = {1,2,3,4,5,6,7};
    vector<int>veci(nums,nums+sizeof(nums)/sizeof(int));
    Solution test;
    test.rotate(veci,3);

    return 0;
}
