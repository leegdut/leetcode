#include <iostream>

using namespace std;

bool isBadVersion(int version);

//class Solution {
//public:
//    int firstBadVersion(int n) {
//        int low = 1;
//        int high = n;

//        unsigned int mid = (low + high)/2;
//        while(high - low >1)
//        {
//            if(isBadVersion(mid))
//                high = mid;
//            else
//                low = mid;

//            mid = (low + high)/2;
//        }
//        return high;
//    }
//};


class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;        //坏区的左边界，每次找到好区的值+1，则+1后的值有可能就是左边界，只到左边界 == 右边界就是坏区边界
        int high = n;       //坏区右边界

        unsigned int mid = low + (high-low)/2;      //      *********low***high  ,,  （low + high）/2 ==    (*********low***high)   /2
                                                //      *********low***high  ,,  low + (high-low）/2 == *********low + (low***high)/2;
        while(low <high)
        {
            if(isBadVersion(mid))
                high = mid;
            else
                low = mid+1;

            mid = low + (high-low)/2;
        }
        return low;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
