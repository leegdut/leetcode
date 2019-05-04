#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector< vector<int> >& trust) {
        vector<int>res(N,0);
        for(int i = 0;i < trust.size();i++)
        {
            res[trust[i][0]-1] = -1;
            if(res[trust[i][1]-1] != -1)
            {
                res[trust[i][1]-1]++;
            }
        }
        for(int j=0;j<N;j++)
        {
            if(res[j] == N-1)
                return j+1;
        }
        return -1;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    int trust[][2] = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    int size = sizeof(trust)/sizeof(int)/2;
    vector< vector<int> > in;
    for(int i = 0;i < size;i++)
    {
        cout<< trust[i] <<" "<< trust[i]+1<<endl;
        vector<int>tmp;
        tmp.push_back(*trust[i]);
        tmp.push_back(*(trust[i]+1));
        in.push_back(tmp);
    }
    Solution test;
    cout<<test.findJudge(4,in);
    return 0;
}

