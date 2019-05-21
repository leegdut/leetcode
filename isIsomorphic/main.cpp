#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() == 0)
            return 1;
        else if (s.length() != t.length()) {
            return 0;
        }
        int i = 0;
        while(i<s.length())
        {
            if(s.find(s[i]) != t.find(t[i]))
                return false;
            i++;
        }

        return true;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    string s = "egg";
    string t = "acd";
    Solution test;
    cout<<test.isIsomorphic(s,t);

    return 0;
}
