#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S)
    {
        string results;
        int flag=0;      //标志位
        for(char c:S)    //遍历字符串，for循环语句的特殊格式，C++11新标准
        {
            if(c == '(' && flag++ >0)
                results += c;
            if(c == ')' && flag-- >1)
                results +=c;
        }
        return results;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    string in("(()())(())(()(()))");
    Solution test;
    test.removeOuterParentheses(in);
    return 0;
}
