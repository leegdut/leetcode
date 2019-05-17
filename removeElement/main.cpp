#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(vector<int>::iterator iter = nums.begin();iter != nums.end();)
        {
            if(*iter == val)
                iter = nums.erase(iter);
            else {
                iter++;
            }
        }
        return nums.size();
    }
};


int main()
{
    cout << "Hello World!" << endl;
    int nums[] = {0,1,2,2,3,0,4,2};

    vector<int> veci(nums,nums + sizeof(nums)/sizeof(int));
    Solution test;
    cout<<test.removeElement(veci,2);

    return 0;
}
