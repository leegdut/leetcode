#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tmp = 0;
        for(int i = 0;i<nums.size();i++)
            tmp += i - nums[i];

        return tmp+  nums.size();
    }
};

int main()
{
    cout << "Hello World!" << endl;



    return 0;
}
