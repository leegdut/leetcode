#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1;i>=0;i--)
        {
            if(digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    int nums[] = {1,2,3};
    vector<int>veci(nums,nums+sizeof (nums)/sizeof (int));
    Solution test;
    test.plusOne(veci);
    return 0;
}
