#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& v) {
        if(v[0][0]==v[1][0]&&v[0][1]==v[1][1])
            return false;
        if(v[0][0]==v[2][0]&&v[0][1]==v[2][1])
            return false;
        if(v[2][0]==v[1][0]&&v[2][1]==v[1][1])
            return false;

        if(v[2][1]==v[1][1]&&v[2][1]==v[0][1])
            return false;

        if(v[2][0]==v[1][0]&&v[2][0]==v[0][0])
            return false;
        double q=(v[1][0]-v[0][0])*1.0/(v[1][1]-v[0][1]);
        double q2=(v[2][0]-v[0][0])*1.0/(v[2][1]-v[0][1]);
        if(q==q2)
            return false;
        return true;

    }
};

int main()
{
    cout << "Hello World!" << endl;

    int num[][2]= {{1,1},{2,3},{3,2}};
    vector<vector<int>> points;
    for(int i = 0;i<sizeof(num)/sizeof(int)/2;i++)
    {
        vector<int>tmp;
        tmp.push_back(num[i][0]);
        tmp.push_back(num[i][1]);
        points.push_back(tmp);
    }
    Solution test;
    cout<<test.isBoomerang(points);
    return 0;
}
