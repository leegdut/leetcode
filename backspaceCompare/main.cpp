#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string A = S;
        string B = T;
        replace_word(A);
        replace_word(B);
//        cout<<"A "<<A<<endl;
//        cout<<"B "<<B<<endl;
        if(A == B)
            return true;
        else {
            return false;
        }
    }

    void replace_word(string & str)
    {
        while(str.find("#")!= string::npos)
        {
            int pos = str.find("#");
            if(pos>=1)
            {
                str = str.substr(0,pos-0-1) + str.substr(pos+1);
//                cout<<str<<endl;
            }else if(pos == 0&&str.length()!=1){
                str = str.substr(pos+1);
            }else if(pos == 0&&str.length()==1)
            {
                str = "";
            }
        }
    }
};

int main()
{
    cout << "Hello World!" << endl;
    string str = "a#c";
    string str2 = "b";
    Solution test;
    cout<<test.backspaceCompare(str,str2);
    return 0;
}
