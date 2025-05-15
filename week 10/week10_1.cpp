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
    int start[v];
    int end[v];
    vector<pair<pair<int,int>,int > > a(v);
    for(int i = 0;i<v;i++)
    {
        cin >> start[i];
    }
    for(int i = 0;i<v;i++)
    {
        cin >> end[i];
        a[i].first.first = start[i];
        a[i].first.second = end[i];
        a[i].second = i+1;
    }
    vector<int> ans = activity(a);
    cout << "Number of non conflicting activities - " << ans.size()<<endl;
    cout << "List of activities - ";
    for(int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
