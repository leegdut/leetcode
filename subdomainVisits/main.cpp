#include <iostream>
#include <string>
#include<vector>
#include <map>

using namespace std;

//find
//substr

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int>record;
        map<string,int>new_record;
        vector<string> output(cpdomains);
        int pos= 0;
        for(int i=0;i<cpdomains.size();i++)
        {
//            cout<<cpdomains[i].find(" ")<<endl;     //the position of " "
//            cout<<cpdomains[i].substr(0,cpdomains[i].find(" "))<<endl;      //first word,from 0 to "position",not include " "
//            cout<<cpdomains[i].substr(cpdomains[i].find(" ")+1)<<endl;      //second word ,not include " "
//            int tmp  = stoi(cpdomains[i].substr(0,cpdomains[i].find(" ")));
//            cout<< tmp<<endl;
            record[cpdomains[i].substr(cpdomains[i].find(" ")+1)] =    stoi(cpdomains[i].substr(0,cpdomains[i].find(" ")));
        }
        for(map<string,int>::iterator iter=record.begin();iter != record.end();iter++)
        {
            while(1)
            {
//                cout<<iter->first.substr(iter->first.find(".",pos)+1)<<endl;
                new_record[iter->first.substr(iter->first.find(".",pos)+1)] =0;
                 pos = iter->first.find(".",pos)+1;
//                cout<<"pos "<<pos<<" string size "<<iter->first.length()<<endl;

                if(iter->first.find(".",pos) == string::npos)
                {
                    pos = 0;
                    break;
                }
            }
        }
        for(map<string,int>::iterator iter=new_record.begin();iter != new_record.end();iter++)
        {
            for(map<string,int>::iterator iter_r=record.begin();iter_r != record.end();iter_r++)
            {
                if(iter_r->first.find(iter->first) != string::npos)
                    iter->second += iter_r->second;
            }
            output.push_back(to_string(iter->second) +" "+iter->first);
        }

        return output;
    }
};


int main()
{
    cout << "Hello World!" << endl;

//    char* str[] = {"901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"};
    char* str[] = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    int size = sizeof(str)/sizeof(char*);
    vector<string> in;
    for(int i=0;i<size;i++)
    {
        string tmp = str[i] + '\0';
        in.push_back(tmp);
    }

//    string testt("google.mail.com");
//    cout<<"fisrst test"<<testt.find("google.mail.com")<<endl;
//    if(testt.find("google.mail.com") == string::npos)
//        cout << "hi"<<endl;
//    cout<<"fisrst test"<<testt.find("gogle.mail.com")<<endl;
//    if(testt.find("goole.mail.com") == 0)
//        cout << "hi1"<<endl;

    Solution test;
    test.subdomainVisits(in);
    return 0;
}
