#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>money;
        for(int i =0; i<bills.size();i++)
        {
            if(bills[i] == 5)
                money[5]++;
            else if(bills[i] == 10)
            {
                if(money[5] != 0)
                {
                    money[5]--;
                    money[10]++;
                }else {
                    return 0;
                }
            }
            else if (bills[i] == 20) {
                if(money[10] != 0 && money[5] != 0)
                {
                    money[10]--;
                    money[5]--;
                    money[20]++;
                }else if (money[5]>2) {
                    money[5] -= 3;
                    money[20]++;
                }else {
                    return 0;
                }
            }
        }
        return 1;
    }
};



int main()
{
    cout << "Hello World!" << endl;


    vector<int>veci = {5,5,10,10,20};
    Solution test;
    cout<<test.lemonadeChange(veci);
    return 0;
}

