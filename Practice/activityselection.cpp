#include <bits/stdc++.h>
using namespace std;

vector<int> activity(vector<pair<pair<int,int>,int > >& act)
{
    int c = 0;
    vector<int> ans;
    sort(act.begin(),act.end(),[](pair<pair<int,int>,int > a,pair<pair<int,int>,int > b)
    {
        return a.first.second < b.first.second;
    });
    for(int i = 0;i<act.size();i++)
    {
        if(c <= act[i].first.first)
        {
            ans.push_back(act[i].second);
            c = act[i].first.second;
        }
    }
    return ans;
}
int main()
{
    int v;
    cin >> v;
    vector<pair<pair<int,int>,int > > a(v);
    for(int i = 0;i<v;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i].first.first = x;
        a[i].first.second = y;
        a[i].second = i+1;
    }
    vector<int> ans = activity(a);
    for(int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}