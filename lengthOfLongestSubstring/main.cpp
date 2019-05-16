#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        int max = 1;
        string tmp;
        tmp = s[0];
        for(int i = 1;i<s.length();i++)
        {
            if(tmp.find(s[i]) == -1)
            {
                tmp = tmp + s[i];
                max = max>tmp.length()?max:tmp.length();
            }else {
                tmp = tmp + s[i];
                int pos = tmp.find(s[i]);
                tmp  = tmp.substr(pos+1);
            }
        }
        return max;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    string str = "abcabcbb";
//    string str = "dvdf";

    Solution test;
    cout<<test.lengthOfLongestSubstring(str);
    return 0;
}
