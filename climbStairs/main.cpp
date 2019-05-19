#include <iostream>
#include <math.h>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;

        int a = n/2;
        int b = n%2;

        if(b == 0 )
            return pow(2,a);
        else {
            return pow(2,a)+1;
        }
    }
};

int main()
{
    cout << "Hello World!" << endl;
    Solution test;
    cout<<test.climbStairs(3);
    return 0;
}
