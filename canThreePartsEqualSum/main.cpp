#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0;
        int counter = 0;
        int tmp = 0;
        for(int i = 0;i<A.size();i++)
            sum += A[i];

        if(sum % 3 != 0)
            return false;
        for(int i = 0;i<A.size();i++)
        {
            tmp += A[i];
            if(counter == 2)
            {
                tmp = 0;
                for(int j = i;j<A.size();j++)
                {
                    tmp += A[j];
                    if (tmp == sum/3)
                        return true;
                }
            }
            if(tmp == sum/3)
            {
                tmp = 0;
                counter++;
            }
        }
        return false;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    int num[] = {3,3,6,5,-2,2,5,1,-9,4};
    vector<int> in(num,num + sizeof(num)/sizeof(int));
    Solution test;
    cout<< "res "<< test.canThreePartsEqualSum(in);
    return 0;
}
