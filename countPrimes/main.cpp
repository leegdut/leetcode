#include <iostream>
#include <math.h>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        if(n==3)
            return 1;
        else if (n<=2) {
            return 0;
        }
        int res = 1;
        for(int i = 3;i<=n;i++)
        {
            bool flag = true;
            for(int j = 3;j<=sqrt(i);j++)
            {
                if(i%j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                res++;
        }
        return res;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Solution test;
    cout<<test.countPrimes(10);
    return 0;
}
