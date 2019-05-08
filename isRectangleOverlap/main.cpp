#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if((rec2[0]>rec1[0] && rec2[0]<rec1[2]) || (rec2[2]>rec1[0] && rec2[2]<rec1[2]))
        {
            if((rec2[1]>rec1[1] && rec2[1]<rec1[3]) || (rec2[3]>rec1[1] && rec2[3]<rec1[3]))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello World!" << endl;

//    int rec1[] = {0,0,2,2};
//    int rec2[] = {1,1,3,3};

        int rec1[] = {0,0,1,1};
        int rec2[] = {1,0,2,1};

    vector<int>A(rec1,rec1+4);
    vector<int>B(rec2,rec2+4);
    Solution test;
    cout<<test.isRectangleOverlap(A,B);

    return 0;
}
