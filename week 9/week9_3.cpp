#include <bits/stdc++.h>
using namespace std;

int minimumsize(vector<int>& s)
{
    int pwt = 0,wt = 0;
    sort(s.begin(),s.end());
    if(s.size() > 1)
    {
        pwt = s[0];
        for(int i = 1;i< s.size();i++)
        {
            pwt += s[i];
            wt += pwt;
        }
        return wt;
    }
    return wt;
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
    int wt = minimumsize(arr);
    cout << wt;
}