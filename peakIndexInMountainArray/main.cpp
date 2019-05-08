#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max = 0;
        for(int i = 1;i<A.size()-1;i++)
        {
            if(A[i] > A[i-1] && A[i] > A[i+1] )
//                max = A[i]>max?A[i]:max;
            {
                max=i;
                return i;
            }
        }
        return max;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    int num[] = {3,4,5,1};
    vector<int>in(num,num + sizeof(num)/ sizeof(int));
    Solution test;
    cout<<test.peakIndexInMountainArray(in);
    return 0;
}
