#include <iostream>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
//        int max_size = a.length() > b.length()?a.length():b.length();
//        string tmp_a  = "0x" + a;
//        string tmp_b  = "0x" + b;
        int i_a =  stoi(a,NULL,2);
        int i_b =  stoi(b,NULL,2);
        int i_sum = i_a + i_b;

        int yu = i_sum%2;
        i_sum = i_sum /2;
        string res = "";
//        char * c;
//        sprintf(res,"%"
//        itoa(i_sum,res.c_str(),2);
        while (i_sum != 0 || yu != 0) {
            res = to_string(yu) + res;
            yu = i_sum%2;
            i_sum = i_sum /2;
        }
//        cout<<res<<endl;
        return res;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    string s1 = "11";
    string s2 = " 1";

    Solution test;
    cout<<test.addBinary(s1,s2);

    return 0;
}
