#include <bits/stdc++.h>
using namespace std;

void finding(vector<int>& s)
{
    sort(s.begin(),s.end());
    int n = s.size();
    if(n % 2 == 0)
    {
        if(s[0] == s[n/2] || s[(n/2)-2] == s[n-1])
        {
            cout << "yes"<<endl;
        }
        cout << (double)(s[n/2]+s[(n/2)-1])/2;
    }
    else
    {
        if(s[0] == s[(n/2)] || s[(n/2)-1] == s[n-1])
        {
            cout << "yes"<<endl;
        }
        cout<<s[n/2];
    }
    
}
int main()
{
    int s;
    cin >> s;
    vector<int> arr(s);
    for(int i =0;i<s;i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    finding(arr);
}