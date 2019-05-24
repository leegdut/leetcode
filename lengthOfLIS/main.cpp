#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int counter = 0;
        int max = 0;

        for(int i  =1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                counter++;
            else {
                max = max>counter?max:counter;
                counter = 0;
            }
        }
        max = max>counter?max:counter;
        return max;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    vector<int> veci = {10,9,2,5,3,7,101,18};
    Solution test;
    cout<< test.lengthOfLIS(veci);
    return 0;
}

