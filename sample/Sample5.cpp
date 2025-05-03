#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int numofparts(string s)
{
    unordered_map<char,int> f;
    for(int i = 0; i < s.length();i++)
    {
        f[s[i]]++;
    }
    for(int i = s.length(); i > 0; i--)
    {
        if(s.length()%i != 0)
        {
            continue;
        }
        bool flag = true;
        for(auto [ch,fr] : f)
        {
            if(fr % i != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            return i;
        }
    }
    return 1;
}
int main()
{
    string s;
    getline(cin,s);
    cout << numofparts(s);
}