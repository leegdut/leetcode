#include <iostream>
#include <vector>
#include<map>

using namespace std;



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>record;
        for(int i = 0;o<tasks.size();i++)
        {
            record[tasks[i]]++;
        }

        while(record.size() != 0)
        {
            if(n>=record.size())
            {
                map<char,int>::iterator iter = record.begin();
                for(;iter != record.end();)
                {
                    if(iter.second>1)
                    {
                        iter.second--;
                        iter++;
                    }else {
                        iter = record.
                    }
                }
            }
        }
    }
};


int main()
{
    cout << "Hello World!" << endl;


    vector<char> tasks = {"A","A","A","B","B","B"};
    Solution test;
    test.leastInterval(tasks,2);

    return 0;
}
