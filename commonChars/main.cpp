#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector< map<char,int> > v_res;
        vector<string> return_res;
        for(int i = 0;i<A.size();i++)
        {
            map<char,int> res;
            for(int j = 0;j<A[i].size();j++)
            {
                if(res[A[i][j]] == 0)
                    res[A[i][j]] = 1;
                else
                    res[A[i][j]]++;
            }
            v_res.push_back(res);
        }

        map<char,int> m_res;
        for(map<char,int>::iterator iter=v_res[0].begin();iter!=v_res[0].end();iter++)
        {
            m_res[iter->first] = iter->second;
            for(int i =1;i<v_res.size();i++)
            {
                if(v_res[i][iter->first]< m_res[iter->first])
                    m_res[iter->first] = v_res[i][iter->first];
            }
            for(int k = 0;k< m_res[iter->first] ;k++)
            {
                string s = "";     //char to string
                s = s + iter->first;       //mark,way to char to string
                return_res.push_back(s);
            }
        }

        return return_res;
    }
};



int main()
{
//    cout << "Hello World!" << endl;
    char* a[] = {"bella","label","roller"};
    vector<string> str(a,a+3);
    Solution test;
    test.commonChars(str);
    return 0;
}

