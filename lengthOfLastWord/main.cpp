#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        string tmp = s;
        while(tmp.rfind(" ") == tmp.length()-1)
        {
            if(tmp.length()>=2)
                tmp = tmp.substr(0,tmp.length()-1);
            else {
                return 0;
            }
        }
        int pos = tmp.rfind(" ");
        if(pos == -1)
            return tmp.length();
        else {
            return tmp.length() - pos-1;
        }
//        cout<<pos<<endl;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    string str = "Hello World";
    Solution test;
    cout<<test.lengthOfLastWord(str);
    return 0;
}
