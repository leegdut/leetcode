#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        map<int,vector<int>>m_res;
        int counter=0;
        int res = 0;
        for(int i = 0;i<costs.size();i++)
        {
            m_res[costs[i][0] - costs[i][1]] = costs[i];
        }
        for(map<int,vector<int>>::iterator iter=m_res.begin();iter != m_res.end();iter++)
        {
            if(counter < m_res.size()/2)
            {
                res += iter->second[0];
            }
            else {
                res += iter->second[1];
            }
            counter++;
        }
        return res;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    int num[][2]= {{10,20},{30,200},{400,50},{30,20}};
    vector<vector<int>> t_in;
    for(int i =0;i<sizeof(num)/sizeof(int)/2;i++)
    {
        vector<int>in;
        in.push_back(num[i][0]);
        in.push_back(num[i][1]);
        t_in.push_back(in);
    }

    Solution test;
    cout<<"res" <<test.twoCitySchedCost(t_in);
    return 0;
}
