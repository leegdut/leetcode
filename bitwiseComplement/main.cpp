#include <iostream>
#include<bitset>

using namespace std;


class Solution {
public:
    int bitwiseComplement(int N) {
        int i= 1;
        while(i<N)
        {
            i = (i<<1) +1;
        }
        return(i^N);        //异或（相同为0，不同为1），找到与N同宽的满的，如101 就是111，然后异或就等于取反，异或结果就是010
    }
};

int main()
{
    cout << "Hello World!" << endl;
    bitset<8> bs(5);
    bitset<8> bs_2(~5);
    cout<<bs << "  " <<bs_2<<endl;
    Solution test;
    test.bitwiseComplement(5);
    return 0;
}
