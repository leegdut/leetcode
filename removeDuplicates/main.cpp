#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(vector<int>::iterator iter= nums.begin()+1;iter != nums.end();)
        {
            if(*iter == *(iter-1))
            {
                iter = nums.erase(iter);
            }else {
                iter++;
            }
        }
        return nums.size();
    }
};

int main()
{
    cout << "Hello World!" << endl;

    int nums[] = {0,0,1,1,1,2,2,3,3,4};

    vector<int> veci(nums,nums + sizeof(nums)/sizeof(int));
    Solution test;
    cout<<test.removeDuplicates(veci);

    return 0;
}
