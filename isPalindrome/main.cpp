#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        string tmp= to_string(x);
        for(int i = 0;i<tmp.size()/2;i++)
        {
            if(tmp[i] != tmp[tmp.size()-1-i])
                return false;
        }
        return true;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Solution test;
//    cout<<5/2;    //2
    cout<<test.isPalindrome(-121);
    return 0;
}
