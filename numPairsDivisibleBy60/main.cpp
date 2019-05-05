#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int counter = 0;
        for(int i =0;i<time.size();i++)
        {
            for(int j =i+1;j<time.size();j++)
            {
                if((time[i]+time[j])%60 == 0)
                {
                    counter++;
                }
            }
        }
        return counter;
    }
};


int main()
{
    int num[] = {30,20,150,100,40};

    vector<int> in(num,num+sizeof(num)/sizeof(int));
    Solution test;
    cout<< "ress "<< test.numPairsDivisibleBy60(in);
    cout << "Hello World!" << endl;
    return 0;
}
