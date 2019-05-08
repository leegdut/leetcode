#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int pos_last = -1;
        int max =0;

        for(int i =0;i<seats.size();i++)
        {
            if(seats[i] == 1)
            {
                if(pos_last == -1)
                {
                    int tmp = i;
                    max = tmp;
                    pos_last =i;
//                    pos_tail =i;
                }else {
                    int tmp = (i - pos_last-1);
                    if(tmp % 2 ==1)
                        tmp = (tmp +1 )/2;
                    else {
                        tmp = tmp/2;
                    }
                    max = tmp > max?tmp:max;
                    pos_last = i;
                }
            }
            if(i == seats.size() -1 && seats[i] == 0)
            {
                if(pos_last == -1)
                {
                    max = i;
                }
                else {
                    int tmp = i -pos_last;
                    max = tmp > max?tmp:max;
                }
            }
        }

        return max;
    }
};

int main()
{
    cout << "Hello World!" << endl;

    int num[] = {1,0,0,0};

    vector<int> seats(num,num + sizeof(num)/sizeof(int));

    Solution test ;
    cout<< test.maxDistToClosest(seats);
    return 0;
}
