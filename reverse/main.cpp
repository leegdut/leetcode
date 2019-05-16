#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int reverse(int x) {

//        if(x > pow(2,31))
//            return -1;
//        else if(x<0)
//        {
//            if(-x > (pow(2,31)-1))
//                return -1;
//        }

        if(x >0 )
        {
            string tmp = to_string(x);
//            string tmp = x + "";      //cannot use
            std::reverse(tmp.begin(),tmp.end());
            long long int res = stoll(tmp);       //not enough
            if(res > (pow(2,31)-1))
                return 0;
            else {
//                int r = res;
                return res;
            }
        }else {
            string tmp = to_string(x);
            std::reverse(tmp.begin()+1,tmp.end());
            long long int res = stoll(tmp);
            res = res  *-1;
            if(res > (pow(2,31)))
                return 0;
            else {
                int r = -1 * res;
                return r;
            }
        }
    }
};



int main()
{
    cout << "Hello World!" << endl;

    Solution test;
    cout<<test.reverse(-2147483648);
    return 0;
}
