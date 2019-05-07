#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        res.push_back(c);
        sort(res.begin(),res.end());
        int min = res[1]-res[0] < res[2]-res[1] ? res[1]-res[0] : res[2]-res[1];
        int max = res[1]-res[0] > res[2]-res[1] ? res[1]-res[0] : res[2]-res[1];
        res.clear();
        if(min + max ==2)
        {
            res.push_back(0);
            res.push_back(0);
            return res;
        }else if(min <= 2)
        {
            res.push_back(1);
            res.push_back(min-1 + max -1);
            return res;
        }else{
            res.push_back(2);
            res.push_back(min-1 + max -1);
            return res;
        }
    }
};

int main()
{
    cout << "Hello World!" << endl;

    Solution test;
    test.numMovesStones(1,2,5);
    return 0;
}
