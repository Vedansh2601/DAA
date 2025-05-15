#include<bits/stdc++.h>
using namespace std;
struct Comp {
    bool operator()(pair<int, string> a, pair<int, string> b) {
        return a.first > b.first;
    }
};
void huffman(string s)
{
    unordered_map<char,int> freq;
    for(char c : s)
    {
        freq[c]++;
    }
    
    
    priority_queue<pair<int,string>,vector<pair<int,string> >,Comp> pq;
    for(auto i : freq)
    {
        string st(1,i.first);
        pq.push({i.second,st});
    }
    
    
    unordered_map<char,string> code;
    for(auto i : freq)
    {
        code[i.first] = "";
    }
    
    
    while(pq.size() > 1)
    {
        auto left = pq.top();
        pq.pop();
        
        auto right = pq.top();
        pq.pop();
        
        for(char c : left.second)
        {
            code[c] = "0" + code[c];
        }
        
        for(char c : right.second)
        {
            code[c] = "1" + code[c];
        }
        
        pq.push({(left.first+right.first),(left.second+right.second)});
    }
    
    cout << "huffman code"<< endl;
    for(auto c : code)
    {
        cout << c.first << " code :- "<<c.second<<endl;
    }
    
    cout << "encoded string -> ";
    string en = "";
    for(char c : s)
    {
        en+=code[c];
    }
    cout <<en<<endl;
   /* unordered_map<string,char> rev;
    for(auto c : code)
    {
        rev[c.second] = c.first;
    }
    string temp = "",decoded = "";
    for(auto c : en)
    {
        temp += c;
        if(rev.count(temp))
        {
            decoded += rev[temp];
            temp = "";
        }
    }
    cout << "decoded string -> "<<decoded<<endl;
    */
}

int main()
{
    string txt;
    getline(cin,txt);
    huffman(txt);
}