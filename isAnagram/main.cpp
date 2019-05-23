#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        sort(s.begin(),s.end());
//        sort(t.begin(),t.end());
//        return (s == t);

//    }
//};

class Solution {
public:
    bool isAnagram(string s, string t) {
    map<char,int>record1;
    map<char,int>record2;
    if(s.length() != t.length())
        return 0;
    for(int i = 0;i<s.length();i++)
    {
        record1[s[i]]++;
        record2[t[i]]++;
    }
    return (record1 == record2);
    }
};


int main()
{
    cout << "Hello World!" << endl;
    string s = "anagram";
    string t = "nagaram";


    Solution test;
    cout<<test.isAnagram(s,t);
    return 0;
}
