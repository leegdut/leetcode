#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int counter = 0;

        int j = 0;

        for(int i = 0;i<g.size();i++)
        {
            for(;j<s.size();j++)
            {
                if(s[j] >= g[i])
                {
                    j++;
                    counter++;
                    break;
                }
            }
        }

        return counter;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    vector<int> child  = {1,2,3};
    vector<int> cookies = {1,1};
    Solution test;
    cout<<test.findContentChildren(child,cookies);
    return 0;
}

