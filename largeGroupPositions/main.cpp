#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        if(S.length()>=3)
        {
            for(int i = 0;i<S.length()-2;i++)
            {
                int j = i;
                while(S[i] == S[j])
                {
                    //                cout<<"S[i] "<<i<< j<<endl;
                    j++;
                }
                j--;
                if(j-i>=2)
                {
                    vector<int>tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    res.push_back(tmp);
                    i = j;
                }
            }
        }
        return res;
//        cout<<"fini"<<endl;
    }
};


int main()
{
    cout << "Hello World!" << endl;

//    string str = "over I speak Goat Latin";
    string str = "abbxxxxzzy";
    Solution test;
    test.largeGroupPositions(str);
    return 0;
}
