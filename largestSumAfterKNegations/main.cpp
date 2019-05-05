#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        for(int i = 0;i<K;i++)
        {
            sort(A.begin(),A.end());
            A[0] = -A[0];
        }
        int sum = 0;
        for(int j = 0;j<A.size();j++)
        {
            sum += A[j];
        }
        return sum;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    int num[] = {2,-3,-1,5,-4};
    vector<int> in(num,num+sizeof(num)/sizeof(int));
    Solution test;
    cout<<"res  "<<test.largestSumAfterKNegations(in,2);
    return 0;
}
