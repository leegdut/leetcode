#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

//find() 可以在指定字符串中查找完全匹配子串的位置

// find_first_of() 在指定字符串中查找第一个任意匹配子串中字符的位置

//find_first_not_of() 在指定字符串中查找第一个不任意匹配子串中字符的位置

//find_first_of 可以找到字符串里面有目标字符串里面内容的位置，如目标字符串里有空格或逗号其中一个，用这个函数就能返回

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
//        string filter = " !?',;.";
        int word_head = 0;
        int word_tail = 0;
        bool next_word = 1;
        map<string,int> res;
        int max = 0;
        string res_str = "";
//        while(1)
//        {
//            pos = paragraph.find_first_of(filter,pos+1);
////            pos_2 = paragraph.find_first_of(filter,pos);
//            if(paragraph.find_first_of(filter,pos) == string::npos)
//                break;
//            cout<<paragraph.substr(pos+1)<<endl;;
//        }

        for(int i = 0;i<paragraph.length();i++)
        {
            if((paragraph[i]>'z' || paragraph[i]<'A') && next_word ==1)     //if now from a to Z
            {
                word_tail = i-1;
                next_word = 0;
                string tmp = paragraph.substr(word_head,word_tail-word_head+1);
                transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);         //to lower
                vector<string>::iterator iter = find(banned.begin(),banned.end(),tmp);
                if(iter == banned.end())
                {
                    res[tmp]++;
                    if(res[tmp] > max)
                    {
                        res_str = tmp;
                        max = res[tmp];
                    }
                }
            }
            if((paragraph[i]<='z' && paragraph[i]>='A') && next_word ==0)
            {
                next_word = 1;
                word_head = i;
            }
            if((paragraph[i]<'z' && paragraph[i]>'A') && i == paragraph.length()-1)     //if now from a to Z
            {
                word_tail = i;
                next_word = 0;
                string tmp = paragraph.substr(word_head,word_tail-word_head+1);
                transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);         //to lower
                vector<string>::iterator iter = find(banned.begin(),banned.end(),tmp);
                if(iter == banned.end())
                {
                    res[tmp]++;
                    if(res[tmp] > max)
                    {
                        res_str = tmp;
                        max = res[tmp];
                    }
                }
            }
        }
//        cout<<res_str;
        return res_str;
    }
};

int main()
{
    cout << "Hello World!" << endl;

//    string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
    string str = "Bob";
    Solution test;
    vector<string> banned;
//    vector<int> bannedi;

//    banned.push_back("hit");
//    find(banned.begin(),banned.end(),"1");

    test.mostCommonWord(str,banned);
    return 0;
}
