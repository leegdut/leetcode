#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    string toGoatLatin(string S) {
//        vector<string>v_str;
        int word_head = 0;
        int word_tail = 0;
        bool next_word = 1;
        int word_counter = 0;
        string res;
        for(int i = 0;i<S.length();i++)
           {
               if((S[i]>'z' || S[i]<'A') && next_word ==1)     //if now from a to Z
               {
                   word_tail = i-1;
                   next_word = 0;
                   string tmp = S.substr(word_head,word_tail-word_head+1);
//                   cout<<" output word "<<tmp<<endl;
                   replace_word(tmp,++word_counter);
                   res += tmp + " ";
//                   v_str.push_back(tmp);
               }
               if((S[i]<='z' && S[i]>='A') && next_word ==0)
               {
                   next_word = 1;
                   word_head = i;
               }
               if((S[i]<='z' && S[i]>='A') && i == S.length()-1)     //if now from a to Z
               {
                   word_tail = i;
                   next_word = 0;
                   string tmp = S.substr(word_head,word_tail-word_head+1);
//                   cout<<" output word last"<<tmp<<endl;
                   replace_word(tmp,++word_counter);
                   res += tmp;
//                   v_str.push_back(tmp);
               }
        }
//        return res;
        cout<<"  "<<res<<endl;
    }

    void replace_word(string & str, int num)
    {
        string head = "";
        head += str[0];
        transform(head.begin(),head.end(),head.begin(),::tolower);
//        cout<< " head "<<head<<endl;
//         transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);         //to lower
        if(head == "a" || head == "e" || head == "o" ||head== "i" ||head == "u")
        {
            string tmp(num,'a');
            str = str + "ma" + tmp;
//            cout <<" in   " <<tmp <<endl;
        }
        else {
            string tmp(num,'a');
            str = str.substr(1) + str[0] + "ma" + tmp;
//            cout << tmp <<endl;
        }
    }

};


int main()
{
    cout << "Hello World!" << endl;

//    string str = "over I speak Goat Latin";
    string str = "Tcl DA";
    Solution test;
    test.toGoatLatin(str);
    return 0;
}
