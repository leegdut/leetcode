#include <iostream>
#include <vector>

using namespace std;


//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if(prices.size() == 0)
//            return 0;
//        int min_price = prices[0];
//        int max_profit  =0;
//        for(int i = 0;i<prices.size();i++)
//        {
//            min_price = min_price < prices[i]?min_price:prices[i];
//            max_profit  = max_profit > (prices[i] - min_price)?max_profit:(prices[i] - min_price);
//        }
//        return max_profit;
//    }
//};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
//        int min_price = prices[0];
        int max_profit  =0;
        for(int i = 1;i<prices.size();i++)
        {
//            min_price = min_price < prices[i]?min_price:prices[i];
//            max_profit  = max_profit > (prices[i] - min_price)?max_profit:(prices[i] - min_price);
            if(prices[i-1] < prices[i])
            {
                max_profit += prices[i] - prices[i-1];
            }
        }
        return max_profit;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    int nums[] = {7,1,5,3,6,4};
    vector<int> veci(nums,nums + sizeof(nums)/sizeof(int));
    Solution test;
    cout<<test.maxProfit(veci);
    return 0;
}
