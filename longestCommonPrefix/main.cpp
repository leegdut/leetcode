#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        int size_strs = strs[0].length();
        for(int i = 1;i<strs.size();i++)
            size_strs = size_strs < strs[i].length()?size_strs:strs[i].length();

        string res = "";
        for(int i = 0;i<size_strs;i++)
        {
            char tmp = strs[0][i];
            for(int j = 1;j<strs.size();j++)
            {
                if(strs[j][i] != tmp)
                    return res;
            }
            res += tmp;
        }
//        cout<<size_strs;
        return res;
    }
};



int main()
{
    cout << "Hello World!" << endl;
    char* str[] =  {"flower","flow","flight"};

    int size_str = sizeof(str)/sizeof(char *);
    vector<string> in;

    for(int i = 0;i<size_str;i++)
    {
        string tmp = str[i] + '\0';
       in.push_back(tmp);
    }

    Solution test;
    cout<<test.longestCommonPrefix(in);
    return 0;
}
