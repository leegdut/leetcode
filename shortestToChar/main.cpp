#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int pos=-1;
        vector<int> res;
        for(int i=0;i<S.length();i++)
        {
            if(S[i] == C)
                pos =i;
            int pos_tail;
            if(S.find(C,i) != string::npos)
            {
                pos_tail = S.find(C,i);
            }else {
                res.push_back(i-pos);
                continue;
            }

            if(pos != -1 && (pos_tail - i) > (i - pos))     //head shorter than tail
                res.push_back(i-pos);
            else if(pos != -1 && (pos_tail - i) < (i - pos))
                res.push_back(pos_tail - i);
            else {
                res.push_back(pos_tail - i);
            }
        }
        return res;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    string S = "loveleetcode";
    char C = 'e';

    Solution test;
    test.shortestToChar(S,C);
    return 0;
}
