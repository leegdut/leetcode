#include <iostream>

using namespace std;


class Solution {
public:
    int addDigits(int num) {
        int sum = 0;

        while (num >= 10) {
            sum = 0;
            while(num)
            {
                sum += num%10;
                num = num/10;
            }
            num = sum;
        }
        return num;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    class Solution {
    public:
        int addDigits(int num) {

        }
    };

    return 0;
}
