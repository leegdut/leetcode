#include <iostream>

using namespace std;

class Solution {
public:
            int aback(char a) {
            if(a=='I') return 1;
            if(a=='V') return 5;
            if(a=='X') return 10;
            if(a=='L') return 50;
            if(a=='C') return 100;
            if(a=='D') return 500;
            if(a=='M') return 1000;
            return 0;
        }

    int romanToInt(string s) {
        int b = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(aback(s[i])<aback(s[i+1]))
            {
                 b=b+(aback(s[i+1])-aback(s[i]));
                i++;
            } else
                b+=aback(s[i]);
        }
        return b;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    string str = "III";
    Solution test;
    cout<<test.romanToInt(str);
    return 0;
}
